#pragma once

#include <cstdint>

namespace jc3
{
#pragma pack(push, 4)
    struct SBrakeAxis
    {
        int32_t handbrake;         //0000 - 0004
        float max_brake_torque;         //0004 - 0008
        float min_time_to_block;         //0008 - 000C
    };
    static_assert(sizeof(SBrakeAxis) == 0xC, "SBrakeAxis has wrong size");
#pragma pack(pop)
#pragma pack(push, 4)
    struct SBrakes
    {
        SBrakeAxis front;         //0000 - 0004
        SBrakeAxis rear;         //000C - 0010
        float handbrake_friction_factor;         //0018 - 001C
    };
    static_assert(sizeof(SBrakes) == 0x1C, "SBrakes has wrong size");
#pragma pack(pop)
}