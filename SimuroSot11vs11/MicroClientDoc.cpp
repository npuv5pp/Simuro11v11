// MicroClientDoc.cpp : implementation of the CMicroClientDoc class
//

#include "stdafx.h"
#include "MicroClient.h"
#include "BaseAgent.h"
#include "DSetupDlg.h"
#include "MicroClientDoc.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif
//FILE* fp;
/////////////////////////////////////////////////////////////////////////////
// CMicroClientDoc

IMPLEMENT_DYNCREATE(CMicroClientDoc, CDocument)

BEGIN_MESSAGE_MAP(CMicroClientDoc, CDocument)
	//{{AFX_MSG_MAP(CMicroClientDoc)
	ON_COMMAND(ID_CONNECT, OnConnect)
	ON_UPDATE_COMMAND_UI(ID_CONNECT, OnUpdateConnect)
	ON_COMMAND(ID_DISCONNECT, OnDisconnect)
	ON_UPDATE_COMMAND_UI(ID_DISCONNECT, OnUpdateDisconnect)
	//}}AFX_MSG_MAP
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// CMicroClientDoc construction/destruction

CMicroClientDoc::CMicroClientDoc()
{
	// TODO: add one-time construction code here

}

CMicroClientDoc::~CMicroClientDoc()
{
}

BOOL CMicroClientDoc::OnNewDocument()
{
	if (!CDocument::OnNewDocument())
		return FALSE;

	// TODO: add reinitialization code here
	// (SDI documents will reuse this document)
	m_pAgent=new CBaseAgent(this);
//	fp=fopen("cht.doc","w");

	return TRUE;
}



/////////////////////////////////////////////////////////////////////////////
// CMicroClientDoc serialization

void CMicroClientDoc::Serialize(CArchive& ar)
{
	if (ar.IsStoring())
	{
		// TODO: add storing code here
	}
	else
	{
		// TODO: add loading code here
	}
}

/////////////////////////////////////////////////////////////////////////////
// CMicroClientDoc diagnostics

#ifdef _DEBUG
void CMicroClientDoc::AssertValid() const
{
	CDocument::AssertValid();
}

void CMicroClientDoc::Dump(CDumpContext& dc) const
{
	CDocument::Dump(dc);
}
#endif //_DEBUG

/////////////////////////////////////////////////////////////////////////////
// CMicroClientDoc commands

void CMicroClientDoc::OnConnect() 
{
	// TODO: Add your command handler code here
//	m_pAgent->Connect();
	DSetupDlg Dialog;

	// ask the user for the name of the team and the server
	Dialog.m_TeamName = _T("CUG-TRUMP");
	Dialog.m_ServerName = _T("127.0.0.1");
	Dialog.m_Channel = 6000;
	
	// user can repeat with a different address	while(TRUE)
	{
		
		// try to connect
		if (m_pAgent->ConnectAgent(Dialog.m_TeamName, Dialog.m_ServerName, Dialog.m_Channel))
			return ;//TRUE;
		if (Dialog.DoModal() != IDOK)
			return ;//FALSE;
		
	}
	m_pAgent->teamname=Dialog.m_TeamName;
}

void CMicroClientDoc::OnUpdateConnect(CCmdUI* pCmdUI) 
{
	// TODO: Add your command update UI handler code here
	//pCmdUI->
	
}

void CMicroClientDoc::OnDisconnect() 
{
	// TODO: Add your command handler code here
//	fclose(fp);
	
}

void CMicroClientDoc::OnUpdateDisconnect(CCmdUI* pCmdUI) 
{
	// TODO: Add your command update UI handler code here
	//pCmdUI->
}
