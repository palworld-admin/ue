#pragma once

namespace ue {
    class FFieldClass {
    public:
        FName name;               // (0x00[0x08]) NOT AUTO-GENERATED PROPERTY
        uint64 id;                // (0x08[0x08]) NOT AUTO-GENERATED PROPERTY
        uint64 cast_flags;        // (0x10[0x08]) NOT AUTO-GENERATED PROPERTY
        EClassFlags class_flags;  // (0x18[0x04]) NOT AUTO-GENERATED PROPERTY
        uint8 pad_43_b2[0x4];     // Fixing Size After Last (Predefined) Property  [ Dumper-7 ]
        FFieldClass* super_class; // (0x20[0x08]) NOT AUTO-GENERATED PROPERTY
    };

    class FFieldVariant {
    public:
        union {
            class FField* field;
            UObject* object;
        } container; // (0x00[0x08]) NOT AUTO-GENERATED PROPERTY
    };

    class FField {
    public:
        void* vft;           // (0x00[0x08]) NOT AUTO-GENERATED PROPERTY
        FFieldClass* _class; // (0x08[0x08]) NOT AUTO-GENERATED PROPERTY
        FFieldVariant owner; // (0x10[0x10]) NOT AUTO-GENERATED PROPERTY
        FField* next;        // (0x20[0x08]) NOT AUTO-GENERATED PROPERTY
        FName name;          // (0x28[0x08]) NOT AUTO-GENERATED PROPERTY
        int32 flags;         // (0x30[0x04]) NOT AUTO-GENERATED PROPERTY
    };

    // Class CoreUObject.Field
    // Size: 0x30 (Inherited: 0x28)
    class UField : public UObject {
    public:
        UField* next;
    };

#ifdef WITH_CASE_PRESERVING_NAME
    static_assert(sizeof(UField) == 0x30 + 0x08);
#else
    static_assert(sizeof(UField) == 0x30);
#endif
}
