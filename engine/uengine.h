#pragma once

namespace ue {
    // Class Engine.Engine
    // Size: 0xd20 (Inherited: 0x28)
    class UEngine : public UObject {
    public:
        inline static UEngine* engine = nullptr;

        int8 pad_0001[0xe8];                        // 0x28(0xe8)
        engine::UGameViewportClient* game_viewport; // 0x110(0x08)
        int8 pad_0002[0xc08];                       // 0x118(0x670)

        static UClass* static_class() {
            static UClass* _class = nullptr;
            if (!_class)
                _class = find_class("Class Engine.Engine");
            return _class;
        }

        static UEngine* get_engine() {
            if (!engine)
                for (int i = 0; i < objects->len(); i++) {
                    if (UObject* obj = objects->get_by_index(i); obj && obj->is_a(static_class())
                                                                 && !obj->is_default_object()) {
                        engine = reinterpret_cast<UEngine*>(obj);
                        break;
                    }
                }

            return engine;
        }
    };

    static_assert(sizeof(UEngine) == 0xd20);
}
