#pragma once

#include <boost/weak_ptr.hpp>

#include "../math/Matrix.h"

namespace jc3
{
#pragma pack(push, 1)
    namespace NEvent
    {
        class CEventImpl
        { };

        struct CEventBase
        {
            //CEventImpl **EventImpl;
            char pad[4];
        };

        struct CSendEvent
        {
            CEventBase Impl;
        };

        struct CReceiveEvent
        {
            CEventBase Impl;
        };

        class CEventHandler
        {
        public:
            char pad[0x8];

        public:
            virtual ~CEventHandler() {};
            virtual void HandleEvent(NEvent::CEventImpl const * event, void * data) {};
        };
    }

    class CRtti
    {
    public:
        virtual ~CRtti() = 0;
    };

    class CGameObject : public CRtti, public NEvent::CEventHandler
    {
    public:
        char pad[0x48];
        boost::weak_ptr<CGameObject> _selfWeak;	// 0060 - 0070
        boost::weak_ptr<CGameObject> _parent;	// 0070 - 0080
        char pad2[0x48];	                    // 0080 - 00C8
    public:
        virtual ~CGameObject() = 0;
        virtual int32_t* GetTypeId() = 0;
        virtual bool IsType(int32_t*) = 0;
        virtual uint32_t GetClassHash() = 0;
        virtual void CGameObject__Function04() = 0;
        virtual void CGameObject__Function05() = 0;
        virtual void CGameObject__Function06() = 0;
        virtual void CGameObject__Function07() = 0;
        virtual void CGameObject__Function08() = 0;
        virtual void CGameObject__Function09() = 0;
        virtual void CGameObject__Function10() = 0;
        virtual void CGameObject__Function11() = 0;
        virtual void CGameObject__Function12() = 0;
        virtual void CGameObject__Function13() = 0;
        virtual void CGameObject__Function14() = 0;
        virtual void CGameObject__Function15() = 0;
        virtual void CGameObject__Function16() = 0;
        virtual void CGameObject__Function17() = 0;
        virtual void CGameObject__Function18() = 0;
        virtual void CGameObject__Function19() = 0;
        virtual void GetTransform(Matrix *) = 0;
        virtual void CGameObject__Function21() = 0;
        virtual void CGameObject__Function22() = 0;
        virtual void CGameObject__Function23() = 0;
        virtual void CGameObject__Function24() = 0;
        virtual void CGameObject__Function25() = 0;
        virtual void CGameObject__Function26() = 0;
        virtual void CGameObject__Function27() = 0;
        virtual void CGameObject__Function28() = 0;
        virtual void CGameObject__Function29() = 0;
        virtual void CGameObject__Function30() = 0;
        virtual void CGameObject__Function31() = 0;
        virtual void CGameObject__Function32() = 0;
        virtual void CGameObject__Function33() = 0;
        virtual void CGameObject__Function34() = 0;
        virtual void CGameObject__Function35() = 0;
        virtual void CGameObject__Function36() = 0;
        virtual void CGameObject__Function37() = 0;
        virtual void CGameObject__Function38() = 0;
        virtual void CGameObject__Function39() = 0;
        virtual void CGameObject__Function40() = 0;
        virtual void CGameObject__Function41() = 0;
        virtual void CGameObject__Function42() = 0;
        virtual void CGameObject__Function43() = 0;

		uint32_t GetNameHash();

        // TODO(xforce): move this to somewhere where it makes sense
        static int32_t* GetClassIdByName(const std::string &name);
    };
#pragma pack(pop)
}