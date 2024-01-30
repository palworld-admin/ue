#pragma once

namespace ue {
    class FLinearColor {
    public:
        float r, g, b, a;

        FLinearColor() : r{0.f},
                         g{0.f},
                         b{0.f},
                         a{0.f} { }

        FLinearColor(const float r, const float g, const float b, const float a) : r{r},
            g{g},
            b{b},
            a{a} { }
    };
}
