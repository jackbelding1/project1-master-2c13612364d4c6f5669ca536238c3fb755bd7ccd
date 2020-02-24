/**
 * \file Game.h
 *
 * \author Magikoopa // Valentino Dore
 *
 * Declaration of Game class.
 *
 * This is the class which is the master class for our game
 */

#pragma once
#include <memory>
#include <vector>
#include <string>
#include "XmlNode.h"
#include "ScoreBoard.h"



//Forward Reference Level
class CLevel;

//Forward Reference Item
class CItem;

//Forward Reference Item
class CItemVisitor;

//Forward Reference Player
class CPlayer;

//Forward Reference CItemImage
class CItemImage;

 /**
 * CGame class for our entire game
 */
class CGame
{
public:
    void OnDraw(Gdiplus::Graphics* graphics, int width, int height);

    void Update(double elapsed);

    /// default constructor
    CGame();

    /** The Player that the game is using
    * \returns the player shared pointer */
    std::shared_ptr<CPlayer> GetPlayer() const { return mPlayer; }
    
    /// function to add item to game
    void AddItem(std::shared_ptr<CItem> item);
	
	/// function to clear all items in game
	void ClearItems();

    /// function to remove a single item from the game
    void RemoveItem(CItem *item);

    /// process level tag from xml
    void ProcessLevel(const std::shared_ptr<xmlnode::CXmlNode>& node);

    /// process delarations tags from xml
    void ProcessDeclarations(const std::shared_ptr<xmlnode::CXmlNode>& node);
	
    /// process items tags from xml
    void ProcessItems(const std::shared_ptr<xmlnode::CXmlNode>& root);

    /// Load in the level
	void Load(const std::wstring &filename);
    
    /// Collision test
    std::vector<std::shared_ptr<CItem>> CollisionTest();
    
    /// Get size of mItems
    size_t GetSize();

    /// Sets Level Number
    void SetLevel(int levelNum);

    /// Moves to next level
    void NextLevel();

    /// Accepts visitor
    void Accept(CItemVisitor* visitor);

    std::shared_ptr<CItemImage> GetImage(std::wstring id);

    void Install();

private:
    /// size that our game is currently on
    double mScale = 1;

    /// The game must know the player
    std::shared_ptr<CPlayer> mPlayer;
    
    /// The game must know the scoreboard
    std::shared_ptr<CScoreBoard> mScoreBoard;

    /// The game must know the level
    std::shared_ptr<CLevel> mLevel;
    
    /// The game must know the items
    std::vector<std::shared_ptr<CItem>> mItems;

    /// vector for declarations
    std::vector<std::shared_ptr<CItemImage>> mItemImages;
};

