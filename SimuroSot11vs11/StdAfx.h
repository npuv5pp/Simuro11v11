// stdafx.h : include file for standard system include files,
//  or project specific include files that are used frequently, but
//      are changed infrequently
//

#if !defined(AFX_STDAFX_H__801AABE7_2D67_11D4_A201_00400564C758__INCLUDED_)
#define AFX_STDAFX_H__801AABE7_2D67_11D4_A201_00400564C758__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

#define VC_EXTRALEAN		// Exclude rarely-used stuff from Windows headers

#include <afxwin.h>         // MFC core and standard components
#include <afxext.h>         // MFC extensions
#include <afxdisp.h>        // MFC Automation classes
#include <afxdtctl.h>		// MFC support for Internet Explorer 4 Common Controls
#ifndef _AFX_NO_AFXCMN_SUPPORT
#include <afxcmn.h>			// MFC support for Windows Common Controls
#endif // _AFX_NO_AFXCMN_SUPPORT

#include <afxsock.h>		// MFC socket extensions
#include <math.h>

#define LEFT_TO_RIGHT	0
#define RIGHT_TO_LEFT	1
#define MAX_PLAYER 3
#define OWN_TEAM 0
#define OTHER_TEAM 1

typedef struct pos_t{
	short	enable ;
	short	side ;
	short	unum ;
	short	angle ;
	short	x ;
	short	y ;
} pos_t ;

typedef struct send_to_team{
		pos_t	pos[MAX_PLAYER * 2] ;

}send_to_team;

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_STDAFX_H__801AABE7_2D67_11D4_A201_00400564C758__INCLUDED_)
