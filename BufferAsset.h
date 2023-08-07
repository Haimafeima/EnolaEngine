#pragma once
class Buffer
{

};

class BufferAsset
{
public:
	BufferAsset();
	~BufferAsset();

private:
	Buffer* buffer = nullptr;
};

BufferAsset::BufferAsset()
{
}

BufferAsset::~BufferAsset()
{
}