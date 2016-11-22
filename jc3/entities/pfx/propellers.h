#pragma once

#include <cstdint>

#include "../../hash_string.h"

#include "misc.h"

namespace jc3
{
#pragma pack(push, 4)
    struct SDockingControls
    {
        float optimal_docking_speed_ms;         //0000 - 0004
        float max_docking_speed_ms;         //0004 - 0008
        float max_docking_control_throttle;         //0008 - 000C
        float docking_yaw_throttle_limit;         //000C - 0010
    };
    static_assert(sizeof(SDockingControls) == 0x10, "SDockingControls has wrong size");
#pragma pack(pop)
#pragma pack(push, 4)
    struct SSteeringAngleLimits
    {
        float steer_left_angle_deg;         //0000 - 0004
        float steer_right_angle_deg;         //0004 - 0008
        uint8_t invert_steering_input;         //0008 - 0009
    };
    static_assert(sizeof(SSteeringAngleLimits) == 0xC, "SSteeringAngleLimits has wrong size");
#pragma pack(pop)
#pragma pack(push, 4)
    struct SDockingPropLimits
    {
        SSteeringAngleLimits docking_yaw_angles;         //0000 - 0004
        SSteeringAngleLimits docking_strafe_angles;         //000C - 0010
    };
    static_assert(sizeof(SDockingPropLimits) == 0x18, "SDockingPropLimits has wrong size");
#pragma pack(pop)
#pragma pack(push, 8)
    struct SPropeller
    {
        SHashString physics_component_name;         //0000 - 0008
        float hinge_position[3];         //0010 - 0014
        SEulerAngles hinge_angles;         //001C - 0020
        float trim_flattening_in_turns;         //0028 - 002C
        float distance_to_hinge;         //002C - 0030
        float min_angle_deg;         //0030 - 0034
        float max_angle_deg;         //0034 - 0038
        SDockingPropLimits docking_limits;         //0038 - 003C
        float zero_angle_deg;         //0050 - 0054
        uint8_t is_impeller;         //0054 - 0055
        float impeller_intake_position[3];         //0058 - 005C
    };
    static_assert(sizeof(SPropeller) == 0x68, "SPropeller has wrong size");
#pragma pack(pop)
#pragma pack(push, 8)
    struct SPropellers
    {
        float max_thrust;         //0000 - 0004
        float max_rpm;         //0004 - 0008
        float max_reverse_rpm;         //0008 - 000C
        float diameter;         //000C - 0010
        float pitch;         //0010 - 0014
        SDockingControls docking_controls;         //0014 - 0018
        SSpline5 thrust_vs_advance_ratio;         //0024 - 0028
        SSpline5 max_steering_vs_speed_ms;         //0074 - 0078
        SSpline5 trim_deg_vs_speed_ms;         //00C4 - 00C8
        SPropeller propellers[2];         //0118 - 0120
        uint8_t number_of_propellers;         //01E8 - 01E9
    };
    static_assert(sizeof(SPropellers) == 0x1F0, "SPropellers has wrong size");
#pragma pack(pop)
}