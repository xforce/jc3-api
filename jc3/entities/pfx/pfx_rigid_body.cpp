#include "pfx_rigid_body.h"

#include <jc3_hooking/hooking.h>

using namespace jc3;

void CPfxRigidBody::ApplyForce(float dt, Vector3f *force)
{
    util::hooking::func_call<void>(0x143644520, this, dt, force);
}
