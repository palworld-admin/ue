#pragma once

namespace ue
{
	class FTextData
	{
	public:
		uint8 Pad[0x28];
		wchar_t* Name;
		size_t Length;
	};

	class FText
	{
	public:
		FTextData* Data;
		uint8 Pad[0x10];


		FText(const wchar_t* text)
		{
			FTextData data;
			data.Name   = const_cast<wchar_t*>(text);
			data.Length = wcslen(text);
		}

		FText(const char* text)
		{
			FTextData data;
			data.Name = const_cast<wchar_t*>
				(std::wstring(text, text + strlen(text)).c_str());
			data.Length = strlen(text);
		}

		wchar_t* Get() const
		{
			if (Data)
				return Data->Name;

			return nullptr;
		}
	};
}
