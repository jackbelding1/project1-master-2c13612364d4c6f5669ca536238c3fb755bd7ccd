/**
*
* \file Wall.h
*
* \author Magikoopa
*
* file containing the wall item
*
*/
#pragma once
#include "Item.h"

/**
* Class for a wall item
*/
class CWall : public CItem 
{
public:

	// Default constructor disabled	
	CWall() = delete;
    
    // Copy constructor disabled
    CWall(const CWall&) = delete;
    
    // Proper constructor
	CWall(CGame* game);

	//Destructor
    ~CWall();

	void Draw(Gdiplus::Graphics* graphics) override;

    void XmlLoad(const std::shared_ptr<xmlnode::CXmlNode>& node) override;

    /** Accept a visitor
     * \param visitor The visitor we accept */
    virtual void Accept(CItemVisitor* visitor) override { visitor->VisitWall(this); }

    virtual double GetHeight() { return mHeight; }

    virtual double GetWidth() { return mWidth; }

private:
    int mWidth = 0;
    int mHeight = 0;
};

