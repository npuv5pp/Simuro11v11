#if !defined(AFX_DSETUPDLG_H__AF3ADFE0_2D54_11D4_8C19_000021D262EF__INCLUDED_)
#define AFX_DSETUPDLG_H__AF3ADFE0_2D54_11D4_8C19_000021D262EF__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000
// DSetupDlg.h : header file
//

/////////////////////////////////////////////////////////////////////////////
// DSetupDlg dialog

class DSetupDlg : public CDialog
{
// Construction
public:
	DSetupDlg(CWnd* pParent = NULL);   // standard constructor

// Dialog Data
	//{{AFX_DATA(DSetupDlg)
	enum { IDD = IDD_DIALOG1 };

	//}}AFX_DATA


// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(DSetupDlg)
	protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV support
	//}}AFX_VIRTUAL
public:
	CString	m_TeamName;
	CString	m_ServerName;
	UINT	m_Channel;
// Implementation
protected:

	// Generated message map functions
	//{{AFX_MSG(DSetupDlg)
		// NOTE: the ClassWizard will add member functions here
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_DSETUPDLG_H__AF3ADFE0_2D54_11D4_8C19_000021D262EF__INCLUDED_)
