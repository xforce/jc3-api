#pragma once

#include <stl/vector>
#include <boost/shared_ptr.hpp>

#include <functional>
#include <string>

#include "../math/Matrix.h"

namespace jc3
{
	class CGameObject;
	class IPfxGameObject;
	class CPhysicsGameObject;
    class CSpawnSystem
    {
	private:
		static void OnSpawned(stl::vector<boost::shared_ptr<CGameObject>>* spawned_objects, void* userdata);

    public:
		struct SpawnFactoryRequest;
		using SpawnFactoryCallback_t = std::function<void(SpawnFactoryRequest* factoryRequest, stl::vector<boost::shared_ptr<CGameObject>>* spawned_objects, void* userdata)>;
		struct SpawnFactoryRequest
		{
			SpawnFactoryCallback_t callback;
			void* userdata = nullptr;
			bool canceled = false;
		};

		static CSpawnSystem * instance();

		uint32_t GetModelHash(const char* modelName);
		int32_t GetModelId(const char* modelName);
		int32_t GetModelId(uint32_t modelHash);

		
		SpawnFactoryRequest * Spawn(std::string modelName, const Matrix spawnMatrix, uint32_t flags, SpawnFactoryCallback_t callback, void* userdata);
		SpawnFactoryRequest* Spawn(uint32_t modelId, const Matrix spawnMatrix, uint32_t flags, SpawnFactoryCallback_t callback, void* userdata = nullptr);
    };
}