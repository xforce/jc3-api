#pragma once

#include <cstdint>

#include "../../hash_string.h"

namespace jc3
{
#pragma pack(pop)
#pragma pack(push, 8)
    struct SEffectAttachment
    {
        SHashString deform_point;         //0000 - 0008
        SHashString effect;         //0010 - 0018
    };
    static_assert(sizeof(SEffectAttachment) == 0x20, "SEffectAttachment has wrong size");
#pragma pack(pop)
#pragma pack(push, 8)
    struct SPartEffectReactions
    {
        struct Arrayon_part_loosened
        {
            int32_t* m_Data;
            uint32_t m_Count;
        }on_part_loosened;         //0000 - 0008
        struct Arrayon_part_broke_off
        {
            int32_t* m_Data;
            uint32_t m_Count;
        }on_part_broke_off;         //0010 - 0018
        struct Arrayon_part_reached_damaged_state
        {
            int32_t* m_Data;
            uint32_t m_Count;
        }on_part_reached_damaged_state;         //0020 - 0028
        struct Arrayon_part_burning
        {
            int32_t* m_Data;
            uint32_t m_Count;
        }on_part_burning;         //0030 - 0038
        struct Arrayon_part_exploded
        {
            int32_t* m_Data;
            uint32_t m_Count;
        }on_part_exploded;         //0040 - 0048
    };
    static_assert(sizeof(SPartEffectReactions) == 0x50, "SPartEffectReactions has wrong size");
#pragma pack(pop)
#pragma pack(push, 8)
    struct SPartEffectAttachments
    {
        SHashString part;         //0000 - 0008
        int32_t first_effect_index;         //0010 - 0014
        int32_t effects_count;         //0014 - 0018
        SPartEffectReactions effect_starts;         //0018 - 0020
        SPartEffectReactions effect_stops;         //0068 - 0070
    };
    static_assert(sizeof(SPartEffectAttachments) == 0xB8, "SPartEffectAttachments has wrong size");
#pragma pack(pop)
#pragma pack(push, 8)
    struct SUsageEffectAttachments
    {
        SHashString usage;         //0000 - 0008
        struct Arrayeffect_indices
        {
            int32_t* m_Data;
            uint32_t m_Count;
        }effect_indices;         //0010 - 0018
    };
    static_assert(sizeof(SUsageEffectAttachments) == 0x20, "SUsageEffectAttachments has wrong size");
#pragma pack(pop)
#pragma pack(push, 8)
    struct SEffectAttachments
    {
        struct Arrayall_effects
        {
            SEffectAttachment* m_Data;
            uint32_t m_Count;
        }all_effects;         //0000 - 0008
        struct Arraypart_effects
        {
            SPartEffectAttachments* m_Data;
            uint32_t m_Count;
        }part_effects;         //0010 - 0018
        struct Arrayusage_effects
        {
            SUsageEffectAttachments* m_Data;
            uint32_t m_Count;
        }usage_effects;         //0020 - 0028
    };
    static_assert(sizeof(SEffectAttachments) == 0x30, "SEffectAttachments has wrong size");
#pragma pack(pop)
}