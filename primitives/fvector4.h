#pragma once

namespace ue {
    class FVector4 {
    public:
        float x, y, z, w;

        float length() const {
            return sqrtf(x * x + y * y + z * z + w * w);
        }

        static float length(const FVector4& a) {
            return sqrtf(a.x * a.x + a.y * a.y + a.z * a.z + a.w * a.w);
        }

        float dot(const FVector4& b) const {
            return x * b.x + y * b.y + z * b.z + w * b.w;
        }

        static float Dot(const FVector4& a, const FVector4& b) {
            return a.x * b.x + a.y * b.y + a.z * b.z + a.w * b.w;
        }

        float Distance(const FVector4& b) const {
            return sqrtf((x - b.x) * (x - b.x) + (y - b.y) * (y - b.y) + (z - b.z) * (z - b.z) + (w - b.w) * (w - b.w));
        }

        static float distance(const FVector4& a, const FVector4& b) {
            return sqrtf((a.x - b.x) * (a.x - b.x) + (a.y - b.y) * (a.y - b.y) + (a.z - b.z) * (a.z - b.z) + (a.w - b.w)
                         * (a.w - b.w));
        }

        FVector4 get_pitch_to(const FVector4& b) const {
            return {1.f, (b.y - y) / (b.x - x), (b.z - z) / (b.x - x), (b.w - w) / (b.x - x)};
        }

        static FVector4 get_pitch_to(const FVector4& a, const FVector4& b) {
            return {1.f, (b.y - a.y) / (b.x - a.x), (b.z - a.z) / (b.x - a.x), (b.w - a.w) / (b.x - a.x)};
        }

        FVector4 operator+(const FVector4& a) const {
            return {x + a.x, y + a.y, z + a.z, w + a.w};
        }

        void operator+=(const FVector4& a) {
            x += a.x;
            y += a.y;
            z += a.z, w += a.w;
        }

        FVector4 operator-(const FVector4& a) const {
            return {x - a.x, y - a.y, z - a.z, w - a.w};
        }

        void operator-=(const FVector4& a) {
            x -= a.x, y -= a.y, z -= a.z, w -= a.w;
        }

        FVector4 operator*(const FVector4& a) const {
            return {x * a.x, y * a.y, z * a.z, w * a.w};
        }

        void operator*=(const FVector4& a) {
            x *= a.x, y *= a.y, z *= a.z, w *= a.w;
        }

        FVector4 operator/(const FVector4& a) const {
            return {x / a.x, y / a.y, z / a.z, w / a.w};
        }

        void operator/=(const FVector4& a) {
            x /= a.x, y /= a.y, z /= a.z, w /= a.w;
        }

        FVector4 operator+(const float a) const {
            return {x + a, y + a, z + a, w + a};
        }

        void operator+=(const float a) {
            x += a, y += a, z += a, w += a;
        }

        FVector4 operator-(const float a) const {
            return {x - a, y - a, z - a, w - a};
        }

        void operator-=(const float a) {
            x -= a, y -= a, z -= a, w -= a;
        }

        FVector4 operator*(const float a) const {
            return {x * a, y * a, z * a, w * a};
        }

        void operator*=(const float a) {
            x *= a, y *= a, z *= a, w *= a;
        }

        FVector4 operator/(const float a) const {
            return {x / a, y / a, z / a, w / a};
        }

        void operator/=(const float a) {
            x /= a, y /= a, z /= a, w /= a;
        }

        bool operator==(const FVector2D a) const {
            return x == a.x && y == a.y;
        }

        bool operator!=(const FVector2D a) const {
            return x != a.x || y != a.y;
        }

        bool operator==(const FVector& a) const {
            return x == a.x && y == a.y && z == a.z;
        }

        bool operator!=(const FVector& a) const {
            return x != a.x || y != a.y || z != a.z;
        }

        bool operator==(const FVector4& a) const {
            return x == a.x && y == a.y && z == a.z && w == a.w;
        }

        bool operator!=(const FVector4& a) const {
            return x != a.x || y != a.y || z != a.z || w == a.w;
        }

        bool operator==(const float a) const {
            return x == a && y == a && z == a && w == a;
        }

        bool operator!=(const float a) const {
            return x != a || y != a || z != a || w != a;
        }

        bool operator>(const FVector2D a) const {
            return x > a.x && y > a.y;
        }

        bool operator>=(const FVector2D a) const {
            return x >= a.x && y >= a.y;
        }

        bool operator<(const FVector2D a) const {
            return x < a.x && y < a.y;
        }

        bool operator<=(const FVector2D a) const {
            return x <= a.x && y <= a.y;
        }

        bool operator>(const FVector& a) const {
            return x > a.x && y > a.y && z > a.z;
        }

        bool operator>=(const FVector& a) const {
            return x >= a.x && y >= a.y && z >= a.z;
        }

        bool operator<(const FVector& a) const {
            return x < a.x && y < a.y && z < a.z;
        }

        bool operator<=(const FVector& a) const {
            return x <= a.x && y <= a.y && z <= a.z;
        }

        bool operator>(const FVector4& a) const {
            return x > a.x && y > a.y && z > a.z && w > a.w;
        }

        bool operator>=(const FVector4& a) const {
            return x >= a.x && y >= a.y && z >= a.z && w >= a.w;
        }

        bool operator<(const FVector4& a) const {
            return x < a.x && y < a.y && z < a.z && z < a.w;
        }

        bool operator<=(const FVector4& a) const {
            return x <= a.x && y <= a.y && z <= a.z && w < a.w;
        }
        
        bool operator>(const float a) const {
            return x > a && y > a;
        }

        bool operator>=(const float a) const {
            return x >= a && y >= a;
        }

        bool operator<(const float a) const {
            return x < a && y < a;
        }

        bool operator<=(const float a) const {
            return x <= a && y <= a;
        }

        operator FVector2D() const {
            return {x, y};
        }

        operator FVector() const {
            return {x, y, z};
        }
    };
}
