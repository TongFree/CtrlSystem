// TestItemSwitch.cpp : implementation file
//

#include "stdafx.h"
#include "ControlSystem.h"
#include "TestItemSwitch.h"
#include "afxdialogex.h"


// TestItemSwitch dialog

IMPLEMENT_DYNAMIC(TestItemSwitch, CDialogEx)

TestItemSwitch::TestItemSwitch(CWnd* pParent /*=NULL*/)
	: CDialogEx(IDD_TEST_ITEM_SWITCH, pParent)
	, m_saveName(_T(""))
	, strV1(_T(""))
	, strV2(_T(""))
{

}

TestItemSwitch::~TestItemSwitch()
{
}

void TestItemSwitch::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
	DDX_Text(pDX, IDC_EDIT25, m_saveName);
	DDX_Text(pDX, IDC_EDIT1, strV1);
	DDX_Text(pDX, IDC_EDIT2, strV2);
}


BEGIN_MESSAGE_MAP(TestItemSwitch, CDialogEx)
	ON_BN_CLICKED(IDC_BUTTON17, &TestItemSwitch::OnBnClickedButton17)
	ON_BN_CLICKED(IDC_BUTTON18, &TestItemSwitch::OnBnClickedButton18)
END_MESSAGE_MAP()


// TestItemSwitch message handlers

// 保存设置
void TestItemSwitch::OnBnClickedButton17()
{
	// TODO: Add your control notification handler code here
}

// 确定
void TestItemSwitch::OnBnClickedButton18()
{
	// TODO: Add your control notification handler code here
}
