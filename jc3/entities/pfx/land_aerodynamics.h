#pragma once

namespace jc3
{
#pragma pack(push, 4)
    struct SLandAerodynamics
    {
        float air_density;         //0000 - 0004
        float frontal_area;         //0004 - 0008
        float drag_coefficient;         //0008 - 000C
        float top_speed_drag_coefficient;         //000C - 0010
        float lift_coefficient;         //0010 - 0014
    };
    static_assert(sizeof(SLandAerodynamics) == 0x14, "SLandAerodynamics has wrong size");
#pragma pack(pop)
}