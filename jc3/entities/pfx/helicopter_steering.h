#pragma once

#include "air_steering.h"

namespace jc3
{
#pragma pack(push, 4)
    struct SHelicopterSteering
    {
        SAirSteering air_steering;         //0000 - 0004
        float return_pitch_limit;         //0048 - 004C
        float return_roll_limit;         //004C - 0050
    };
    static_assert(sizeof(SHelicopterSteering) == 0x50, "SHelicopterSteering has wrong size");
#pragma pack(pop)
}