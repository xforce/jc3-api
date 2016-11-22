#pragma once

#include <cstdint>

namespace jc3
{
#pragma pack(push, 4)
    struct SBoatBuoyancyModule
    {
        float position[3];         //0000 - 0004
        float radius;         //000C - 0010
        float buoyancy;         //0010 - 0014
        float forward_drag;         //0014 - 0018
        float lateral_drag;         //0018 - 001C
        float vertical_drag;         //001C - 0020
        float air_drag;         //0020 - 0024
    };
    static_assert(sizeof(SBoatBuoyancyModule) == 0x24, "SBoatBuoyancyModule has wrong size");
#pragma pack(pop)
#pragma pack(push, 8)
    struct SBoatBuoyancy
    {
        float base_position[3];         //0000 - 0004
        float base_radius;         //000C - 0010
        float base_buoyancy;         //0010 - 0014
        float base_forward_drag;         //0014 - 0018
        float base_lateral_drag;         //0018 - 001C
        float base_vertical_drag;         //001C - 0020
        float base_air_drag;         //0020 - 0024
        float up_velocity_cap;         //0024 - 0028
        struct Arraybuoyancy_modules
        {
            SBoatBuoyancyModule* m_Data;
            uint32_t m_Count;
        }buoyancy_modules;         //0028 - 0030
    };
    static_assert(sizeof(SBoatBuoyancy) == 0x38, "SBoatBuoyancy has wrong size");
#pragma pack(pop)

}