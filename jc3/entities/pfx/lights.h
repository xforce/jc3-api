#pragma once

#include <cstdint>

namespace jc3
{

#pragma pack(push, 4)
    struct SColor
    {
        float R;         //0000 - 0004
        float G;         //0004 - 0008
        float B;         //0008 - 000C
    };
    static_assert(sizeof(SColor) == 0xC, "SColor has wrong size");
#pragma pack(pop)
#pragma pack(push, 4)
    struct SUVScale
    {
        float u;         //0000 - 0004
        float v;         //0004 - 0008
    };
    static_assert(sizeof(SUVScale) == 0x8, "SUVScale has wrong size");
#pragma pack(pop)
#pragma pack(push, 8)
    struct SVehicleDynamicLight
    {
        const char* behavior;         //0000 - 0008
        uint32_t behavior_hash;         //0008 - 000C
        const char* part;         //0010 - 0018
        uint32_t part_hash;         //0018 - 001C
        uint32_t part_index;         //001C - 0020
        SColor diffuse;         //0020 - 0024
        float range;         //002C - 0030
        float falloff_start;         //0030 - 0034
        float near_cap;         //0034 - 0038
        float multiplier;         //0038 - 003C
        float min_luminosity;         //003C - 0040
        int32_t light_type;         //0040 - 0044
        int32_t blinking;         //0044 - 0048
        float angle;         //0048 - 004C
        int8_t cast_shadows;         //004C - 004D
        int8_t projected_texture_index;         //004D - 004E
        int16_t volumetric_mode;         //004E - 0050
        float volume_intensity;         //0050 - 0054
        SUVScale uvscale;         //0054 - 0058
        const char* deformable_transform;         //0060 - 0068
        uint32_t deformable_transform_hash;         //0068 - 006C
        uint32_t preset_id;         //006C - 0070
    };
    static_assert(sizeof(SVehicleDynamicLight) == 0x70, "SVehicleDynamicLight has wrong size");
#pragma pack(pop)
#pragma pack(push, 8)
    struct SVehicleDynamicLights
    {
        struct Arraylights
        {
            SVehicleDynamicLight* m_Data;
            uint32_t m_Count;
        }lights;         //0000 - 0008
    };
    static_assert(sizeof(SVehicleDynamicLights) == 0x10, "SVehicleDynamicLights has wrong size");
#pragma pack(pop)
}