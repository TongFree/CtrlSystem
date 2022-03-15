
// ControlSystemView.cpp : CControlSystemView ���ʵ��
//

#include "pch.h"
#include "framework.h"
// SHARED_HANDLERS ������ʵ��Ԥ��������ͼ������ɸѡ�������
// ATL ��Ŀ�н��ж��壬�����������Ŀ�����ĵ����롣
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
// ��׼��ӡ����
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
// CControlSystemView ����/����

CControlSystemView::CControlSystemView()
	: CFormView(IDD_CONTROL_FORM)
	, CPID(_T(""))
	, CPNAME(_T(""))
{
	// TODO: �ڴ˴���ӹ������

}

CControlSystemView::~CControlSystemView()
{
}


BOOL CControlSystemView::PreCreateWindow(CREATESTRUCT& cs)
{
	// TODO: �ڴ˴�ͨ���޸�
	//  CREATESTRUCT cs ���޸Ĵ��������ʽ

	return CFormView::PreCreateWindow(cs);
}



void CControlSystemView::OnInitialUpdate()
{
	CFormView::OnInitialUpdate();
	
	m_editFont.CreatePointFont(120, _T("����"));
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
		if (it->state != "ɾ��")
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
	// TODO: �ڴ���ӿؼ�֪ͨ����������
	UpdateData(TRUE);
	if (CPNAME == "A1")
	{
		::PostMessage(AfxGetMainWnd()->GetSafeHwnd(), NM_TV, (LPARAM)NM_TV, (LPARAM)0);
	}
	else
	{
		MessageBox(_T("��Ʒ�ͺŴ����δ�����Ʒ�ͺ�"));
		CPNAME.Empty();
	}
}

void CControlSystemView::OnBnClickedButtonH2()
{
	// TODO: �ڴ���ӿؼ�֪ͨ����������
	::PostMessage(AfxGetMainWnd()->GetSafeHwnd(), NM_USERLOGIN, (LPARAM)NM_USERLOGIN, (LPARAM)0);

}

void CControlSystemView::OnBnClickedButtonH3()
{
	// TODO: �ڴ���ӿؼ�֪ͨ����������
	//m_comm.Write(_T("swrtg4wgfs"));
}

void CControlSystemView::OnBnClickedButtonH4()
{
	// TODO: �ڴ���ӿؼ�֪ͨ����������
	UpdateData(TRUE);
	if (CPNAME == "A1")
	{
		//�򿪴���
		//m_comm.Open(2);

		::PostMessage(AfxGetMainWnd()->GetSafeHwnd(), NM_TESTVIEW, (LPARAM)NM_TESTVIEW, (LPARAM)0);

		//CDialogEx::OnOK();

	}
	else
	{
		MessageBox(_T("��Ʒ�ͺŴ����δ�����Ʒ�ͺ�"));
		CPNAME.Empty();
	}
}

// CControlSystemView ����

void CControlSystemView::OnDraw(CDC* /*pDC*/)
{
	CControlSystemDoc* pDoc = GetDocument();
	ASSERT_VALID(pDoc);
	if (!pDoc)
		return;

	// TODO: �ڴ˴�Ϊ����������ӻ��ƴ���
}


// CControlSystemView ��ӡ

BOOL CControlSystemView::OnPreparePrinting(CPrintInfo* pInfo)
{
	// Ĭ��׼��
	return DoPreparePrinting(pInfo);
}

void CControlSystemView::OnBeginPrinting(CDC* /*pDC*/, CPrintInfo* /*pInfo*/)
{
	// TODO: ��Ӷ���Ĵ�ӡǰ���еĳ�ʼ������
}

void CControlSystemView::OnEndPrinting(CDC* /*pDC*/, CPrintInfo* /*pInfo*/)
{
	// TODO: ��Ӵ�ӡ����е��������
}


// CControlSystemView ���

#ifdef _DEBUG

void CControlSystemView::AssertValid() const
{
	CFormView::AssertValid();
}

void CControlSystemView::Dump(CDumpContext& dc) const
{
	CFormView::Dump(dc);
}


CControlSystemDoc* CControlSystemView::GetDocument() const // �ǵ��԰汾��������
{
	ASSERT(m_pDocument->IsKindOf(RUNTIME_CLASS(CControlSystemDoc)));
	return (CControlSystemDoc*)m_pDocument;
}
#endif //_DEBUG



// CControlSystemView ��Ϣ�������


// ��Ʒcombox
void CControlSystemView::OnCbnSelchangeCombo1()
{
	// TODO: Add your control notification handler code here
	int select = pComBox.GetCurSel();
	pComBox.GetLBText( select, pName);
}
