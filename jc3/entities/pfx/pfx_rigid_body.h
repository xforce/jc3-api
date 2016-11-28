#pragma once

#include "pfx_instance.h"
#include "../../math/Matrix.h"

namespace jc3
{
    class CPfxRigidBody : public IPfxInstance
    {
    public:
        char pad[0x88];

        void ApplyForce(float dt, Vector3f *force);
    }; // 0xC0
}