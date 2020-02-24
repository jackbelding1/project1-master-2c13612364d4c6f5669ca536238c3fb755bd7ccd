/**
*
* \file ScoreBoard.cpp
*
* \author Magikoopa
*/

#include "pch.h"
#include "ScoreBoard.h"

using namespace Gdiplus;
using namespace std;


/**
* Function that uses the time from scoreboard to create a clock
* \return std::wstring a clock time in the format of m:ss
*/
std::wstring CScoreBoard::GetClock()
{
	int minutes = mTimeElapsed / 60;
	int seconds = static_cast<int>(mTimeElapsed) % 60;
	std::wstring clock = std::to_wstring(minutes) + L":";

	// check to see if under 10 seconds have elapsed to pad the clock
	if (seconds < 10)
	{
		clock += L"0";
	}

	clock += std::to_wstring(seconds);
	return clock;
}

/**
* function to get the tuition in the form of $d
* \return std::wstring the tution amount
*/
std::wstring CScoreBoard::GetTuitionUSD()
{
	std::wstring tuition = L"$" + std::to_wstring(mTuition);
	return tuition;
}

/// draws the scoreboard
/// \param graphics the graphics context
void CScoreBoard::Draw(Gdiplus::Graphics* graphics)
{
	FontFamily fontFamily(L"Arial");
	Gdiplus::Font font(&fontFamily, 50);
	SolidBrush green(Color(0, 64, 0));

	// Draw the tuition amount in the top right corner
	graphics->DrawString(GetTuitionUSD().c_str(), -1, &font, PointF(2016, 2), &green);

	// Draw the Time elapsed in the top left corner
	graphics->DrawString(GetClock().c_str(), -1, &font, PointF(116, 2), &green);

}

/**
* Default constructor
*/
CScoreBoard::CScoreBoard()
{
	mTimeElapsed = 0.0;
	mTuition = 0;
}

/**
* Default destructor
*/

CScoreBoard::~CScoreBoard()
{

}
/**
* Function to update the scoreboard 
* \param elapsed the time elapsed
*/
void CScoreBoard::Update(double elapsed)
{
	mTimeElapsed += elapsed;
}


/**
* function that updates the scoreboard
* \param elapsed the time since last update
* \param tuition_gained the amount of tuition gained since last update
*/

/*
void CScoreBoard::Update(double elapsed)
{
	mTimeElapsed += elapsed;
}*/
