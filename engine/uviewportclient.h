#pragma once

namespace ue::engine {
	class UWorld;

	// Class Engine.GameViewportClient
    // Size: 0x88 (Inherited: 0x38)
    // Note: This does not change
    class UGameViewportClient : public UObject {
    public:
        char pad_0000[0x10];          // 0x28(0x10)
        char pad_0001[0x8];           // 0x38(0x8)
    	UConsole* viewport_console;   // 0x40(0x8)
        char pad_0002[0x30];          // 0x48(0x30)
        UWorld* world;                // 0x78(0x08)
        UGameInstance* game_instance; // 0x80(0x08)
    };

    static_assert(sizeof(UGameViewportClient) == 0x88);
}
