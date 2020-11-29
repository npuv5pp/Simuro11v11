// MicroClientView.h : interface of the CMicroClientView class
//
/////////////////////////////////////////////////////////////////////////////

#if !defined(AFX_MICROCLIENTVIEW_H__801AABED_2D67_11D4_A201_00400564C758__INCLUDED_)
#define AFX_MICROCLIENTVIEW_H__801AABED_2D67_11D4_A201_00400564C758__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000


class CMicroClientView : public CView
{
protected: // create from serialization only
	CMicroClientView();
	DECLARE_DYNCREATE(CMicroClientView)

// Attributes
public:
	CMicroClientDoc* GetDocument();

// Operations
public:

// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CMicroClientView)
	public:
	virtual void OnDraw(CDC* pDC);  // overridden to draw this view
	virtual BOOL PreCreateWindow(CREATESTRUCT& cs);
	protected:
	//}}AFX_VIRTUAL

// Implementation
public:
	virtual ~CMicroClientView();
#ifdef _DEBUG
	virtual void AssertValid() const;
	virtual void Dump(CDumpContext& dc) const;
#endif

protected:

// Generated message map functions
protected:
	//{{AFX_MSG(CMicroClientView)
		// NOTE - the ClassWizard will add and remove member functions here.
		//    DO NOT EDIT what you see in these blocks of generated code !
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};

#ifndef _DEBUG  // debug version in MicroClientView.cpp
inline CMicroClientDoc* CMicroClientView::GetDocument()
   { return (CMicroClientDoc*)m_pDocument; }
#endif

/////////////////////////////////////////////////////////////////////////////

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_MICROCLIENTVIEW_H__801AABED_2D67_11D4_A201_00400564C758__INCLUDED_)
