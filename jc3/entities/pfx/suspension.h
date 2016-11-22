#pragma once

#include <cstdint>

namespace jc3
{
#pragma pack(push, 4)
    struct SSuspensionAxis
    {
        float antirollbar_strength;         //0000 - 0004
        float compression;         //0004 - 0008
        float direction[3];         //0008 - 000C
        float length;         //0014 - 0018
        float relaxation;         //0018 - 001C
        float max_velocity_for_damp_clamp;         //001C - 0020
        float strength;         //0020 - 0024
        float raycast_offset;         //0024 - 0028
        float lateral_tire_force_offset;         //0028 - 002C
        float longitudinal_tire_force_offset;         //002C - 0030
        float tire_drag_force_offset;         //0030 - 0034
        float hardpoint_offset_along_spring;         //0034 - 0038
        float min_length;         //0038 - 003C
        float max_length_offset;         //003C - 0040
    };
    static_assert(sizeof(SSuspensionAxis) == 0x40, "SSuspensionAxis has wrong size");
#pragma pack(pop)
#pragma pack(push, 4)
    struct SWheelHardpointOffset
    {
        int32_t wheel_index;         //0000 - 0004
        float offset[3];         //0004 - 0008
    };
    static_assert(sizeof(SWheelHardpointOffset) == 0x10, "SWheelHardpointOffset has wrong size");
#pragma pack(pop)
#pragma pack(push, 8)
    struct SSuspension
    {
        SSuspensionAxis front;         //0000 - 0004
        SSuspensionAxis rear;         //0040 - 0044
        struct Arraywheel_hardpoint_offsets
        {
            SWheelHardpointOffset* m_Data;
            uint32_t m_Count;
        }wheel_hardpoint_offsets;         //0080 - 0088
    };
    static_assert(sizeof(SSuspension) == 0x90, "SSuspension has wrong size");
#pragma pack(pop)
}