#include "pch.h"
#include "CollisionVisitor.h"

void CCollisionVisitor::VisitFloor(CFloor* floor)
{
	mCollision = true;
}

void CCollisionVisitor::VisitWall(CWall* wall)
{
	mCollision = true;
}
