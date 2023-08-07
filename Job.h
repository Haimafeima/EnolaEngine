#pragma once
#include <functional>
class Job
{
public:
	Job();
	~Job();
private:
	std::function<int> fun;
};