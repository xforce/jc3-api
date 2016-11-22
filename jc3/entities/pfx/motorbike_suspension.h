#pragma once

#include "suspension.h"

namespace jc3
{
#pragma pack(push, 8)
    struct SMotorbikeSuspension
    {
        SSuspension land_suspension;         //0000 - 0008
        float upper_steering_offset;         //0090 - 0094
    };
    static_assert(sizeof(SMotorbikeSuspension) == 0x98, "SMotorbikeSuspension has wrong size");
#pragma pack(pop)
}