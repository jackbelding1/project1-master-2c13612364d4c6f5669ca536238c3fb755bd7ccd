#pragma once
#include "ItemVisitor.h"

class CDoorVisitor : public CItemVisitor
{
public:
    /** Get the number of buildings
     * \returns Number of buildings */
    bool GetCollision() const { return mCollision; }

    void VisitDoor(CDoor* floor) override;

private:
    /// Item Collision
    bool mCollision = false;
};

