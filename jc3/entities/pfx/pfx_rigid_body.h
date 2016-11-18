#pragma once

#include "pfx_instance.h"

namespace jc3
{
    class CPfxRigidBody : public IPfxInstance
    {
    public:
        char pad[0x88];
    }; // 0xC0
}