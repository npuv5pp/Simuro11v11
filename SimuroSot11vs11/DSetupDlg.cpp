// DSetupDlg.cpp : implementation file
//

#include "stdafx.h"
#include "MicroClient.h"
#include "DSetupDlg.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

/////////////////////////////////////////////////////////////////////////////
// DSetupDlg dialog


DSetupDlg::DSetupDlg(CWnd* pParent /*=NULL*/)
	: CDialog(DSetupDlg::IDD, pParent)
{
	//{{AFX_DATA_INIT(DSetupDlg)

	//}}AFX_DATA_INIT	
	m_TeamName = _T("CUG-TRUMP");
	m_ServerName = _T("127.0.0.1");
	m_Channel = 6000;
}


void DSetupDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialog::DoDataExchange(pDX);
	//{{AFX_DATA_MAP(DSetupDlg)

	//}}AFX_DATA_MAP	
	//DDX_Text(pDX, IDC_TEAM, m_TeamName);
	//DDX_Text(pDX, IDC_SERVER, m_ServerName);
	//DDX_Text(pDX, IDC_CHANNEL, m_Channel);
}


BEGIN_MESSAGE_MAP(DSetupDlg, CDialog)
	//{{AFX_MSG_MAP(DSetupDlg)
		// NOTE: the ClassWizard will add message map macros here
	//}}AFX_MSG_MAP
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// DSetupDlg message handlers
