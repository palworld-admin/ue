#pragma once

namespace ue
{
	// Class CoreUObject.Property
	// Size: 0x70 (Inherited: 0x30)
	class UProperty : public UField
	{
	public:
		int32 array_dim;
		int32 element_size;
		uint64 property_flags;
		int8 pad_0001[0xC];
		int32 offset_internal;
		UProperty* property_link_next;
		UProperty* next_ref;
		UProperty* destructor_link_next;
		UProperty* post_construct_link_next;
	};
#ifndef WITH_CASE_PRESERVING_NAME
	static_assert(sizeof(UProperty) == 0x70);
#endif
}
