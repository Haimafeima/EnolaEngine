#include "JobSystem.h"
#include "isystem.h"
#include <vector>
void InitGraphics()
{
	return;
}

int main()
{
	std::vector<SystemBase*> systems;
	systems.push_back();
	systems.push_back();
	while (1)
	{
		for (int i=0;i< systems.size(); ++i)
		{
			systems[i]->Tick();
		}
	}
	return 0;
}