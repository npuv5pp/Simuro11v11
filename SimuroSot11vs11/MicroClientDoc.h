// MicroClientDoc.h : interface of the CMicroClientDoc class
//
/////////////////////////////////////////////////////////////////////////////

#if !defined(AFX_MICROCLIENTDOC_H__801AABEB_2D67_11D4_A201_00400564C758__INCLUDED_)
#define AFX_MICROCLIENTDOC_H__801AABEB_2D67_11D4_A201_00400564C758__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000
class CBaseAgent;
class CMicroClientDoc : public CDocument
{
protected: // create from serialization only
	CMicroClientDoc();
	DECLARE_DYNCREATE(CMicroClientDoc)

// Attributes
public:
	CBaseAgent* m_pAgent;

// Operations
public:

// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CMicroClientDoc)
	public:
	virtual BOOL OnNewDocument();
	virtual void Serialize(CArchive& ar);
	//}}AFX_VIRTUAL

// Implementation
public:
	virtual ~CMicroClientDoc();
#ifdef _DEBUG
	virtual void AssertValid() const;
	virtual void Dump(CDumpContext& dc) const;
#endif

protected:

// Generated message map functions
protected:
	//{{AFX_MSG(CMicroClientDoc)
	afx_msg void OnConnect();
	afx_msg void OnUpdateConnect(CCmdUI* pCmdUI);
	afx_msg void OnDisconnect();
	afx_msg void OnUpdateDisconnect(CCmdUI* pCmdUI);
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};

/////////////////////////////////////////////////////////////////////////////

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_MICROCLIENTDOC_H__801AABEB_2D67_11D4_A201_00400564C758__INCLUDED_)
