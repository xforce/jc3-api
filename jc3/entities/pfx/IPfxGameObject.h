#pragma once

#include <cstdint>

namespace jc3
{
    class IPfxInstance;
    struct SObjectID;
    class IPfxGameObject
    {
    public:
        virtual ~IPfxGameObject() = 0;
        virtual IPfxInstance* GetPfxInstance() = 0;
        virtual void IPfxGameObject__Function02() = 0;
        virtual void IPfxGameObject__Function03() = 0;
        virtual void GetGameObjectId(SObjectID* result) = 0;
        virtual int32_t* GetTypeId() = 0;
        virtual bool IPfxGameObject__Function06() = 0;
        virtual bool IPfxGameObject__Function07() = 0;
        virtual void IPfxGameObject__Function08() = 0;
    };
}