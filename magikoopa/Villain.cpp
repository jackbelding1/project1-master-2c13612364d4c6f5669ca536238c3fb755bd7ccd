/**
 * \file Villain.cpp
 *
 * \author Brian Kim
 */

#include "pch.h"
#include "Villain.h"

using namespace Gdiplus;
using namespace std;

 /** Constructor
 * \param city The city this is a member of
 */
CVillain::CVillain(CGame* game) : CItem(game)
{
}

/**
*  Destructor
*/
CVillain::~CVillain()
{
}