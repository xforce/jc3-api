#pragma once

namespace jc3
{
#pragma pack(push, 4)
    struct SBoatAudio
    {
        float min_rpm;         //0000 - 0004
        float max_rpm;         //0004 - 0008
        float rpm_mix;         //0008 - 000C
        float velocity_to_rpm;         //000C - 0010
    };
    static_assert(sizeof(SBoatAudio) == 0x10, "SBoatAudio has wrong size");
#pragma pack(pop)
}