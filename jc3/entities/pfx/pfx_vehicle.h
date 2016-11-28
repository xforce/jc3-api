#pragma once

#include "pfx_breakable.h"

#include "custom_land_global.h"
#include "brakes.h"
#include "suspension.h"
#include "land_aerodynamics.h"
#include "transmission.h"
#include "land_engine.h"
#include "motorbike_suspension.h"
#include "motorbike_steering.h"
#include "land_global.h"
#include "water_interaction.h"
#include "propellers.h"
#include "fins.h"
#include "rotors.h"
#include "driver_lean.h"
#include "air_global.h"
#include "air_engine.h"
#include "air_steering.h"
#include "air_audio.h"
#include "helicopter_model.h"
#include "helicopter_steering.h"
#include "boat_global.h"
#include "boat_steering.h"

namespace jc3
{
// TODO(xforce): Clean this up a bit
	struct SResourceCache;
	struct SResourceHandle
	{
		unsigned __int16 index;
		unsigned __int16 timestamp;
		void *resourceCache;
		void *userCtx;
	};

	template<typename T>
	struct TResourceCachePtr
	{
		SResourceHandle *handle;
	};

	struct CAdfStructPtrBase
	{
		struct SData
		{
			void *adfStruct;
			unsigned int adfStructTypeHash;
		};

		TResourceCachePtr<SData> ptr;
        virtual bool GetAdfResource(unsigned int path_hash, SResourceCache *rc) { return false; };
	};

	template <typename T>
	struct TAdfStructPtr : public CAdfStructPtrBase
	{
		T *data;
	};

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

#pragma pack(push,1)
	struct hkVector4f
	{
		float x, y, z, w;
	};
#pragma pack(pop)

#pragma pack(push, 0x10)
	struct SWheelSuspensionConstant
	{
		hkVector4f hardpointOffset;
		hkVector4f hardpointLocal;
		hkVector4f directionLocal;
		float suspensionForceMagnitudeAtRest_N;
		float suspensionLengthAtRest_m;
		SSuspensionAxis *suspensionProperties;
    };
    static_assert(sizeof(SWheelSuspensionConstant) == 0x40, "SWheelSuspensionConstant has wrong size");
#pragma pack(pop)

    class CPfxVehicle : public CPfxBreakable
    {
    public:
        char pad_0370[0x7C];                                    // 0370 - 03EC
        float topSpeed;                                         // 03EC - 03F0
        char pad_03F0[0x210];                                   // 03F0 - 0600
        TAdfStructPtr<SLandAerodynamics> landAerodynamicsResourceCachePtr;
        TAdfStructPtr<SLandAerodynamics> landAerodynamicsAIResourceCachePtr;
		SLandAerodynamics * landAerodynamics;                   // 0630 - 0638
        char pad_638[0x2D8];                                    // 0638 - 0910
        TAdfStructPtr<SWaterInteraction> waterInteractionResourceCachePtr;
        char pad_928[0x18];                                     // 0928 - 0940
        TAdfStructPtr<SPropellers> propellersResourceCachePtr;
        SPropellers *propellersProperties;
        char pad_960[0x240];                                    // 0960 - 0BA0
        TAdfStructPtr<SFins> finsResourceCachePtr;
        SFins *finsProperties;
        char pad_0BC0[0x378];                                   // 0BC0 - 0F38
        TAdfStructPtr<SRotors> rotorsResourceCachePointer;
        SRotors *rotorProperties;
        char pad_0F58[0x530];                                   // 0F58 - 1488
        CAdfStructPtrBase landSteeringResourceCachePtr;
        CAdfStructPtrBase landSteeringAIResourceCachePtr;
        char pad_14A8[0x70];                                    // 14A8 - 1518
        TAdfStructPtr<SDriverLean> driverLeanResourceCachePtr;
        SDriverLean *driverLeanProperties;
        char pad_1538[0x78];                                    // 1538 - 15B0
        hkArrayBase<WheelInfo> wheelInfo;                       // 15B0 - 15C0
        char pad_15C0[0x6B0];                                   // 15C0 - 1C70
		SWheelSuspensionConstant wheelSuspensionConstants[16];  // 1C70 - 2070
        char pad_2070[0x100];                                   // 2070 - 2170
        int numberOfWheelSuspensions;                           // 2170 - 2174
        char pad_2174[0x3C];                                    // 2174 - 21B0

        void ApplyAirSteering(SAirSteering &airSteering) {
            util::hooking::func_call<void>(0x1434C8550, this ,&airSteering);
        }

        void ApplyAirEngine(SAirEngine &airEngine) {
            util::hooking::func_call<void>(0x1434AD2C0, this, &airEngine);
        }
        void ApplyAirEngine(SAirAudio &airAudio) {
            util::hooking::func_call<void>(0x1448509B0, this, &airAudio);
        }
    };
    static_assert(sizeof(CPfxVehicle) == 0x21B0, "CPfxVehicle has wrong size");
    static_assert(offsetof(CPfxVehicle, wheelInfo) == 0x15B0, "CPfxVehicle is broken! wheelInfo");
    static_assert(offsetof(CPfxVehicle, rotorProperties) == 0xF50, "CPfxVehicle is broken! rotorProperties");
    

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


    struct BrakesState
    {
        float brakingTorque[16];
        bool wheelIsLocked[16];
        float unknown1;
        float highestBrakeTorqueNormalized;
        float relatedToBurnout;
    };
    static_assert(sizeof(BrakesState) == 0x5C, "BrakesState has wrong size");

    const struct GravityModifiers
    {
        float unknown[3];
        float gravityMultiplierGrounded;
        float someGravityMultiplier;
        float someGravityMultiplier2;
        float unknown2;
        // Some other stuff
    };

#pragma pack(push, 0x10)
    class CPfxCar : public CPfxVehicle
    {
    public:
        SBrakes *brakesProperties;
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
        TAdfStructPtr<SLandGlobal> landGlobalResourceCachePtr;
        TAdfStructPtr<SLandGlobal> landGlobalAIResourceCachePtr;
        TAdfStructPtr<SLandEngine> landEngineResourceCachePtr;
        TAdfStructPtr<STransmission> transmissionResourceCachePtr;
        TAdfStructPtr<SSuspension> suspensionResourceCachePtr;
        TAdfStructPtr<SBrakes> brakesResourceCachePtr;
        TAdfStructPtr<SBrakes> brakesAIResourceCachePtr;
    };
    static_assert(offsetof(CPfxCar, topSpeedKph) == 0x2394, "Nope");
    static_assert(sizeof(CPfxCar) == 0x2450, "CPfxCar has wrong size");
#pragma pack(pop)


    class CPfxMotorBike : public CPfxCar
    {
	public:
		float leanNormalized;
		float maxLeanAtCurrentSpeed_Deg;
		float reversingTorque;
		float leanInput;
		float wheelieNormalized;
		float maxLeanToWheelie_Rad;
		float wheelieTorque;
		float nosieTorque;
		float wheelieDeadZone;
		float rollAnimationEaseT;
		float rollAnimationBlendSpeed;
		char pad[0x74];
		TAdfStructPtr<SMotorbikeSuspension> motorbikeSuspensionResourceCachePtr;
		TAdfStructPtr<SMotorbikeSteering> motorbikeSteeringResourceCachePtr;
		TAdfStructPtr<SMotorbikeSteering> motorbikeSteeringAIResourceCachePtr;

        void ApplyMotorbikeSteering(SMotorbikeSteering &steering) {
            util::hooking::func_call<void>(0x1434F3D20, this, &steering);
        }
    };

    class CPfxAirSteering
    {

    };

    class CPfxAirVehicle : public CPfxVehicle
    {
    public:
        TAdfStructPtr<SAirGlobal> airGlobalResourceCachePtr;
        SAirGlobal *airGlobal;
        TAdfStructPtr<SAirEngine> airEngineResourceCachePtr;
        TAdfStructPtr<SSuspension> airSuspensionResourceCachePtr;
        char pad_2200[0x90];
    };
    static_assert(sizeof(CPfxAirVehicle) == 0x2290, "CPfxAirVehicle has wrong size");

    class CPfxAirPlane : public CPfxAirVehicle
    {
    public:
        TAdfStructPtr<SAirSteering> airSteeringResourceCachePtr;
        TAdfStructPtr<SAirAudio> airAudioResourceCachePtr;
        char pad_5580[0x5670 - 0x5580];
    };

    class CPfxHelicopter : public CPfxAirVehicle
    {
    public:
        char pad_2290[0x350]; // 2290 - 25E0
        TAdfStructPtr<SHelicopterModel> helicopterModelResourceCachePointer;
        SHelicopterModel aIModelData;
        SHelicopterModel playerModelData;
        TAdfStructPtr<SHelicopterSteering> helicopterSteeringResourceCachePtr;
    };

    class CPfxBoat : public CPfxVehicle
    {
    public:
        char pad_21B0[0x90]; // 21B0 - 2240
        TAdfStructPtr<SBoatGlobal> boatGlobalResourceCachePtr;
        SBoatGlobal *boatGlobal;
        TAdfStructPtr<SBoatSteering> boatSteeringResourceCachePtr;
        SBoatSteering *boatSteering;
    };
};