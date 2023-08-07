#pragma once
#include"Asset.h"
class Image
{
public:
	Image();
	~Image();

private:

};

Image::Image()
{
}

Image::~Image()
{
}
class ImageAsset : public Asset
{
public:
	ImageAsset();
	~ImageAsset();

private:
	Image* image;
};

ImageAsset::ImageAsset()
{
}

ImageAsset::~ImageAsset()
{
}