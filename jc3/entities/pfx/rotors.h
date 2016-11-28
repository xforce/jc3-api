#pragma once

#include <cstdint>

#include "../../hash_string.h"

namespace jc3
{
#pragma pack(push, 8)
    struct SRotor
    {
        SHashString physics_component_name;         //0000 - 0008
        float position[3];         //0010 - 0014
        float axis[3];         //001C - 0020
        int32_t does_steer;         //0028 - 002C
        float rotation_speed;         //002C - 0030
        float torque;         //0030 - 0034
    };
    static_assert(sizeof(SRotor) == 0x38, "SRotor has wrong size");
#pragma pack(pop)
#pragma pack(push, 8)
    struct SRotors
    {
        float max_rpm;         //0000 - 0004
        float acceleration_rpm;         //0004 - 0008
        float acceleration_multiplier;         //0008 - 000C
        float deceleration_multiplier;         //000C - 0010
        float deceleration_freespin_multiply;         //0010 - 0014
        float thrust_smoothing;         //0014 - 0018
        float freespin_control;         //0018 - 001C
        struct Arrayrotors
        {
            SRotor* m_Data;
            uint32_t m_Count;
        }rotors;         //0020 - 0028
    };
    static_assert(sizeof(SRotors) == 0x30, "SRotors has wrong size");
#pragma pack(pop)

#pragma pack(push, 8)
    class CPfxVehicle;
    struct CPfxAirPropulsion
    {
        char pad_00[0xB0];
        int numRotors;
        float rotorRpm;
        float rotorMaxRpm;
        float rotorAccelerationRpm;
        float rotorAccelerationMultiplier;
        float rotorDeaccelerationMultiplier;
        float rotorDeaccelerationFreeSpinMultiplier;
        float rotorFreeSpinControl;
        float thrustSmooth;
        float thrust;
        char useSmooth;
        CPfxVehicle *pfxVehicle;
        SRotors *rotorProperties;
    };
    static_assert(sizeof(CPfxAirPropulsion) == 0xF0, "CPfxAirPropulsion has wrong size");
#pragma pack(pop)
}