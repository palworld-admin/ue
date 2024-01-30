#pragma once

namespace ue
{
	class UFunction;

	// Class CoreUObject.Class
	// Size: 0x3c0 (Inherited: 0xb0)
	class UClass : public UStruct
	{
	public:
		EClassCastFlags cast_flags; // 0xb0(0x08) 
		UObject* default_object;    // 0xb4((0x04)
		int8 pad_0002[0x300];       // 0xb8(0x310)
	};
#ifdef WITH_CASE_PRESERVING_NAME
    static_assert(sizeof(UClass) == 0x3c0 + 0x08);
#else
	static_assert(sizeof(UClass) == 0x3c0);
#endif
}
