#pragma once

#include "IPfxInstance.h"

namespace jc3
{
    class CPfxRigidBody : public IPfxInstance
    {
    public:
        char pad[0x88];
    }; // 0xC0
}