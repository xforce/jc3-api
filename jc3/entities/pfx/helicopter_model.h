#pragma once

namespace jc3
{
#pragma pack(push, 4)
    struct SHelicopterModel
    {
        float center_of_torques_x;         //0000 - 0004
        float center_of_torques_y;         //0004 - 0008
        float center_of_torques_z;         //0008 - 000C
        float altitude_input_power;         //000C - 0010
        float yaw_input_power;         //0010 - 0014
        float pitch_input_power;         //0014 - 0018
        float roll_input_power;         //0018 - 001C
        float pitch_input_dead_zone;         //001C - 0020
        float t_to_full_yaw_s;         //0020 - 0024
        float max_speed_t_to_full_yaw_s;         //0024 - 0028
        float bank_start_velocity_kmph;         //0028 - 002C
        float bank_max_velocity_kmph;         //002C - 0030
        float min_speed_dive_kmph;         //0030 - 0034
        float max_speed_dive_kmph;         //0034 - 0038
        float add_dive_pitch_deg;         //0038 - 003C
        float add_climb_pitch_deg;         //003C - 0040
        float max_roll_input_for_climb;         //0040 - 0044
        float climb_speed_low_speed_kmph;         //0044 - 0048
        float dive_speed_low_speed_kmph;         //0048 - 004C
        float min_altitude_input;         //004C - 0050
        float unsettled_altitude_gain_climb;         //0050 - 0054
        float unsettled_altitude_gain_dive;         //0054 - 0058
        float max_diving_gs;         //0058 - 005C
        float max_climbing_gs;         //005C - 0060
        float add_force_forward_power;         //0060 - 0064
        float add_force_lateral_power;         //0064 - 0068
        float trim_input_gain;         //0068 - 006C
        float forward_drag;         //006C - 0070
        float lateral_drag;         //0070 - 0074
        float vertical_drag;         //0074 - 0078
        float tail_lateral_drag;         //0078 - 007C
        float tail_vertical_drag;         //007C - 0080
        float angular_drag;         //0080 - 0084
        float low_speed_max_drag_yaw_speed;         //0084 - 0088
        float high_speed_max_drag_yaw_speed;         //0088 - 008C
        float yaw_drag_no_input;         //008C - 0090
        float forward_drag_no_input;         //0090 - 0094
        float lateral_drag_no_input;         //0094 - 0098
        float vertical_drag_no_input;         //0098 - 009C
        float tail_distance_to_com_m;         //009C - 00A0
        float add_forward_force;         //00A0 - 00A4
        float add_right_force;         //00A4 - 00A8
        float add_lateral_factor_pull_up;         //00A8 - 00AC
        float max_roll_deg;         //00AC - 00B0
        float add_bank_roll_deg;         //00B0 - 00B4
        float add_bank_roll_pull_up_deg;         //00B4 - 00B8
        float max_pitch_low_speed_deg;         //00B8 - 00BC
        float max_pitch_high_speed_deg;         //00BC - 00C0
        float counter_pitch_angle_deg;         //00C0 - 00C4
        float counter_pitch_speed_kmph;         //00C4 - 00C8
        float roll_p;         //00C8 - 00CC
        float roll_i;         //00CC - 00D0
        float roll_d;         //00D0 - 00D4
        float roll_max_amplitude;         //00D4 - 00D8
        float pitch_p;         //00D8 - 00DC
        float pitch_i;         //00DC - 00E0
        float pitch_d;         //00E0 - 00E4
        float pitch_max_amplitude;         //00E4 - 00E8
        float yaw_p;         //00E8 - 00EC
        float yaw_i;         //00EC - 00F0
        float yaw_d;         //00F0 - 00F4
        float yaw_max_amplitude;         //00F4 - 00F8
        float low_speed_altitude_p;         //00F8 - 00FC
        float low_speed_altitude_i;         //00FC - 0100
        float low_speed_altitude_d;         //0100 - 0104
        float high_speed_altitude_p;         //0104 - 0108
        float high_speed_altitude_i;         //0108 - 010C
        float high_speed_altitude_d;         //010C - 0110
        float altitude_limit_threshold_low;         //0110 - 0114
        float altitude_limit_threshold_high;         //0114 - 0118
    };
    static_assert(sizeof(SHelicopterModel) == 0x118, "SHelicopterModel has wrong size");
#pragma pack(pop)
}