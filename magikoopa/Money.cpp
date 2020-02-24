/**
 * \file Money.cpp
 *
 * \author Brian Kim
 */

#include "pch.h"
#include "Money.h"

using namespace Gdiplus;
using namespace std;

/**
 * Constructor
 * \param game the Game this Money is a part of
 */
CMoney::CMoney(CGame* game) : CItem(game)
{
}

/**
 * Destructor
 */
CMoney::~CMoney()
{
}