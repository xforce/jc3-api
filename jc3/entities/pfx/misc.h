#pragma once

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
    struct SSpline5
    {
        float x_min;         //0000 - 0004
        float x_max;         //0004 - 0008
        float y_min;         //0008 - 000C
        float y_max;         //000C - 0010
        int8_t number_of_control_points;         //0010 - 0011
        SSplineControlPoint control_points[5];         //0014 - 0018
    };
    static_assert(sizeof(SSpline5) == 0x50, "SSpline5 has wrong size");
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
}