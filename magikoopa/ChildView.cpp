/**
 * \file ChildView.cpp
 *
 * \author Magikoopa
 *
 * Implementation of the CChildView Class
 */

#include "pch.h"
#include "framework.h"
#include "magikoopa.h"
#include "ChildView.h"
#include "Game.h"
#include "Player.h"
#include "ScoreBoard.h"
#include "DoubleBufferDC.h"
#include <Windows.h>
#include <mmsystem.h>
using namespace Gdiplus;
using namespace std;

#ifdef _DEBUG
#define new DEBUG_NEW
#endif


// Frame duration in milliseconds
const int FrameDuration = 30;

/// Maximum amount of time to allow for elapsed
const double MaxElapsed = 0.050;

// CChildView

CChildView::CChildView()
{
}

CChildView::~CChildView()
{
}


BEGIN_MESSAGE_MAP(CChildView, CWnd)
	ON_WM_PAINT()
    ON_COMMAND(ID_LEVEL_LEVEL0, &CChildView::OnLevelLevel0)
    ON_COMMAND(ID_LEVEL_LEVEL1, &CChildView::OnLevelLevel1)
    ON_COMMAND(ID_LEVEL_LEVEL2, &CChildView::OnLevelLevel2)
    ON_COMMAND(ID_LEVEL_LEVEL3, &CChildView::OnLevelLevel3)
    ON_WM_KEYDOWN()
    ON_WM_KEYUP()
    ON_WM_ERASEBKGND()
    ON_WM_TIMER()
END_MESSAGE_MAP()



// CChildView message handlers

BOOL CChildView::PreCreateWindow(CREATESTRUCT& cs) 
{
	if (!CWnd::PreCreateWindow(cs))
		return FALSE;

	cs.dwExStyle |= WS_EX_CLIENTEDGE;
	cs.style &= ~WS_BORDER;
	cs.lpszClass = AfxRegisterWndClass(CS_HREDRAW|CS_VREDRAW|CS_DBLCLKS, 
		::LoadCursor(nullptr, IDC_ARROW), reinterpret_cast<HBRUSH>(COLOR_WINDOW+1), nullptr);

	return TRUE;
}

void CChildView::OnPaint() 
{
    CPaintDC paintDC(this);     // device context for painting
    CDoubleBufferDC dc(&paintDC); // device context for painting
	
	Graphics graphics(dc.m_hDC);

    if (mFirstDraw)
    {
        mFirstDraw = false;
        SetTimer(1, FrameDuration, nullptr);

        PlaySound(TEXT("images/darude.wav"), NULL, SND_ASYNC);
        /*
        * Initialize the elapsed time system
        */
        LARGE_INTEGER time, freq;
        QueryPerformanceCounter(&time);
        QueryPerformanceFrequency(&freq);

        mLastTime = time.QuadPart;
        mTimeFreq = double(freq.QuadPart);

        mGame.Load(L"levels/level1.xml");
    }

    /*
    * Compute the elapsed time since the last draw
    */
    LARGE_INTEGER time;
    QueryPerformanceCounter(&time);
    long long diff = time.QuadPart - mLastTime;
    double elapsed = double(diff) / mTimeFreq;
    mLastTime = time.QuadPart;


    //
    // Prevent tunnelling
    //
    while (elapsed > MaxElapsed)
    {
        mGame.Update(MaxElapsed);

        elapsed -= MaxElapsed;
    }
    // Consume any remaining time
    if (elapsed > 0)
    {
        mGame.Update(elapsed);
    }

    // Rectangle screen size to handle scaling/scrolling
    CRect rect;
    GetClientRect(&rect);

    mGame.OnDraw(&graphics, rect.Width(), rect.Height());


}


void CChildView::OnLevelLevel0()
{
    mGame.SetLevel(0);
    mGame.Install();
}


void CChildView::OnLevelLevel1()
{
    mGame.SetLevel(1);
    mGame.Install();
}


void CChildView::OnLevelLevel2()
{
    mGame.SetLevel(2);
    mGame.Install();
}


void CChildView::OnLevelLevel3()
{
    mGame.SetLevel(3);
    mGame.Install();
}


void CChildView::OnKeyDown(UINT nChar, UINT nRepCnt, UINT nFlags)
{
    switch (nChar)
    {
    case VK_RIGHT:
        // right arrow pressed
        mGame.GetPlayer()->SetVelocityX(500);
        break;

    case VK_LEFT:
        // left arrow pressed
        mGame.GetPlayer()->SetVelocityX(-500);
        break;

    case VK_SPACE:
        // space bar pressed
        mGame.GetPlayer()->SetVelocityY(-800);
        break;
    }
}


void CChildView::OnKeyUp(UINT nChar, UINT nRepCnt, UINT nFlags)
{
    switch (nChar)
    {
    // left or right arrow released
    case VK_RIGHT:
        mGame.GetPlayer()->SetVelocityX(0);
        break;
    case VK_LEFT:
        mGame.GetPlayer()->SetVelocityX(0);
        break;
    }
}

/**
 * Erase the background
 *
 * This is disabled to eliminate flicker
 * \param pDC Device context
 * \returns FALSE
 */
BOOL CChildView::OnEraseBkgnd(CDC* pDC)
{
    return FALSE;
}


/**
 * Handle timer events
 * \param nIDEvent The timer event ID
 */
void CChildView::OnTimer(UINT_PTR nIDEvent)
{
    Invalidate();
    CWnd::OnTimer(nIDEvent);
}
