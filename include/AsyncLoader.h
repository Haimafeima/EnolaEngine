#pragma once
#include <string>
class AsyncLoader
{
public:
	AsyncLoader()=default;
	~AsyncLoader() = default;
	virtual Asset* Load(std::string path) = 0;
	virtual std::string GetExtensionName() = 0;
};