#include "CCharacter.h"

using namespace jc3;

jc3::CCharacter* jc3::CCharacter::GetLocalPlayerCharacter()
{
    return util::hooking::func_call<CCharacter*>(0x143AD7B70);
}