#pragma once

namespace ue
{
	class FGuid
	{
	public:
		uint32 A;
		uint32 B;
		uint32 C;
		uint32 D;

		friend bool operator==(const FGuid& x, const FGuid& y)
		{
			return ((x.A ^ y.A) | (x.B ^ y.B) | (x.C ^ y.C) | (x.D ^ y.D)) == 0;
		}

		bool IsValid() const
		{
			return ((A | B | C | D) != 0);
		}

		std::wstring get_wide_string() const
		{
			return std::format(
				L"{:08X}-{:04X}-{:04X}-{:04X}-{:04X}{:08X}",
				A, B >> 16, B & 0xFFFF, C >> 16, C & 0xFFFF, D
			);
		}

		std::string to_string() const
		{
			return std::format(
				"{:08X}-{:04X}-{:04X}-{:04X}-{:04X}{:08X}",
				A, B >> 16, B & 0xFFFF, C >> 16, C & 0xFFFF, D
			);
		}
	};
}
