#pragma once

#include "CDamageable.h"
#include "pfx/CPfxVehicle.h"

namespace jc3
{
#pragma pack(push, 1)
    class CVehicle : public CDamageable
    {
    public:
        char pad[0x4B68];           // 0268 - 4DD0
        CPfxVehicle *PfxVehicle;	// 4DD0 - 4DD8
    };
#pragma pack(pop)
}