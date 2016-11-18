#pragma once

#include "entities/CNetworkPlayer.h"

#include <cstdint>

namespace jc3
{
    class CNetworkPlayerManager
    {
    public:

        CNetworkPlayer * GetLocalNetworkPlayer() {
            static auto networkPlayerManager = 0x142F36958;
            return *(CNetworkPlayer **)(*(uintptr_t*)networkPlayerManager + 0x48);
        }
    };
}