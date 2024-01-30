#pragma once

namespace ue::controller {
    // Class Engine.Controller
    // Size: 0x328 (Inherited: 0x290)
    class AController : public engine::AActor {
    public:
        int8 pad_0005[0x8];                 // 0x290(0x08)
        engine::APlayerState* player_state; // 0x298(0x08)
        int8 pad_0006[0x88];                // 0x2a0(0x88)

        void set_control_rotation(const FRotator& new_rotation);

        bool line_of_sight_to(AActor* other, FVector view_point, bool alternate_checks);
    };

	static_assert(sizeof(AController) == 0x328);
}
