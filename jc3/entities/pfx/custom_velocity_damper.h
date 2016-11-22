#pragma once

namespace jc3
{
#pragma pack(push, 4)
    struct SVelocityDamper
    {
        float normal_spin_damping;         //0000 - 0004
        float collision_spin_damping;         //0004 - 0008
        float collision_spin_threshold;         //0008 - 000C
    };
    static_assert(sizeof(SVelocityDamper) == 0xC, "SVelocityDamper has wrong size");
#pragma pack(pop)
#pragma pack(push, 4)
    struct SCustomVelocityDamper
    {
        SVelocityDamper velocity_damper;         //0000 - 0004
        float handbrake_spin_damping;         //000C - 0010
    };
    static_assert(sizeof(SCustomVelocityDamper) == 0x10, "SCustomVelocityDamper has wrong size");
#pragma pack(pop)
}