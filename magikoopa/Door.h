/**
*
* \file Door.h
*
* \author Magikoopa
*
* A file contianing the door item
*
*/

#pragma once
#include "Item.h"
#include "Player.h"


/**
* Class for the door item
*/
class CDoor : public CItem
{
private:
    /// Variable indicating the state of the door
    bool mIsOpen;

    /// Collision Test
    virtual bool CollisionTest(CPlayer* player);

public:
    // Default constructor disabled	
    CDoor() = delete;

    // Copy constructor disabled
    CDoor(const CDoor&) = delete;

    // Proper constructor
    CDoor(CGame *game);

    //Destructor
    ~CDoor();

    /** Accept a visitor
     * \param visitor The visitor we accept */
    virtual void Accept(CItemVisitor* visitor) override { visitor->VisitDoor(this); }
};

