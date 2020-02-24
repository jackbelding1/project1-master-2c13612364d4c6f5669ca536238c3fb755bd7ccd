/**
 * \file Level.cpp
 *
 * \author Magikoopa // Charles Talaga
 *
 * Implementation of Level class.
 *
 */

#include "pch.h"
#include <algorithm>
#include <vector> 
#include "Level.h"
#include "ScreenNotice.h"

using namespace Gdiplus;
using namespace std;
using namespace xmlnode;


CLevel::CLevel(CGame* game)
{
    mLevelNumber = LevelNumber::level1;
    mGame = game;
    mScreenNotice = make_shared<CScreenNotice>();
}

CLevel::~CLevel()
{

}

/**
 * Add item to temporary list of items
 * \param item The item handled
 */
//void CLevel::AddItem(CItem item)
//{
//    auto item1 = std::make_shared<CItem>(item);
//    mItems.push_back(item1);
//}

/**
* Update Level Number
*/
void CLevel::NextLevel()
{
    mScreenNotice->SetState(CScreenNotice::ScreenState::Victory);
    switch (mLevelNumber)
    {
    case LevelNumber::level0:
        mLevelNumber = LevelNumber::level1;
        break;

    case LevelNumber::level1:
        mLevelNumber = LevelNumber::level2;
        break;

    case LevelNumber::level2:
        mLevelNumber = LevelNumber::level3;
        break;
    }
}

/**
* Install Current Level
*/
void CLevel::Install()
{
    /// Load Current Level
    if (mLevelNumber == LevelNumber::level0)
    {
        mGame->Load(L"levels/level0.xml");
        mScreenNotice->Update(0);
    }
    else if (mLevelNumber == LevelNumber::level1)
    {
        mGame->Load(L"levels/level1.xml");
        mScreenNotice->Update(1);
    }
    else if (mLevelNumber == LevelNumber::level2)
    {
        mGame->Load(L"levels/level2.xml");
        mScreenNotice->Update(2);
    }
    else if (mLevelNumber == LevelNumber::level3)
    {
        mGame->Load(L"levels/level3.xml");
        mScreenNotice->Update(3);
    }


}

/**
 * Set starting attributes from Xml node
 * \param node Xml node we are extracting from
 */ 
void CLevel::XmlLoad(const std::shared_ptr<xmlnode::CXmlNode>& node)
{
    mWidth = node->GetAttributeDoubleValue(L"width", 0);
    mHeight = node->GetAttributeDoubleValue(L"height", 0);
    mStartX = node->GetAttributeDoubleValue(L"start-x", 0);
    mStartY = node->GetAttributeDoubleValue(L"start-y", 0);
}

/**
* level draw function that simply calls it's associated screen notice's draw function
* \param graphics the graphics context
*/
void CLevel::Draw(Gdiplus::Graphics* graphics)
{
    mScreenNotice->Draw(graphics);
}
