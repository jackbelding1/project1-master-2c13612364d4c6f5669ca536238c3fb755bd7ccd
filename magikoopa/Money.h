/**
 * \file Money.h
 *
 * \author Magikoopa
 *
 * Declaration of Money class.
 *
 * This class represents a money item that increases tuition
 */

#pragma once
#include "Item.h"


 /**
 * Class representing a money item object
 */
class CMoney : public CItem
{
public:
    // Default constructor disabled	
    CMoney() = delete;

    // Copy constructor disabled
    CMoney(const CMoney&) = delete;

    // Proper constructor
    CMoney(CGame* game);

    //Destructor
    ~CMoney();

    /** Accept a visitor
     * \param visitor The visitor we accept */
    virtual void Accept(CItemVisitor* visitor) override { visitor->VisitMoney(this); }

private:
    /// Value of the money item
    double mValue = 0.00;
};