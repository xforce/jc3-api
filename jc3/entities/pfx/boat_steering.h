#pragma once

namespace jc3
{
#pragma pack(push, 4)
    struct SSpeedDependentInputFilter
    {
        float t_to_full_input_min_speed_s;         //0000 - 0004
        float t_to_full_input_max_speed_s;         //0004 - 0008
        float input_start_speed_kmph;         //0008 - 000C
        float input_max_speed_kmph;         //000C - 0010
        float counterinput_speed_factor;         //0010 - 0014
        float zeroinput_speed_factor;         //0014 - 0018
        float input_speedcurve_falloff;         //0018 - 001C
    };
    static_assert(sizeof(SSpeedDependentInputFilter) == 0x1C, "SSpeedDependentInputFilter has wrong size");
#pragma pack(pop)
#pragma pack(push, 4)
    struct SBoatSteering
    {
        SSpeedDependentInputFilter steeringfilter;         //0000 - 0004
        float acceleration_smoothing;         //001C - 0020
    };
    static_assert(sizeof(SBoatSteering) == 0x20, "SBoatSteering has wrong size");
#pragma pack(pop)
}