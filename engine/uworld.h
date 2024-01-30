#pragma once

namespace ue::engine {
	// Class Engine.World
    // Size: 0x870 (Inherited: 0x28)
    class UWorld : public UObject {
    public:
        int8 pad_0001[0x08];                 // 0x28(0x08)
        ULevel* persistent_level;            // 0x30(0x08)
        int8 pad_0002[0x120];                // 0x38(0x120)
        AGameState* game_state;              // 0x158(0x08)
        int8 pad_0003[0x10];                 // 0x160(0x10)
        TArray<ULevel*> levels;              // 0x170(0x10)
        int8 pad_0004[0x38];                 // 0x180(0x38)
        UGameInstance* owning_game_instance; // 0x1B8(0x08)
        int8 pad_0005[0x6b0];                // 0x1C0(0x6b0)
    };

    static_assert(sizeof(UWorld) == 0x870);

    /**
     * \brief Proxy class that allows verification on GWorld accesses.\n
     * Possible signatures:\n
     * 48 8B 1D ?? ?? ?? ?? 48 85 DB 74 3B 41 B0 01\n
     * Reference:\n
     * https://github.com/EpicGames/UnrealEngine/blob/release/Engine/Source/Runtime/Engine/Classes/Engine/World.h
     */
    class UWorldProxy {
    public:
        UWorld* world; // 0x0(0x08)
    };
}

namespace ue {
    inline engine::UWorldProxy* world_proxy;
}
