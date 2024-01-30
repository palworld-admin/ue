#pragma once

namespace ue {
    class FMatrix {
    public:
        float m[4][4];

        FMatrix() {
            ZeroMemory(this, sizeof(FMatrix));
        }

        explicit FMatrix(const FRotator& rotation, const FVector& origin = {0.f, 0.f, 0.f}) {
            const float rad_pitch = rotation.x * static_cast<float>(M_PI) / 180.f;
            const float rad_yaw   = rotation.y * static_cast<float>(M_PI) / 180.f;
            const float rad_roll  = rotation.z * static_cast<float>(M_PI) / 180.f;

            const float sp = sinf(rad_pitch);
            const float cp = cosf(rad_pitch);
            const float sy = sinf(rad_yaw);
            const float cy = cosf(rad_yaw);
            const float sr = sinf(rad_roll);
            const float cr = cosf(rad_roll);

            m[0][0] = cp * cy;
            m[0][1] = cp * sy;
            m[0][2] = sp;
            m[0][3] = 0.f;
            m[1][0] = sr * sp * cy - cr * sy;
            m[1][1] = sr * sp * sy + cr * cy;
            m[1][2] = -sr * cp;
            m[1][3] = 0.f;
            m[2][0] = -(cr * sp * cy + sr * sy);
            m[2][1] = cy * sr - cr * sp * sy;
            m[2][2] = cr * cp;
            m[2][3] = 0.f;
            m[3][0] = origin.x;
            m[3][1] = origin.y;
            m[3][2] = origin.z;
            m[3][3] = 1.f;
        }

        FMatrix operator*(const FMatrix& m2) const {
            FMatrix out;
            for (byte r = 0; r < 4; r++) {
                for (byte c = 0; c < 4; c++) {
                    float sum = 0.f;

                    for (byte i = 0; i < 4; i++)
                        sum += m[r][i] * m2.m[i][c];

                    out.m[r][c] = sum;
                }
            }

            return out;
        }

        void operator*=(const FMatrix& m2) {
            *this = this->operator*(m2);
        }
    };
}
