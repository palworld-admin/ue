#pragma once

/**
 * \brief SDK UE Static Offsets
 */
namespace ue::offsets
{
	/**
	 * \brief Process Event Index
	 */
	inline int32 process_event_index;

	class UeAddress
	{
	public:
		static void set_module(uintptr_t address);
		static void set_gname(const char* signature);
		static void set_gworld(const char* signature);
		static void set_gobject(const char* signature);
		static void set_static_construct_object(const char* signature);
		static void set_process_event_index(int32 index);

		static uintptr_t get_module();
		static uintptr_t get_gname();
		static uintptr_t get_gworld();
		static uintptr_t get_gobject();
		static uintptr_t get_static_construct_object();
	};


#ifdef USE_STATIC_FIND_OBJECT
    inline uintptr_t static_find_object;
#endif
}
