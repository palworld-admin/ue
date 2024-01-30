// ReSharper disable CppInconsistentNaming
#pragma once

namespace ue
{
	class UObject;

	// class FUObjectItem
	// Size: 0x18
	struct FUObjectItem
	{
		UObject* object;       //0x0000
		int32_t flags;         //0x0008
		int32_t cluster_index; //0x000C
		int32_t serial_number; //0x0010

		bool is_unreachable() const
		{
			return !!(flags & static_cast<std::underlying_type_t<EInternalObjectFlags>>(
				EInternalObjectFlags::Unreachable));
		}

		bool is_pending_kill() const
		{
			return !!(flags & static_cast<std::underlying_type_t<EInternalObjectFlags>>(
				EInternalObjectFlags::PendingKill));
		}

		bool is_valid(const bool even_if_pending_kill) const
		{
			return even_if_pending_kill
				       ? !this->is_unreachable()
				       : !(this->is_unreachable() || this->is_pending_kill());
		}

		UObject* get_valid_object() const
		{
			if (IsBadReadPtr(this, sizeof(this)) || IsBadReadPtr(this->object, sizeof(this->object)))
			{
				return nullptr;
			}
			return this->object;
		}
	};

	static_assert(sizeof(FUObjectItem) == 0x18);

	// FChunkedFixedUObjectArray
	// Size: 0x20
	class TUObjectArray
	{
	public:
		int32 len() const
		{
			return num_elements_;
		}

		bool valid_index(const int index) const
		{
			return index < len() && index >= 0;
		}

		UObject* get_by_index(const int32 index) const
		{
			if (valid_index(index))
			{
				if (const auto object_items = get_object_pointer(index);
					object_items && object_items->get_valid_object())
				{
					return object_items->get_valid_object();
				}
			}

			return nullptr;
		}

		FUObjectItem* get_object_pointer(const int32 index) const
		{
			const int32 chunk_index        = index / elements_per_chunk;
			const int32 within_chunk_index = index % elements_per_chunk;

			if (!valid_index(index))
			{
				return nullptr;
			}

			if (chunk_index >= num_chunks_)
			{
				return nullptr;
			}

			if (index >= max_elements_)
			{
				return nullptr;
			}

			const auto m_chunk = objects_[chunk_index];
			if (!m_chunk)
			{
				return nullptr;
			}

			return m_chunk + within_chunk_index;
		}

		FUObjectItem* get_item_by_index(const int32 index) const
		{
			if (index < num_elements_)
			{
				return objects_[index];
			}
			return nullptr;
		}

		FUObjectItem& operator[](const int index)
		{
			if (FUObjectItem* item_pointer = get_object_pointer(index))
			{
				return *item_pointer;
			}
		}

	private:
		enum
		{
			elements_per_chunk = 64 * 1024,
		};

		FUObjectItem** objects_              = nullptr;
		FUObjectItem* pre_allocated_objects_ = nullptr;
		int32 max_elements_                  = 0;
		int32 num_elements_                  = 0;
		int32 max_chunks_                    = 0;
		int32 num_chunks_                    = 0;
	};

	static_assert(sizeof(TUObjectArray) == 0x20);

	// class FUObjectArray
	// Size: 0x130
	class FUObjectArray
	{
	public:
		TUObjectArray* get()
		{
			return &array_;
		}

		int32 len() const
		{
			return array_.len();
		}

		explicit operator bool() const
		{
			return array_.len() > 0;
		}

	private:
		int8 pad_0001[0x0D] = {};
		TUObjectArray array_;
		int8 pad_0002[0x100] = {};
	};

	static_assert(sizeof(FUObjectArray) == 0x130);

#ifdef USE_FU_OBJECT_ARRAY
    inline FUObjectArray objects = {};
#else
	inline TUObjectArray* objects = nullptr;
#endif
}
