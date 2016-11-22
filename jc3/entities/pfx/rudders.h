#pragma once
#include <cstdint>

#include "../../hash_string.h"

namespace jc3
{
#pragma pack(push, 4)
    struct SEulerAngles
    {
        float pitch_deg;         //0000 - 0004
        float yaw_deg;         //0004 - 0008
        float roll_deg;         //0008 - 000C
    };
    static_assert(sizeof(SEulerAngles) == 0xC, "SEulerAngles has wrong size");
#pragma pack(pop)
#pragma pack(push, 4)
    struct SSplineControlPoint
    {
        float x;         //0000 - 0004
        float y;         //0004 - 0008
        float y2;         //0008 - 000C
    };
    static_assert(sizeof(SSplineControlPoint) == 0xC, "SSplineControlPoint has wrong size");
#pragma pack(pop)
#pragma pack(push, 4)
    struct SSpline20
    {
        float x_min;         //0000 - 0004
        float x_max;         //0004 - 0008
        float y_min;         //0008 - 000C
        float y_max;         //000C - 0010
        int8_t number_of_control_points;         //0010 - 0011
        SSplineControlPoint control_points[20];         //0014 - 0018
    };
    static_assert(sizeof(SSpline20) == 0x104, "SSpline20 has wrong size");
#pragma pack(pop)
#pragma pack(push, 8)
    struct SRudder
    {
        const char* name;         //0000 - 0008
        SHashString physics_component_name;         //0008 - 0010
        float hinge_point[3];         //0018 - 001C
        SEulerAngles hinge_angles;         //0024 - 0028
        SSpline20 zero_angle_deg_vs_speed_kph;         //0030 - 0034
        float distance_to_hinge;         //0134 - 0138
        float turn_steering_factor;         //0138 - 013C
        float pitch_steering_factor;         //013C - 0140
        float roll_steering_factor;         //0140 - 0144
        float min_angle_deg;         //0144 - 0148
        float max_angle_deg;         //0148 - 014C
        float air_density;         //014C - 0150
        float frontal_area;         //0150 - 0154
        float drag_coefficient;         //0154 - 0158
        float lift_coefficient;         //0158 - 015C
    };
    static_assert(sizeof(SRudder) == 0x160, "SRudder has wrong size");
#pragma pack(pop)
#pragma pack(push, 8)
    struct SRudders
    {
        struct Arrayrudders
        {
            SRudder* m_Data;
            uint32_t m_Count;
        }rudders;         //0000 - 0008
    };
    static_assert(sizeof(SRudders) == 0x10, "SRudders has wrong size");
#pragma pack(pop)
}