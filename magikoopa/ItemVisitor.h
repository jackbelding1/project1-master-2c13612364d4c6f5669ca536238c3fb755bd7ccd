/**
 * \file ItemVisitor.h
 *
 * \author Magikoopa
 *
 * Item visitor base class.
 */


#pragma once

 // Forward references to all item types
class CBackground;
class CBusStop;
class CDoor;
class CFloor;
class CMoney;
class CTuitionIncrease;
class CVillain;
class CWall;

/** Item visitor base class */
class CItemVisitor
{
public:
    virtual ~CItemVisitor() {}

    /** Visit a CWall object
     * \param wall Wall we are visiting */
    virtual void VisitBackground(CBackground* background) {}

    /** Visit a CBusStop object
     * \param busstop Bus stop we are visiting */
    virtual void VisitBusStop(CBusStop* busstop) {}

    /** Visit a CDoor object
    * \param door Door we are visiting */
    virtual void VisitDoor(CDoor* door) {}

    /** Visit a CFloor object
    * \param floor Floor tile we are visiting */
    virtual void VisitFloor(CFloor* floor) {}

    /** Visit a CMoney object
    * \param money Money we are visiting */
    virtual void VisitMoney(CMoney* money) {}

    /** Visit a CTuitionIncrease object
    * \param tuitionincrease Tuition increase we are visiting */
    virtual void VisitTuitionIncrease(CTuitionIncrease* tuitionincrease) {}

    /** Visit a CVillain object
    * \param villain Villain we are visiting */
    virtual void VisitVillain(CVillain* villain) {}

    /** Visit a CWall object
    * \param wall Wall we are visiting */
    virtual void VisitWall(CWall* wall) {}
};