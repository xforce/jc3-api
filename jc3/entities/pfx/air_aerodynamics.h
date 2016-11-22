#pragma once

#include <cstdint>

#include "../../hash_string.h"

#include "misc.h"

namespace jc3
{

#pragma pack(push, 8)
    struct SAerodynamicSurface
    {
        SHashString name;         //0000 - 0008
        SHashString physics_component_name;         //0010 - 0018
        float center_point[3];         //0020 - 0024
        SEulerAngles surface_normal_angles;         //002C - 0030
        float turn_steering_factor;         //0038 - 003C
        float pitch_steering_factor;         //003C - 0040
        float roll_steering_factor;         //0040 - 0044
        float air_density;         //0044 - 0048
        float frontal_area;         //0048 - 004C
        float drag_coefficient;         //004C - 0050
        float top_speed_drag_coefficient;         //0050 - 0054
        float extra_brake_drag_coefficient;         //0054 - 0058
        float lift_coefficient;         //0058 - 005C
    };
    static_assert(sizeof(SAerodynamicSurface) == 0x60, "SAerodynamicSurface has wrong size");
#pragma pack(pop)
#pragma pack(push, 8)
    struct SAerodynamics
    {
        struct Arrayaerodynamic_surfaces
        {
            SAerodynamicSurface* m_Data;
            uint32_t m_Count;
        }aerodynamic_surfaces;         //0000 - 0008
        SSpline20 lift_c_vs_attack_angle_deg;         //0010 - 0014
        SSpline20 drag_c_vs_attack_angle_deg;         //0114 - 0118
    };
    static_assert(sizeof(SAerodynamics) == 0x218, "SAerodynamics has wrong size");
#pragma pack(pop)
}