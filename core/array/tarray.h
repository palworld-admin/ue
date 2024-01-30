#pragma once

namespace ue
{
	template <class T>
	class TArray
	{
		friend class FString;

	public:
		T& operator[](int32 i)
		{
			return data[i];
		}

		int len() const
		{
			return count_;
		}

		int size() const
		{
			return max_;
		}

		bool is_valid(int i)
		{
			return static_cast<bool>(i < this->count_);
		}

	private:
		T* data;
		int32 count_;
		int32 max_;
	};
}
