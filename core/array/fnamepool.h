#pragma once
#include "ue/offsets.h"

namespace ue
{
	namespace offsets
	{
		// FName Blocks
		constexpr uint32 fname_max_block_bits    = 13;
		constexpr uint32 fname_block_offset_bits = 16;
		constexpr uint32 fname_max_block         = 1 << fname_max_block_bits;;
		constexpr uint32 fname_block_offset      = 1 << fname_block_offset_bits;
		constexpr uint32 fname_size              = 1024;
	}

	class FNameEntryHandle
	{
	public:
		uint32 block  = 0;
		uint32 offset = 0;

		FNameEntryHandle(const uint32 in_block, const uint32 in_offset) : block(in_block),
		                                                                  offset(in_offset)
		{
		}

		explicit FNameEntryHandle(const uint32 id) : block(id >> offsets::fname_block_offset_bits),
		                                             offset(id & 65535)
		{
		}

		explicit operator uint32() const
		{
			return block << offsets::fname_block_offset_bits | offset;
		}
	};

	static_assert(sizeof(FNameEntryHandle) == 0x08);

	class FNameEntryHeader
	{
	public:
		uint16 is_wide : 1;
#ifdef WITH_CASE_PRESERVING_NAME
        uint16 len : 15;
#else
		static constexpr uint32 probe_hash_bits = 5;
		uint16 lower_case_probe_hash : probe_hash_bits;
		uint16 len                   : 10;
#endif
	};

	class FNameEntry
	{
	public:
		uint32 get_length() const
		{
			return header_.len;
		}

		bool is_entry_wide() const
		{
			return header_.is_wide;
		}

		const char* get_ansi_name_ex() const
		{
			return ansi_name;
		}

		const wchar_t* get_wide_name_ex() const
		{
			return wide_name;
		}

		std::string get_ansi_name() const
		{
			const auto str_len = get_length();
			if (str_len > 1024)
			{
				return "[Error: Overflow]";
			}

			return std::string(ansi_name, str_len);
		}

		std::wstring get_wide_name() const
		{
			const auto str_len = get_length();
			return std::wstring(wide_name, str_len);
		}

		std::string get_string() const
		{
			if (is_entry_wide())
			{
				const int size = WideCharToMultiByte(CP_UTF8, 0, wide_name, header_.len, nullptr, 0, nullptr, nullptr);
				std::string str(size, 0);
				WideCharToMultiByte(CP_UTF8, 0, wide_name, header_.len, str.data(), size, nullptr, nullptr);
				return str;
			}
			return std::string(ansi_name, header_.len);
		}

	private:
		FNameEntryHeader header_ = {};

		union
		{
			int8 ansi_name[offsets::fname_size] = {};
			wchar_t wide_name[offsets::fname_size];
		};
	};

	class FNameEntryAllocator
	{
	public:
		int8 lock[0x8];                         // 0x08
		uint32 current_block;                   // 0x04
		uint32 current_byte_cursor;             // 0x04
		uint8* block[offsets::fname_max_block]; // 0x10000

		FNameEntryAllocator(const uint32 m_current_block, const uint32 m_current_byte_cursor) :
			lock{},
			current_block(m_current_block),
			current_byte_cursor(m_current_byte_cursor),
			block{}
		{
		}

		FNameEntry& get_by_id(const int32_t key) const
		{
			const uint32 p_block = key >> 16;
			const uint16 offset  = static_cast<uint16>(key);

			if (!is_valid_index(key, p_block, offset))
			{
				return *reinterpret_cast<FNameEntry*>(block[0] + 0); // "None"
			}

			return *reinterpret_cast<FNameEntry*>(block[p_block] + static_cast<uint32_t>(2 * offset));
		}

		uint32 num_blocks() const
		{
			return current_block + 1;
		}

		bool is_valid_index(const int32 key) const
		{
			const uint32 p_block = key >> 16;
			const uint16 offset  = static_cast<uint16>(key);
			return is_valid_index(key, p_block, offset);
		}

		FNameEntry* get(const FNameEntryHandle handle) const
		{
			return reinterpret_cast<FNameEntry*>(block[handle.block] + stride * handle.offset);
		}

		bool is_valid_index(const int32 key, const uint32 p_block, const uint16 offset) const
		{
			return (key >= 0 && p_block < num_blocks() && offset * stride < block_size);
		}

	private:
		enum { stride = alignof(FNameEntry) };

		enum { block_size = stride * offsets::fname_block_offset };

		enum { max_size = 0x1FFFE };
	};

	static_assert(sizeof(FNameEntryAllocator) == 0x10010);

	class FNamePool
	{
	public:
		FNameEntryAllocator entry_allocator; // 0x10010
		int32 ansi_count;                    // 0x10010(0x04)
		int32 wide_count;                    // 0x10014(0x08)
	};

	static_assert(sizeof(FNamePool) - sizeof(FNameEntryAllocator) == 0x08);

	inline FNamePool* names;
}
