#pragma once

namespace ue::engine {
    class APlayerState;

    // Class Engine.Pawn
    // Size: 0x318 (Inherited: 0x290)
    // Note: doesn't change
    class APawn : public AActor {
    public:
        int8 pad_0005[0x20];        // 0x290(0x20)
        APlayerState* player_state; // 0x2B0(0x08)
        int8 pad_0006[0x60];        // 0x2B8(0x60)
    };

    static_assert(sizeof(APawn) == 0x318);
}
