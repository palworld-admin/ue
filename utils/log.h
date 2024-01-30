#pragma once
#include <chrono>
#include <print>
#include <time.h>

/**
 * \brief This namespace contains utility functions for logging
 * Some function are needed to refactored but I'm too lazy to do it
 */


#ifdef UE_ENABLE_LOG
#define LOG(str, ...) \
  ue::utils::log(str, ##__VA_ARGS__)

#define PRINT(str, ...) \
  ue::utils::print(str, ##__VA_ARGS__)
#else
#define LOG(str, ...)
#define PRINT(str, ...)
#endif

namespace ue::utils
{
	/**
	 * \brief Timestamp for logging
	 * https://gist.github.com/mokumus/bdd9d4fa837345f01b35e0cd03d67f35
	 * `asctime` is unsafe, but we don't care
	 * _CRT_SECURE_NO_WARNINGS is enabled
	 * \return timestamp in string format
	 */
	inline char* timestamp()
	{
		const time_t now       = time(nullptr);
		char* time             = asctime(gmtime(&now));
		time[strlen(time) - 1] = '\0';
		return time;
	}

	/**
	 * \brief Log to console
	 * \param fmt
	 * \param ... 
	 */
	static void log(const char* fmt, ...)
	{
		va_list args;
		va_start(args, fmt);
		std::print("{} [LOG]: ", timestamp());
		vprintf(fmt, args);
		std::println("");
		va_end(args);
	}

	static void log(const wchar_t* fmt, ...)
	{
		va_list args;
		va_start(args, fmt);
		std::print("{} [LOG]: ", timestamp());
		vwprintf(fmt, args);
		std::println("");
		va_end(args);
	}


	static void print(const char* fmt, ...)
	{
		va_list args;
		va_start(args, fmt);
		vprintf(fmt, args);
		va_end(args);
	}

	static void print(const wchar_t* fmt, ...)
	{
		va_list args;
		va_start(args, fmt);
		vwprintf(fmt, args);
		va_end(args);
	}

	static void print(const std::string& fmt)
	{
		std::printf(fmt.c_str());
	}

	static void print(const std::wstring& fmt)
	{
		std::wprintf(fmt.c_str());
	}
}
