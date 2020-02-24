#pragma once
#include "ItemVisitor.h"

class CCollisionVisitor : public CItemVisitor
{
public:
    /** Get the number of buildings
     * \returns Number of buildings */
    bool GetCollision() const { return mCollision; }

    void VisitFloor(CFloor* floor) override;
    void VisitWall(CWall* wall) override;

private:
    /// Item Collision
    bool mCollision = false;
};

