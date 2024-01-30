#pragma once


namespace ue
{
	template <typename ValueType, typename KeyType>
	class TPair
	{
	public:
		ValueType First;
		KeyType Second;
	};


	template <typename KeyType, typename ValueType>
	class TMap
	{
		uint8 WaitTillIImplementIt[0x50];
	};

	class FWeakObjectPtr
	{
	protected:
		int32 ObjectIndex;
		int32 ObjectSerialNumber;

	public:
		UObject* Get() const;
		UObject* operator->() const;

		bool operator==(const FWeakObjectPtr& Other) const;
		bool operator!=(const FWeakObjectPtr& Other) const;

		bool operator==(const UObject* Other) const;
		bool operator!=(const UObject* Other) const;
	};

	template <typename ElementType>
	class TSet
	{
		uint8 WaitTillIImplementIt[0x50];
	};

	template <typename ClassType>
	class TSubclassOf
	{
		class UClass* ClassPtr;

	public:
		TSubclassOf() = default;

		TSubclassOf(UClass* Class)
			: ClassPtr(Class)
		{
		}

		UClass* Get()
		{
			return ClassPtr;
		}

		operator UClass*() const
		{
			return ClassPtr;
		}

		template <typename Target, typename = std::enable_if<std::is_base_of_v<Target, ClassType>, bool>::type>
		operator TSubclassOf<Target>() const
		{
			return ClassPtr;
		}

		UClass* operator->()
		{
			return ClassPtr;
		}

		TSubclassOf& operator=(UClass* Class)
		{
			ClassPtr = Class;

			return *this;
		}

		bool operator==(const TSubclassOf& Other) const
		{
			return ClassPtr == Other.ClassPtr;
		}

		bool operator!=(const TSubclassOf& Other) const
		{
			return ClassPtr != Other.ClassPtr;
		}

		bool operator==(UClass* Other) const
		{
			return ClassPtr == Other;
		}

		bool operator!=(UClass* Other) const
		{
			return ClassPtr != Other;
		}
	};
}
