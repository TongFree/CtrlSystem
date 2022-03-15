// TestView.cpp : implementation file
//

#include "pch.h"
#include "stdafx.h"
#include "Markup.h"
#include "ControlSystem.h"
#include "TestView.h"
#include "TestAdd.h"
#include "MainFrm.h"
#include "uuid.h"


// CTestView 

IMPLEMENT_DYNCREATE(CTestView, CFormView)

CTestView::CTestView()
	: CFormView(IDD_TESTVIEW)
	, m_user(_T(""))
	, test_Msg(_T(""))
	, test_total(_T(""))
	, test_current(_T(""))
{

}

CTestView::~CTestView()
{
}

void CTestView::DoDataExchange(CDataExchange* pDX)
{
	CFormView::DoDataExchange(pDX);
	DDX_Text(pDX, IDC_EDIT17, m_user);
	DDX_Text(pDX, IDC_EDIT2, test_Msg);
	DDX_Text(pDX, IDC_EDIT18, test_total);
	DDX_Text(pDX, IDC_EDIT19, test_current);
	DDX_Control(pDX, IDC_LIST1, test_list_left);
	DDX_Control(pDX, IDC_LIST2, test_list_right);
	DDX_Control(pDX, IDC_BUTTON2, m_btnAdd);
	DDX_Control(pDX, IDC_BUTTON6, m_btnDel);
	DDX_Control(pDX, IDC_EDIT55, m_editQueryText);
	DDX_Control(pDX, IDC_COMBO1, pComBox);
}


BEGIN_MESSAGE_MAP(CTestView, CFormView)
	ON_BN_CLICKED(IDC_BUTTON3, &CTestView::OnBnClickedButton3)
	ON_BN_CLICKED(IDC_BUTTON5, &CTestView::OnBnClickedButton5)
	ON_BN_CLICKED(IDC_BUTTON2, &CTestView::OnBnClickedButton2)
	ON_BN_CLICKED(IDC_BUTTON6, &CTestView::OnBnClickedButton6)
	ON_NOTIFY(LVN_ITEMCHANGED, IDC_LIST1, &CTestView::OnLvnItemchangedList1)
	ON_BN_CLICKED(IDC_BUTTON1, &CTestView::OnBnClickedButton1)
	ON_BN_CLICKED(IDC_BUTTONQuery, &CTestView::OnBnClickedButtonquery)
	ON_BN_CLICKED(IDC_BUTTONQuery, &CTestView::OnBnClickedButtonquery)
	ON_BN_CLICKED(IDC_BUTTONQuery, &CTestView::OnBnClickedButtonquery)
	ON_BN_CLICKED(IDC_BUTTONQuery, &CTestView::OnBnClickedButtonquery)
	ON_NOTIFY(LVN_ITEMCHANGED, IDC_LIST2, &CTestView::OnLvnItemchangedList2)
	ON_BN_CLICKED(IDC_BUTTON9, &CTestView::OnBnClickedButton9)
	ON_CBN_SELCHANGE(IDC_COMBO1, &CTestView::OnCbnSelchangeCombo1)
END_MESSAGE_MAP()


// ��ʼ������

void CTestView::OnInitialUpdate()
{
	CFormView::OnInitialUpdate();

	// ��Ʒ�б�
	pInfo.OnInitialUpdate();

	for (vector<Product>::iterator it = pInfo.m_vecData.begin(); it != pInfo.m_vecData.end(); it++)
	{
		if (it->state != "ɾ��")
		{
			pComBox.AddString(it->name);
		}
	}


	pComBox.SetCurSel(0);
	pComBox.GetLBText(0, pEdit);

	// ��ʼ��Info���
	test_list_left.SetExtendedStyle(LVS_EX_GRIDLINES | LVS_EX_FULLROWSELECT);
	test_list_left.InsertColumn(0, _T("ID"), LVCFMT_LEFT, 50);
	test_list_left.InsertColumn(1, _T("��������"), LVCFMT_LEFT, 100);
	test_list_left.InsertColumn(2, _T("��ʼ����"), LVCFMT_LEFT, 100);
	test_list_left.InsertColumn(3, _T("��������"), LVCFMT_LEFT, 100);
	test_list_left.InsertColumn(4, _T("����"), LVCFMT_LEFT, 50);
	test_list_left.InsertColumn(5, _T("����"), LVCFMT_LEFT, 50);
	test_list_left.InsertColumn(6, _T("���"), LVCFMT_LEFT, 100);
	test_list_left.InsertColumn(7, _T("����״̬"), LVCFMT_LEFT, 50);
	test_list_left.InsertColumn(8, _T("ʱ��"), LVCFMT_LEFT, 50);
	test_list_left.InsertColumn(9, _T("���"), LVCFMT_LEFT, 50);


	test_list_left.SetFocus();
	info.list = &test_list_left;
	info.m_editQueryText = &m_editQueryText;
	// ��ʼ��Ϣ��¼���
	test_list_right.SetExtendedStyle(LVS_EX_GRIDLINES | LVS_EX_FULLROWSELECT);
	test_list_right.InsertColumn(0, _T("ID"), LVCFMT_LEFT, 50);
	test_list_right.InsertColumn(1, _T("��������"), LVCFMT_LEFT, 100);
	test_list_right.InsertColumn(2, _T("���к�"), LVCFMT_LEFT, 100);
	test_list_right.InsertColumn(3, _T("��¼"), LVCFMT_LEFT, 100);
	test_list_right.InsertColumn(4, _T("ʱ��"), LVCFMT_LEFT, 100);
	test_list_right.InsertColumn(5, _T("����Ա"), LVCFMT_LEFT, 50);
	test_list_right.InsertColumn(6, _T("״̬"), LVCFMT_LEFT, 50);


	test_list_right.SetFocus();
	record.list = &test_list_right;
	// ��ʼ�������Ϣ


	GetClientRect(&m_rect);
	m_pointOld.x = m_rect.right - m_rect.left;
	m_pointOld.y = m_rect.bottom - m_rect.top;
	m_btnAdd.GetClientRect(&m_rectBtn);

	// ���� ��¼info
	info.OnInitialUpdate();
	info.RefreshData(pEdit);
	// ���� ��¼���
	record.OnInitialUpdate();

}


// CTestView message handlers 
// ��ʼ����
// Ŀǰ��ģ�����
void CTestView::OnBnClickedButton3()
{
	// TODO: Add your control notification handler code here
//	comm.Write(_T("���Կ�ʼ"));

	RecordData rd;
	CString testName = test_list_left.GetItemText(test_list_left.GetSelectionMark(), 1);
	CString serial = test_list_left.GetItemText(test_list_left.GetSelectionMark(), 9);
	rd.tName = testName;
	rd.tSerial = serial;
	rd.opUser = m_user;

	CTime time = CTime::GetCurrentTime();
	CString timeRand;
	timeRand.Format(_T("%04d%02d%02d %02d:%02d:%02d"), time.GetYear(), time.GetMonth(), time.GetDay(), time.GetHour(), time.GetMinute(), time.GetSecond());
	rd.recordTime = timeRand;

	int rand = time.GetSecond();


	rd.serial = genUUID();
	//rd.serialCode.Format(_T("%d"), n);
	rd.state = "�½�";
	record.m_vecData.push_back(rd);
	record.RefreshData(testName);


}




// �������ݰ�ť
void CTestView::OnBnClickedButton5()
{
	// TODO: Add your control notification handler code here
	// ������Լ�¼

}

// ������ݰ�ť   From: �������Dlg�����ڱ���ͼButton����
void CTestView::OnBnClickedButton2()
{
	// TODO: Add your control notification handler code here
	// TODO: �ڴ���ӿؼ�֪ͨ����������

	TestAdd addEdit;
	if (addEdit.DoModal() == IDOK)
	{

		if (addEdit.test_name.IsEmpty())
		{
			return;
		}
		TestData tData;
		// �ж��Ƿ�����
		for (vector<TestData>::reverse_iterator it = info.m_vecData.rbegin(); it != info.m_vecData.rend(); it++)
		{
			if (addEdit.test_name== it->tName && it->tState != "ɾ��")
			{
				MessageBox(_T("�ò�����Ϣ�Ѵ���"));
			}
		}
		// �ж��Ƿ����
		for (vector<Product>::reverse_iterator it = pInfo.m_vecData.rbegin(); it != pInfo.m_vecData.rend(); it++)
		{
			if (it->name == pEdit && it->state != "ɾ��")
			{
				tData.pName = it->name;
				tData.pModel = it->model;
				tData.pSerial = it->serial;
				tData.tName = addEdit.test_name;
				tData.startCondition = addEdit.test_condition;
				tData.endCondition = addEdit.test_end_condition;
				tData.tCeiling = addEdit.test_ceiling;
				tData.tFloor = addEdit.test_floor;
				tData.tResult = addEdit.test_result;
				tData.tSerial = genUUID();
				CTime time = CTime::GetCurrentTime();
				tData.tTime.Format(_T("%04d%02d%02d %02d:%02d:%02d"), time.GetYear(), time.GetMonth(), time.GetDay(), time.GetHour(), time.GetMinute(), time.GetSecond());

				tData.tState = "�½�";
				info.m_vecData.push_back(tData);
				info.RefreshData(pEdit);
				info.SaveData();
			}
		}
	}
}

// ɾ������
void CTestView::OnBnClickedButton6()
{
	// TODO: Add your control notification handler code here
	CString testName = test_list_left.GetItemText(test_list_left.GetSelectionMark(), 1);
	CString testSerial = test_list_left.GetItemText(test_list_left.GetSelectionMark(), 9);
	for (vector<TestData>::iterator it = info.m_vecData.begin(); it != info.m_vecData.end(); it++)
	{
		if (it->tName == testName && it->tSerial == testSerial)
		{
			it->tState = "ɾ��";
			info.RefreshData(pEdit);
			break;
		}
	}
}

// �����ѡ��  ��ȡѡ�б�ID �޸��б��±�
void CTestView::OnLvnItemchangedList1(NMHDR *pNMHDR, LRESULT *pResult)
{
	LPNMLISTVIEW pNMLV = reinterpret_cast<LPNMLISTVIEW>(pNMHDR);
	// TODO: Add your control notification handler code here
	{
		if (pNMLV->uChanged == LVIF_STATE)
		{
			if (pNMLV->uNewState)
			{
				int nIndex = pNMLV->iItem;

				test_list_left.SetItemState(nIndex, LVIS_FOCUSED | LVIS_SELECTED, LVIS_FOCUSED | LVIS_SELECTED);   //ѡ����
				test_list_left.SetSelectionMark(nIndex);
				CString testName = test_list_left.GetItemText(test_list_left.GetSelectionMark(), 1);
				record.RefreshData(testName);

			}
		}

	}
	*pResult = 0;
}

// ˢ�¼�¼����
// ��ҵ�����Ժ��ȡָ����¼��ID  Ŀǰû��ҵ�� 
void CTestView::OnLvnItemchangedList2(NMHDR *pNMHDR, LRESULT *pResult)
{
	LPNMLISTVIEW pNMLV = reinterpret_cast<LPNMLISTVIEW>(pNMHDR);
	// TODO: Add your control notification handler code here

	*pResult = 0;
}

// �˳�����
void CTestView::OnBnClickedButton1()
{
	// TODO: Add your control notification handler code here
	::PostMessage(AfxGetMainWnd()->GetSafeHwnd(), NM_A, (LPARAM)NM_A, (LPARAM)0);
}


// ��ѯ��Ϣ��
void CTestView::OnBnClickedButtonquery()
{
	// TODO: Add your control notification handler code here
	UpdateData();
	info.RefreshData();
}




// ɾ�� ���Լ�¼
void CTestView::OnBnClickedButton9()
{
	// TODO: Add your control notification handler code here
	CString testName = test_list_left.GetItemText(test_list_left.GetSelectionMark(), 1);
	CString testSerial = test_list_left.GetItemText(test_list_left.GetSelectionMark(), 9);
	CString rSerial = test_list_right.GetItemText(test_list_right.GetSelectionMark(), 2);

	for (vector<RecordData>::iterator it = record.m_vecData.begin(); it != record.m_vecData.end(); it++)
	{
		if (it->tName == testName && it->tSerial == testSerial && it->serial == rSerial)
		{
			it->state = "ɾ��";
			record.RefreshData(testName);
			break;
		}
	}
}

// ���������ɫ
HBRUSH CTestView::OnCtlColor(CDC* pDC, CWnd* pWnd, UINT nCtlColor)
{
	HBRUSH bbr = CFormView::OnCtlColor(pDC, pWnd, nCtlColor);
	switch (nCtlColor)
	{
	case IDC_STATIC:
	{
		pDC->SetBkColor(RGB(235,255,0));
		CFont font;
		font.CreatePointFont(100, "���Ŀ���");
		pDC->SelectObject(&font);
		return m_brush;
	}
	break;
	default:
		break;
	}
	return bbr;
}


void CTestView::OnCbnSelchangeCombo1()
{
	// TODO: Add your control notification handler code here
	int select = pComBox.GetCurSel();
	pComBox.GetLBText(select, pEdit);
	info.RefreshData(pEdit);
}
