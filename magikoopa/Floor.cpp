/**
*
* \file Floor.cpp
*
* \author Jack Belding
*
*/

#include "pch.h"
#include "Floor.h"

using namespace Gdiplus;
using namespace std;

/**
 * Constructor
 * \param game The game the floor object is a part of
 */
CFloor::CFloor(CGame *game) : CItem(game)
{
}


/**
 * Destructor
 */
CFloor::~CFloor()
{
    
}

void CFloor::XmlLoad(const std::shared_ptr<xmlnode::CXmlNode>& node)
{
    CItem::XmlLoad(node);
    mWidth = node->GetAttributeDoubleValue(L"width", 0);
    mHeight = node->GetAttributeDoubleValue(L"height", 0);
}

void CFloor::Draw(Gdiplus::Graphics* graphics)
{
    //mItemImage = mImage->GetImage();
    double wid = GetImage()->GetWidth();
    double hit = GetImage()->GetHeight();

    // Start drawing at this position
    double pos = GetX() - mWidth / 2.;
    double end_pos = GetX() + mWidth / 2. - 1.; //-1 for error
    while (pos < end_pos)
    {
        graphics->DrawImage(GetImage().get(),
            float(pos), float(GetY() - hit / 2),
            (float)wid, (float)hit);

        //graphics->DrawImage(GetImage().get(),
        //    float(pos), float(GetY() - hit / 2),
        //    (float)wid, (float)hit);
        pos += wid;
    }
}
