/**
*
* \file Door.cpp
*
* \author Jack Belding
*
*/

#include "pch.h"
#include "Door.h"

using namespace Gdiplus;
using namespace std;

/// Collision distance for the door in pixels
const double CollisionDistance = 20;

bool CDoor::CollisionTest(CPlayer* player)
{
    // Collision for door is different
    double dx = player->GetX() - GetX();
    double dy = player->GetY() - GetY();
    double distance = sqrt(dx * dx + dy * dy);
    if (distance < CollisionDistance)
    {
        return true;
    }

    return false;
}

/**
 * Constructor
 * \param game the Game this Door is a part of
 */
CDoor::CDoor(CGame *game) : CItem(game)
{
}

/**
 * Destructor
 */
CDoor::~CDoor()
{
}