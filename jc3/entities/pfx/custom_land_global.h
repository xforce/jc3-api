#pragma once

#include <cstdint>

namespace jc3
{
#pragma pack(push, 4)
    struct SWheelDamage
    {
        int32_t skew_health;         //0000 - 0004
        float broken_wheel_friction_fraction;         //0004 - 0008
        float broken_wheel_radius_fraction;         //0008 - 000C
    };
    static_assert(sizeof(SWheelDamage) == 0xC, "SWheelDamage has wrong size");
#pragma pack(pop)
#pragma pack(push, 4)
    struct SDrift
    {
        float drift_entry_slip_angle;         //0000 - 0004
        float drift_exit_slip_angle;         //0004 - 0008
        float max_drift_angle_deg;         //0008 - 000C
        float drift_limit_spread_angle_deg;         //000C - 0010
        float constant_drift_torque;         //0010 - 0014
        float max_drift_torque;         //0014 - 0018
        float counter_steer_torque;         //0018 - 001C
        float counter_steer_torque_handbrake;         //001C - 0020
        float counter_steer_torque_brake;         //0020 - 0024
        float drift_yaw_vel_damp;         //0024 - 0028
        float overdrift_yaw_vel_damp;         //0028 - 002C
        float exit_drift_yaw_vel_damp;         //002C - 0030
        float velocity_rotation_start_angle;         //0030 - 0034
        float velocity_rotation_end_angle;         //0034 - 0038
        float velocity_rotation_amount;         //0038 - 003C
        float velocity_rotation_angle_exp;         //003C - 0040
        float counter_steer_rot_factor;         //0040 - 0044
        float steering_sensitivity;         //0044 - 0048
        float min_speed_to_drift_kmph;         //0048 - 004C
        float keep_velocity_strength;         //004C - 0050
        float max_keep_velocity_acceleration_g;         //0050 - 0054
    };
    static_assert(sizeof(SDrift) == 0x54, "SDrift has wrong size");
#pragma pack(pop)
#pragma pack(push, 4)
    struct SPerformanceBoost
    {
        float torque_multiplier;         //0000 - 0004
        float grip_multiplier;         //0004 - 0008
        float push_force;         //0008 - 000C
        float boost_blend_time;         //000C - 0010
        float extra_top_speed;         //0010 - 0014
    };
    static_assert(sizeof(SPerformanceBoost) == 0x14, "SPerformanceBoost has wrong size");
#pragma pack(pop)
#pragma pack(push, 4)
    struct STurboJump
    {
        float f_multiplier;         //0000 - 0004
        float r_multiplier;         //0004 - 0008
        float punch_delay_time;         //0008 - 000C
        float punch_speed_kph;         //000C - 0010
        float top_speed_kph;         //0010 - 0014
        float top_speed_jump_multiplier;         //0014 - 0018
    };
    static_assert(sizeof(STurboJump) == 0x18, "STurboJump has wrong size");
#pragma pack(pop)
#pragma pack(push, 4)
    struct SArcadePhysics
    {
        SPerformanceBoost heat_boost;         //0000 - 0004
        SPerformanceBoost nitro_boost;         //0014 - 0018
        SPerformanceBoost nitro_boost_upgraded;         //0028 - 002C
        STurboJump turbo_jump;         //003C - 0040
        STurboJump turbo_jump_upgraded;         //0054 - 0058
    };
    static_assert(sizeof(SArcadePhysics) == 0x6C, "SArcadePhysics has wrong size");
#pragma pack(pop)
#pragma pack(push, 4)
    struct SCustomLandGlobal
    {
        float linear_damping[3];         //0000 - 0004
        float gravity_multiplier_grounded;         //000C - 0010
        float gravity_multiplier_in_air_up;         //0010 - 0014
        float gravity_multiplier_in_air_down;         //0014 - 0018
        float takeoff_pitch_damping;         //0018 - 001C
        SWheelDamage front_wheels_damage;         //001C - 0020
        SWheelDamage rear_wheels_damage;         //0028 - 002C
        SDrift drift;         //0034 - 0038
        SArcadePhysics arcade;         //0088 - 008C
    };
    static_assert(sizeof(SCustomLandGlobal) == 0xF4, "SCustomLandGlobal has wrong size");
#pragma pack(pop)

}