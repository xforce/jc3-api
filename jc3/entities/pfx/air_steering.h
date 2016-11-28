#pragma once

namespace jc3
{
#pragma pack(push, 4)
    struct SInputAxisTiming
    {
        float timeToMaxInputAtMinSpeed_s;         //0000 - 0004
        float timeToMaxInputAtMaxSpeed_s;         //0004 - 0008
        float centeringInputTimeFactor;         //0008 - 000C
        float counterInputTimeFactor;         //000C - 0010
    };
    static_assert(sizeof(SInputAxisTiming) == 0x10, "SInputAxisTiming has wrong size");
#pragma pack(pop)
#pragma pack(push, 4)
    struct SAirSteering
    {
        float max_steering_angle;         //0000 - 0004
        float acceleration_smoothing;         //0004 - 0008
        float roll_return;         //0008 - 000C
        float pitch_return;         //000C - 0010
        float referenceMinSpeedKPH;         //0010 - 0014
        float referenceMaxSpeedKPH;         //0014 - 0018
        SInputAxisTiming rollAxisTiming;         //0018 - 001C
        SInputAxisTiming pitchAxisTiming;         //0028 - 002C
        SInputAxisTiming yawAxisTiming;         //0038 - 003C
    };
    static_assert(sizeof(SAirSteering) == 0x48, "SAirSteering has wrong size");
#pragma pack(pop)
}