// MicroClientView.cpp : implementation of the CMicroClientView class
//

#include "stdafx.h"
#include "MicroClient.h"

#include "MicroClientDoc.h"
#include "MicroClientView.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

/////////////////////////////////////////////////////////////////////////////
// CMicroClientView

IMPLEMENT_DYNCREATE(CMicroClientView, CView)

BEGIN_MESSAGE_MAP(CMicroClientView, CView)
	//{{AFX_MSG_MAP(CMicroClientView)
		// NOTE - the ClassWizard will add and remove mapping macros here.
		//    DO NOT EDIT what you see in these blocks of generated code!
	//}}AFX_MSG_MAP
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// CMicroClientView construction/destruction

CMicroClientView::CMicroClientView()
{
	// TODO: add construction code here

}

CMicroClientView::~CMicroClientView()
{
}

BOOL CMicroClientView::PreCreateWindow(CREATESTRUCT& cs)
{
	// TODO: Modify the Window class or styles here by modifying
	//  the CREATESTRUCT cs

	return CView::PreCreateWindow(cs);
}

/////////////////////////////////////////////////////////////////////////////
// CMicroClientView drawing

void CMicroClientView::OnDraw(CDC* pDC)
{
	CMicroClientDoc* pDoc = GetDocument();
	ASSERT_VALID(pDoc);
	// TODO: add draw code for native data here
}

/////////////////////////////////////////////////////////////////////////////
// CMicroClientView diagnostics

#ifdef _DEBUG
void CMicroClientView::AssertValid() const
{
	CView::AssertValid();
}

void CMicroClientView::Dump(CDumpContext& dc) const
{
	CView::Dump(dc);
}

CMicroClientDoc* CMicroClientView::GetDocument() // non-debug version is inline
{
	ASSERT(m_pDocument->IsKindOf(RUNTIME_CLASS(CMicroClientDoc)));
	return (CMicroClientDoc*)m_pDocument;
}
#endif //_DEBUG

/////////////////////////////////////////////////////////////////////////////
// CMicroClientView message handlers
