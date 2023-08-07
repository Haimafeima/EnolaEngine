#pragma once
#include "Asset.h"
#include "include/AsyncLoader.h"
#include <map>
#include "PathUtils.h"
class AssetManager
{
	static AssetManager* GetAssetManager()
	{
		return assetManager;
	};
	void Register(AsyncLoader* loader)
	{
		auto name=loader->GetExtensionName();
		loaders.emplace(name, loader);
	}
	bool Load(std::string path)
	{
		//根据后缀
		std::string ext = utils::GetExtention(path);
		AsyncLoader* loader = nullptr;
		if (loaders.find(ext) != loaders.end())
		{
			//job
			auto asset=loaders[ext]->Load(path);
			if (asset->GetStage()== ERROR)
			{
				Register();
				return false;
			}
		}
	}
	Asset* CreateAsset(AssetType type)
	{
		Asset* asset;
		//Reflection
		asset->Create();
		return asset;
	}
	bool Release(Asset* asset)
	{
		return true;
	}
private:
	void Register(std::string path, utils::UUID id)
	{
		mapNameToId.emplace(path, id);
		mapIdToName.emplace(id, path);
	}
	AssetManager() = default;
	~AssetManager() = delete;
	AssetManager(const AssetManager&) = delete;
	AssetManager& operator=(const AssetManager&)= delete;
	static AssetManager* assetManager;
	std::map<std::string, AsyncLoader*> loaders;
	std::map<std::string, utils::UUID> mapNameToId;
	std::map<utils::UUID, std::string> mapIdToName;

	//std::map<std::string, utils::UUID> mapNameToId;
	//std::map<utils::UUID, std::string> mapIdToName;
};
//初始化
AssetManager *AssetManager::assetManager=new AssetManager();