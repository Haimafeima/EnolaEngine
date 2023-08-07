#pragma once
#include <stdint.h>
#include <vector>
enum Stage
{
	Idle = 0,
	ERROR,
	CPULOAD,
	GPULOAD,
};
class AssetType
{

};
//template<class T>
class Asset
{
public:
	Asset();
	~Asset();
	uint64_t GetId();
	Stage GetStage();
	AssetType GetType();
	std::vector<Asset> GetDependence();

	virtual bool Create()=0;
	virtual bool Load()=0;
	virtual bool Release()=0;
private:
	uint64_t uuid=0;
	Stage stage = Idle;
	uint32_t size = 0;
	uint8_t* data=nullptr;
	std::vector<Asset> dependences;
};
//复制一个对象
