#pragma once

namespace ue
{
	enum class EClassCastFlags : uint64
	{
		None = 0x0000000000000000,
		Field = 0x0000000000000001,
		Int8Property = 0x0000000000000002,
		Enum = 0x0000000000000004,
		Struct = 0x0000000000000008,
		ScriptStruct = 0x0000000000000010,
		Class = 0x0000000000000020,
		ByteProperty = 0x0000000000000040,
		IntProperty = 0x0000000000000080,
		FloatProperty = 0x0000000000000100,
		UInt64Property = 0x0000000000000200,
		ClassProperty = 0x0000000000000400,
		UInt32Property = 0x0000000000000800,
		InterfaceProperty = 0x0000000000001000,
		NameProperty = 0x0000000000002000,
		StrProperty = 0x0000000000004000,
		Property = 0x0000000000008000,
		ObjectProperty = 0x0000000000010000,
		BoolProperty = 0x0000000000020000,
		UInt16Property = 0x0000000000040000,
		Function = 0x0000000000080000,
		StructProperty = 0x0000000000100000,
		ArrayProperty = 0x0000000000200000,
		Int64Property = 0x0000000000400000,
		DelegateProperty = 0x0000000000800000,
		NumericProperty = 0x0000000001000000,
		MulticastDelegateProperty = 0x0000000002000000,
		ObjectPropertyBase = 0x0000000004000000,
		WeakObjectProperty = 0x0000000008000000,
		LazyObjectProperty = 0x0000000010000000,
		SoftObjectProperty = 0x0000000020000000,
		TextProperty = 0x0000000040000000,
		Int16Property = 0x0000000080000000,
		DoubleProperty = 0x0000000100000000,
		SoftClassProperty = 0x0000000200000000,
		Package = 0x0000000400000000,
		Level = 0x0000000800000000,
		Actor = 0x0000001000000000,
		PlayerController = 0x0000002000000000,
		Pawn = 0x0000004000000000,
		SceneComponent = 0x0000008000000000,
		PrimitiveComponent = 0x0000010000000000,
		SkinnedMeshComponent = 0x0000020000000000,
		SkeletalMeshComponent = 0x0000040000000000,
		Blueprint = 0x0000080000000000,
		DelegateFunction = 0x0000100000000000,
		StaticMeshComponent = 0x0000200000000000,
		MapProperty = 0x0000400000000000,
		SetProperty = 0x0000800000000000,
		EnumProperty = 0x0001000000000000,
	};

	constexpr EClassCastFlags operator|(EClassCastFlags left, EClassCastFlags right)
	{
		using cast_flags_type = std::underlying_type_t<EClassCastFlags>;
		return static_cast<EClassCastFlags>(static_cast<cast_flags_type>(left) | static_cast<cast_flags_type>(right));
	}

	inline bool operator&(EClassCastFlags left, EClassCastFlags right)
	{
		using cast_flags_type = std::underlying_type_t<EClassCastFlags>;
		return (static_cast<cast_flags_type>(left) & static_cast<cast_flags_type>(right)) == static_cast<
			cast_flags_type>(
			right);
	}

	enum EObjectFlags : uint64
	{
		RF_NoFlags = 0x00000000,
		RF_Public = 0x00000001,
		RF_Standalone = 0x00000002,
		RF_MarkAsNative = 0x00000004,
		RF_Transactional = 0x00000008,
		RF_ClassDefaultObject = 0x00000010,
		RF_ArchetypeObject = 0x00000020,
		RF_Transient = 0x00000040,
		RF_MarkAsRootSet = 0x00000080,
		RF_TagGarbageTemp = 0x00000100,
		RF_NeedInitialization = 0x00000200,
		RF_NeedLoad = 0x00000400,
		RF_KeepForCooker = 0x00000800,
		RF_NeedPostLoad = 0x00001000,
		RF_NeedPostLoadSubobjects = 0x00002000,
		RF_NewerVersionExists = 0x00004000,
		RF_BeginDestroyed = 0x00008000,
		RF_FinishDestroyed = 0x00010000,
		RF_BeingRegenerated = 0x00020000,
		RF_DefaultSubObject = 0x00040000,
		RF_WasLoaded = 0x00080000,
		RF_TextExportTransient = 0x00100000,
		RF_LoadCompleted = 0x00200000,
		RF_InheritableComponentTemplate = 0x00400000,
		RF_DuplicateTransient = 0x00800000,
		RF_StrongRefOnFrame = 0x01000000,
		RF_NonPIEDuplicateTransient = 0x02000000,
		RF_WillBeLoaded = 0x08000000,
		RF_HasExternalPackage = 0x10000000,
		RF_AllocatedInSharedPage = 0x80000000,
	};

	enum class EInternalObjectFlags : int32_t
	{
		None = 0,
		Native = 1 << 25,
		Async = 1 << 26,
		AsyncLoading = 1 << 27,
		Unreachable = 1 << 28,
		PendingKill = 1 << 29,
		RootSet = 1 << 30,
		NoStrongReference = 1 << 31
	};

	enum EClassFlags : uint64
	{
		CLASS_None = 0x00000000u,
		Abstract = 0x00000001u,
		DefaultConfig = 0x00000002u,
		Config = 0x00000004u,
		Transient = 0x00000008u,
		Parsed = 0x00000010u,
		MatchedSerializers = 0x00000020u,
		ProjectUserConfig = 0x00000040u,
		Native = 0x00000080u,
		NoExport = 0x00000100u,
		NotPlaceable = 0x00000200u,
		PerObjectConfig = 0x00000400u,
		ReplicationDataIsSetUp = 0x00000800u,
		EditInlineNew = 0x00001000u,
		CollapseCategories = 0x00002000u,
		Interface = 0x00004000u,
		CustomConstructor = 0x00008000u,
		Const = 0x00010000u,
		LayoutChanging = 0x00020000u,
		CompiledFromBlueprint = 0x00040000u,
		MinimalAPI = 0x00080000u,
		RequiredAPI = 0x00100000u,
		DefaultToInstanced = 0x00200000u,
		TokenStreamAssembled = 0x00400000u,
		HasInstancedReference = 0x00800000u,
		Hidden = 0x01000000u,
		Deprecated = 0x02000000u,
		HideDropDown = 0x04000000u,
		GlobalUserConfig = 0x08000000u,
		Intrinsic = 0x10000000u,
		Constructed = 0x20000000u,
		ConfigDoNotCheckDefaults = 0x40000000u,
		NewerVersionExists = 0x80000000u,
	};

	constexpr EClassFlags operator|(const EClassFlags left, const EClassFlags right)
	{
		using class_flags_type = std::underlying_type_t<EClassFlags>;
		return static_cast<EClassFlags>(static_cast<class_flags_type>(left) | static_cast<class_flags_type>(right));
	}

	inline bool operator&(const EClassFlags left, const EClassFlags right)
	{
		using class_flags_type = std::underlying_type_t<EClassFlags>;
		return ((static_cast<class_flags_type>(left) & static_cast<class_flags_type>(right)) == static_cast<
			class_flags_type>(
			right));
	}
}
