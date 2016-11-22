#pragma once

#include <cstdint>

#include "../../hash_string.h"

#include "misc.h"

namespace jc3
{

#pragma pack(push, 8)
    struct SBoatEngine
    {
        SHashString physics_component_name;         //0000 - 0008
        SSpline5 max_acceleration_vs_speed;         //0010 - 0014
        float propulsion_displacement_limit;         //0060 - 0064
        float engine_axis[3];         //0064 - 0068
        float engine_position[3];         //0070 - 0074
        float engine_graphical_offset[3];         //007C - 0080
        float propeller_offset[3];         //0088 - 008C
    };
    static_assert(sizeof(SBoatEngine) == 0x98, "SBoatEngine has wrong size");
#pragma pack(pop)
}