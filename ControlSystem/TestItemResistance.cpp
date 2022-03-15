// TestItemResistance.cpp : implementation file
//

#include "stdafx.h"
#include "ControlSystem.h"
#include "TestItemResistance.h"
#include "afxdialogex.h"


// TestItemResistance dialog

IMPLEMENT_DYNAMIC(TestItemResistance, CDialogEx)

TestItemResistance::TestItemResistance(CWnd* pParent /*=NULL*/)
	: CDialogEx(IDD_TEST_ITEM_RESISTANCE, pParent)
	, sv1(_T(""))
	, sv2(_T(""))
	, sv3(_T(""))
	, sv4(_T(""))
	, sv5(_T(""))
	, sv6(_T(""))
	, ev1(_T(""))
	, ev2(_T(""))
	, ev3(_T(""))
	, ev4(_T(""))
	, ev5(_T(""))
	, ev6(_T(""))
	, m_saveName(_T(""))
{

}

TestItemResistance::~TestItemResistance()
{
}

void TestItemResistance::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
	DDX_Text(pDX, IDC_EDIT1, sv1);
	DDX_Text(pDX, IDC_EDIT4, sv2);
	DDX_Text(pDX, IDC_EDIT23, sv3);
	DDX_Text(pDX, IDC_EDIT7, sv4);
	DDX_Text(pDX, IDC_EDIT11, sv5);
	DDX_Text(pDX, IDC_EDIT24, sv6);
	DDX_Text(pDX, IDC_EDIT2, ev1);
	DDX_Text(pDX, IDC_EDIT5, ev2);
	DDX_Text(pDX, IDC_EDIT6, ev3);
	DDX_Text(pDX, IDC_EDIT10, ev4);
	DDX_Text(pDX, IDC_EDIT8, ev5);
	DDX_Text(pDX, IDC_EDIT9, ev6);
	DDX_Text(pDX, IDC_EDIT25, m_saveName);
}


BEGIN_MESSAGE_MAP(TestItemResistance, CDialogEx)
	ON_BN_CLICKED(IDC_BUTTON17, &TestItemResistance::OnBnClickedButton17)
	ON_BN_CLICKED(IDC_BUTTON18, &TestItemResistance::OnBnClickedButton18)
END_MESSAGE_MAP()


// TestItemResistance message handlers

// ±£¥Ê≈‰÷√
void TestItemResistance::OnBnClickedButton17()
{
	// TODO: Add your control notification handler code here
}

// »∑∂®
void TestItemResistance::OnBnClickedButton18()
{
	// TODO: Add your control notification handler code here
}
