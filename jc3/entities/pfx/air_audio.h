#pragma once

namespace jc3
{
#pragma pack(push, 4)
    struct SAirAudio
    {
        float acceleration;         //0000 - 0004
        float rpm_ramp_up_speed;         //0004 - 0008
        float shutdown_rpm;         //0008 - 000C
        float min_rpm;         //000C - 0010
        float max_rpm;         //0010 - 0014
        float top_speed;         //0014 - 0018
        float thrust_coef;         //0018 - 001C
        float velocity_coef;         //001C - 0020
        float idle_load;         //0020 - 0024
        float load_hold_dt;         //0024 - 0028
        float load_release_dt;         //0028 - 002C
    };
    static_assert(sizeof(SAirAudio) == 0x2C, "SAirAudio has wrong size");
#pragma pack(pop)
}