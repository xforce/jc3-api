#pragma once

namespace jc3
{
#pragma pack(push, 4)
    struct SLandSteering
    {
        float dead_zone;         //0000 - 0004
        float saturation_zone;         //0004 - 0008
        float t_to_full_steer_s;         //0008 - 000C
        float max_speed_t_to_full_steer_s;         //000C - 0010
        float min_speed_kmph;         //0010 - 0014
        float max_speed_kmph;         //0014 - 0018
        float steer_angle_min_speed_deg;         //0018 - 001C
        float steer_angle_max_speed_deg;         //001C - 0020
        float steer_curve_falloff;         //0020 - 0024
        float countersteer_speed_factor;         //0024 - 0028
        float steer_in_speed_factor;         //0028 - 002C
        float steer_input_power_pc;         //002C - 0030
        float steer_input_power_durango;         //0030 - 0034
        float steer_input_power_orbis;         //0034 - 0038
        float wheel_drift_aligning_strength;         //0038 - 003C
    };
    static_assert(sizeof(SLandSteering) == 0x3C, "SLandSteering has wrong size");
#pragma pack(pop)
}