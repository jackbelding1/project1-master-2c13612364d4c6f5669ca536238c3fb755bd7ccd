
// magikoopa.h : main header file for the magikoopa application
//
#pragma once

#ifndef __AFXWIN_H__
	#error "include 'pch.h' before including this file for PCH"
#endif

#include "resource.h"       // main symbols


// CmagikoopaApp:
// See magikoopa.cpp for the implementation of this class
//

class CmagikoopaApp : public CWinApp
{
public:
	CmagikoopaApp() noexcept;


// Overrides
public:
	virtual BOOL InitInstance();
	virtual int ExitInstance();

// Implementation

public:
	afx_msg void OnAppAbout();
	DECLARE_MESSAGE_MAP()

private:
	Gdiplus::GdiplusStartupInput gdiplusStartupInput;
	ULONG_PTR gdiplusToken = 0;
};

extern CmagikoopaApp theApp;
