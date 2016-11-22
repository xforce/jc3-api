#pragma once

namespace jc3
{
#pragma pack(push, 4)
    struct SBoatPerformanceBoost
    {
        float prop_torque_multiplier;         //0000 - 0004
        float prop_rpm_multiplier;         //0004 - 0008
        float extra_top_speed;         //0008 - 000C
    };
    static_assert(sizeof(SBoatPerformanceBoost) == 0xC, "SBoatPerformanceBoost has wrong size");
#pragma pack(pop)
#pragma pack(push, 4)
    struct SBoatTurboJump
    {
        float up_multiplier;         //0000 - 0004
        float punch_delay_time;         //0004 - 0008
        float punch_speed_kph;         //0008 - 000C
        float top_speed_kph;         //000C - 0010
        float top_speed_jump_multiplier;         //0010 - 0014
    };
    static_assert(sizeof(SBoatTurboJump) == 0x14, "SBoatTurboJump has wrong size");
#pragma pack(pop)
#pragma pack(push, 4)
    struct SBoatGlobal
    {
        SBoatPerformanceBoost heat_boost;         //0000 - 0004
        SBoatPerformanceBoost nitro_boost;         //000C - 0010
        SBoatPerformanceBoost nitro_boost_upgraded;         //0018 - 001C
        SBoatTurboJump turbo_jump;         //0024 - 0028
        SBoatTurboJump turbo_jump_upgraded;         //0038 - 003C
    };
    static_assert(sizeof(SBoatGlobal) == 0x4C, "SBoatGlobal has wrong size");
#pragma pack(pop)
}