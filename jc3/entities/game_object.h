#pragma once

#include <boost/weak_ptr.hpp>
#include <stl/vector>

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
        boost::weak_ptr<CGameObject> selfWeak;	                        // 0060 - 0070
        boost::weak_ptr<CGameObject> parent;	                        // 0070 - 0080
        stl::vector<boost::shared_ptr<CGameObject>> children;			// 0080 - 0098
        char pad2[0x30];	                                            // 0098 - 00C8
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
        virtual void SetTransform(Matrix* world_matrix) = 0;
        virtual Matrix GetTransform(Matrix* t1) = 0;
        virtual bool GetTransform2(Matrix* t) = 0;
        virtual Matrix GetPreviousTransform(Matrix* t0) = 0;
        virtual bool GetPreviousTransform2(Matrix* t) = 0;
        virtual Matrix* GetLocalTransform() = 0;
        virtual void SetLocalTransform(Matrix* T) = 0;
        virtual void CGameObject__Function26() = 0;
        virtual void CGameObject__Function27() = 0;
        virtual bool GetRenderTransform(Matrix* m, float dft) = 0;
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

    static_assert(sizeof(CGameObject) == 0xC8, "Bad size for CGameObject");
    static_assert(offsetof(CGameObject, parent) == 0x70, "CGameObject is broken! m_Parent");
}
