/**
 * \file BusStop.cpp
 *
 * \author Magikoopa
 *
 * Implementation of BusStop class.
 *
 */

#include "pch.h"
#include "BusStop.h"
#include "Item.h"

using namespace Gdiplus;
using namespace std;

/**
 * Constructor
 * \param game the Game this bus stop is a part of
 */
CBusStop::CBusStop(CGame *game) : CItem(game)
{

}

/**
 * Destructor
 */ 
CBusStop::~CBusStop()
{
    
}