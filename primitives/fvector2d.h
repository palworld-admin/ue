#pragma once

namespace ue {
    class FVector2D {
    public:
        float x, y;

        FVector2D operator+(const FVector2D& a) const {
            return {x + a.x, y + a.y};
        }

        void operator+=(const FVector2D& a) {
            x += a.x;
            y += a.y;
        }

        FVector2D operator-(const FVector2D& a) const {
            return {x - a.x, y - a.y};
        }

        void operator-=(const FVector2D& a) {
            x -= a.x;
            y -= a.y;
        }

        FVector2D operator*(const FVector2D& a) const {
            return {x * a.x, y * a.y};
        }

        void operator*=(const FVector2D& a) {
            x *= a.x;
            y *= a.y;
        }

        FVector2D operator/(const FVector2D& a) const {
            return {x / a.x, y / a.y};
        }

        void operator/=(const FVector2D& a) {
            x /= a.x;
            y /= a.y;
        }

        FVector2D operator+(const float a) const {
            return {x + a, y + a};
        }

        void operator+=(const float a) {
            x += a;
            y += a;
        }

        FVector2D operator-(const float a) const {
            return {x - a, y - a};
        }

        void operator-=(const float a) {
            x -= a;
            y -= a;
        }

        FVector2D operator*(const float a) const {
            return {x * a, y * a};
        }

        void operator*=(const float a) {
            x *= a;
            y *= a;
        }

        FVector2D operator/(const float a) const {
            return {x / a, y / a};
        }

        void operator/=(const float a) {
            x /= a;
            y /= a;
        }

        bool is_zero() const {
            if (x == 0.f && y == 0.f) {
                return true;
            }

            return false;
        }
    };
}
