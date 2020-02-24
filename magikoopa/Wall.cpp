/**
*
* \file Wall.cpp
*
* \author Jack Belding 
*
*/

#include "pch.h"
#include "Wall.h"
#include "Item.h"

using namespace Gdiplus;
using namespace std;

/**
 * Constructor
 * \param game the Game this wall is a part of
 */
CWall::CWall(CGame *game) : CItem(game)
{
    
}


/**
 * Destructor
 */ 
CWall::~CWall()
{
    
}

void CWall::Draw(Gdiplus::Graphics* graphics)
{
    //mItemImage = mImage->GetImage();
    double wid = GetImage()->GetWidth();
    double hit = GetImage()->GetHeight();

    // Start drawing at this position
    double pos = GetY() - mHeight / 2.;
    double end_pos = GetY() + mHeight / 2. - 1.; // -1 for error
    while (pos < end_pos)
    {
        //graphics->DrawImage(GetImage().get(),
        //    float(GetX() + wid / 2 + 64.), float(pos),
        //    (float)wid, (float)hit);
        graphics->DrawImage(GetImage().get(),
            float(GetX() - wid / 2), float(pos),
            (float)wid, (float)hit);
        pos += hit;
    }
}

void CWall::XmlLoad(const std::shared_ptr<xmlnode::CXmlNode>& node)
{
    CItem::XmlLoad(node);
    mWidth = node->GetAttributeIntValue(L"width", 0);
    mHeight = node->GetAttributeIntValue(L"height", 0);
}
