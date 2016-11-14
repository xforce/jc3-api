#pragma once

#include <jc3_hooking/hooking.h>

#include "CDamageable.h"

#include <cstddef>

namespace jc3
{
#pragma pack(push, 1)
    class CCharacter;

    class CInteractionContext : public CGameObject
    {
    };

    class CInteractionGraph
    {
    public:
        char pad[0x60];							// 0010 - 0050
        CInteractionContext *Context;	// 0060 - 0068
        char pad4[0x210];						// 0194 - 0278
    };
    static_assert(offsetof(CInteractionGraph, Context) == 0x60, "FUck you");

    class CInteractionUserProxy
    {
    public:
        CCharacter *Character;										// 0008 - 0010
        CInteractionGraph *Graph;								// 0010 - 0018
        char pad[0x230];
    public:
        virtual ~CInteractionUserProxy();
    };
    static_assert(sizeof(CInteractionUserProxy) == 0x248, "Bad size for jc3::CInteractionUserProxy");

    class IPfxCharacter
    {
    public:
        virtual ~IPfxCharacter() = 0;
        virtual CCharacter* GetPfxGameObject() = 0;
    };

    class IAttachedEffectParameterProvider
    {
    public:
        virtual ~IAttachedEffectParameterProvider() = 0;
    };

    class CAttachedEffectContainer : public IAttachedEffectParameterProvider
    {
    public:
        virtual ~CAttachedEffectContainer() = 0;
    };

    class CCombinedAttachedEffectContainer : public CAttachedEffectContainer
    {
    public:
        virtual ~CCombinedAttachedEffectContainer() = 0;
        virtual void CCombinedAttachedEffectContainer__Function001() = 0; /* We need this for multiple inheritance to work */

        char pad[0xB8];
    };

    class CCharacter : public CDamageable, public IPfxCharacter, public CCombinedAttachedEffectContainer
    {
    public:
        char pad[0x650];
        char pad2[0x1088];
        CInteractionUserProxy InteractionUserProxy; // 0x1A08

        CGameObject* GetVehicle()
        {
            auto graph = InteractionUserProxy.Graph;
            if (graph && graph->Context && graph->Context->_parent.lock())
                return graph->Context->_parent.lock().get();

            return nullptr;
        }

        bool IsInVehicle()
        {
            auto graph = InteractionUserProxy.Graph;
            if (graph && graph->Context && graph->Context->_parent.lock())
                return true;

            return false;
        }

        static CCharacter* GetLocalPlayerCharacter();
    };
    static_assert(offsetof(CCharacter, InteractionUserProxy) == 0x1A08, "CCharacter is broken! InteractionUserProxy");
};