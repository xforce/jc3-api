#pragma once

#include "pfx_rigid_body.h"

namespace jc3
{
    class CPfxBreakable : public CPfxRigidBody
    {
    public:
        char pad[0x2B0]; // 00C0 - 0370
    }; // 0x370
}