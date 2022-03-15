// TestItemCurrent.cpp : implementation file
//

#include "stdafx.h"
#include "ControlSystem.h"
#include "TestItemCurrent.h"
#include "afxdialogex.h"


// TestItemCurrent dialog

IMPLEMENT_DYNAMIC(TestItemCurrent, CDialogEx)

TestItemCurrent::TestItemCurrent(CWnd* pParent /*=NULL*/)
	: CDialogEx(IDD_TEST_ITEM_AMP_STATIC, pParent)
	, m_silent_time(_T(""))
{

}

TestItemCurrent::~TestItemCurrent()
{
}

void TestItemCurrent::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
	DDX_Text(pDX, IDC_EDIT3, m_silent_time);
}


BEGIN_MESSAGE_MAP(TestItemCurrent, CDialogEx)
	ON_BN_CLICKED(IDC_BUTTON1, &TestItemCurrent::OnBnClickedButton1)
END_MESSAGE_MAP()


// TestItemCurrent message handlers

// 向三态输出界面跳转
void TestItemCurrent::OnBnClickedButton1()
{
	// TODO: Add your control notification handler code here

}
