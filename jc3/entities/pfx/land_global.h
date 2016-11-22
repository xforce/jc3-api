#pragma once

#include <cstdint>

namespace jc3
{

#pragma pack(push, 4)
    struct SLandWheel
    {
        float radius;         //0000 - 0004
        float rim_radius;         //0004 - 0008
        float width;         //0008 - 000C
        int8_t use_shape_cast;         //000C - 000D
        float mass;         //0010 - 0014
        float arcade_friction_multiplier;         //0014 - 0018
        float arcade_drag_multiplier;         //0018 - 001C
        int8_t match_road_velocity_on_landing;         //001C - 001D
    };
    static_assert(sizeof(SLandWheel) == 0x20, "SLandWheel has wrong size");
#pragma pack(pop)
#pragma pack(push, 4)
    struct SWheelHardpoint
    {
        float position[3];         //0000 - 0004
    };
    static_assert(sizeof(SWheelHardpoint) == 0xC, "SWheelHardpoint has wrong size");
#pragma pack(pop)
#pragma pack(push, 8)
    struct SLandGlobal
    {
        int32_t number_of_wheels;         //0000 - 0004
        int32_t number_of_front_wheels;         //0004 - 0008
        int8_t is_rear_steered;         //0008 - 0009
        int8_t is_all_wheel_steered;         //0009 - 000A
        int32_t wheels_friction_type;         //000C - 0010
        float normal_clipping_angle_cosine;         //0010 - 0014
        float ground_clearance;         //0014 - 0018
        SLandWheel front_wheels;         //0018 - 001C
        SLandWheel rear_wheels;         //0038 - 003C
        struct Arraybase_wheel_hardpoint_positions
        {
            SWheelHardpoint* m_Data;
            uint32_t m_Count;
        }base_wheel_hardpoint_positions;         //0058 - 0060
    };
    static_assert(sizeof(SLandGlobal) == 0x68, "SLandGlobal has wrong size");
#pragma pack(pop)
}