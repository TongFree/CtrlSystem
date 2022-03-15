// TestItemSignalGenerator.cpp : implementation file
//

#include "stdafx.h"
#include "ControlSystem.h"
#include "TestItemSignalGenerator.h"
#include "afxdialogex.h"


// TestItemSignalGenerator dialog

IMPLEMENT_DYNAMIC(TestItemSignalGenerator, CDialogEx)

TestItemSignalGenerator::TestItemSignalGenerator(CWnd* pParent /*=NULL*/)
	: CDialogEx(IDD_TEST_ITEM_SIGNAL_OC, pParent)
	, startOneHz(_T(""))
	, startTwoHz(_T(""))
	, endOneHz(_T(""))
	, endTwoHz(_T(""))
	, startOneV(_T(""))
	, endOneV(_T(""))
	, startTwoV(_T(""))
	, endTwoV(_T(""))
	, startOneB(_T(""))
	, endOneB(_T(""))
	, startTwoB(_T(""))
	, endTwoB(_T(""))
	, m_saveName(_T(""))
{

}

TestItemSignalGenerator::~TestItemSignalGenerator()
{
}

void TestItemSignalGenerator::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
	DDX_Control(pDX, IDC_COMBO1, s1_combo);
	DDX_Control(pDX, IDC_COMBO2, s2_combo);
	DDX_Control(pDX, IDC_COMBO4, e1_combo);
	DDX_Control(pDX, IDC_COMBO12, e2_combo);
	DDX_Text(pDX, IDC_EDIT1, startOneHz);
	DDX_Text(pDX, IDC_EDIT7, startTwoHz);
	DDX_Text(pDX, IDC_EDIT5, endOneHz);
	DDX_Text(pDX, IDC_EDIT8, endTwoHz);
	DDX_Text(pDX, IDC_EDIT2, startOneV);
	DDX_Text(pDX, IDC_EDIT3, endOneV);
	DDX_Text(pDX, IDC_EDIT10, startTwoV);
	DDX_Text(pDX, IDC_EDIT24, endTwoV);
	DDX_Text(pDX, IDC_EDIT4, startOneB);
	DDX_Text(pDX, IDC_EDIT6, endOneB);
	DDX_Text(pDX, IDC_EDIT11, startTwoB);
	DDX_Text(pDX, IDC_EDIT9, endTwoB);
	DDX_Text(pDX, IDC_EDIT25, m_saveName);
}


BEGIN_MESSAGE_MAP(TestItemSignalGenerator, CDialogEx)
	ON_BN_CLICKED(IDC_BUTTON17, &TestItemSignalGenerator::OnBnClickedButton17)
	ON_BN_CLICKED(IDC_BUTTON18, &TestItemSignalGenerator::OnBnClickedButton18)
END_MESSAGE_MAP()


// TestItemSignalGenerator message handlers

// ±£¥Ê≈‰÷√
void TestItemSignalGenerator::OnBnClickedButton17()
{
	// TODO: Add your control notification handler code here
}

// »∑∂®
void TestItemSignalGenerator::OnBnClickedButton18()
{
	// TODO: Add your control notification handler code here
}
