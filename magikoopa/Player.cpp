/**
 * \file Player.cpp
 *
 * \author Magikoopa
 *
 * Implementation of Player class.
 *
 */

#include "pch.h"
#include "Player.h"
#include "Item.h"
#include "CollisionVisitor.h"
#include "RemoveItemVisitor.h"
#include "DoorVisitor.h"

using namespace std;
using namespace Gdiplus;

/// Gnome default picture
std::wstring filename = L"images/gnome.png";
// Gnome right 1
std::wstring filenameRight1 = L"images/gnome-walk-right-1.png";
// Gnome right 2
std::wstring filenameRight2 = L"images/gnome-walk-right-2.png";
// Gnome left 1
std::wstring filenameLeft1 = L"images/gnome-walk-left-1.png";
// Gnome left 2
std::wstring filenameLeft2 = L"images/gnome-walk-left-2.png";
/// Gnome initialX
int initialX = 200;
/// Gnome initialY
int initialY = 200;

/// Gravity in virtual pixels per second per second
const double Gravity = 1000.0;

/// Horizontal character speed in pixels per second
const double HorizontalSpeed = 500.00;

const double JumpSpeed = -800;

/// Small value to ensure we do not stay in collision
const double Epsilon = 0.01;

 /**
  * CPlayer constructor
  */
CPlayer::CPlayer(CGame* game)
{
    // Load image from gnome file
    mGnome = unique_ptr<Bitmap>(Bitmap::FromFile(filename.c_str()));
    if (mGnome->GetLastStatus() != Ok)
    {
        wstring msg(L"Failed to open ");
        msg += filename;
        AfxMessageBox(msg.c_str());
    }
    
    // Set position
    mPosition.SetX(initialX);
    mPosition.SetY(initialY);

    //Initialize velocity
    mV.SetX(0);
    mV.SetY(0);
    mGame = game;
}

/**
 * Draw our player
 * \param graphics The graphics context to draw on
 */
void CPlayer::Draw(Gdiplus::Graphics* graphics)
{
    double wid = mGnome->GetWidth();
    double hit = mGnome->GetHeight();

    //graphics->DrawImage(mGnome.get(),
    //    float(mPosition.X()), float(mPosition.Y()),
    //    (float)wid, (float)hit);

    graphics->DrawImage(mGnome.get(),
        float(mPosition.X() - wid / 2), float(mPosition.Y() - hit / 2),
        (float)wid, (float)hit);
}

/**
 * Handle updates in time of our player
 * of time that has elapsed.
 * \param elapsed Time elapsed since the class call
 */
void CPlayer::Update(double elapsed)
{
    int whichPic = static_cast<int>(mPosition.X() / 200.0);
    if (mV.X() > 0)
    {
        if (whichPic % 2 == 0)
        {
            mGnome = unique_ptr<Bitmap>(Bitmap::FromFile(filenameRight1.c_str()));
        }
        else
        {
            mGnome = unique_ptr<Bitmap>(Bitmap::FromFile(filenameRight2.c_str()));
        }
    }
    else if (mV.X() < 0)
    {
        if (whichPic % 2 == 0)
        {
            mGnome = unique_ptr<Bitmap>(Bitmap::FromFile(filenameLeft1.c_str()));
        }
        else
        {
            mGnome = unique_ptr<Bitmap>(Bitmap::FromFile(filenameLeft2.c_str()));
        }
    }
    else
    {
        mGnome = unique_ptr<Bitmap>(Bitmap::FromFile(filename.c_str()));
    }
    //SetLocation(GetX() + mV.X() * elapsed,
    //    GetY() + mV.X() * elapsed);

    // Gravity
    // Compute a new velocity with gravity added in.
    CVector newV(mV.X(), mV.Y() + Gravity * elapsed);

    // Update position
    CVector newP = mPosition + newV * elapsed;

    //
    // Try updating the Y location. 
    //
    SetLocation(mPosition.X(), newP.Y());

    auto collisions = mGame->CollisionTest();
    for (auto collided : collisions)
    {
        CCollisionVisitor collisionVisitor;
        collided->Accept(&collisionVisitor);
        if (collisionVisitor.GetCollision())
        {
            if (newV.Y() > 0)
            {
                // We are falling, stop at the collision point
                newP.SetY(collided->GetY() - collided->GetHeight() / 2 - GetHeight() / 2 - Epsilon);
            }
            else
            {
                // We are rising, stop at the collision point
                newP.SetY(collided->GetY() + collided->GetHeight() / 2 + GetHeight() / 2 + Epsilon);
            }

            // If we collide, we cancel any velocity
            // in the Y direction
            newV.SetY(0);
        }
}

    // 
    // Try updating the X location
    //
    //SetLocation(newP.X(), mPosition.Y());
    SetLocation(newP.X(), newP.Y());


    collisions = mGame->CollisionTest();
    for (auto collided : collisions)
    {
        CCollisionVisitor collisionVisitor;
        collided->Accept(&collisionVisitor);
        if (collisionVisitor.GetCollision())
        {
            if (newV.X() > 0)
            {
                // We are moving to the right, stop at the collision point
                newP.SetX(collided->GetX() - collided->GetWidth() / 2 - GetWidth() / 2 - Epsilon);
            }
            else
            {
                // We are moving to the left, stop at the collision point
                newP.SetX(collided->GetX() + collided->GetWidth() / 2 + GetWidth() / 2 + Epsilon);
            }

            // If we collide, we cancel any velocity
            // in the X direction
            newV.SetX(0);
        }
    }

    //// Update the velocity and position
    mV = newV;
    SetLocation(newP.X(), newP.Y());

    for (auto collided : collisions)
    {
        // Other visitors here (collided is an std::shared_ptr<CItem>)
        CRemoveItemVisitor removeVisitor;
        collided->Accept(&removeVisitor);
        if (removeVisitor.GetRemove())
        {
            mGame->RemoveItem(collided.get());
        }

        // Collision with door
        CDoorVisitor doorVisitor;
        collided->Accept(&doorVisitor);
        if (doorVisitor.GetCollision())
        {
            mGame->NextLevel();
            mGame->Install();
        }
    }
}