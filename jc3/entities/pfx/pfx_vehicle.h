#pragma once

#include "CPfxBreakable.h"

namespace jc3
{
    struct __declspec(align(16)) WheelInfo
    {
        char pad[0x150];
        float spinVelocity;
        float spinAngle;
        float sideForce;
        float forwardSlipVelocity;
        float sideSlipVelocity;
        float torque;
        float angularVelocity;
        float invInertia;
        float slipAngleDeg;
        float slipRatioSAE;
        float camberAngleDeg;
        float lateralTireForceOffset;
        float longitudinalTireForceOffset;
        float tireDragForceOffset;
        float wheelFrictionMultiplier;
        float wheelDragMultiplier;
        float burnoutFrictionMultiplier;
        float groundFrictionTorque;
        float unkown1;
        bool wasInAir;
        bool isConstrainedToGround;
        char pad2[0x43];
    };
    template<int s> struct Wow;

    static_assert(sizeof(WheelInfo) == 0x1F0, "Has wrong size");

    template<typename T>
    class hkArrayBase
    {
    public:
        T * Data;
        int size;
        int capacityAndFlags;
    };

    struct CarAerodynamics
    {
        float airDensity;
        float frontalArea;
        float dragCoefficient;
        float topSpeedDragCoefficient;
        float liftCoefficient;
    };

    struct Vector4f {
        float x, y, z, w;
    };

    const struct SuspensionProperties
    {
        float antiRollbarStrength;
        float compression;
        float no_idea[3];
        float length;
        float relaxation;
        float no_idea_2;
        float strength;
        float no_idea_3;
        float lateralTireForceOffset;
        float longitudinalTireForceOffse;
        float tireDragForceOffset;
        float hardpointOffsetOnSpring;
        float lengthRelated[2];
    };

    struct WheelSuspension
    {
        Vector4f hardpointOffset;
        Vector4f hardpointLocal;
        Vector4f directionLocal;
        float suspensionForceMagnitudeAtRest;
        float suspensionLengthAtRest;
        SuspensionProperties *suspensionProperties;
    };

    class CPfxVehicle : public CPfxBreakable
    {
    public:
        char pad_0370[0x7C];                             // 0370 - 03EC
        float topSpeed;                                  // 03EC - 03F0
        char pad_03F0[0x240];                            // 03F0 - 0630
        CarAerodynamics * carAerodynamics;               // 0630 - 0638
        char pad_638[0xF78];                             // 0638 - 15B0
        hkArrayBase<WheelInfo> wheelInfo;                // 15B0 - 15C0
        char pad_15C0[0x6B0];                            // 15C0 - 1C70
        WheelSuspension wheelSuspensions[16];            // 1C70 - 2070
        char pad_2070[0x100];                            // 2070 - 2170
        int numberOfWheelSuspensions;                    // 2170 - 2174
        char pad_2174[0x3C];                             // 2174 - 21B0
    };
    static_assert(sizeof(CPfxVehicle) == 0x21B0, "CPfxVehicle has wrong size");
    static_assert(offsetof(CPfxVehicle, wheelInfo) == 0x15B0, "CPfxVehicle is broken! wheelInfo");

    struct BrakeInfo
    {
        int handbrake;
        float maxTorque;
        float minTimeToBlock;
    };

    /* 13716 */
    const struct Brakes
    {
        BrakeInfo front;
        BrakeInfo rear;
        float handbrakeFrictionFactor;
    };

    struct BrakesState
    {
        float brakingTorque[16];
        bool wheelIsLocked[16];
        float unknown1;
        float highestBrakeTorqueNormalized;
        float relatedToBurnout;
    };

    static_assert(sizeof(BrakesState) == 0x5C, "BrakesState has wrong size");

    struct __declspec(align(4)) CLandVehicleEngine
    {
        char isClutching;
        char align1[0x3];
        float clutchDelay;
        float clutchingTime;
        float clutchAmount;
        float manualClutchEngageTimer;
        float sourceClutchRpm;
        float targetClutchRpm;
        float engineRevs;
        float engineDamage;
        float revLimiterMagnitudeRPM;
        char isRevLimiting;
        char align2[0x3];
        float fullLoadTorque;
        float lowestMaxTorque;
        float engineMinNoise;
        float engineDamageNoiseScale;
        float engineMaxDamageTorqueFactor;
        float minRPM;
        float optRPM;
        float maxTorque;
        float torqueFactorAtMinRPM;
        float torqueFactorAtMaxRPM;
        float resistanceFactorAtMinRPM;
        float resistanceFactorAtOptRPM;
        float resistanceFactorAtMaxRPM;
        float clutchSlipRPM;
        float maxRPM;
        float overdriveMaxRPM;
        bool isOverdriveActive;
        char align3[0x3];
    };

    static_assert(sizeof(CLandVehicleEngine) == 0x070, "CLandVehicleEngine has wrong size");

    /* 13719 */
    struct TransmissionProperties
    {
        hkArrayBase<float> downshiftRPMsPerGear;
        hkArrayBase<float> upshiftRPMsPerGear;
        char numNitrousGears;
        char numNormalGears;
        bool isReverseUsingForwardGears;
        char align1[0x1];
        float forwardTorqueRatio;
        float lowGearForwardTorqueRatio;
        float maxTransmissionRPM;
        float maxReversingTransmissionRPM;
        float targetCruiseRPM;
        float decayTimeToCruiseRPM;
        float lowGearingPrimaryTransmissionRatio;
        bool unknown1;
        bool hasManualClutch;
        char align2[0x2];
        float manualClutchBlendRpm;
        float manualClutchBlendTime;
        float downshiftRPM;
        float upshiftRPM;
        float primaryTransmissionRatio;
        float clutchDelayTime;
        float reverseGearRatio;
        hkArrayBase<float> gearsRatio;
        hkArrayBase<float> wheelsTorqueRatio;
    };

    /* 13720 */
    struct TransmissionState
    {
        float loadFactor;
        bool isLowGearing;
        char align1[0x3];
        float gearChangeWait;
        float lastTransmissionRPM;
        float unkown1;
        char lastGear;
        char align2[0x3];
        float transmissionRPM;
        float clutchRPM;
        float mainTransmittedTorque;
        float wheelsTransmittedTorque[16];
        bool isReversing;
        char currentGear;
        bool delayed;
        char align3[0x1];
        float clutchDelayCountdown;
    };

    /* 13721 */
    struct __declspec(align(8)) CLandVehicleTransmission
    {
        TransmissionProperties transmissionProperties;
        TransmissionState transmissionState;
        char align[0x4];
    };

    static_assert(sizeof(CLandVehicleTransmission) == 0xF0, "CLandVehicleTransmission has wrong size");

    const struct GravityModifiers
    {
        float unknown[3];
        float gravityMultiplierGrounded;
        float someGravityMultiplier;
        float someGravityMultiplier2;
        float unknown2;
        // Some other stuff
    };

    class CPfxCar : public CPfxVehicle
    {
    public:
        Brakes *brakesProperties;
        BrakesState brakesState;
        char align1[0x4];
        CLandVehicleEngine *landVehicleEngine;
        CLandVehicleTransmission *landVehicleTransmission;
        char tryingToReverse;
        char align2[0x3];
        float engineTorque;
        float engineRPM;
        char pad2[0x160 - 0x84];
        // 2310
        GravityModifiers * someGravityModifiers;
        char pad3[0x7C];
        float topSpeedKph; // 0x2394
        char pad4[0x10];
    };
    static_assert(offsetof(CPfxCar, topSpeedKph) == 0x2394, "Nope");

    class CPfxMotorBike : public CPfxVehicle
    {

    };
};