#pragma once

namespace ue
{
	template <typename T>
	T get_vfunction(const void* instance, const int32 index)
	{
		auto vtable = *static_cast<const void***>(const_cast<void*>(instance));
		return reinterpret_cast<T>(vtable[index]);
	}
}
