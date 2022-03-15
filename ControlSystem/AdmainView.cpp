// AdmainView.cpp : implementation file
//

#include "pch.h"
#include "Markup.h"
#include "ControlSystem.h"
#include "AdmainView.h"

#include "TestItemView.h"
#include "MainFrm.h"
#include "uuid.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#endif



// CAdmainView

IMPLEMENT_DYNCREATE(CAdmainView, CFormView)

CAdmainView::CAdmainView()
	: CFormView(IDD_ADMIN)
{

}

CAdmainView::~CAdmainView()
{
}

void CAdmainView::DoDataExchange(CDataExchange* pDX)
{
	CFormView::DoDataExchange(pDX);
	DDX_Control(pDX, IDC_LIST4, m_left_list);
	DDX_Control(pDX, IDC_LIST5, m_mid_list);
	DDX_Control(pDX, IDC_LIST6, m_right_list);
}

BEGIN_MESSAGE_MAP(CAdmainView, CFormView)
	ON_BN_CLICKED(IDC_BUTTON1, &CAdmainView::OnBnClickedButton1)
	ON_BN_CLICKED(IDC_BUTTON2, &CAdmainView::OnBnClickedButton2)
	ON_BN_CLICKED(IDC_BUTTON13, &CAdmainView::OnBnClickedButton13)
	ON_BN_CLICKED(IDC_BUTTON3, &CAdmainView::OnBnClickedButton3)
	ON_BN_CLICKED(IDC_BUTTON6, &CAdmainView::OnBnClickedButton6)
	ON_BN_CLICKED(IDC_BUTTON7, &CAdmainView::OnBnClickedButton7)
	ON_BN_CLICKED(IDC_BUTTON8, &CAdmainView::OnBnClickedButton8)
	ON_BN_CLICKED(IDC_BUTTON9, &CAdmainView::OnBnClickedButton9)
	ON_BN_CLICKED(IDC_BUTTON10, &CAdmainView::OnBnClickedButton10)
	ON_BN_CLICKED(IDC_BUTTON17, &CAdmainView::OnBnClickedButton17)
	ON_BN_CLICKED(IDC_BUTTON18, &CAdmainView::OnBnClickedButton18)
	ON_BN_CLICKED(IDC_BUTTON11, &CAdmainView::OnBnClickedButton11)
	ON_BN_CLICKED(IDC_BUTTON12, &CAdmainView::OnBnClickedButton12)
	ON_BN_CLICKED(IDC_BUTTON15, &CAdmainView::OnBnClickedButton15)
	ON_BN_CLICKED(IDC_BUTTON16, &CAdmainView::OnBnClickedButton16)
	ON_NOTIFY(LVN_ITEMCHANGED, IDC_LIST4, &CAdmainView::OnLvnItemchangedList4)
	ON_NOTIFY(LVN_ITEMCHANGED, IDC_LIST5, &CAdmainView::OnLvnItemchangedList5)
	ON_NOTIFY(LVN_ITEMCHANGED, IDC_LIST6, &CAdmainView::OnLvnItemchangedList6)
END_MESSAGE_MAP()


// ��ʼ������
void CAdmainView::OnInitialUpdate() 
{
	CFormView::OnInitialUpdate();
	// ��ʼ����Ʒ���

	pInfo.list = &m_left_list;
	pInfo.OnInitialUpdate();

	m_left_list.SetExtendedStyle(LVS_EX_GRIDLINES | LVS_EX_FULLROWSELECT);
	m_left_list.InsertColumn(0, _T("ID"), LVCFMT_LEFT, 50);
	m_left_list.InsertColumn(1, _T("������"), LVCFMT_LEFT, 100);
	m_left_list.InsertColumn(2, _T("����"), LVCFMT_LEFT, 100);
	m_left_list.InsertColumn(3, _T("�ͺ�"), LVCFMT_LEFT, 100);
	m_left_list.SetFocus();
	pInfo.RefreshData();

	// ��ʼ��������Ϣ��
	info.list = &m_mid_list;
	info.OnInitialUpdate();

	m_mid_list.SetExtendedStyle(LVS_EX_GRIDLINES | LVS_EX_FULLROWSELECT);
	m_mid_list.InsertColumn(0, _T("ID"), LVCFMT_LEFT, 50);
	m_mid_list.InsertColumn(1, _T("��������"), LVCFMT_LEFT, 100);
	m_mid_list.InsertColumn(2, _T("��ʼ����"), LVCFMT_LEFT, 100);
	m_mid_list.InsertColumn(3, _T("��������"), LVCFMT_LEFT, 100);
	m_mid_list.InsertColumn(4, _T("����"), LVCFMT_LEFT, 50);
	m_mid_list.InsertColumn(5, _T("����"), LVCFMT_LEFT, 50);
	m_mid_list.InsertColumn(6, _T("���"), LVCFMT_LEFT, 100);
	m_mid_list.InsertColumn(7, _T("����״̬"), LVCFMT_LEFT, 100);
	m_mid_list.InsertColumn(8, _T("ʱ��"), LVCFMT_LEFT, 50);

	m_mid_list.SetFocus();

	// ��ʼ���������
	item.list = &m_right_list;
	item.OnInitialUpdate();
	m_right_list.SetExtendedStyle(LVS_EX_GRIDLINES | LVS_EX_FULLROWSELECT);
	m_right_list.InsertColumn(0, _T("ID"), LVCFMT_LEFT, 50);
	m_right_list.InsertColumn(1, _T("������"), LVCFMT_LEFT, 100);
	m_right_list.SetFocus();
}

// CAdmainView diagnostics

#ifdef _DEBUG
void CAdmainView::AssertValid() const
{
	CFormView::AssertValid();
}

#ifndef _WIN32_WCE
void CAdmainView::Dump(CDumpContext& dc) const
{
	CFormView::Dump(dc);
}
#endif
#endif //_DEBUG


// CAdmainView message handlers

// ��Ʒ���� 
void CAdmainView::OnBnClickedButton1()
{
	// TODO: Add your control notification handler code here

	ProductItem addEdit;

	// �ж���Ӳ�Ʒ��Ϣ�ڲ�Ʒ�����Ƿ����

	if (addEdit.DoModal() == IDOK)
	{
		// �ж���������Ƿ�Ϊ��
		if (addEdit.name.IsEmpty())
		{
			return;
		}
		if (addEdit.name.IsEmpty()|| addEdit.model.IsEmpty())
		{
			return;
		}
		// ��֤��ƷΨһ��
		for (vector<Product>::reverse_iterator it = pInfo.m_vecData.rbegin(); it != pInfo.m_vecData.rend(); it++)
		{
			if (addEdit.name == it->name && it->state != "ɾ��")
			{
				MessageBox(_T("�ò�Ʒ��Ϣ�Ѵ���"));
				return;
			}
		}
		Product p;
		p.name = addEdit.name;
		p.model = addEdit.model;
		p.serial = addEdit.serial;
		CTime time = CTime::GetCurrentTime();
		p.createTime.Format(_T("%04d%02d%02d %02d:%02d:%02d"), time.GetYear(), time.GetMonth(), time.GetDay(), time.GetHour(), time.GetMinute(), time.GetSecond());

		p.state = "�½�";
		pInfo.m_vecData.push_back(p);
		pInfo.RefreshData();
	}
}

// ��Ʒɾ�� 
void CAdmainView::OnBnClickedButton2()
{
	// TODO: Add your control notification handler code here
	CString pSerial = m_left_list.GetItemText(m_left_list.GetSelectionMark(), 1);

	for (vector<Product>::iterator it = pInfo.m_vecData.begin(); it != pInfo.m_vecData.end(); it++)
	{
		if (it->serial == pSerial)
		{
			it->state = "ɾ��";
			pInfo.RefreshData();
			break;
		}
	}
}


// ��Ʒ�޸�
void CAdmainView::OnBnClickedButton13()
{
	// TODO: Add your control notification handler code here
	CString pSerial = m_left_list.GetItemText(m_left_list.GetSelectionMark(), 1);
	CString pName = m_left_list.GetItemText(m_left_list.GetSelectionMark(), 2);
	CString pModel = m_left_list.GetItemText(m_left_list.GetSelectionMark(), 3);

	ProductItem addEdit;
	addEdit.serial = pSerial;
	addEdit.name = pName;

	if (addEdit.DoModal() == IDOK)
	{
		if (pSerial.IsEmpty())
		{
			return;
		}

		Product p;
		p.name = addEdit.name;
		p.model = addEdit.model;
		p.serial = addEdit.serial;
		CTime time = CTime::GetCurrentTime();
		p.createTime.Format(_T("%04d%02d%02d %02d:%02d:%02d"), time.GetYear(), time.GetMonth(), time.GetDay(), time.GetHour(), time.GetMinute(), time.GetSecond());

		p.state = "�½�";
		// ɾ��������
		for (vector<Product>::iterator it = pInfo.m_vecData.begin(); it != pInfo.m_vecData.end(); it++)
		{
			if (it->serial == pSerial)
			{
				pInfo.m_vecData.pop_back();
				break;
			}
		}
		pInfo.m_vecData.push_back(p);
		pInfo.RefreshData();
	}
}

// ��������
void CAdmainView::OnBnClickedButton3()
{
	TestAdd addEdit;
	if (addEdit.DoModal() == IDOK)
	{
		CString pName = m_left_list.GetItemText(m_left_list.GetSelectionMark(), 2);
		// �ж��Ƿ�ѡ�в�Ʒ
		if (pName.IsEmpty())
		{
			MessageBox(_T("��ָ����Ʒ������"));
			return;
		}
		// �ж���������Ƿ�Ϊ��
		if (addEdit.test_name.IsEmpty())
		{
			return;
		}
		TestData tData;
		// �ж������Ϣ����Ϣ�����Ƿ����
		for (vector<TestData>::reverse_iterator it = info.m_vecData.rbegin(); it != info.m_vecData.rend(); it++)
		{
			if (addEdit.test_name == it->tName && it->tState != "ɾ��")
			{
				MessageBox(_T("�ò�����Ϣ�Ѵ���"));
				return;
			}
		}
		// �ж���Ӳ�Ʒ�ڲ�Ʒ�����Ƿ����
		for (vector<Product>::reverse_iterator it = pInfo.m_vecData.rbegin(); it != pInfo.m_vecData.rend(); it++)
		{
			if (it->name == pName && it->state != "ɾ��")
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
				info.RefreshData(pName);
				info.SaveData();
			}
		}
	}
}

// ����ɾ��
void CAdmainView::OnBnClickedButton6()
{
	// TODO: Add your control notification handler code here
	
	// ѡ��Ҫɾ������Ϣ
	CString testName = m_mid_list.GetItemText(m_mid_list.GetSelectionMark(), 1);
	CString testSerial = m_mid_list.GetItemText(m_mid_list.GetSelectionMark(), 9);

	for (vector<TestData>::iterator it = info.m_vecData.begin(); it != info.m_vecData.end(); it++)
	{
		if (it->tName == testName && it->tSerial == testSerial)
		{
			it->tState = "ɾ��";
			// ��ȡ��ǰѡ�еĲ�Ʒ����
			CString pName = m_left_list.GetItemText(m_left_list.GetSelectionMark(), 2);
			info.RefreshData(pName);
			info.SaveData();
			break;
		}
	}
}

// �����޸�
void CAdmainView::OnBnClickedButton7()
{
	CString tName = m_mid_list.GetItemText(m_mid_list.GetSelectionMark(), 1);
	CString tStart = m_mid_list.GetItemText(m_mid_list.GetSelectionMark(), 2);
	CString tEnd = m_mid_list.GetItemText(m_mid_list.GetSelectionMark(), 3);

	TestAdd addEdit;
	TestData tData;
	for (vector<TestData>::iterator it = info.m_vecData.begin(); it != info.m_vecData.end(); it++)
	{
		if (it->tName == tName && it->tState !="ɾ��")
		{
			addEdit.test_name = it->tName;
			addEdit.test_condition = it->startCondition;
			addEdit.test_end_condition = it->endCondition;
			addEdit.test_ceiling = it->tCeiling;
			addEdit.test_floor = it->tFloor;
			addEdit.test_result = it->tResult;

			tData.pName = it->pName;
			tData.pModel = it->pModel;
			tData.pSerial = it->pSerial;
		}
	}
	if (addEdit.DoModal() == IDOK)
	{
		// �����������Ϊ��
		if (tName.IsEmpty())
		{
			return;
		}
		// ɾ�������� 
		for (vector<TestData>::iterator it = info.m_vecData.begin(); it != info.m_vecData.end(); it++)
		{
			if (it->tSerial == tData.tSerial)
			{
				info.m_vecData.pop_back();
				tData.tName = addEdit.test_name;
				tData.startCondition = addEdit.test_condition;
				tData.endCondition = addEdit.test_end_condition;
				tData.tCeiling = addEdit.test_ceiling;
				tData.tFloor = addEdit.test_floor;
				tData.tResult = addEdit.test_result;
				tData.tSerial = genUUID();

				CTime time = CTime::GetCurrentTime();
				tData.tTime.Format(_T("%04d%02d%02d %02d:%02d:%02d"), time.GetYear(), time.GetMonth(), time.GetDay(), time.GetHour(), time.GetMinute(), time.GetSecond());
				tData.tState = "����";
				// ɾ��������
				vector<TestData> temp;
				info.m_vecData.push_back(tData);
				info.RefreshData(tData.pName);
				info.SaveData();
				break;
			}
		}

	} 
}

// ��������
void CAdmainView::OnBnClickedButton8()
{
	// ����δѡ��ʱ��ť�����
	if (m_mid_list.GetSelectionMark() == -1)
	{
		MessageBox(_T("��ѡ���ƶ���"));
		return;
	}
	if (m_mid_list.GetSelectionMark() <= 0)
	{
		MessageBox(_T("�Ѵﵽ���"));
		return;
	}


	CString tName = m_mid_list.GetItemText(m_mid_list.GetSelectionMark(), 1);
	CString tName1 = m_mid_list.GetItemText(m_mid_list.GetSelectionMark()-1 , 1);
	vector<TestData> tempVector;
	TestData temp; 
	for (vector<TestData>::iterator it = info.m_vecData.begin(); it != info.m_vecData.end(); it++)
	{
		if (it->tName == tName1) {
			temp = *it;
			continue;
		}

		tempVector.push_back(*it);
		if (it->tName == tName)
		{
			tempVector.push_back(temp);

		}
	}

	info.m_vecData = tempVector;

	CString pName = m_left_list.GetItemText(m_left_list.GetSelectionMark(), 2);
	info.RefreshData(pName);
	info.SaveData();

}

// ��������
void CAdmainView::OnBnClickedButton9()
{

	// ����δѡ��ʱ��ť�����
	int a = m_mid_list.GetSelectionMark();
	int b = m_mid_list.GetItemCount();
	if (m_mid_list.GetSelectionMark() == -1)
	{
		MessageBox(_T("��ѡ���ƶ���"));
		return;
	}

	if (m_mid_list.GetSelectionMark() >= m_mid_list.GetItemCount() -1)
	{
		MessageBox(_T("�޷�����������"));
		return;
	}



	CString tName = m_mid_list.GetItemText(m_mid_list.GetSelectionMark(), 1);
	CString tName1 = m_mid_list.GetItemText(m_mid_list.GetSelectionMark() + 1, 1);
	vector<TestData> tempVector;
	TestData temp; 
	for (vector<TestData>::iterator it = info.m_vecData.begin(); it != info.m_vecData.end(); it++)
	{
		if (it->tName == tName) {
			temp = *it;
			continue;
		}

		tempVector.push_back(*it);
		if (it->tName == tName1)
		{
			tempVector.push_back(temp);
		}
	}

	info.m_vecData = tempVector;

	CString pName = m_left_list.GetItemText(m_left_list.GetSelectionMark(), 2);
	info.RefreshData(pName);
	info.SaveData();
}

// �������ñ��� || ˢ��
void CAdmainView::OnBnClickedButton10()
{
	// TODO: Add your control notification handler code here
}


// �޸Ĳ�����
void CAdmainView::OnBnClickedButton17()
{
	// TODO: Add your control notification handler code here

}

// ɾ��������
void CAdmainView::OnBnClickedButton18()
{
	// TODO: Add your control notification handler code here
}

// ��ʼ����
void CAdmainView::OnBnClickedButton11()
{
	// TODO: Add your control notification handler code here
}

// �鿴��¼
void CAdmainView::OnBnClickedButton12()
{
	// TODO: Add your control notification handler code here
}

// ���ص�¼
void CAdmainView::OnBnClickedButton15()
{
	::PostMessage(AfxGetMainWnd()->GetSafeHwnd(), NM_A, (LPARAM)NM_A, (LPARAM)0);
}

// �������
void CAdmainView::OnBnClickedButton16()
{
	// Ϊ�������ҳ�����������Ϣ
	// ����δѡ��ʱ��ť�����
	
	if (m_mid_list.GetSelectionMark() == -1)
	{
		MessageBox(_T("��ѡ�������Ϣ�����"));
		return;
	}
	CString tName = m_mid_list.GetItemText(m_mid_list.GetSelectionMark(), 1);
	TestItemView addEdit;

	// ��ȡѡ������
	for (vector<TestData>::iterator it = info.m_vecData.begin(); it != info.m_vecData.end(); it++)
	{
		if (it->tName == tName) {
			addEdit.tData = *it;
		}
	}

	if (addEdit.DoModal() == IDOK)
	{

		// RefreshData();
	}

}

// ѡ�в�Ʒ�б�
void CAdmainView::OnLvnItemchangedList4(NMHDR *pNMHDR, LRESULT *pResult)
{
	LPNMLISTVIEW pNMLV = reinterpret_cast<LPNMLISTVIEW>(pNMHDR);
	// TODO: Add your control notification handler code here
	{
		if (pNMLV->uChanged == LVIF_STATE)
		{
			if (pNMLV->uNewState)
			{
				int nIndex = pNMLV->iItem;

				m_left_list.SetItemState(nIndex, LVIS_FOCUSED | LVIS_SELECTED, LVIS_FOCUSED | LVIS_SELECTED);   //ѡ����
				m_left_list.SetSelectionMark(nIndex);
				CString pName = m_left_list.GetItemText(m_left_list.GetSelectionMark(), 2);
				info.RefreshData(pName);
			}
		}

	}
	*pResult = 0;
}

// ѡ�в�����Ϣ�б�
void CAdmainView::OnLvnItemchangedList5(NMHDR *pNMHDR, LRESULT *pResult)
{
	LPNMLISTVIEW pNMLV = reinterpret_cast<LPNMLISTVIEW>(pNMHDR);
	// TODO: Add your control notification handler code here
	*pResult = 0;
}

// ѡ�в�����Ŀ�б�
void CAdmainView::OnLvnItemchangedList6(NMHDR *pNMHDR, LRESULT *pResult)
{
	LPNMLISTVIEW pNMLV = reinterpret_cast<LPNMLISTVIEW>(pNMHDR);
	// TODO: Add your control notification handler code here
	*pResult = 0;
}

