// TestItemToolChannel.cpp : implementation file
//

#include "stdafx.h"
#include "ControlSystem.h"
#include "TestItemToolChannel.h"
#include "afxdialogex.h"


// TestItemToolChannel dialog

IMPLEMENT_DYNAMIC(TestItemToolChannel, CDialogEx)

TestItemToolChannel::TestItemToolChannel(CWnd* pParent /*=NULL*/)
	: CDialogEx(IDD_TEST_ITEM_TOOL, pParent)
	, m_saveName(_T(""))
{

}

TestItemToolChannel::~TestItemToolChannel()
{
}

void TestItemToolChannel::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
	DDX_Control(pDX, IDC_COMBO20, r_out_channel2);
	DDX_Control(pDX, IDC_COMBO18, r_out_channel1);
	DDX_Control(pDX, IDC_COMBO20, r_out_channel2);
	DDX_Control(pDX, IDC_COMBO19, r_out_channel3);
	DDX_Control(pDX, IDC_COMBO21, r_out_channel4);
	DDX_Control(pDX, IDC_COMBO1, v_out_channel5);
	DDX_Control(pDX, IDC_COMBO5, v_out_channel6);
	DDX_Control(pDX, IDC_COMBO8, v_out_channel7);
	DDX_Control(pDX, IDC_COMBO11, v_out_channel8);
	DDX_Control(pDX, IDC_COMBO2, v_out_channel9);
	DDX_Control(pDX, IDC_COMBO6, v_out_channel10);
	DDX_Control(pDX, IDC_COMBO9, v_out_channel11);
	DDX_Control(pDX, IDC_COMBO16, v_out_channel12);
	DDX_Control(pDX, IDC_COMBO12, v_out_channel13);
	DDX_Control(pDX, IDC_COMBO22, v_out_channel14);
	DDX_Control(pDX, IDC_COMBO86, v_out_channel15);
	DDX_Control(pDX, IDC_COMBO87, v_out_channel16);
	DDX_Control(pDX, IDC_COMBO24, in_channel1);
	DDX_Control(pDX, IDC_COMBO27, in_channel2);
	DDX_Control(pDX, IDC_COMBO30, in_channel3);
	DDX_Control(pDX, IDC_COMBO40, in_channel4);
	DDX_Control(pDX, IDC_COMBO25, in_channel5);
	DDX_Control(pDX, IDC_COMBO28, in_channel6);
	DDX_Control(pDX, IDC_COMBO38, in_channel7);
	DDX_Control(pDX, IDC_COMBO89, in_channel8);
	DDX_Control(pDX, IDC_COMBO26, in_channel9);
	DDX_Control(pDX, IDC_COMBO29, in_channel10);
	DDX_Control(pDX, IDC_COMBO88, in_channel11);
	DDX_Control(pDX, IDC_COMBO90, in_channel12);
	DDX_Control(pDX, IDC_COMBO44, in_channel13);
	DDX_Control(pDX, IDC_COMBO91, in_channel14);
	DDX_Control(pDX, IDC_COMBO92, in_channel15);
	DDX_Control(pDX, IDC_COMBO93, in_channel16);
	DDX_Text(pDX, IDC_EDIT30, m_saveName);
}


BEGIN_MESSAGE_MAP(TestItemToolChannel, CDialogEx)
	ON_BN_CLICKED(IDC_BUTTON1, &TestItemToolChannel::OnBnClickedButton1)
	ON_BN_CLICKED(IDC_BUTTON6, &TestItemToolChannel::OnBnClickedButton6)
	ON_BN_CLICKED(IDC_BUTTON26, &TestItemToolChannel::OnBnClickedButton26)
	ON_BN_CLICKED(IDC_BUTTON27, &TestItemToolChannel::OnBnClickedButton27)
END_MESSAGE_MAP()


// TestItemToolChannel message handlers

// 输入全选
void TestItemToolChannel::OnBnClickedButton1()
{
	// TODO: Add your control notification handler code here
}

// 输出全选
void TestItemToolChannel::OnBnClickedButton6()
{
	// TODO: Add your control notification handler code here
}

// 保存配置
void TestItemToolChannel::OnBnClickedButton26()
{
	// TODO: Add your control notification handler code here
}

// 确定
void TestItemToolChannel::OnBnClickedButton27()
{
	// TODO: Add your control notification handler code here
}
