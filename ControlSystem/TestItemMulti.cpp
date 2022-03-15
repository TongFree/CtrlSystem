// TestItemMulti.cpp : implementation file
//

#include "stdafx.h"
#include "ControlSystem.h"
#include "TestItemMulti.h"
#include "afxdialogex.h"


// TestItemMulti dialog

IMPLEMENT_DYNAMIC(TestItemMulti, CDialogEx)

TestItemMulti::TestItemMulti(CWnd* pParent /*=NULL*/)
	: CDialogEx(IDD_TEST_ITEM_OPTION, pParent)
	, startHz(_T(""))
	, startB(_T(""))
	, endHz(_T(""))
	, endB(_T(""))
	, m_saveName(_T(""))
{

}

TestItemMulti::~TestItemMulti()
{
}

void TestItemMulti::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
	DDX_Text(pDX, IDC_EDIT7, startHz);
	DDX_Text(pDX, IDC_EDIT10, startB);
	DDX_Text(pDX, IDC_EDIT11, endHz);
	DDX_Text(pDX, IDC_EDIT26, endB);
	DDX_Control(pDX, IDC_COMBO3, s_d2_combo);
	DDX_Control(pDX, IDC_COMBO2, s_d1_combo);
	DDX_Control(pDX, IDC_COMBO13, e_d2_combo);
	DDX_Control(pDX, IDC_COMBO12, e_d1_combo);
	DDX_Control(pDX, IDC_COMBO6, s_u1_combo);
	DDX_Control(pDX, IDC_COMBO22, e_u1_combo);
	DDX_Control(pDX, IDC_COMBO8, s_u2_combo);
	DDX_Control(pDX, IDC_COMBO14, e_u2_combo);
	DDX_Text(pDX, IDC_EDIT25, m_saveName);
}


BEGIN_MESSAGE_MAP(TestItemMulti, CDialogEx)
	ON_BN_CLICKED(IDC_BUTTON17, &TestItemMulti::OnBnClickedButton17)
	ON_BN_CLICKED(IDC_BUTTON18, &TestItemMulti::OnBnClickedButton18)
	ON_BN_CLICKED(IDC_CHECK2, &TestItemMulti::OnBnClickedCheck2)
	ON_BN_CLICKED(IDC_CHECK3, &TestItemMulti::OnBnClickedCheck3)
	ON_BN_CLICKED(IDC_CHECK4, &TestItemMulti::OnBnClickedCheck4)
	ON_BN_CLICKED(IDC_CHECK5, &TestItemMulti::OnBnClickedCheck5)
	ON_BN_CLICKED(IDC_CHECK6, &TestItemMulti::OnBnClickedCheck6)
	ON_BN_CLICKED(IDC_CHECK7, &TestItemMulti::OnBnClickedCheck7)
	ON_BN_CLICKED(IDC_CHECK8, &TestItemMulti::OnBnClickedCheck8)
	ON_BN_CLICKED(IDC_CHECK9, &TestItemMulti::OnBnClickedCheck9)
END_MESSAGE_MAP()


// TestItemMulti message handlers

// 保存配置
void TestItemMulti::OnBnClickedButton17()
{
	// TODO: Add your control notification handler code here
}

// 确定
void TestItemMulti::OnBnClickedButton18()
{
	// TODO: Add your control notification handler code here
}

// 拉低通道1 脉冲输出
void TestItemMulti::OnBnClickedCheck2()
{
	// TODO: Add your control notification handler code here
}

// 拉低通道1 数据
void TestItemMulti::OnBnClickedCheck3()
{
	// TODO: Add your control notification handler code here
}

// 拉低通道2	脉冲输出
void TestItemMulti::OnBnClickedCheck4()
{
	// TODO: Add your control notification handler code here
}

// 拉低通道2 数据
void TestItemMulti::OnBnClickedCheck5()
{
	// TODO: Add your control notification handler code here
}

// 拉高通道1 脉冲输出
void TestItemMulti::OnBnClickedCheck6()
{
	// TODO: Add your control notification handler code here
}

// 拉高通道1 数据
void TestItemMulti::OnBnClickedCheck7()
{
	// TODO: Add your control notification handler code here
}

// 拉高通道2 脉冲输出
void TestItemMulti::OnBnClickedCheck8()
{
	// TODO: Add your control notification handler code here
}

// 拉高通道2 数据
void TestItemMulti::OnBnClickedCheck9()
{
	// TODO: Add your control notification handler code here
}
