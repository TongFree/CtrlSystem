// TestItemAdd.cpp : implementation file
//

#include "stdafx.h"
#include "ControlSystem.h"
#include "TestItemAdd.h"
#include "afxdialogex.h"


// CTestItemAdd dialog

IMPLEMENT_DYNAMIC(CTestItemAdd, CDialog)

CTestItemAdd::CTestItemAdd(CWnd* pParent /*=NULL*/)
	: CDialog(IDD_TEST_ITEM_ADD, pParent)
	, m_add_edit(_T(""))
	, m_modify_edit(_T(""))
{

}

CTestItemAdd::~CTestItemAdd()
{
}

void CTestItemAdd::DoDataExchange(CDataExchange* pDX)
{
	CDialog::DoDataExchange(pDX);
	DDX_Control(pDX, IDC_COMBO1, CB1);
	DDX_Control(pDX, IDC_COMBO4, CB2);
	DDX_Control(pDX, IDC_COMBO2, CB3);
	DDX_Control(pDX, IDC_COMBO12, CB4);
	DDX_Control(pDX, IDC_COMBO3, CB5);
	DDX_Control(pDX, IDC_COMBO5, CB6);
	DDX_Control(pDX, IDC_COMBO6, CB7);
	DDX_Control(pDX, IDC_COMBO22, CB8);
	DDX_Control(pDX, IDC_COMBO8, CB9);
	DDX_Control(pDX, IDC_COMBO9, CB10);
	DDX_Control(pDX, IDC_COMBO10, CB11);
	DDX_Control(pDX, IDC_COMBO16, CB12);
	DDX_Control(pDX, IDC_COMBO87, CB13);
	DDX_Control(pDX, IDC_COMBO18, CB14);
	DDX_Control(pDX, IDC_COMBO19, CB15);
	DDX_Control(pDX, IDC_COMBO20, CB16);
	DDX_Control(pDX, IDC_COMBO107, CB17);
	DDX_Control(pDX, IDC_COMBO108, CB18);
	DDX_Control(pDX, IDC_COMBO25, CB19);
	DDX_Control(pDX, IDC_COMBO102, CB20);
	DDX_Control(pDX, IDC_COMBO106, CB21);
	DDX_Control(pDX, IDC_COMBO109, CB22);
	DDX_Control(pDX, IDC_COMBO36, CB23);
	DDX_Control(pDX, IDC_COMBO110, CB24);
	DDX_Control(pDX, IDC_COMBO111, CB25);
	DDX_Text(pDX, IDC_EDIT5, m_modify_edit);
	DDX_Text(pDX, IDC_EDIT4, m_add_edit);
}


BEGIN_MESSAGE_MAP(CTestItemAdd, CDialog)
	ON_BN_CLICKED(IDC_BUTTON23, &CTestItemAdd::OnBnClickedButton23)
	ON_BN_CLICKED(IDC_BUTTON28, &CTestItemAdd::OnBnClickedButton28)
	ON_BN_CLICKED(IDC_BUTTON18, &CTestItemAdd::OnBnClickedButton18)
	ON_BN_CLICKED(IDC_BUTTON29, &CTestItemAdd::OnBnClickedButton29)
	ON_BN_CLICKED(IDC_BUTTON30, &CTestItemAdd::OnBnClickedButton30)
	ON_BN_CLICKED(IDC_BUTTON31, &CTestItemAdd::OnBnClickedButton31)
END_MESSAGE_MAP()


// CTestItemAdd message handlers

// ȫѡ
void CTestItemAdd::OnBnClickedButton23()
{
	// TODO: Add your control notification handler code here
}

// ��ѡ
void CTestItemAdd::OnBnClickedButton28()
{
	// TODO: Add your control notification handler code here
}



// ȷ�ϰ�ť
void CTestItemAdd::OnBnClickedButton18()
{
	// TODO: Add your control notification handler code here
	CDialog::OnOK();
}

// ��Ӳ�����	�뵥ѡ���������
void CTestItemAdd::OnBnClickedButton29()
{
	// TODO: Add your control notification handler code here
}

// �޸Ĳ�����	�뵥ѡ�������޸�
void CTestItemAdd::OnBnClickedButton30()
{
	// TODO: Add your control notification handler code here
}

// ɾ��������	�뵥ѡ������ɾ��
void CTestItemAdd::OnBnClickedButton31()
{
	// TODO: Add your control notification handler code here
}

// �ж��Ƿ�ѡ
bool CheckItemSingle() {
	
	return 0;
}