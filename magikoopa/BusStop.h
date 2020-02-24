/**
 * \file BusStop.h
 *
 * \author Magikoopa
 *
 * Declaration of BusStop class.
 *
 * This is the special group item that transforms CGnome into a CATA bus
 */

#pragma once

#include "Item.h"

/**
* BusStop class for custom group item
*/
class CBusStop : public CItem 
{
public:
    
    //Default constructor disabled
    CBusStop() = delete;
    
    //Copy constructor disabled
    CBusStop(const CBusStop&) = delete;
    
    //Proper constructor
    CBusStop(CGame* game);

    //Destructor
    ~CBusStop();
    

    /** Accept a visitor
     * \param visitor The visitor we accept */
    virtual void Accept(CItemVisitor* visitor) override { visitor->VisitBusStop(this); }
};

