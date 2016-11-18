#pragma once

#include "physics_game_object.h"

namespace jc3
{
#pragma pack(push, 1)
    class IOverridableEffectAttachment
    {
    public:
        virtual ~IOverridableEffectAttachment() = 0;
        virtual void IOverridableEffectAttachment__Function001() = 0; /* We need this for multiple inheritance to work */
    };

    class CDamageable : public CPhysicsGameObject, public IOverridableEffectAttachment
    {
    public:
        char pad3[0x110]; // 0158 - 0x268

        virtual void CDamageable_Function01() = 0;
        virtual void CDamageable_Function02() = 0;
        virtual void SetHealth(int16_t health, void* unknown) = 0;
        virtual int16_t GetHealth() = 0;
        virtual bool CDamageable_Function05() = 0;
        virtual void CDamageable_Function06() = 0;
        virtual void CDamageable_Function07() = 0;
        virtual void CDamageable_Function08() = 0;
        virtual void CDamageable_Function09() = 0;
        virtual void CDamageable_Function10() = 0;
    };
#pragma pack(pop)

    static_assert(sizeof(CDamageable) == 0x268, "Bad size for CDamageable");
}