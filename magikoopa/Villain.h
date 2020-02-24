/**
 * \file Villain.h
 *
 * \author Magikoopa
 *
 * Declaration of Villain class.
 *
 * This class represents a villain item that acts as an obstacle for the player
 */

#pragma once

#include "Item.h"

 /**
 * Class representing a villain item object
 */
class CVillain : public CItem 
{
public:

    ///  Default constructor (needs to be disabled)
    CVillain();

    ///  Copy constructor (disabled)
    CVillain(const CVillain&) = delete;

	CVillain(CGame* game);

	~CVillain();

    /** Accept a visitor
     * \param visitor The visitor we accept */
    virtual void Accept(CItemVisitor* visitor) override { visitor->VisitVillain(this); }

private:
    // Currently empty
};