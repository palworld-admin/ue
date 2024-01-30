#pragma once
#include <xor.h>

namespace ue
{
	class UPackage;
	class UFunction;
	class UStruct;
	class UClass;

	// Class CoreUObject.Object
	// Size: 0x28 (Inherited: 0x00)
	class UObject
	{
	public:
		void** vf_table;      // 0x00(0x08)
		int32 flags;          // 0x08(0x04)
		int32 internal_index; // 0x0C(0x04)
		UClass* _class;       // 0x10(0x08)
		FName name;           // 0x18(0x08)
		UObject* outer;       // 0x20(0x08)

		bool is_default_object() const
		{
			return (flags & 0x10) == 0x10;
		}

		bool has_type_flag(EClassCastFlags type_flag) const;

		std::string get_name() const
		{
			return this->name.get_name();
		}

		std::string get_full_name() const;
		const char* get_full_name_ex() const;

		const char* get_name_ex() const
		{
			const auto name_temp = get_name();
			return name_temp.c_str();
		}

		/**
		 * \brief Find UObject
		 * \tparam T UObject
		 * \param name Full object name eg. `Font Roboto.Roboto`
		 * \param required_type Object Flag
		 * \return UObject*
		 */
		template <typename T = UObject>
		static T* find(const std::string& name, const EClassCastFlags required_type = EClassCastFlags::None)
		{
#ifdef USE_FU_OBJECT_ARRAY
            for (int i = 0; i < objects.get()->len(); ++i) {
                if (const auto object = objects.get()->get_by_index(i);
                    object->has_type_flag(required_type) && object->get_full_name() == name) {
                    return static_cast<T*>(object);
                }
            }
#else
			for (int i = 0; i < objects->len(); ++i)
			{
				if (const auto object = objects->get_by_index(i);
					object->has_type_flag(required_type) && object->get_full_name() == name)
				{
					return static_cast<T*>(object);
				}
			}

#endif

			return nullptr;
		}

		/**
		 * \brief Find UObject
		 * \tparam T UObject
		 * \param name Object name eg. `Roboto.Roboto`
		 * \param required_type Object Flag
		 * \return UObject*
		 */
		template <typename T = UObject>
		static T* find_fast(const std::string& name, const EClassCastFlags required_type = EClassCastFlags::None)
		{
#ifdef USE_FU_OBJECT_ARRAY
            for (int i = 0; i < objects.get()->len(); ++i) {
                if (const auto object = objects.get()->get_by_index(i);
                    object->has_type_flag(required_type) && object->get_name() == name) {
                    return static_cast<T*>(object);
                }
            }
#else
			for (int i = 0; i < objects->len(); ++i)
			{
				if (const auto object = objects->get_by_index(i);
					object->has_type_flag(required_type) && object->get_name() == name)
				{
					return static_cast<T*>(object);
				}
			}

#endif
			return nullptr;
		}

		/**
		 * \brief Find UE Class
		 * \param name Full Class Name eg. `Class Engine.ACharacter`
		 * \return UClass 
		 */
		static UClass* find_class(const std::string& name)
		{
			return find<UClass>(name);
		}

		/**
		 * \brief Find UE Class
		 * \param name Short Class Name eg. `ACharacter`
		 * \return UClass 
		 */
		static UClass* find_class_fast(const std::string& name)
		{
			return find_fast<UClass>(name, EClassCastFlags::Class);
		}

		/**
		 * \brief Compare Another UObject using UClass
		 * \param cmp void*
		 * \return bool
		 */
		bool is_a(const void* cmp) const;

#ifdef USE_FU_OBJECT_ARRAY
        template <typename T = UObject>
        static T* get_object_casted(const uint32_t index) {

            return static_cast<T*>(objects.get()->get_by_index(index));
        }
#endif

		/**
		 * \brief Get Object Static Class
		 * \return UClass 
		 */
		static UClass* static_class()
		{
			static auto ptr = find<UClass>(_("Class CoreUObject.Object"));
			return ptr;
		}


#ifdef USE_STATIC_FIND_OBJECT
		/**
		 * \brief Find UObjects using StaticFindObject
		 * \tparam T Objects
		 * \param name Object Name
		 * \param outer Optional `Class`, `Function`
		 * \return T
		 */
		template <typename T>
		static T static_find_object(const wchar_t* name, UObject* outer = nullptr)
		{
			return UObject::static_find_object_ex<T>(nullptr, outer, name);
		}

		/**
		* \brief Find UObjects using StaticFindObject
		* \tparam T Objects
		* \param klass UClass can be null
		* \param name Object Name
		* \param outer Optional
		* \return T
		*/
		template <typename T>
		static T static_find_object_ex(UObject* klass, UObject* outer, const wchar_t* name)
		{
			return reinterpret_cast<T(*)(UObject*, UObject*, const wchar_t*)>(
				offsets::static_find_object)(klass, outer, name);
		}
#endif
	};

#ifdef WITH_CASE_PRESERVING_NAME
    static_assert(sizeof(UObject) == 0x30);
#else
	static_assert(sizeof(UObject) == 0x28);
#endif
}
