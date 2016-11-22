#pragma once

#include <cstdint>

#include "../../hash_string.h"

#include "misc.h"

namespace jc3
{
#pragma pack(push, 8)
    struct SFin
    {
        SHashString physics_component_name;         //0000 - 0008
        float area;         //0010 - 0014
        float height;         //0014 - 0018
        uint8_t effective_in_air;         //0018 - 0019
        uint8_t effective_in_water;         //0019 - 001A
        float steering_factor;         //001C - 0020
        float hinge_position[3];         //0020 - 0024
        SEulerAngles hinge_angles;         //002C - 0030
        float distance_to_hinge;         //0038 - 003C
        float min_angle_deg;         //003C - 0040
        float max_angle_deg;         //0040 - 0044
    };
    static_assert(sizeof(SFin) == 0x48, "SFin has wrong size");
#pragma pack(pop)
#pragma pack(push, 8)
    struct SFins
    {
        SSpline5 lift_vs_attack_angle_deg;         //0000 - 0004
        SSpline5 max_steering_vs_speed_ms;         //0050 - 0054
        float reference_speed_ms;         //00A0 - 00A4
        float pressure_drag;         //00A4 - 00A8
        float pressure_drag2;         //00A8 - 00AC
        SFin fins[5];         //00B0 - 00B8
        uint8_t number_of_fins;         //0218 - 0219
    };
    static_assert(sizeof(SFins) == 0x220, "SFins has wrong size");
#pragma pack(pop)

}