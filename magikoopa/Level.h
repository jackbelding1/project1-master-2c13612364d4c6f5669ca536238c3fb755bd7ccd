/**
 * \file Item.h
 *
 * \author Magikoopa // Charles Talaga
 *
 * Declaration of Level class.
 *
 * This is the class for a Level of the Game
 */


#pragma once
#include <string>
#include <vector>
#include "Game.h"
#include "ScreenNotice.h"

/**
 * CLevel class
 */ 
class CLevel
{
public: 
    CLevel(CGame* game);

    CLevel() = delete;

    ~CLevel();

    CLevel(const CLevel&) = delete;
    ///Reset/Initialize level
    ///void Reset();

    // void Install(CGame *game);	
    
    /// Add item to mItems
    //void AddItem(CItem item);

    /// Getter for X
    double GetX() { return mStartY; }

    /// Getter for Y
    double GetY() { return mStartY; }

    void NextLevel();

    void Install();
    
    /// Xml Load
    void XmlLoad(const std::shared_ptr<xmlnode::CXmlNode>& node);	

    enum class LevelNumber { level0, level1, level2, level3 };

    /// Set Level
    void SetLevel(LevelNumber levelNum) { mLevelNumber = levelNum; }

    /// draw function
    void Draw(Gdiplus::Graphics* graphics);

private:

    /// The screen notice
    std::shared_ptr<CScreenNotice> mScreenNotice;

    /// Level Number
    LevelNumber mLevelNumber = LevelNumber::level1;

    /// Game
    CGame* mGame;

	/// Level completed?
	bool mComplete;
	
	/// list of items
    std::vector<std::shared_ptr<CItem>> mItems;

    /// Attributes of level
    double mWidth = 0;
    double mHeight = 0;
    double mStartX = 0;
    double mStartY = 0;
};

