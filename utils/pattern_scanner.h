#pragma once
#include <cstdint>
#include <Windows.h>
#include <lazy_importer.h>

namespace ue::utils
{
	inline uintptr_t pattern_scan(const uintptr_t address, const char* signature, const bool relative = false)
	{
		static auto pattern_to_byte = [](const char* pattern)
		{
			auto bytes       = std::vector<int>{};
			const auto start = const_cast<char*>(pattern);
			const auto end   = const_cast<char*>(pattern) + LI_FN(strlen)(pattern);

			for (auto current = start; current < end; ++current)
			{
				if (*current == '?')
				{
					++current;
					bytes.push_back(-1);
				}
				else
				{
					bytes.push_back(LI_FN(strtoul)(current, &current, 16));
				}
			}
			return bytes;
		};

		const auto dos_header = reinterpret_cast<PIMAGE_DOS_HEADER>(address);
		const auto nt_headers = reinterpret_cast<PIMAGE_NT_HEADERS>(
			reinterpret_cast<std::uint8_t*>(address) + dos_header->e_lfanew);

		const auto size_of_image = nt_headers->OptionalHeader.SizeOfImage;
		const auto pattern_bytes = pattern_to_byte(signature);
		const auto scan_bytes    = reinterpret_cast<std::uint8_t*>(address);

		const auto s = pattern_bytes.size();
		const auto d = pattern_bytes.data();

		for (auto i = 0ul; i < size_of_image - s; ++i)
		{
			bool found = true;
			for (auto j = 0ul; j < s; ++j)
			{
				if (scan_bytes[i + j] != d[j] && d[j] != -1)
				{
					found = false;
					break;
				}
			}

			if (found)
			{
				const auto offset = *reinterpret_cast<int*>(&scan_bytes[i] + 3);
				return relative
					       ? reinterpret_cast<std::uintptr_t>(&scan_bytes[i]) + offset + 7
					       : reinterpret_cast<std::uintptr_t>(&scan_bytes[i]);
			}
		}

		return 0;
	}
}
