#include "spawn_system.h"

#include <boost/shared_ptr.hpp>

#include <jc3_hooking/hooking.h>

using namespace jc3;

uint32_t CSpawnSystem::GetModelHash(const char* modelName)
{
	return util::hooking::func_call<uint32_t>(0x144A8D3E0, modelName);
}

int32_t CSpawnSystem::GetModelId(const char* modelName)
{
	return GetModelId(GetModelHash(modelName));
}

int32_t CSpawnSystem::GetModelId(uint32_t modelHash)
{
	return util::hooking::func_call<int32_t>(0x144782AB0, this, modelHash);
}

void CSpawnSystem::OnSpawned(stl::vector<boost::shared_ptr<CGameObject>>* spawned_objects, void* userdata)
{
	if (!userdata)
		__debugbreak();

	// call the user callback
	auto request = static_cast<SpawnFactoryRequest*>(userdata);
	if (!request->canceled) {
		request->callback(request, spawned_objects, request->userdata);
	}

	delete request;
}

jc3::CSpawnSystem * jc3::CSpawnSystem::instance()
{
	return *(CSpawnSystem**)(0x142F18998);
}

jc3::CSpawnSystem::SpawnFactoryRequest* jc3::CSpawnSystem::Spawn(uint32_t modelId, const Matrix spawnMatrix, uint32_t flags, SpawnFactoryCallback_t callback, void* userdata /*= nullptr*/)
{
	auto request = new SpawnFactoryRequest;
	request->callback = callback;
	request->userdata = userdata;

	util::hooking::func_call<void>(0x1447C1280, this, modelId, &spawnMatrix, flags, CSpawnSystem::OnSpawned, request, 0xFFFFFFFF);
	return request;
}

jc3::CSpawnSystem::SpawnFactoryRequest * CSpawnSystem::Spawn(std::string modelName, const Matrix spawnMatrix, uint32_t flags, SpawnFactoryCallback_t callback, void* userdata)
{
	return Spawn(GetModelId(modelName.c_str()), spawnMatrix, flags, callback, userdata);
}
