/**
 * \file TuitionIncrease.h
 *
 * \author Magikoopa
 *
 * Declaration of TuitionIncrease class.
 *
 * This item will increase tuition by 10%
 */

#pragma once
#include "Item.h"

/**
* Tuition increase item
*/
class CTuitionIncrease : public CItem 
{
public:
    // Default constructor disabled
    CTuitionIncrease() = delete;
    
    // Copy constructor disabled
    CTuitionIncrease(const CTuitionIncrease&) = delete;
    
    // Proper constructor
	CTuitionIncrease(CGame* game);

	// Destructor
    ~CTuitionIncrease();

    /** Accept a visitor
     * \param visitor The visitor we accept */
    virtual void Accept(CItemVisitor* visitor) override { visitor->VisitTuitionIncrease(this); }
};

