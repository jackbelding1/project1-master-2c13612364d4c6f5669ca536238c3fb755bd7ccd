/**
*
* \file Floor.h
*
* \author Magikoopa
*
* file to contain floor class
*
*/


#pragma once
#include "Item.h"

/**
* Class for the floor tile
*/
class CFloor : public CItem   
{
public:
    // Default constructor disabled
	CFloor() = delete;
	
	// Copy constructor disabled
	CFloor(const CFloor&) = delete;
	
	// Proper constructor
	CFloor(CGame* game);

	// Destructor
	~CFloor();

	void Draw(Gdiplus::Graphics* graphics) override;

	/** Accept a visitor
	 * \param visitor The visitor we accept */
	virtual void Accept(CItemVisitor* visitor) override { visitor->VisitFloor(this); }

	virtual void XmlLoad(const std::shared_ptr<xmlnode::CXmlNode>& node) override;

	virtual double GetHeight() { return mHeight; }

	virtual double GetWidth() { return mWidth; }


private:
	double mHeight = 0;
	double mWidth = 0;
};
