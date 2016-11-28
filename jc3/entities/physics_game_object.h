#pragma once

#include "pfx/pfx_game_object.h"
#include "game_object.h"

namespace jc3
{
#pragma pack(push, 1)
    class CPhysicsGameObject : public IPfxGameObject, public CGameObject
    {
    public:
        char pad2[0x60]; // 00D0 - 0150
        float DragCoefficient;
        float Mass;
        float LinearDamping;
        float AngularDamping;
        float GravityFactor;
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
        virtual void CPhysicsGameObject__Function11() = 0;
        virtual void CPhysicsGameObject__Function12() = 0;
        virtual void CPhysicsGameObject__Function13() = 0;
        virtual void CPhysicsGameObject__Function14() = 0;
        virtual void ActivatePhysics() = 0;
    };
#pragma pack(pop)

    static_assert(sizeof(CPhysicsGameObject) == 0x150, "Bad size for CPhysicsGameObject");
    static_assert(offsetof(CPhysicsGameObject, GravityFactor) == 0x140, "Bad size for CPhysicsGameObject");
}