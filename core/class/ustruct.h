#pragma once

namespace ue
{
	class FField;

	// Class CoreUObject.Struct
	// Size: 0xb0 (Inherited: 0x30)
	class UStruct : public UField
	{
	public:
		int8 pad_0001[0x10];   // 0x30(0x10)
		UStruct* super_struct; // 0x40(0x08)
		UStruct* children;     // 0x48(0x08)
		char pad_0002[0x60];   // 0x50(0x60)
	};

#ifdef WITH_CASE_PRESERVING_NAME
    static_assert(sizeof(UStruct) == 0xb0 + 0x08);
#else
	static_assert(sizeof(UStruct) == 0xb0);
#endif
}
