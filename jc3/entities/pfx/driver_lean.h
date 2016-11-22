#pragma once

namespace jc3
{
#pragma pack(push, 4)
    struct SDriverLean
    {
        float t_to_full_lean_min_speed_s;         //0000 - 0004
        float t_to_full_lean_max_speed_s;         //0004 - 0008
        float lean_start_speed_kmph;         //0008 - 000C
        float lean_max_speed_kmph;         //000C - 0010
        float counterlean_speed_factor;         //0010 - 0014
        float zerolean_speed_factor;         //0014 - 0018
        float lean_speedcurve_falloff;         //0018 - 001C
        float max_lean_angle_deg;         //001C - 0020
        float max_drift_lean_angle_deg;         //0020 - 0024
        float ease_in_angle_deg;         //0024 - 0028
        float leaning_torque;         //0028 - 002C
        float drift_leaning_torque;         //002C - 0030
        float righting_torque;         //0030 - 0034
        float drift_factor_lean_power;         //0034 - 0038
        float lean_damping;         //0038 - 003C
        float lean_ratio_for_max_steer;         //003C - 0040
    };
    static_assert(sizeof(SDriverLean) == 0x40, "SDriverLean has wrong size");
#pragma pack(pop)
}