#pragma once

namespace jc3
{
#pragma pack(push, 4)
    struct SAirEngine
    {
        float min_thrust;         //0000 - 0004
        float max_thrust;         //0004 - 0008
        float run_thrust;         //0008 - 000C
        float max_thrust_acceleration;         //000C - 0010
        float taxiing_max_thrust;         //0010 - 0014
        float taxiing_input_threshold;         //0014 - 0018
        float taxiing_top_speed;         //0018 - 001C
    };
    static_assert(sizeof(SAirEngine) == 0x1C, "SAirEngine has wrong size");
#pragma pack(pop)
}