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
        char pad[0x58];						// 0158 - 01B0
        int16_t maxHealth;					// 01B0 - 01B2
        int16_t minHealth;					// 01B2 - 01B4
        char pad2[0x7A];					// 01B4 - 022E
        bool destroyed;						// 022E - 022F
        bool invulnerable;					// 022F - 0230
        bool m_UnkownBool1;	        		// 0230 - 0231
        char alignment[1];					// 0231 - 0232
        int16_t curHealth;					// 0232 - 0234
        int16_t lastHealth;					// 0234 - 0236
        char pad4[0x32];					// 0262 - 0258

        virtual void CDamageable_Function01() = 0;
        virtual void CDamageable_Function02() = 0;
        virtual void SetHealth(int16_t health, void* unknown) = 0;
        virtual int16_t GetHealth() = 0;
        virtual bool IsDestroyed() = 0;
        virtual void CDamageable_Function06() = 0;
        virtual void CDamageable_Function07() = 0;
        virtual void CDamageable_Function08() = 0;
        virtual void CDamageable_Function09() = 0;
        virtual void CDamageable_Function10() = 0;

        void SetInvulnerable(bool invulnerable)
        {
            invulnerable = invulnerable;
        }

        bool IsInvulnerable()
        {
            return invulnerable;
        }
    };
#pragma pack(pop)

    static_assert(sizeof(CDamageable) == 0x268, "Bad size for CDamageable");
}
