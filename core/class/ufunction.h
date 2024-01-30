#pragma once

namespace ue
{
	// Class CoreUObject.Function
	// Size: 0xe0 (Inherited: 0xb0)
	class UFunction : public UStruct
	{
	public:
		int32 function_flags;
		uint16 rep_offset;
		uint8 num_params;
		int8 pad_0003;
		uint16 params_size;
		uint16 return_value_offset;
		uint16 rpc_id;
		uint16 rpc_response_id;
		UProperty* first_property_to_init;
		UFunction* event_graph_function;
		int32 event_graph_call_offset;
		int8 pad_0004[0x4];
		void* func;
	};
#ifdef WITH_CASE_PRESERVING_NAME
    static_assert(sizeof(UFunction) == 0xe0 + 0x08);
#else
	static_assert(sizeof(UFunction) == 0xe0);
#endif
}
