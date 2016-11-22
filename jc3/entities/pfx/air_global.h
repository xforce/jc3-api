#pragma once

#include <cstdint>

#include "land_global.h"

namespace jc3
{
#pragma pack(push, 4)
    struct SAirPerformanceBoost
    {
        float push_acceleration;         //0000 - 0004
        float boost_blend_time;         //0004 - 0008
        float extra_top_speed;         //0008 - 000C
    };
    static_assert(sizeof(SAirPerformanceBoost) == 0xC, "SAirPerformanceBoost has wrong size");
#pragma pack(pop)
#pragma pack(push, 8)
    struct SAirGlobal
    {
        float ground_pitch_angle_deg;         //0000 - 0004
        float altitude_limit_threshold_low;         //0004 - 0008
        float altitude_limit_threshold_high;         //0008 - 000C
        int32_t number_of_wheels;         //000C - 0010
        int32_t number_of_front_wheels;         //0010 - 0014
        int8_t is_rear_steered;         //0014 - 0015
        SLandWheel front_wheels;         //0018 - 001C
        SLandWheel rear_wheels;         //0038 - 003C
        struct Arraybase_wheel_hardpoint_positions
        {
            SWheelHardpoint* m_Data;
            uint32_t m_Count;
        }base_wheel_hardpoint_positions;         //0058 - 0060
        SAirPerformanceBoost nitro_boost;         //0068 - 006C
        SAirPerformanceBoost nitro_boost_upgraded;         //0074 - 0078
        SAirPerformanceBoost heat_boost;         //0080 - 0084
    };
    static_assert(sizeof(SAirGlobal) == 0x90, "SAirGlobal has wrong size");
#pragma pack(pop)
}