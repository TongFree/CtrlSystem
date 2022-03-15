// TestItemJig.cpp : implementation file
//

#include "stdafx.h"
#include "ControlSystem.h"
#include "TestItemJig.h"
#include "afxdialogex.h"


// TestItemJig dialog

IMPLEMENT_DYNAMIC(TestItemJig, CDialogEx)

TestItemJig::TestItemJig(CWnd* pParent /*=NULL*/)
	: CDialogEx(IDD_TEST_ITEM_JIG, pParent)
	, s1_name(_T(""))
	, s2_name(_T(""))
	, s3_name(_T(""))
	, s4_name(_T(""))
	, s1_delay(_T(""))
	, s2_delay(_T(""))
	, s3_delay(_T(""))
	, s4_delay(_T(""))
	, m_saveName(_T(""))
{

}

TestItemJig::~TestItemJig()
{
}

void TestItemJig::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
	DDX_Text(pDX, IDC_EDIT1, s1_name);
	DDX_Text(pDX, IDC_EDIT2, s2_name);
	DDX_Text(pDX, IDC_EDIT3, s3_name);
	DDX_Text(pDX, IDC_EDIT7, s4_name);
	DDX_Text(pDX, IDC_EDIT4, s1_delay);
	DDX_Text(pDX, IDC_EDIT5, s2_delay);
	DDX_Text(pDX, IDC_EDIT6, s3_delay);
	DDX_Text(pDX, IDC_EDIT10, s4_delay);
	DDX_Control(pDX, IDC_COMBO55, s1_combo1);
	DDX_Control(pDX, IDC_COMBO63, s1_combo2);
	DDX_Control(pDX, IDC_COMBO94, s1_combo3);
	DDX_Control(pDX, IDC_COMBO95, s2_combo1);
	DDX_Control(pDX, IDC_COMBO64, s2_combo2);
	DDX_Control(pDX, IDC_COMBO96, s2_combo3);
	DDX_Control(pDX, IDC_COMBO97, s3_combo1);
	DDX_Control(pDX, IDC_COMBO98, s3_combo2);
	DDX_Control(pDX, IDC_COMBO99, s3_combo3);
	DDX_Control(pDX, IDC_COMBO100, s4_combo1);
	DDX_Control(pDX, IDC_COMBO101, s4_combo2);
	DDX_Control(pDX, IDC_COMBO105, s4_combo3);
	DDX_Text(pDX, IDC_EDIT25, m_saveName);
}


BEGIN_MESSAGE_MAP(TestItemJig, CDialogEx)
	ON_BN_CLICKED(IDC_BUTTON17, &TestItemJig::OnBnClickedButton17)
	ON_BN_CLICKED(IDC_BUTTON18, &TestItemJig::OnBnClickedButton18)
END_MESSAGE_MAP()


// TestItemJig message handlers

// ±£¥Ê≈‰÷√
void TestItemJig::OnBnClickedButton17()
{
	// TODO: Add your control notification handler code here
}

// »∑∂®
void TestItemJig::OnBnClickedButton18()
{
	// TODO: Add your control notification handler code here
}
