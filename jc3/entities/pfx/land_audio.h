#pragma once

namespace jc3
{
#pragma pack(push, 4)
    struct SLandAudio
    {
        float min_rpm;         //0000 - 0004
        float max_rpm;         //0004 - 0008
    };
    static_assert(sizeof(SLandAudio) == 0x8, "SLandAudio has wrong size");
#pragma pack(pop)
}