#pragma once

#include "land_steering.h"

namespace jc3
{
#pragma pack(push, 4)
    struct SMotorbikeWheelie
    {
        float max_lean_angle_deg;         //0000 - 0004
        float input_reactiveness;         //0004 - 0008
        float dead_zone;         //0008 - 000C
        float min_speed;         //000C - 0010
        float wheelie_angle_deg;         //0010 - 0014
        float wheelie_torque;         //0014 - 0018
        float wheelie_center_of_mass_offset[3];         //0018 - 001C
        float nosie_angle_deg;         //0024 - 0028
        float nosie_torque;         //0028 - 002C
        float nosie_center_of_mass_offset[3];         //002C - 0030
    };
    static_assert(sizeof(SMotorbikeWheelie) == 0x38, "SMotorbikeWheelie has wrong size");
#pragma pack(pop)
#pragma pack(push, 4)
    struct SMotorbikeSteering
    {
        SLandSteering land_steering;         //0000 - 0004
        SMotorbikeWheelie wheelie;         //003C - 0040
    };
    static_assert(sizeof(SMotorbikeSteering) == 0x74, "SMotorbikeSteering has wrong size");
#pragma pack(pop)
}