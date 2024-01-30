#pragma once

namespace ue
{
	template <class T>
	class TEnumAsByte
	{
	public:
		TEnumAsByte(): value_(0)
		{
		}

		explicit TEnumAsByte(T value) : value_(static_cast<uint8_t>(value))
		{
		}

		explicit TEnumAsByte(const int32_t value) : value_(static_cast<uint8_t>(value))
		{
		}

		explicit TEnumAsByte(const uint8_t value) : value_(value)
		{
		}

		explicit operator T() const
		{
			return static_cast<T>(value_);
		}

		T get_value() const
		{
			return static_cast<T>(value_);
		}

	private:
		uint8_t value_;
	};
}
