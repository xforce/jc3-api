#include "game_object.h"

#include <unordered_map>
#include <string>
#include <cstdint>

#include <jc3_hooking/hooking.h>

using namespace jc3;

static std::unordered_map<std::string, int32_t> _classIds;

int32_t* CGameObject::GetClassIdByName(const std::string &name)
{
    if (_classIds.find(name) == std::end(_classIds))
    {
        int32_t classId;
        util::hooking::func_call<void>(0x14322B030, &classId, name.c_str());

        _classIds[name] = classId;
    }

    return &_classIds[name];
}

uint32_t CGameObject::GetNameHash()
{
    return util::hooking::func_call<uint32_t>(0x1437758D0, this);
}
