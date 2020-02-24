/**
 * \file Game.cpp
 *
 * \author Magikoopa // Valentino Dore
 *
 * Implementation of Game class.
 *
 */


#include "pch.h"
#include <vector>
#include <iterator>
#include "Game.h"
#include "Item.h"
#include "Level.h"
#include "XmlNode.h"
#include "Floor.h"
#include "Villain.h"
#include "Door.h"
#include "Money.h"
#include "Floor.h"
#include "Player.h"
#include "ItemImage.h"
#include "Wall.h"
#include "Background.h"  
#include "TuitionIncrease.h"
#include "CollisionVisitor.h"


using namespace Gdiplus;
using namespace std;
using namespace xmlnode;

/// Game area height in virtual pixels
const static int Height = 1024;

/**
* CGame Constructor
*/
CGame::CGame()
{
    mScoreBoard = make_shared<CScoreBoard>();
    mPlayer = make_shared<CPlayer>(this);
    mLevel = make_shared<CLevel>(this);
}

void CGame::Update(double elapsed)
{

    mPlayer->Update(elapsed);

    //TODO Update level, items, scoreboard, etc

    // Update the time by setting the scoreboard time to the current time + elapsed
    mScoreBoard->Update(elapsed);
}

/**
 * Draw the game area
 * \param graphics The GDI+ graphics context to draw on
 * \param width Width of the client window
 * \param height Height of the client window
 */
void CGame::OnDraw(Gdiplus::Graphics* graphics, int width, int height)
{
    //
    // Automatic Scaling
    //
    mScale = float(height) / float(Height);
    graphics->ScaleTransform(mScale, mScale);

    // Determine the virtual width
    auto virtualWidth = (float)width / mScale;

    // Compute the amount to scroll in the X dimension
    auto xOffset = (float)-mPlayer->GetX() + virtualWidth / 2.0f;

    //Transform graphics so the offset is in the center
    auto save = graphics->Save();
    graphics->TranslateTransform(xOffset, 0);


    // PUT DRAW FUNCTIONS BELOW (EXCEPT SCOREBOARD)
    //          ||
    //          ||
    //          \/
    for (auto item : mItems)
    {
        item->Draw(graphics);
    }

    mPlayer->Draw(graphics);

    // PUT DRAW FUNCTIONS ABOVE 
    //          /\
    //          ||
    //          ||


    // Restore offset
    graphics->Restore(save);

    mScoreBoard->Draw(graphics);
    mLevel->Draw(graphics);

}

/**
 * Adds item to game
 * \param item The item being added to mItems
 */ 
void CGame::AddItem(std::shared_ptr<CItem> item)
{
    mItems.push_back(item);
}

/**
 * Clears all items in mItems
 */ 
void CGame::ClearItems()
{
    mItems.clear();
}

/**
 * Removes a single item from the game
 * \param item Item to be removed from mItems
 */
void CGame::RemoveItem(CItem *item)
{
    for (int i=0; i<mItems.size(); i++)
    {
        if ((*item).GetX() == (*mItems[i]).GetX() && (*item).GetY() == (*mItems[i]).GetY())
        {
            mItems.erase(mItems.begin()+i);
        }
    }
}

/**
* Processes Level
*
*/
void CGame::ProcessLevel(const std::shared_ptr<xmlnode::CXmlNode>& node)
{
    //auto level = shared_ptr<CLevel>();
    //level->XmlLoad(node);
    //mLevel = level;
    //mPlayer->SetX(level->GetX());
    //mPlayer->SetY(level->GetY());
    mPlayer->SetY(node->GetAttributeDoubleValue(L"start-y", 0));
    mPlayer->SetX(node->GetAttributeDoubleValue(L"start-x", 0));

}

void CGame::ProcessDeclarations(const std::shared_ptr<xmlnode::CXmlNode>& root)
{
    
    for (auto node : root->GetChildren())
    {
        if (node->GetType() == NODE_ELEMENT && (node->GetName() != L"platform" && node->GetName() != L"money"))
        {
            wstring id = node->GetAttributeValue(L"id", L"");
            wstring image = node->GetAttributeValue(L"image", L"");
            wstring temp = L"images/";
            temp.append(image);
            image = temp;
            //mItemImages.push_back(make_shared<CItemImage>(id, image));
            mItemImages.push_back(make_shared<CItemImage>(id, temp));
        }
        else if (node->GetType() == NODE_ELEMENT && node->GetName() == L"platform" )
        {
            wstring id = node->GetAttributeValue(L"id", L"");
            wstring image = node->GetAttributeValue(L"mid-image", L"");
            wstring temp = L"images/";
            temp.append(image);
            image = temp;
            //mItemImages.push_back(make_shared<CItemImage>(id, image));
            mItemImages.push_back(make_shared<CItemImage>(id, temp));
        }
        else if (node->GetType() == NODE_ELEMENT && node->GetName() == L"money")
        {
            wstring id = node->GetAttributeValue(L"id", L"");
            wstring image = node->GetAttributeValue(L"image", L"");
            wstring temp = L"images/";
            temp.append(image);
            image = temp;
            //mItemImages.push_back(make_shared<CItemImage>(id, image));
            mItemImages.push_back(make_shared<CItemImage>(id, temp));
        }
    }
}

/**
 * Handler for an item node in the level XML
 * \param node The node to be dealt with
 */ 
void CGame::ProcessItems(const std::shared_ptr<xmlnode::CXmlNode> &root)
{
   for (auto node : root->GetChildren())
   {
       // pointer for item we are loading
       shared_ptr<CItem> item;
       // id of item
       wstring id;

       // Extract id
       if (node->GetType() == NODE_ELEMENT)
       {
           id = node->GetAttributeValue(L"id", L"");
       }      

       if (node->GetType() == NODE_ELEMENT && node->GetName() == L"platform")
       {
           item = make_shared<CFloor>(this);
       }
       else if (node->GetType() == NODE_ELEMENT && node->GetName() == L"wall")
       {
           item = make_shared<CWall>(this);
       }
       else if (node->GetType() == NODE_ELEMENT && node->GetName() == L"money")
       {
           item = make_shared<CMoney>(this);
       }

       else if (node->GetType() == NODE_ELEMENT && node->GetName() == L"door")
       {
           item = make_shared<CDoor>(this);
       }
       else if (node->GetType() == NODE_ELEMENT && node->GetName() == L"villain")
       {
           item = make_shared<CVillain>(this);
       }
       else if (node->GetType() == NODE_ELEMENT && node->GetName() == L"background")
       {
           item = make_shared<CBackground>(this);
       }
       else if (node->GetType() == NODE_ELEMENT && node->GetName() == L"tuition-up")
       {
           item = make_shared<CTuitionIncrease>(this);
       }

       if (item != nullptr)
       {
           item->SetImage(this->GetImage(id));
           item->XmlLoad(node);
           AddItem(item);
       }
   }
}


void CGame::Load(const wstring &filename)
{
    try
    {
        //Open document for reading
        shared_ptr<CXmlNode> root = CXmlNode::OpenDocument(filename);
        
        // Clear items
        ClearItems();
        
        // Process Level
        if (root->GetType() == NODE_ELEMENT && root->GetName() == L"level")
        {
            ProcessLevel(root);
        }

        // Iterate through children of the node of the xml doc
        for (auto node:root->GetChildren())
        {
            if (node->GetType() == NODE_ELEMENT && node->GetName() == L"declarations")
            {
                ProcessDeclarations(node);
            }
            else if (node->GetType() == NODE_ELEMENT && node->GetName() == L"items")
            {
                ProcessItems(node);
            }
        }
    }
    
    catch(CXmlNode::Exception ex)
    {
        AfxMessageBox(ex.Message().c_str());
    }
}


/**
* Tests to see if gnome collides with an items
* \param player The gnome character passed
* \returns Pointer to item that it is colliding with, nullptr if no collision
*/
vector<shared_ptr<CItem>> CGame::CollisionTest()
{
    vector<shared_ptr<CItem>> collisions;
    for (auto item : mItems)
    {
        if (item->CollisionTest(mPlayer.get()))
        {
            collisions.push_back(item);
        }
    }
    return collisions;
}

/**
 * returns the number of items in mItems
 */
size_t CGame::GetSize()
{
    return mItems.size();
}

void CGame::SetLevel(int levelNum)
{
    switch (levelNum)
    {
    case 0:
        mLevel->SetLevel(CLevel::LevelNumber::level0);
        break;
    case 1:
        mLevel->SetLevel(CLevel::LevelNumber::level1);
        break;
    case 2:
        mLevel->SetLevel(CLevel::LevelNumber::level2);
        break;
    case 3:
        mLevel->SetLevel(CLevel::LevelNumber::level3);
        break;
    }
}

void CGame::NextLevel()
{
    mScoreBoard->Reset();
    mLevel->NextLevel();
}

/** Accept a visitor for the collection
 * \param visitor The visitor for the collection
 */
void CGame::Accept(CItemVisitor* visitor)
{
    for (auto item : mItems)
    {
        item->Accept(visitor);
    }
}

shared_ptr<CItemImage> CGame::GetImage(wstring id)
{
    for (auto itemImage : mItemImages)
    {
        if (itemImage->GetID() == id)
            return itemImage;
    }
}

void CGame::Install()
{
    mLevel->Install();
}