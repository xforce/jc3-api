#pragma once

#include <cstdint>

namespace jc3
{
#pragma pack(push, 4)
    struct SLandEngine
    {
        int32_t rpm_power_band;         //0000 - 0004
        float resistance_at_min_rpm;         //0004 - 0008
        float resistance_at_max_rpm;         //0008 - 000C
        float resistance_at_optimal_rpm;         //000C - 0010
        float rev_limiter_rpm_drop;         //0010 - 0014
        float max_rpm;         //0014 - 0018
        float min_rpm;         //0018 - 001C
        float optimal_rpm;         //001C - 0020
        float torque_factor_at_max_rpm;         //0020 - 0024
        float torque_factor_at_min_rpm;         //0024 - 0028
        float torque_factor_at_optimal_rpm;         //0028 - 002C
        float clutch_slip_rpm;         //002C - 0030
        float engine_min_noise;         //0030 - 0034
        float engine_damage_noise_scale;         //0034 - 0038
        float engine_max_damage_torque;         //0038 - 003C
    };
    static_assert(sizeof(SLandEngine) == 0x3C, "SLandEngine has wrong size");
#pragma pack(pop)
}