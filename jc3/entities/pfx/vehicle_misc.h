#pragma once

#include <cstdint>

#include "../../hash_string.h"

namespace jc3
{
#pragma pack(push, 8)
    struct SVehicleDoor
    {
        SHashString door_behavior;         //0000 - 0008
        float open_door_duration_s;         //0010 - 0014
        float close_door_duration_s;         //0014 - 0018
    };
    static_assert(sizeof(SVehicleDoor) == 0x18, "SVehicleDoor has wrong size");
#pragma pack(pop)
#pragma pack(push, 4)
    struct SPatchProvision
    {
        float value_0;         //0000 - 0004
        float value_1;         //0004 - 0008
        float value_2;         //0008 - 000C
        float value_3;         //000C - 0010
        float value_4;         //0010 - 0014
        float value_5;         //0014 - 0018
        float value_6;         //0018 - 001C
        float value_7;         //001C - 0020
        float value_8;         //0020 - 0024
        float value_9;         //0024 - 0028
        float value_10;         //0028 - 002C
        float value_11;         //002C - 0030
        float value_12;         //0030 - 0034
        float value_13;         //0034 - 0038
        float value_14;         //0038 - 003C
        float value_15;         //003C - 0040
        float value_16;         //0040 - 0044
        float value_17;         //0044 - 0048
        float value_18;         //0048 - 004C
        float value_19;         //004C - 0050
    };
    static_assert(sizeof(SPatchProvision) == 0x50, "SPatchProvision has wrong size");
#pragma pack(pop)
#pragma pack(push, 8)
    struct SVehicleMisc
    {
        float open_door_duration_s;         //0000 - 0004
        float close_door_duration_s;         //0004 - 0008
        struct Arraydoors
        {
            SVehicleDoor* m_Data;
            uint32_t m_Count;
        }doors;         //0008 - 0010
        float official_top_speed;         //0018 - 001C
        float full_nitro_refill_time;         //001C - 0020
        float nitro_refill_min_speed_kph;         //0020 - 0024
        float full_nitro_use_time;         //0024 - 0028
        float full_nitro_use_time_upgraded;         //0028 - 002C
        float turbo_jump_cooldown;         //002C - 0030
        float turbo_jump_cooldown_upgraded;         //0030 - 0034
        float max_landing_speed_kmph;         //0034 - 0038
        float max_take_off_speed_kmph;         //0038 - 003C
        float max_tilt_to_land_deg;         //003C - 0040
        SPatchProvision patch_provision;         //0040 - 0044
    };
    static_assert(sizeof(SVehicleMisc) == 0x90, "SVehicleMisc has wrong size");
#pragma pack(pop)

}