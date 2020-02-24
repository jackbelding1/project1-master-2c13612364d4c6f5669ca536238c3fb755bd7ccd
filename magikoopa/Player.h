/**
 * \file Player.h
 *
 * \author Magikoopa
 *
 * Declaration of Player class.
 *
 * This is the class which holds the player which the person controls
 */

#pragma once
#include <string>
#include <memory>
#include "Vector.h"
#include "Game.h"

 /**
 * CPlayer class for our player
 */
class CPlayer
{
public:
    CPlayer(CGame* game);

    // Delete default constructor
    CPlayer() = delete;

    /** The directory were the images are stored */
    static const std::wstring ImagesDirectory;

    /// Draw the player
    /// \param graphics Graphics device to draw on
    void Draw(Gdiplus::Graphics* graphics);

    /**Updates the current state of the gnome
    */
    void Update(double elapsed);

    /** The Width of the gnome
     * \returns Width of gnome */
    double GetWidth() { return mGnome->GetWidth(); }

    /** The Height of the gnome
     * \returns Height of gnome */
    double GetHeight() { return mGnome->GetHeight(); }

    /** The X location of the player
    *\returns X location in pixels */
    double GetX() const { return mPosition.X(); }

    /** The Y location of the player
    * \returns Y location in pixels */
    double GetY() const { return mPosition.Y(); }

    /** Sets the X location of the player
    */
    void SetX(double x) { mPosition.SetX(x); }

    /** Sets the Y location of the player
    */
    void SetY(double y) { mPosition.SetY(y); }

    /** The X velocity of the player
    * \sets the velocity in the x dir */
    void SetVelocityX(double x) { mV.SetX(x); }

    /** The Y velocity of the player
    * \sets the velocity in the y dir */
    void SetVelocityY(double y) { mV.SetY(y); }

    /** The X velocity of the player
    * \returns the velocity in the x dir */
    double GetVelocityX() const {return mV.X(); }

    /** The Y velocity of the player
    * \returns the velocity in the y dir */
    double GetVelocityY() const { return mV.Y(); }

    /** The X and Y pos of the player
    * \sets the pos in the x and y dir */
    void SetLocation(double x, double y) { mPosition.SetX(x), mPosition.SetY(y); }

    /** The current image of gnome
    * \sets the new current image */
    void SetImage(const std::wstring& file);

private:
    /// The image of the player
    std::unique_ptr<Gdiplus::Bitmap> mGnome;

    /// Velocity Vector
    CVector mV;

    ///// speed at which our player is moving at in X direction
    //double mVelocityX = 0;

    ///// speed at which our player is moving at in Y direction
    //double mVelocityY = 0;

    /// Position of the player
    CVector mPosition;

    /// Game gnome belongs to
    CGame* mGame;

};

