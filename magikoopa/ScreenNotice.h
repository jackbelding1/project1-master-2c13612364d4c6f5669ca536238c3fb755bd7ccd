/**
* \file ScreenNotice.h
*
* \author magikoopa
*
* file containing the screen notice class
*/

#pragma once
#include <string>
#include <memory>


/**
* class for a message to appear on the screen
*/
class CScreenNotice
{
public:
	/// The states of the Screen Notice
	enum class ScreenState { Empty, LevelBegin, Victory, Defeat };

	/// default constructor
	CScreenNotice();

	/// default destructor
	~CScreenNotice();

	/// draw function
	void Draw(Gdiplus::Graphics* graphics);

	/// updates the level
	void Update(int level);

	/// Set the current state of the notice
	void SetState(ScreenState state) { mState = state; }
private:
	ScreenState mState;

	/// The current level number
	int mLevelNumber;

};

