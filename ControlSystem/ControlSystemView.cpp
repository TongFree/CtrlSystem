
// ControlSystemView.cpp : CControlSystemView 类的实现
//

#include "pch.h"
#include "framework.h"
// SHARED_HANDLERS 可以在实现预览、缩略图和搜索筛选器句柄的
// ATL 项目中进行定义，并允许与该项目共享文档代码。
#ifndef SHARED_HANDLERS
#include "ControlSystem.h"
#endif

#include "ControlSystemDoc.h"
#include "ControlSystemView.h"
#include "MainFrm.h"


#ifdef _DEBUG
#define new DEBUG_NEW
#endif

// CControlSystemView

IMPLEMENT_DYNCREATE(CControlSystemView, CFormView)

BEGIN_MESSAGE_MAP(CControlSystemView, CFormView)
	ON_BN_CLICKED(IDC_BUTTON1, &CControlSystemView::OnBnClickedButtonH1)
	ON_BN_CLICKED(IDC_BUTTON2, &CControlSystemView::OnBnClickedButtonH2)
	ON_BN_CLICKED(IDC_BUTTON3, &CControlSystemView::OnBnClickedButtonH3)
	ON_BN_CLICKED(IDC_BUTTON4, &CControlSystemView::OnBnClickedButtonH4)
	//ON_WM_SIZE()
// 标准打印命令
	ON_COMMAND(ID_FILE_PRINT, &CControlSystemView::OnFilePrint)
	ON_COMMAND(ID_FILE_PRINT_DIRECT, &CControlSystemView::OnFilePrint)
	ON_COMMAND(ID_FILE_PRINT_PREVIEW, &CControlSystemView::OnFilePrintPreview)
	ON_CBN_SELCHANGE(IDC_COMBO1, &CControlSystemView::OnCbnSelchangeCombo1)
END_MESSAGE_MAP()

void CControlSystemView::DoDataExchange(CDataExchange * pDX)
{
	DDX_Text(pDX, IDC_EDIT1, CPID);
	DDX_Text(pDX, IDC_EDIT2, CPNAME);
	DDX_Control(pDX, IDC_BUTTON1, BUTTONH1);
	DDX_Control(pDX, IDC_BUTTON2, BUTTONH2);
	DDX_Control(pDX, IDC_BUTTON3, BUTTONH3);
	DDX_Control(pDX, IDC_EDIT1, EDITH1);
	DDX_Control(pDX, IDC_EDIT2, EDITH2);
	DDX_Control(pDX, IDC_STATIC1, staticH1);
	DDX_Control(pDX, IDC_COMBO1, pComBox);
}
// CControlSystemView 构造/析构

CControlSystemView::CControlSystemView()
	: CFormView(IDD_CONTROL_FORM)
	, CPID(_T(""))
	, CPNAME(_T(""))
{
	// TODO: 在此处添加构造代码

}

CControlSystemView::~CControlSystemView()
{
}


BOOL CControlSystemView::PreCreateWindow(CREATESTRUCT& cs)
{
	// TODO: 在此处通过修改
	//  CREATESTRUCT cs 来修改窗口类或样式

	return CFormView::PreCreateWindow(cs);
}



void CControlSystemView::OnInitialUpdate()
{
	CFormView::OnInitialUpdate();
	
	m_editFont.CreatePointFont(120, _T("宋体"));
	BUTTONH1.SetFont(&m_editFont);
	BUTTONH2.SetFont(&m_editFont);
	BUTTONH3.SetFont(&m_editFont);
	EDITH1.SetFont(&m_editFont);
	EDITH2.SetFont(&m_editFont);
	GetParentFrame()->RecalcLayout();
	ResizeParentToFit(true);
	UpdateData(true);
	GetDlgItem(IDC_STATIC1)->SetFont(&m_editFont);
	GetDlgItem(IDC_STATIC2)->SetFont(&m_editFont);
	//GetDlgItem(IDC_OPEN_PORT_BTN)->EnableWindow(TRUE);
	//GetDlgItem(IDC_CLOSE_PORT_BTN)->EnableWindow(FALSE);
	//SetWindowPos(NULL, 480, 5200, 640, 480, SWP_NOZORDER);//SWP_NOZORDER   SWP_NOMOVE
	CPID = TEXT("A1");
	CPNAME = TEXT("A1");

	pInfo.OnInitialUpdate();
	for (vector<Product>::iterator it = pInfo.m_vecData.begin(); it != pInfo.m_vecData.end(); it++)
	{
		if (it->state != "删除")
		{
			pComBox.AddString(it->name);
		}
	}
	int a= pComBox.GetCount();


	pComBox.SetCurSel(0);
	pComBox.GetLBText( 0, pName);
	a = pComBox.GetCount();
	UpdateData(false);
}

void CControlSystemView::OnBnClickedButtonH1()
{
	// TODO: 在此添加控件通知处理程序代码
	UpdateData(TRUE);
	if (CPNAME == "A1")
	{
		::PostMessage(AfxGetMainWnd()->GetSafeHwnd(), NM_TV, (LPARAM)NM_TV, (LPARAM)0);
	}
	else
	{
		MessageBox(_T("产品型号错误或未输入产品型号"));
		CPNAME.Empty();
	}
}

void CControlSystemView::OnBnClickedButtonH2()
{
	// TODO: 在此添加控件通知处理程序代码
	::PostMessage(AfxGetMainWnd()->GetSafeHwnd(), NM_USERLOGIN, (LPARAM)NM_USERLOGIN, (LPARAM)0);

}

void CControlSystemView::OnBnClickedButtonH3()
{
	// TODO: 在此添加控件通知处理程序代码
	//m_comm.Write(_T("swrtg4wgfs"));
}

void CControlSystemView::OnBnClickedButtonH4()
{
	// TODO: 在此添加控件通知处理程序代码
	UpdateData(TRUE);
	if (CPNAME == "A1")
	{
		//打开串口
		//m_comm.Open(2);

		::PostMessage(AfxGetMainWnd()->GetSafeHwnd(), NM_TESTVIEW, (LPARAM)NM_TESTVIEW, (LPARAM)0);

		//CDialogEx::OnOK();

	}
	else
	{
		MessageBox(_T("产品型号错误或未输入产品型号"));
		CPNAME.Empty();
	}
}

// CControlSystemView 绘制

void CControlSystemView::OnDraw(CDC* /*pDC*/)
{
	CControlSystemDoc* pDoc = GetDocument();
	ASSERT_VALID(pDoc);
	if (!pDoc)
		return;

	// TODO: 在此处为本机数据添加绘制代码
}


// CControlSystemView 打印

BOOL CControlSystemView::OnPreparePrinting(CPrintInfo* pInfo)
{
	// 默认准备
	return DoPreparePrinting(pInfo);
}

void CControlSystemView::OnBeginPrinting(CDC* /*pDC*/, CPrintInfo* /*pInfo*/)
{
	// TODO: 添加额外的打印前进行的初始化过程
}

void CControlSystemView::OnEndPrinting(CDC* /*pDC*/, CPrintInfo* /*pInfo*/)
{
	// TODO: 添加打印后进行的清理过程
}


// CControlSystemView 诊断

#ifdef _DEBUG

void CControlSystemView::AssertValid() const
{
	CFormView::AssertValid();
}

void CControlSystemView::Dump(CDumpContext& dc) const
{
	CFormView::Dump(dc);
}


CControlSystemDoc* CControlSystemView::GetDocument() const // 非调试版本是内联的
{
	ASSERT(m_pDocument->IsKindOf(RUNTIME_CLASS(CControlSystemDoc)));
	return (CControlSystemDoc*)m_pDocument;
}
#endif //_DEBUG



// CControlSystemView 消息处理程序


// 产品combox
void CControlSystemView::OnCbnSelchangeCombo1()
{
	// TODO: Add your control notification handler code here
	int select = pComBox.GetCurSel();
	pComBox.GetLBText( select, pName);
}
