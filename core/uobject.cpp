#include <ue/ue.h>

// template <typename T, typename... Args>
// T ue::UObject::call_function(const char* function_name, Args&&... args)
// {
// 	UObject* fn = nullptr;
// 	if (!fn)
// 		fn = find(function_name);
//
// 	struct
// 	{
// 		std::decay_t<Args> params;
// 		T return_value;
// 	} params{std::forward<Args>(args)...};
//
// 	process_event(this, fn, &params);
// 	return params.return_value;
// }

bool ue::UObject::has_type_flag(const EClassCastFlags type_flag) const
{
	return type_flag != EClassCastFlags::None ? _class->cast_flags & type_flag : true;
}

std::string ue::UObject::get_full_name() const
{
	std::string string;

	// prevent bad pointers
	if (IsBadReadPtr(this, sizeof(this)) ||
		IsBadReadPtr(this->_class, sizeof(this->_class)) ||
		IsBadReadPtr(this->outer, sizeof(this->outer)))
	{
		return "";
	}

	if (_class)
	{
		if (outer)
		{
			for (auto p = outer; p; p = p->outer)
				string  = p->get_name() + "." + string;
			string = _class->get_name() + " " + string + this->get_name();
		}
		else if (!outer)
		{
			string = _class->get_name() + " " + this->get_name();
		}
	}

	return string;
}

const char* ue::UObject::get_full_name_ex() const
{
	return get_full_name().c_str();
}

bool ue::UObject::is_a(const void* cmp) const
{
	for (auto super = _class; super;
	     super      = reinterpret_cast<UClass*>(super->super_struct))
	{
		if (super == cmp)
		{
			return true;
		}
	}

	return false;
}
