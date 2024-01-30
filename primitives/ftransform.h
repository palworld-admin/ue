#pragma once

namespace ue {
    class FTransform {
    public:
        FVector4 rotation;
        FVector translation;
        float pad0001;
        FVector scale_3d;
        float pad0002;

        FMatrix to_matrix_with_scale() const {
            FMatrix m;
            m.m[3][0] = translation.x;
            m.m[3][1] = translation.y;
            m.m[3][2] = translation.z;

            const float x2 = rotation.x + rotation.x;
            const float y2 = rotation.y + rotation.y;
            const float z2 = rotation.z + rotation.z;

            const float xx2 = rotation.x * x2;
            const float yy2 = rotation.y * y2;
            const float zz2 = rotation.z * z2;
            m.m[0][0]       = (1.0f - (yy2 + zz2)) * scale_3d.x;
            m.m[1][1]       = (1.0f - (xx2 + zz2)) * scale_3d.y;
            m.m[2][2]       = (1.0f - (xx2 + yy2)) * scale_3d.z;

            const float yz2 = rotation.y * z2;
            const float wx2 = rotation.w * x2;
            m.m[2][1]       = (yz2 - wx2) * scale_3d.z;
            m.m[1][2]       = (yz2 + wx2) * scale_3d.y;

            const float xy2 = rotation.x * y2;
            const float wz2 = rotation.w * z2;
            m.m[1][0]       = (xy2 - wz2) * scale_3d.y;
            m.m[0][1]       = (xy2 + wz2) * scale_3d.x;

            const float xz2 = rotation.x * z2;
            const float wy2 = rotation.w * y2;
            m.m[2][0]       = (xz2 + wy2) * scale_3d.z;
            m.m[0][2]       = (xz2 - wy2) * scale_3d.x;

            m.m[0][3] = 0.0f;
            m.m[1][3] = 0.0f;
            m.m[2][3] = 0.0f;
            m.m[3][3] = 1.0f;

            return m;
        }
    };
}
