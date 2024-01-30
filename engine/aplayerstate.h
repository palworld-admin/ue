#pragma once

namespace ue::engine {
    class APawn;

    // Class Engine.PlayerState
    // Size: 0x3A8 (Inherited: 0x290)
    // Note: Pads doesn't change
    class APlayerState : public AActor {
    public:
        int8 pad_0004[0x78];         // 0x290(0x78)
        APawn* pawn_private;         // 0x308(0x08)
        int8 pad_0005[0x78];         // 0x310(0x78)
        FString player_name_private; // 0x388(0x10)
        int8 pad_0006[0x10];         // 0x398(0x10)
    };

    //static_assert(sizeof(APlayerState) == 0x3A8);
}
