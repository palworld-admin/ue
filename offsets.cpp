#include <ue/ue.h>

void ue::offsets::UeAddress::set_module(const uintptr_t address)
{
	memory::module = address;
}

void ue::offsets::UeAddress::set_gname(const char* signature)
{
	names = reinterpret_cast<decltype(names)>(utils::pattern_scan(memory::module, signature, true));
}

void ue::offsets::UeAddress::set_gworld(const char* signature)
{
	world_proxy = reinterpret_cast<decltype(world_proxy)>(ue::utils::pattern_scan(
		memory::module, signature, true));
}

void ue::offsets::UeAddress::set_gobject(const char* signature)
{
	objects = reinterpret_cast<decltype(objects)>(utils::pattern_scan(memory::module, signature, true));
}

void ue::offsets::UeAddress::set_static_construct_object(const char* signature)
{
	engine::static_construct_object_internal = utils::pattern_scan(memory::module, signature);
}

void ue::offsets::UeAddress::set_process_event_index(const int32 index)
{
	process_event_index = index;
}

uintptr_t ue::offsets::UeAddress::get_module()
{
	return memory::module;
}

uintptr_t ue::offsets::UeAddress::get_gname()
{
	return reinterpret_cast<uintptr_t>(names);
}

uintptr_t ue::offsets::UeAddress::get_gworld()
{
	return reinterpret_cast<uintptr_t>(world_proxy);
}

uintptr_t ue::offsets::UeAddress::get_gobject()
{
	return reinterpret_cast<uintptr_t>(objects);
}

uintptr_t ue::offsets::UeAddress::get_static_construct_object()
{
	return engine::static_construct_object_internal;
}
