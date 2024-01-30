#pragma once

namespace ue
{
	class FString : TArray<wchar_t>
	{
	public:
		FString() = default;

		explicit FString(const wchar_t* other)
		{
			max_ = count_ = *other ? static_cast<int32_t>(wcslen(other)) + 1 : 0;

			if (count_)
			{
				data = const_cast<wchar_t*>(other);
			}
		}

		explicit FString(const char* c)
		{
			const size_t c_size = strlen(c);
			std::wstring wc(c_size, L'#');
			size_t out_size;
			if (!mbstowcs_s(&out_size, wc.data(), c_size, c, c_size - 1))
			{
				return;
			}
			data = const_cast<wchar_t*>(wc.c_str());
		}

		FString(const wchar_t* other, const int size)
		{
			data = const_cast<wchar_t*>(other);
			max_ = count_ = size;
		}

		bool is_valid() const
		{
			return data != nullptr;
		}

		std::wstring get_wide_string() const
		{
			return std::wstring(this->data);
		}

		const wchar_t* c_str() const
		{
			return data;
		}

		std::string to_string() const
		{
			const auto length = std::wcslen(data);
			std::string str(length, '\0');
			std::use_facet<std::ctype<wchar_t>>(
					std::locale())
				.narrow(data, data + length, '?', str.data());

			return str;
		}

		static const wchar_t* convert(const char* c)
		{
			const size_t c_size = strlen(c);
			std::wstring wc(c_size, L'#');
			size_t out_size;
			if (!mbstowcs_s(&out_size, wc.data(), c_size, c, c_size - 1))
			{
				return L"";
			}

			return wc.c_str();
		}
	};
}
