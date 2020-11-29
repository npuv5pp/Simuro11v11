// MicroClient.h : main header file for the MICROCLIENT application
//

#if !defined(AFX_MICROCLIENT_H__801AABE5_2D67_11D4_A201_00400564C758__INCLUDED_)
#define AFX_MICROCLIENT_H__801AABE5_2D67_11D4_A201_00400564C758__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

#ifndef __AFXWIN_H__
	#error include 'stdafx.h' before including this file for PCH
#endif

#include "resource.h"       // main symbols

/////////////////////////////////////////////////////////////////////////////
// CMicroClientApp:
// See MicroClient.cpp for the implementation of this class
//

class CMicroClientApp : public CWinApp
{
public:
	CMicroClientApp();

// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CMicroClientApp)
	public:
	virtual BOOL InitInstance();
	//}}AFX_VIRTUAL

// Implementation
	//{{AFX_MSG(CMicroClientApp)
	afx_msg void OnAppAbout();
		// NOTE - the ClassWizard will add and remove member functions here.
		//    DO NOT EDIT what you see in these blocks of generated code !
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};


/////////////////////////////////////////////////////////////////////////////

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_MICROCLIENT_H__801AABE5_2D67_11D4_A201_00400564C758__INCLUDED_)
