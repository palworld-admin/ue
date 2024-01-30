#pragma once
#define NUM_TFUNCTION_INLINE_BYTES 32
#define TFUNCTION_INLINE_SIZE         NUM_TFUNCTION_INLINE_BYTES
#define TFUNCTION_INLINE_ALIGNMENT    16

namespace ue
{
	class UPackage;
	class UClass;
	class FName;
}

// https://github.com/Re-UE4SS/UEPseudo/blob/53418fdd718016c0e5000c90a846c5a33a331450/include/Unreal/UObjectGlobals.hpp#L56
// https://github.com/Re-UE4SS/UEPseudo/blob/53418fdd718016c0e5000c90a846c5a33a331450/include/Unreal/Function.hpp#L20
namespace ue::engine
{
	/**
	* Used to declare an untyped array of data with compile-time alignment.
	* It needs to use template specialization as the MS_ALIGN and GCC_ALIGN macros require literal parameters.
	*/
	template <int32 Size, uint32 Alignment>
	struct TAlignedBytes
	{
		alignas(Alignment) uint8 Pad[Size];
	};

	/** An untyped array of data with compile-time alignment and size derived from another type. */
	template <typename ElementType>
	struct TTypeCompatibleBytes
	{
		using ElementTypeAlias_NatVisHelper = ElementType;
		ElementType* GetTypedPtr() { return (ElementType*)this; }
		const ElementType* GetTypedPtr() const { return (const ElementType*)this; }

		alignas(ElementType) uint8 Pad[sizeof(ElementType)];
	};

	struct FFunctionStorage
	{
		void* HeapAllocation;
		TAlignedBytes<TFUNCTION_INLINE_SIZE, TFUNCTION_INLINE_ALIGNMENT> InlineAllocation;
	};

	// A temporary placeholder implementation that assumes:
	// TFunction == class TFunction final : public UE::Core::Private::Function::TFunctionRefBase<UE::Core::Private::Function::TFunctionStorage<false>, FuncType>
	template <typename T>
	class TFunction
	{
	private:
		void* TempFuncPtr{};
		FFunctionStorage TempStorage{};

	public:
		TFunction() = default;
	};

	struct FStaticConstructObjectParameters
	{
		/** The class of the object to create */
		const UClass* Class;

		/** The object to create this object within (the Outer property for the new object will be set to the value specified here). */
		UObject* Outer;

		/** The name to give the new object.If no value(NAME_None) is specified, the object will be given a unique name in the form of ClassName_#. */
		FName Name;

		/** The ObjectFlags to assign to the new object. some flags can affect the behavior of constructing the object. */
		EObjectFlags SetFlags = RF_NoFlags;

		/** The InternalObjectFlags to assign to the new object. some flags can affect the behavior of constructing the object. */
		EInternalObjectFlags InternalSetFlags = EInternalObjectFlags::None;

		/** If true, copy transient from the class defaults instead of the pass in archetype ptr(often these are the same) */
		bool bCopyTransientsFromClassDefaults = false;

		/** If true, Template is guaranteed to be an archetype */
		bool bAssumeTemplateIsArchetype = false;

		/**
		 * If specified, the property values from this object will be copied to the new object, and the new object's ObjectArchetype value will be set to this object.
		 * If nullptr, the class default object is used instead.
		 */
		UObject* Template = nullptr;

		/** Contains the mappings of instanced objects and components to their templates */
		struct FObjectInstancingGraph* InstanceGraph = nullptr;

		/** Assign an external Package to the created object if non-null */
		UPackage* ExternalPackage = nullptr;

		// Accessing parameters below here is disallowed because we don't support these parameters
	private:
		// 5.00+
		/** Callback for custom code to initialize properties before PostInitProperties runs */
		TFunction<void()> PropertyInitCallback{};

		// 5.00+
		void* SubobjectOverrides = nullptr;

	public:
		FStaticConstructObjectParameters(const class UClass* InClass, UObject* InOuter) : Class(InClass), Outer(InOuter)
		{
		}
	};

	inline uintptr_t static_construct_object_internal;
}
