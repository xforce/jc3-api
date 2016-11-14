#pragma once

#include "CPfxBreakable.h"

#include <boost/weak_ptr.hpp>

#include <cstdint>

namespace jc3
{
    class IResource
    {
    public:
        virtual ~IResource() = 0;
        virtual void IResource__Function001() = 0;
    };

    class IPfxInstance : IResource
    {
    public:
        boost::weak_ptr<IPfxInstance> _selfWeak;
        char _alignment[0x20];

    public:
        virtual ~IPfxInstance() = 0;
        virtual int64_t GetType() = 0;
    }; // 0x38

    static_assert(sizeof(IPfxInstance) == 0x38, "Bad size for IPfxInstance");
};