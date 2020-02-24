/**
*
* \file ScoreBoard.h
*
* \author Magikoopa
*
* file containing the scoreboard class
*/

#pragma once
#include <string>
/**
* Class for a scoreboard
*/
class CScoreBoard
{
private:

	/// Variable to keep track of time
	double mTimeElapsed;

	/// Variable to keep track of tuition
	int mTuition;

public:
	
	/// function to get the clock in m:ss form
	std::wstring GetClock();

	/// function to get the USD amount of tuition
	std::wstring GetTuitionUSD();

	/// Draw the scoreboard
	/// \param graphics Graphics device to draw on
	void Draw(Gdiplus::Graphics* graphics);

	/// default constructor
	CScoreBoard();

	/// destructor
	~CScoreBoard();

	/// mTimeElapsed getter
	/// \return mTimeElapsed the time elapsed
	//double GetTimeElapsed() { return mTimeElapsed; }

	/// mTimeElapsed setter
	/// \param time the new time elapsed
	//void SetTimeElapsed(double time) { mTimeElapsed = time; }

	/// mTuition Getter
	/// \return mTuition the tuition
	//int GetTuition() { return mTuition; }

	/// update function
	void Update(double elapsed);

	/// Reset function
	void Reset() { mTimeElapsed = 0.0; mTuition = 0.0; }
};

