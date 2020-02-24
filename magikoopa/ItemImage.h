

#pragma once
#include <string>
#include <memory>
#include <vector>
#include "Game.h"

class CItemImage
{
public:
	CItemImage() = delete;
	CItemImage(const CItemImage&) = delete;
	CItemImage(std::wstring id, std::wstring filename);

	std::wstring GetID() { return mID; }

	std::shared_ptr<Gdiplus::Bitmap> GetImage() { return mImage; }

private:
	///Item ID
	std::wstring mID;

	/// The image of the player
	std::shared_ptr<Gdiplus::Bitmap> mImage;
};

