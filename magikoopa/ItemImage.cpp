#include "pch.h"
#include "ItemImage.h"

using namespace std;
using namespace Gdiplus;

CItemImage::CItemImage(std::wstring id, std::wstring filename)
{
	mID = id;
    mImage = shared_ptr<Bitmap>(Bitmap::FromFile(filename.c_str()));
    if (mImage->GetLastStatus() != Ok)
    {
        wstring msg(L"Failed to open ");
        msg += filename;
        AfxMessageBox(msg.c_str());
    }
}