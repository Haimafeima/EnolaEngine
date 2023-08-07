#pragma once
#include <queue>
#include "Job.h"
class TransferQueue
{
public:
	TransferQueue();
	~TransferQueue();
	void push();
	void pop();
private:
	std::queue<Job> jobQueues;
};

TransferQueue::TransferQueue()
{
}

TransferQueue::~TransferQueue()
{
}