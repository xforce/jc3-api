#pragma once

#include <cstdint>

namespace jc3
{
#pragma pack(push, 4)
    struct SBuoyancyModule
    {
        float position[3];         //0000 - 0004
    };
    static_assert(sizeof(SBuoyancyModule) == 0xC, "SBuoyancyModule has wrong size");
#pragma pack(pop)
#pragma pack(push, 8)
    struct SBuoyancy
    {
        float buoyancy;         //0000 - 0004
        float drag;         //0004 - 0008
        float radius;         //0008 - 000C
        float side_area;         //000C - 0010
        float bottom_area;         //0010 - 0014
        float up_velocity_cap;         //0014 - 0018
        struct Arraybuoyancy_modules
        {
            SBuoyancyModule* m_Data;
            uint32_t m_Count;
        }buoyancy_modules;         //0018 - 0020
    };
    static_assert(sizeof(SBuoyancy) == 0x28, "SBuoyancy has wrong size");
#pragma pack(pop)
}