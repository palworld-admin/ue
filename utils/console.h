#pragma once
#include <corecrt_wstdio.h>
#include <lazy_importer.h>
#include <cstdio>
#include <Windows.h>

namespace ue::utils
{
	inline bool enable_console()
	{
		const bool console = LI_FN(AllocConsole)();

		freopen_s(reinterpret_cast<_iobuf**>(__acrt_iob_func(0)), "conin$", "r", __acrt_iob_func(0));
		freopen_s(reinterpret_cast<_iobuf**>(__acrt_iob_func(1)), "conout$", "w", __acrt_iob_func(1));
		freopen_s(reinterpret_cast<_iobuf**>(__acrt_iob_func(2)), "conout$", "w", __acrt_iob_func(2));

		return console;
	}

	inline bool disable_console()
	{
		fclose(__acrt_iob_func(0));
		fclose(__acrt_iob_func(1));
		fclose(__acrt_iob_func(2));

		return LI_FN(FreeConsole)();
	}
}
