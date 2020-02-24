#pragma once
#include "ItemVisitor.h"

class CRemoveItemVisitor : public CItemVisitor
{
public:
    /** Get the number of buildings
     * \returns Number of buildings */
    bool GetRemove() const { return mRemove; }

    void VisitMoney(CMoney* floor) override;
    void VisitTuitionIncrease(CTuitionIncrease* wall) override;
    void VisitBusStop(CBusStop* busStop) override;

private:
    /// Item Collision
    bool mRemove = false;
};

