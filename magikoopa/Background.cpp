/**
 * \file Background.cpp
 *
 * \author Brian Kim
 */

#include "pch.h"
#include "Background.h"

using namespace Gdiplus;
using namespace std;

/**
 * Constructor
 * \param game the Game this Money is a part of
 */
CBackground::CBackground(CGame* game) : CItem(game)
{
}

/**
 * Destructor
 */
CBackground::~CBackground()
{
}