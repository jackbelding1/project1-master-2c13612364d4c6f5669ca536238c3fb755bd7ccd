/**
 * \file Item.h
 *
 * \author Magikoopa // Charles Talaga
 *
 * Declaration of Item class.
 *
 * This is the class for the items the player interacts with
 */


#pragma once
#include "Game.h"
#include "ItemVisitor.h"
#include "ItemImage.h"
#include "Vector.h"

/**
 * CItem class
 */
class CItem
{
public:
    /// Default constructor disabled	
    CItem() = delete;

    /// Copy constructor disabled
    CItem(const CItem&) = delete;

    /// Proper constructor
    CItem(CGame* game);

    /// Destructor
    ~CItem();

    virtual bool CollisionTest(CPlayer* player);

    /// Getter for X Position
    double GetX() { return mP.X(); }

    /// Getter for Y Position
    double GetY() { return mP.Y(); }

    /// Setter for X Position
    void SetX(double x) { mP.SetX(x); }

    /// Setter for Y Position
    void SetY(double y) { mP.SetY(y); }

    /// Getter for height
    virtual double GetHeight() { return mImageNode->GetImage()->GetHeight(); }

    /// Getter for width
    virtual double GetWidth() { return mImageNode->GetImage()->GetWidth(); }
    
    /// Sets attributes from Xml node
    virtual void XmlLoad(const std::shared_ptr<xmlnode::CXmlNode>& node);

    /// Draws the item
    virtual void Draw(Gdiplus::Graphics* graphics);

    /// Getter for image
    //std::shared_ptr<Gdiplus::Bitmap> GetImage() { return mItemImage; }

    /** Accept a visitor
     * \param visitor The visitor we accept */
    virtual void Accept(CItemVisitor* visitor) = 0;

    void SetImage(std::shared_ptr<CItemImage> image) { mImageNode = image; }

    /// Getter for image
    std::shared_ptr<Gdiplus::Bitmap> GetImage() { return mImageNode->GetImage(); }
  
private: 
    /// Vector for the position of the item
    CVector mP;
    
	/// Game
	CGame* mGame;

    /// Item Image Node
    std::shared_ptr<CItemImage> mImageNode;
};

