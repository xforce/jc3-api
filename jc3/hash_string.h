#pragma once

#include <cstdint>

namespace jc3
{
#pragma pack(push, 8)
    struct SHashString
    {
        const char* string;         //0000 - 0008
        uint32_t hash;         //0008 - 000C
    };
    static_assert(sizeof(SHashString) == 0x10, "SHashString has wrong size");
#pragma pack(pop)
}