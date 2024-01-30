#pragma once

namespace ue::engine {
    // Class Engine.GameInstance
    // Size: 0x48 (Inherited: 0x28)
    // Note: Does not change
    class UGameInstance {
    public:
        char pad_0001[0x38];                 // 0x00(0x38)
        TArray<ULocalPlayer*> local_players; // 0x38(0x10)
    };

#ifdef WITH_CASE_PRESERVING_NAME
    static_assert(sizeof(UGameInstance) == 0x48 + 0x08);
#else
    static_assert(sizeof(UGameInstance) == 0x48);
#endif
}
