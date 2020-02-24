/**
 * \file Item.cpp
 *
 * \author Magikoopa // Charles Talaga
 *
 * Implementation of Item class.
 *
 */


#include "pch.h"
#include "Wall.h"
#include "Player.h"

using namespace Gdiplus;
using namespace std;

/**
 * Constructor
 * \param game the Game this item is a part of
 */
CItem::CItem(CGame* game) : mGame(game)
{
}


/**
 * Destructor
 */
CItem::~CItem()
{
}

/**
 * Checks if an item collides
 *
 * /param item The item to check collision with
 *
 * /return True on collision
 */
bool CItem::CollisionTest(CPlayer* player)
{
    // Border for the player
    auto playerLeft = player->GetX() - player->GetWidth() / 2;
    auto playerRight = player->GetX() + player->GetWidth() / 2;
    auto playerTop = player->GetY() - player->GetHeight() / 2;
    auto playerBottom = player->GetY() + player->GetHeight() / 2;

    // For us
    auto ourLeft = GetX() - GetWidth() / 2;
    auto ourRight = GetX() + GetWidth() / 2;
    auto ourTop = GetY() - GetHeight() / 2;
    auto ourBottom = GetY() + GetHeight() / 2;

    // Test for all of the non-collision cases,
    // cases where there is a gap between the two items
    if (ourRight < playerLeft ||  // Completely to the left
        ourLeft > playerRight ||  // Completely to the right
        ourTop > playerBottom ||  // Completely below
        ourBottom < playerTop)    // Completely above
    {
        return false;
    }

    return true;
}

void CItem::XmlLoad(const std::shared_ptr<xmlnode::CXmlNode>& node)
{
    mP.SetX(node->GetAttributeDoubleValue(L"x", 0));
    mP.SetY(node->GetAttributeDoubleValue(L"y", 0));
}

void CItem::Draw(Gdiplus::Graphics* graphics)
{
    std::shared_ptr<Gdiplus::Bitmap> itemImage = mImageNode->GetImage();
    double wid = itemImage->GetWidth();
    double hit = itemImage->GetHeight();

    //graphics->DrawImage(itemImage.get(),
    //    float(mP.X()), float(mP.Y()),
    //    (float)wid, (float)hit);

    graphics->DrawImage(itemImage.get(),
        float(mP.X() - wid / 2), float(mP.Y() - hit / 2),
        (float)wid, (float)hit);
}
