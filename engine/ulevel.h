#pragma once

namespace ue::engine {
    // Class Engine.Level
    // Size: 0x2F0 (Inherited: 0x28)
    class ULevel : public UObject {
    public:
        uint8 pad_0001[0xb0];   // 0x28(0xb0)
        TArray<AActor*> actors; // 0xD8(0x10)
    };
    static_assert(sizeof(ULevel) == 0xe8);
}
