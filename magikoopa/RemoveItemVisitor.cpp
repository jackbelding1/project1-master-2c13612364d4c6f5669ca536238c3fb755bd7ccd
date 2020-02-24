#include "pch.h"
#include "RemoveItemVisitor.h"

void CRemoveItemVisitor::VisitMoney(CMoney* floor)
{
	mRemove = true;
}

void CRemoveItemVisitor::VisitTuitionIncrease(CTuitionIncrease* wall)
{
	mRemove = true;
}

void CRemoveItemVisitor::VisitBusStop(CBusStop* busStop)
{
	mRemove = true;
}
