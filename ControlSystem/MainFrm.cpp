
// MainFrm.cpp : CMainFrame ���ʵ��
//

#include "pch.h"
#include "framework.h"
#include "MainFrm.h"
#include "Resource.h"

#include "CnComm.h"


#include "ControlSystemView.h"
#include "TestView.h"
#include "AdmainView.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#endif

// CMainFrame
IMPLEMENT_DYNCREATE(CMainFrame, CFrameWnd)

//const int  iMaxUserToolbars = 10;
//const UINT uiFirstUserToolBarId = AFX_IDW_CONTROLBAR_FIRST + 40;
//const UINT uiLastUserToolBarId = uiFirstUserToolBarId + iMaxUserToolbars - 1;

BEGIN_MESSAGE_MAP(CMainFrame, CFrameWnd)
	ON_WM_CREATE()

	//ON_MESSAGE��Ӧ�����Զ�����Ϣ
	//����NM_X��Ϣ���Զ�����OnMyChange����
	ON_MESSAGE(NM_A, OnMyChange)
	ON_MESSAGE(NM_B, OnMyChange)
	ON_MESSAGE(NM_C, OnMyChange)
	ON_MESSAGE(NM_D, OnMyChange)
	ON_MESSAGE(NM_TV, OnMyChange)
	ON_MESSAGE(NM_C_ONE, OnMyChange)
	ON_MESSAGE(NM_C_TWO, OnMyChange)
	ON_MESSAGE(NM_C_THREE, OnMyChange)
	ON_MESSAGE(NM_C_FOUR, OnMyChange)
	ON_MESSAGE(NM_C_FIVE, OnMyChange)
	ON_MESSAGE(NM_C_SIX, OnMyChange)
	ON_MESSAGE(NM_C_SEVEN, OnMyChange)
	ON_MESSAGE(NM_C_EIGHT, OnMyChange)
	ON_MESSAGE(NM_C_NINE, OnMyChange)
	ON_MESSAGE(NM_C_TEN, OnMyChange)
	ON_MESSAGE(NM_C_ELEVEN, OnMyChange)
	ON_MESSAGE(NM_USERLOGIN, OnMyChange)
	ON_MESSAGE(NM_XIUGAI, OnMyChange)
	ON_MESSAGE(NM_NEW, OnMyChange)
	ON_MESSAGE(NM_LEFTVIEW, OnMyChange)

	ON_MESSAGE(NM_DISPLAY, OnMyChange)
	ON_MESSAGE(NM_TESTVIEW, OnMyChange)

	//ON_WM_SIZE()
//	ON_COMMAND(ID_FILE_CLOSE, &CMainFrame::OnFileClose)
END_MESSAGE_MAP()

static UINT indicators[] =
{
	ID_SEPARATOR,           // ״̬��ָʾ��
	ID_INDICATOR_CAPS,
	ID_INDICATOR_NUM,
	ID_INDICATOR_SCRL,
};

// CMainFrame ����/����

CMainFrame::CMainFrame()
{
	// TODO: �ڴ���ӳ�Ա��ʼ������
}

CMainFrame::~CMainFrame()
{
}

int CMainFrame::OnCreate(LPCREATESTRUCT lpCreateStruct)
{
	if (CFrameWnd::OnCreate(lpCreateStruct) == -1)
		return -1;

	if (!m_wndStatusBar.Create(this))
	{
		TRACE0("δ�ܴ���״̬��\n");
		return -1;      // δ�ܴ���
	}
	m_wndStatusBar.SetIndicators(indicators, sizeof(indicators)/sizeof(UINT));
	//����ͼ��
	//SetClassLong(m_hWnd, GCLP_HICON, (LONG)AfxGetApp()->LoadIconA(IDI_ICON_MAN));
	//SetClassLongPtr(m_hWnd, GCLP_HICON, (LONG)AfxGetApp()->LoadIconA(IDI_ICON_MAN));

	//���ñ��� �Ҳ����
	//SetTitle(TEXT("V1.0"));

	//���ô��ڴ�С�;�����ʾ Move Window �ĸ�����ǰ����Ϊ���ڵĳ�ʼλ�� ������Ϊ���ڳ�ʼ��С
	//���ô��ھ�����ʾ
	CenterWindow();
	//resize();
	// TODO: �������Ҫ��ͣ������������ɾ��������
	//m_wndToolBar.EnableDocking(CBRS_ALIGN_ANY);
	//EnableDocking(CBRS_ALIGN_ANY);
	//DockControlBar(&m_wndToolBar);


	return 0;
}



BOOL CMainFrame::PreCreateWindow(CREATESTRUCT& cs)
{
	//cs.style = cs.style&~WS_MAXIMIZEBOX; // 
	//cs.style &= ~WS_THICKFRAME;//ʹ���ڲ��������ı��С
	if( !CFrameWnd::PreCreateWindow(cs) )
		return FALSE;
	// TODO: �ڴ˴�ͨ���޸�
	//  CREATESTRUCT cs ���޸Ĵ��������ʽ

	return TRUE;
}

// CMainFrame ���

#ifdef _DEBUG
void CMainFrame::AssertValid() const
{
	CFrameWnd::AssertValid();
}

void CMainFrame::Dump(CDumpContext& dc) const
{
	CFrameWnd::Dump(dc);
}
#endif //_DEBUG


// CMainFrame ��Ϣ�������



//BOOL CMainFrame::LoadFrame(UINT nIDResource, DWORD dwDefaultStyle, CWnd* pParentWnd, CCreateContext* pContext) 
//{
//	// ���ཫִ�������Ĺ���
//
//	if (!CFrameWnd::LoadFrame(nIDResource, dwDefaultStyle, pParentWnd, pContext))
//	{
//		return FALSE;
//	}
//
//	CWinApp* pApp = AfxGetApp();
//	if (pApp->m_pMainWnd == NULL)
//		pApp->m_pMainWnd = this;
//
//	// �ø������ڵġ��رա��滻���ļ����˵��ϵġ��˳���ѡ��
//	if (AfxGetApp()->m_pMainWnd != this)
//	{
//		CMenu *pMenu = GetMenu();
//		ASSERT(pMenu);
//		BOOL bNameValid;
//		CString strTemp;
//		bNameValid = strTemp.LoadString(IDS_CLOSE);
//		ASSERT(bNameValid);
//		pMenu->ModifyMenu(ID_APP_EXIT, MF_BYCOMMAND | MF_STRING, ID_FILE_CLOSE, strTemp);
//	}
//
//	return TRUE;
//}


//void CMainFrame::OnFileClose()
//{
//	DestroyWindow();
//}

LRESULT CMainFrame::OnMyChange(WPARAM wParam, LPARAM lParam)
{
	CCreateContext Context;
	switch (wParam)
	{
	case NM_A:
	{
		CDocument *pDoc = GetActiveDocument();
		Context.m_pNewViewClass = RUNTIME_CLASS(CControlSystemView);
		Context.m_pCurrentDoc = pDoc;
		Context.m_pCurrentFrame = this;

		CView *pNewView = (CView *)this->CreateView(&Context);
		pNewView->OnInitialUpdate();
		GetActiveView()->DestroyWindow();
		this->SetActiveView(pNewView);  //�����ֶ�������ͼActive״̬
		this->ShowWindow(SW_SHOW); //�ֶ����ÿɼ�
		this->RecalcLayout();
		//MessageBox(_T("NM_A"));
	}
	break;
	case NM_TV:
	{
		
		CControlSystemView* csView = (CControlSystemView*)GetActiveView();
		// ����
		// ��Ʒ����
		CString pName = csView->pName;
		// �û���
		CString mUser = csView->CPNAME;
		CDocument *pDoc = GetActiveDocument();
		Context.m_pNewViewClass = RUNTIME_CLASS(CTestView);
		Context.m_pCurrentDoc = pDoc;
		Context.m_pCurrentFrame = this;
		CView* pNewView = (CView*)this->CreateView(&Context);
		CTestView* ctView = (CTestView*)pNewView;
		ctView->pEdit = pName;
		ctView->m_user = mUser;
		pNewView->OnInitialUpdate();
		GetActiveView()->DestroyWindow();

		this->SetActiveView(pNewView);  //�����ֶ�������ͼActive״̬
		this->ShowWindow(SW_SHOW); //�ֶ����ÿɼ�
		this->RecalcLayout();
		
		//MessageBox(_T("NM_D"));


	}
	break;
	case  NM_USERLOGIN:
	{

		CDocument *pDoc = GetActiveDocument();
		Context.m_pNewViewClass = RUNTIME_CLASS(CAdmainView);
		Context.m_pCurrentDoc = pDoc;
		Context.m_pCurrentFrame = this;

		CView *pNewView = (CView *)this->CreateView(&Context);

		pNewView->OnInitialUpdate();
		GetActiveView()->DestroyWindow();
		this->SetActiveView(pNewView);  //�����ֶ�������ͼActive״̬
		this->ShowWindow(SW_SHOW); //�ֶ����ÿɼ�
		this->RecalcLayout();
	}
	break;
	default:
	{

	}
	}

	return 0;//LRESULT();
}

void CMainFrame::Onsize(UINT nType, int cx, int cy)
{
}

void CMainFrame::resize()
{
}


//BOOL CMainFrame::OnCreateClient(LPCREATESTRUCT lpcs, CCreateContext* pContext)
//{
//	// TODO: Add your specialized code here and/or call the base class
//	//if (!m_spliter.CreateStatic(this, 1, 2))
//	//{
//	//	return FALSE;
//	//}
//	//CRect rect;
//	//GetClientRect(&rect);
//	//if (!m_spliter.CreateView(0, 0, RUNTIME_CLASS(CSelectViewThree), CSize(0, 0), pContext)
//	//|| !m_spliter.CreateView(0, 1, RUNTIME_CLASS(CDisplayView), CSize(rect.Width(),rect.Height()), pContext))
//	//{
//	//	return FALSE;
//	//}
//
//
//	return CFrameWnd::OnCreateClient(lpcs, pContext);
//}

