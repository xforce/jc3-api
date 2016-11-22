#pragma once

#include <cstdint>

#include "../../hash_string.h"

#include "misc.h"

namespace jc3
{
#pragma pack(push, 8)
    struct STriangulatedMesh
    {
        struct Arrayvertices
        {
            float* m_Data;
            uint32_t m_Count;
        }vertices;         //0000 - 0008
        struct Arraytriangles
        {
            uint8_t* m_Data;
            uint32_t m_Count;
        }triangles;         //0010 - 0018
    };
    static_assert(sizeof(STriangulatedMesh) == 0x20, "STriangulatedMesh has wrong size");
#pragma pack(pop)
#pragma pack(push, 8)
    struct SPartWaterInteractionElement
    {
        SHashString name;         //0000 - 0008
        SHashString from_part;         //0010 - 0018
        STriangulatedMesh hull;         //0020 - 0028
    };
    static_assert(sizeof(SPartWaterInteractionElement) == 0x40, "SPartWaterInteractionElement has wrong size");
#pragma pack(pop)
#pragma pack(push, 8)
    struct SWaterInteraction
    {
        struct Arraypart_elements
        {
            SPartWaterInteractionElement* m_Data;
            uint32_t m_Count;
        }part_elements;         //0000 - 0008
        int32_t will_sink;         //0010 - 0014
        float angular_drag_pitch;         //0014 - 0018
        float angular_drag_yaw;         //0018 - 001C
        float angular_drag_roll;         //001C - 0020
        float angular_drag_roll_at_speed;         //0020 - 0024
        float angular_drag_ref_speed_kmph;         //0024 - 0028
        float drag_falloff_power;         //0028 - 002C
        float pressure_drag;         //002C - 0030
        float pressure_drag_2;         //0030 - 0034
        float suction_drag;         //0034 - 0038
        float suction_drag_2;         //0038 - 003C
        float depth_full_drag;         //003C - 0040
        float add_skin_friction_laminar;         //0040 - 0044
        float add_skin_friction_turbulent;         //0044 - 0048
        float reference_drag_speed_ms;         //0048 - 004C
        float anti_penetration_max_accel;         //004C - 0050
        float anti_penetration_multiplier;         //0050 - 0054
        float anti_penetration_power;         //0054 - 0058
        float depth_full_anti_penetration;         //0058 - 005C
        SSpline5 planing_vs_forward_speed_ms;         //005C - 0060
        SSpline5 buoyancy_factor_vs_speed_ms;         //00AC - 00B0
        SSpline5 flat_water_vs_speed_ms;         //00FC - 0100
    };
    static_assert(sizeof(SWaterInteraction) == 0x150, "SWaterInteraction has wrong size");
#pragma pack(pop)

}