#pragma once

namespace ue {
    class FVector {
    public:
        float x, y, z;

        FVector operator+(const FVector& a) const {
            return {x + a.x, y + a.y, z + a.z};
        }

        void operator+=(const FVector& a) {
            x += a.x;
            y += a.y;
            z += a.z;
        }

        FVector operator-(const FVector& a) const {
            return {x - a.x, y - a.y, z - a.z};
        }

        void operator-=(const FVector& a) {
            x -= a.x;
            y -= a.y;
            z -= a.z;
        }

        FVector operator*(const FVector& a) const {
            return {x * a.x, y * a.y, z * a.z};
        }

        void operator*=(const FVector& a) {
            x *= a.x;
            y *= a.y;
            z *= a.z;
        }

        FVector operator/(const FVector& a) const {
            return {x / a.x, y / a.y, z / a.z};
        }

        void operator/=(const FVector& a) {
            x /= a.x;
            y /= a.y;
            z /= a.z;
        }

        FVector operator+(const float a) const {
            return {x + a, y + a, z + a};
        }

        void operator+=(const float a) {
            x += a;
            y += a;
            z += a;
        }

        FVector operator-(const float a) const {
            return {x - a, y - a, z - a};
        }

        void operator-=(const float a) {
            x -= a;
            y -= a;
            z -= a;
        }

        FVector operator*(const float a) const {
            return {x * a, y * a, z * a};
        }

        void operator*=(const float a) {
            x *= a;
            y *= a;
            z *= a;
        }

        FVector operator/(const float a) const {
            return {x / a, y / a, z / a};
        }

        void operator/=(const float a) {
            x /= a;
            y /= a;
            z /= a;
        }

        
        bool is_zero() const {
            if (x == 0.f && y == 0.f && z == 0) {
                return true;
            }

            return false;
        }
        
        FVector forward() const {
            float sp{}, sy{}, cp{}, cy{};
            float angle{};

            angle = y * static_cast<float>(M_PI / 180.0f);
            sy    = sinf(angle);
            cy    = cosf(angle);

            angle = -x * static_cast<float>(M_PI / 180.0f);
            sp    = sinf(angle);
            cp    = cosf(angle);

            return {cp * cy, cp * sy, -sp};
        }

        FVector right() const {
            const auto [x, y, z] = this->forward();
            return {-y, x, z};
        }
    };
}
