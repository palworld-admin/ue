#pragma once

namespace ue {
    class FRotator {
    public:
        float x, y, z;

        FRotator operator+(const FRotator& a) const {
            return {x + a.x, y + a.y, z + a.z};
        }

        void operator+=(const FRotator& a) {
            x += a.x;
            y += a.y;
            z += a.z;
        }

        FRotator operator-(const FRotator& a) const {
            return {x - a.x, y - a.y, z - a.z};
        }

        void operator-=(const FRotator& a) {
            x -= a.x;
            y -= a.y;
            z -= a.z;
        }

        FRotator operator*(const FRotator& a) const {
            return {x * a.x, y * a.y, z * a.z};
        }

        void operator*=(const FRotator& a) {
            x *= a.x;
            y *= a.y;
            z *= a.z;
        }

        FRotator operator/(const FRotator& a) const {
            return {x / a.x, y / a.y, z / a.z};
        }

        void operator/=(const FRotator& a) {
            x /= a.x;
            y /= a.y;
            z /= a.z;
        }

        FRotator operator+(const float a) const {
            return {x + a, y + a, z + a};
        }

        void operator+=(const float a) {
            x += a;
            y += a;
            z += a;
        }

        FRotator operator-(const float a) const {
            return {x - a, y - a, z - a};
        }

        void operator-=(const float a) {
            x -= a;
            y -= a;
            z -= a;
        }

        FRotator operator*(const float a) const {
            return {x * a, y * a, z * a};
        }

        void operator*=(const float a) {
            x *= a;
            y *= a;
            z *= a;
        }

        FRotator operator/(const float a) const {
            return {x / a, y / a, z / a};
        }

        void operator/=(const float a) {
            x /= a;
            y /= a;
            z /= a;
        }
    };
}
