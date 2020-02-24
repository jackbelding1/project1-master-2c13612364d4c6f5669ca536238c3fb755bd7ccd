/**
*
* \file ScreenNotice.cpp
*
* \author magikoopa
*/

#include "pch.h"
#include "ScreenNotice.h"

using namespace Gdiplus;
using namespace std;

/**
* constructor
*/
CScreenNotice::CScreenNotice()
{
	mState = ScreenState::LevelBegin;
	mLevelNumber = 1;
}

/**
* destructor
*/
CScreenNotice::~CScreenNotice()
{
}

/**
* Draw function
* \param graphics the graphics context
*/
void CScreenNotice::Draw(Gdiplus::Graphics* graphics)
{
	FontFamily fontFamily(L"Arial");
	Gdiplus::Font font(&fontFamily, 150);
	SolidBrush green(Color(0, 64, 0));

	std::wstring output;

	// determine what to draw
	switch (mState)
	{
	case CScreenNotice::ScreenState::Empty:
	{
		break; 
	}
	case CScreenNotice::ScreenState::LevelBegin:
	{
		output = L"Begin Level ";
		switch (mLevelNumber)
		{
		case 0:
			output += L"0!";
			break;
		case 1:
			output += L"1!";
			break;
		case 2:
			output += L"2!";
			break;
		case 3:
			output += L"3!";
			break;
		default:
			break;
		}
		break;
	}
	case CScreenNotice::ScreenState::Victory:
	{
		
		break; 
	}
	case CScreenNotice::ScreenState::Defeat:
	{
		
		break; 
	}
	default:
	{
		break;
	}
	}
	graphics->DrawString(output.c_str(), -1, &font, PointF(500, 350), &green);
}

/**
* called whenever a level is installed
* \param level the level number
*/
void CScreenNotice::Update(int level)
{
	mLevelNumber = level;
}
