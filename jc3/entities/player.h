#pragma once

#include <boost/shared_ptr.hpp>

#include "game_object.h"
#include "character.h"

namespace jc3
{
    class CAvatar
    {
    public:
        virtual void SetActionMap(void *action_map) {};

        char pad_008[0x80];
    };

    class CPlayer : public NEvent::CEventHandler, public CAvatar
    {
        char pad1[0x78];												// 0098 - 0108
        CCharacter *character;										// 0110 - 0118
        char pad2[0x28];												// 0118 - 0140
        boost::shared_ptr<CGameObject> character_sp;					// 0140 - 0150
        void *behaviorTreeAvatar;										// 0150 - 0158
        void *aimControl;								                // 0158 - 0160
    };
}