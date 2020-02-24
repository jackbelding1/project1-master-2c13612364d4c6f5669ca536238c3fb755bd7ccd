/**
 * \file Background.h
 *
 * \author Magikoopa
 *
 * Declaration of Background class.
 *
 * This class represents a Background item that increases tuition
 */

#pragma once
#include "Item.h"


 /**
 * Class representing a Background item object
 */
class CBackground : public CItem
{
public:
    // Default constructor disabled	
    CBackground() = delete;

    // Copy constructor disabled
    CBackground(const CBackground&) = delete;

    // Proper constructor
    CBackground(CGame* game);

    //Destructor
    ~CBackground();

    /** Accept a visitor
     * \param visitor The visitor we accept */
    virtual void Accept(CItemVisitor* visitor) override { visitor->VisitBackground(this); }
};