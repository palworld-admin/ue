#pragma once

namespace ue::engine {
    class APlayerState;

    // Class Engine.GameStateBase
    // Size: 0x50 (Inherited: 0x290)
    // Note: This almost doesn't change
    class AGameStateBase : public AActor {
    public:
        int8 pad_0004[0x18];                // 0x290(0x18)
        TArray<APlayerState*> player_array; // 0x2A8(0x10)
    };

    // Class Engine.GameState
    // Size: 0x290 (Inherited: 0x270)
    class AGameState : public AGameStateBase {
    public:
        FName match_state;          // 0x270(0x08)
        FName previous_match_state; // 0x278(0x08)
        int32 elapsed_time;         // 0x280(0x04)
        int8 pad_0005[0xc];         // 0x284(0x0c)
    };
}
