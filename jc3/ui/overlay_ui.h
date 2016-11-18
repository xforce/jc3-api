#pragma once

#include <cstdint>
#include <jc3_hooking/hooking.h>

namespace jc3
{
    class COverlayUI
    {
    public:
        static void ShowCursor() {
            auto overlayInstance = *(uintptr_t*)(0x142F38858);
            util::hooking::func_call<void>(0x14470FE60, overlayInstance);
        }

        static void HideCursor() {
            auto overlayInstance = *(uintptr_t*)(0x142F38858);
            util::hooking::func_call<void>(0x14470FE10, overlayInstance);
        }
	};
}