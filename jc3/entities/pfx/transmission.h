#pragma once

#include <cstdint>

namespace jc3
{
#pragma pack(push, 4)
    struct STransmission
    {
        int32_t gears;         //0000 - 0004
        int32_t nitrous_gears;         //0004 - 0008
        float gear_ratios[8];         //0008 - 000C
        float upshift_rpm[8];         //0028 - 002C
        float downshift_rpm[8];         //0048 - 004C
        int32_t sequential;         //0068 - 006C
        int32_t manual_clutch;         //006C - 0070
        float manual_clutch_blend_rpm;         //0070 - 0074
        float manual_clutch_blend_time;         //0074 - 0078
        float forward_ratio_percentage;         //0078 - 007C
        float low_gear_forward_ratio_pct;         //007C - 0080
        float top_speed;         //0080 - 0084
        float low_gears_final_drive;         //0084 - 0088
        float final_drive;         //0088 - 008C
        int32_t reverse_uses_forward_gears;         //008C - 0090
        float reverse_gear_ratio;         //0090 - 0094
        float clutch_delay;         //0094 - 0098
        float decay_time_to_cruise_rpm;         //0098 - 009C
        float target_cruise_rpm;         //009C - 00A0
    };
    static_assert(sizeof(STransmission) == 0xA0, "STransmission has wrong size");
#pragma pack(pop)
}