#pragma once

namespace ue
{
	inline void process_event(void* object, void* u_function, void* params)
	{
		const auto vtable = *static_cast<void***>(object);
		reinterpret_cast<void(*)(void*, void*, void*)>(vtable[offsets::process_event_index])
			(object, u_function, params);
	};
}
