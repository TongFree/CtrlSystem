
// MainFrm.cpp : CMainFrame 类的实现
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

	//ON_MESSAGE响应的是自定义消息
	//产生NM_X消息，自动调用OnMyChange函数
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
	ID_SEPARATOR,           // 状态行指示器
	ID_INDICATOR_CAPS,
	ID_INDICATOR_NUM,
	ID_INDICATOR_SCRL,
};

// CMainFrame 构造/析构

CMainFrame::CMainFrame()
{
	// TODO: 在此添加成员初始化代码
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
		TRACE0("未能创建状态栏\n");
		return -1;      // 未能创建
	}
	m_wndStatusBar.SetIndicators(indicators, sizeof(indicators)/sizeof(UINT));
	//设置图标
	//SetClassLong(m_hWnd, GCLP_HICON, (LONG)AfxGetApp()->LoadIconA(IDI_ICON_MAN));
	//SetClassLongPtr(m_hWnd, GCLP_HICON, (LONG)AfxGetApp()->LoadIconA(IDI_ICON_MAN));

	//设置标题 右侧标题
	//SetTitle(TEXT("V1.0"));

	//设置窗口大小和居中显示 Move Window 四个参数前两个为窗口的初始位置 后两个为窗口初始大小
	//设置窗口居中显示
	CenterWindow();
	//resize();
	// TODO: 如果不需要可停靠工具栏，则删除这三行
	//m_wndToolBar.EnableDocking(CBRS_ALIGN_ANY);
	//EnableDocking(CBRS_ALIGN_ANY);
	//DockControlBar(&m_wndToolBar);


	return 0;
}



BOOL CMainFrame::PreCreateWindow(CREATESTRUCT& cs)
{
	//cs.style = cs.style&~WS_MAXIMIZEBOX; // 
	//cs.style &= ~WS_THICKFRAME;//使窗口不能用鼠标改变大小
	if( !CFrameWnd::PreCreateWindow(cs) )
		return FALSE;
	// TODO: 在此处通过修改
	//  CREATESTRUCT cs 来修改窗口类或样式

	return TRUE;
}

// CMainFrame 诊断

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


// CMainFrame 消息处理程序



//BOOL CMainFrame::LoadFrame(UINT nIDResource, DWORD dwDefaultStyle, CWnd* pParentWnd, CCreateContext* pContext) 
//{
//	// 基类将执行真正的工作
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
//	// 用辅助窗口的“关闭”替换“文件”菜单上的“退出”选项
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
		this->SetActiveView(pNewView);  //必须手动设置视图Active状态
		this->ShowWindow(SW_SHOW); //手动设置可见
		this->RecalcLayout();
		//MessageBox(_T("NM_A"));
	}
	break;
	case NM_TV:
	{
		
		CControlSystemView* csView = (CControlSystemView*)GetActiveView();
		// 传递
		// 产品名称
		CString pName = csView->pName;
		// 用户名
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

		this->SetActiveView(pNewView);  //必须手动设置视图Active状态
		this->ShowWindow(SW_SHOW); //手动设置可见
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
		this->SetActiveView(pNewView);  //必须手动设置视图Active状态
		this->ShowWindow(SW_SHOW); //手动设置可见
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

