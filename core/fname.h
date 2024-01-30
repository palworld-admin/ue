#pragma once

namespace ue
{
	class FName
	{
	public:
		uint32 comparison_index;

#ifdef WITH_CASE_PRESERVING_NAME
        uint32 display_index;
#endif
		uint32 number;

		uint32 get_display_index() const
		{
#ifdef WITH_CASE_PRESERVING_NAME
            return display_index;
#else
			return comparison_index;
#endif
		}

		FName(): comparison_index(0),
		         number(0)
		{
		}

		explicit FName(const char* name_to_find): comparison_index(0),
		                                          number(0)
		{
			for (int i = 1000; i < names->ansi_count; i++)
			{
				const auto name = names->entry_allocator.get_by_id(i).get_ansi_name().c_str();
				if (!name)
					continue;
				if (strcmp(name, name_to_find) == 0)
				{
					comparison_index = i;
					return;
				}
			}
		}

		std::string get_name() const
		{
			const auto entry = names->entry_allocator.get(FNameEntryHandle(get_display_index()));

			auto name = entry->get_string();
			if (number > 0)
			{
				name += '_' + std::to_string(number);
			}

			if (const auto pos = name.rfind('/'); pos != std::string::npos)
			{
				name = name.substr(pos + 1);
			}

			return name;
		}

		bool operator==(const FName& other) const
		{
#ifdef WITH_CASE_PRESERVING_NAME
            return display_index == other.display_index;            
#else
			return comparison_index == other.comparison_index;
#endif
		}

		bool operator!=(const FName& other) const
		{
#ifdef WITH_CASE_PRESERVING_NAME
            return display_index != other.display_index;            
#else
			return comparison_index != other.comparison_index;
#endif
		}
	};

#ifdef WITH_CASE_PRESERVING_NAME
    static_assert(sizeof(FName) == 0x0C);
#else
	static_assert(sizeof(FName) == 0x08);
#endif
}
