#pragma once

namespace ue::engine {
    class UGameViewportClient;

    // Class Engine.Player
    // Size: 0x48 (Inherited: 0x28)
    // Note: Doesn't Change
    class UPlayer : public UObject {
    public:
        int8 pad_0001[0x8];                               // 0x28(0x08)
        controller::APlayerController* player_controller; // 0x30(0x08)
        int8 pad_0002[0x10];                              // 0x38(0x10)
    };

    static_assert(sizeof(UPlayer) == 0x48);

    // Class Engine.LocalPlayer
    // Size: 0x80 (Inherited: 0x48)
    // Note: Doesn't Change
    class ULocalPlayer : public UPlayer {
    public:
        int8 pad_48[0x30];                    // 0x48(0x30)
        UGameViewportClient* viewport_client; // 0x78(0x08)
    };

    static_assert(sizeof(ULocalPlayer) == 0x80);
}
