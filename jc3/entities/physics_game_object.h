#pragma once

#include "pfx/pfx_game_object.h"
#include "game_object.h"

namespace jc3
{
#pragma pack(push, 1)
    struct SCollisionInfo;
    class CDamageMsg {
    public:
        char pad[0xC0];  // 0008 - 00C8

        virtual ~CDamageMsg() = 0;
    };

    class CPhysicsGameObject : public IPfxGameObject, public CGameObject
    {
    public:
        char pad2[0x60]; // 00D0 - 0150
        float dragCoefficient;
        float mass;
        float linearDamping;
        float angularDamping;
        float gravityFactor;
        char pad3[0xC]; // 00D0 - 0150

    public:
        virtual ~CPhysicsGameObject() = 0;
        virtual void CPhysicsGameObject__Function01() = 0;
        virtual void CPhysicsGameObject__Function02() = 0;
        virtual void CPhysicsGameObject__Function03() = 0;
        virtual void CPhysicsGameObject__Function04() = 0;
        virtual void CPhysicsGameObject__Function05() = 0;
        virtual void CPhysicsGameObject__Function06() = 0;
        virtual void CPhysicsGameObject__Function07() = 0;
        virtual void CPhysicsGameObject__Function08() = 0;
        virtual void CPhysicsGameObject__Function09() = 0;
        virtual void CPhysicsGameObject__Function10() = 0;
        virtual void OnCollision(SCollisionInfo const *) = 0;
        virtual void OnDamage(CDamageMsg &) = 0;
        virtual void IsDamageable() = 0;
        virtual void GetDragCoefficient() = 0;
        virtual void ActivatePhysics() = 0;
    };
#pragma pack(pop)
    static_assert(sizeof(CDamageMsg) == 0xC8, "CDamageMsg has wrong size");

    static_assert(sizeof(CPhysicsGameObject) == 0x150, "Bad size for CPhysicsGameObject");
    static_assert(offsetof(CPhysicsGameObject, gravityFactor) == 0x140, "Bad size for CPhysicsGameObject");
}
