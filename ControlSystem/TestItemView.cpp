// TestItemView.cpp : implementation file
//

#include "TestItemView.h"
// TestItemView dialog

IMPLEMENT_DYNAMIC(TestItemView, CDialogEx)

TestItemView::TestItemView(CWnd* pParent /*=NULL*/)
	: CDialogEx(IDD_TEST_ITEM, pParent)
{

}

TestItemView::~TestItemView()
{
}

void TestItemView::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
	DDX_Control(pDX, IDC_LIST1, m_item_list);
}


BEGIN_MESSAGE_MAP(TestItemView, CDialogEx)
	ON_BN_CLICKED(IDC_BUTTON1, &TestItemView::OnBnClickedButton1)
	ON_BN_CLICKED(IDC_BUTTON2, &TestItemView::OnBnClickedButton2)
	ON_BN_CLICKED(IDC_BUTTON3, &TestItemView::OnBnClickedButton3)
	ON_BN_CLICKED(IDC_BUTTON5, &TestItemView::OnBnClickedButton5)
	ON_BN_CLICKED(IDC_BUTTON10, &TestItemView::OnBnClickedButton10)
	ON_BN_CLICKED(IDC_BUTTON11, &TestItemView::OnBnClickedButton11)
	ON_BN_CLICKED(IDC_BUTTON12, &TestItemView::OnBnClickedButton12)
	ON_BN_CLICKED(IDC_BUTTON13, &TestItemView::OnBnClickedButton13)
	ON_BN_CLICKED(IDC_BUTTON14, &TestItemView::OnBnClickedButton14)
	ON_BN_CLICKED(IDC_BUTTON16, &TestItemView::OnBnClickedButton16)
	ON_BN_CLICKED(IDC_BUTTON19, &TestItemView::OnBnClickedButton19)
	ON_BN_CLICKED(IDC_BUTTON22, &TestItemView::OnBnClickedButton22)
	ON_BN_CLICKED(IDC_BUTTON20, &TestItemView::OnBnClickedButton20)
	ON_BN_CLICKED(IDC_BUTTON21, &TestItemView::OnBnClickedButton21)
	ON_BN_CLICKED(IDC_BUTTON23, &TestItemView::OnBnClickedButton23)
	ON_NOTIFY(LVN_ITEMCHANGED, IDC_LIST1, &TestItemView::OnLvnItemchangedList1)
	ON_BN_CLICKED(IDC_BUTTON8, &TestItemView::OnBnClickedButton8)
END_MESSAGE_MAP()


// TestItemView message handlers

BOOL TestItemView::OnInitDialog() 
{
	CDialogEx::OnInitDialog();
	m_item_list.SetExtendedStyle(LVS_EX_GRIDLINES | LVS_EX_FULLROWSELECT);
	m_item_list.InsertColumn(0, _T("ID"), LVCFMT_LEFT, 50);
	m_item_list.InsertColumn(1, _T("����"), LVCFMT_LEFT, 100);
	m_item_list.InsertColumn(1, _T("����"), LVCFMT_LEFT, 100);
	m_item_list.InsertColumn(1, _T("ͨ��"), LVCFMT_LEFT, 100);
	m_item_list.InsertColumn(1, _T("ͨ������"), LVCFMT_LEFT, 100);
	m_item_list.InsertColumn(1, _T("״̬λ"), LVCFMT_LEFT, 100);
	m_item_list.SetFocus();

	item.list = &m_item_list;
	item.OnInitialUpdate();
	return true;
}

// ���� ��ת
void TestItemView::OnBnClickedButton1()
{
	// TODO: Add your control notification handler code here
	CTestItemAdd addEdit;
	if (addEdit.DoModal() == IDOK)
	{
		// RefreshData();
	}

}

// ɾ��  ѡ��ɾ��(��ѡ)
void TestItemView::OnBnClickedButton2()
{
	// TODO: Add your control notification handler code here

}

// �޸�	ѡ���޸�(��ѡ)
void TestItemView::OnBnClickedButton3()
{
	// TODO: Add your control notification handler code here
}

// ���ͨ��	��ת���
void TestItemView::OnBnClickedButton5()
{
	TestInputDetectionChannel addEdit;
	if (addEdit.DoModal() == IDOK)
	{
		// RefreshData();
	}
}

// ģ���ź�	��ת���
void TestItemView::OnBnClickedButton10()
{
	TestItemAnalogSignal addEdit;
	if (addEdit.DoModal() == IDOK)
	{
		// RefreshData();
	}
}

// �źŷ�����	��ת���
void TestItemView::OnBnClickedButton11()
{
	TestItemSignalGenerator addEdit;
	if (addEdit.DoModal() == IDOK)
	{
		// RefreshData();
	}
}

// ��������	��ת���
void TestItemView::OnBnClickedButton12()
{
	TestItemMulti addEdit;
	if (addEdit.DoModal() == IDOK)
	{
		// RefreshData();
	}
}


// ��̬���	��ת���
void TestItemView::OnBnClickedButton13()
{
	TestItemTriState addEdit;
	if (addEdit.DoModal() == IDOK)
	{
		// RefreshData();
	}
}

// �ɱ�̵���	��ת���
void TestItemView::OnBnClickedButton14()
{
	TestItemResistance addEdit;
	if (addEdit.DoModal() == IDOK)
	{
		// RefreshData();
	}
}

// ��װͨ��	��ת���
void TestItemView::OnBnClickedButton16()
{
	TestItemToolChannel addEdit;
	if (addEdit.DoModal() == IDOK)
	{
		// RefreshData();
	}
}

// �ɱ�̸���	��ת���
void TestItemView::OnBnClickedButton19()
{
	TestItemElectronicLoad addEdit;
	if (addEdit.DoModal() == IDOK)
	{
		// RefreshData();
	}
}

// �о�����	��ת���
void TestItemView::OnBnClickedButton22()
{
	TestItemJig addEdit;
	if (addEdit.DoModal() == IDOK)
	{
		// RefreshData();
	}
}


// CAN ��ת���
void TestItemView::OnBnClickedButton20()
{
	TestItemSwitch addEdit;
	if (addEdit.DoModal() == IDOK)
	{
		// RefreshData();
	}
}

// RS232ͨ�Žӿ�	��ת���
void TestItemView::OnBnClickedButton21()
{
	TestItemCurrent addEdit;
	if (addEdit.DoModal() == IDOK)
	{
		// RefreshData();
	}
}

// ѡ����Ŀ�����Ŀ�����޸�
void TestItemView::OnBnClickedButton23()
{
	// TODO: Add your control notification handler code here
}

// ѡ����Ŀ
void TestItemView::OnLvnItemchangedList1(NMHDR *pNMHDR, LRESULT *pResult)
{
	LPNMLISTVIEW pNMLV = reinterpret_cast<LPNMLISTVIEW>(pNMHDR);
	// TODO: Add your control notification handler code here
	*pResult = 0;
}


void TestItemView::OnBnClickedButton8()
{
	// TODO: Add your control notification handler code here
	CDialog::OnOK();
}
