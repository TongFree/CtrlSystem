// TestInputDetectionChannel.cpp : implementation file
//

#include "stdafx.h"
#include "ControlSystem.h"
#include "TestInputDetectionChannel.h"
#include "afxdialogex.h"


// TestInputDetectionChannel dialog

IMPLEMENT_DYNAMIC(TestInputDetectionChannel, CDialogEx)

TestInputDetectionChannel::TestInputDetectionChannel(CWnd* pParent /*=NULL*/)
	: CDialogEx(IDD_TEST_ITEM_CHANNEL, pParent)
{

}

TestInputDetectionChannel::~TestInputDetectionChannel()
{
}

void TestInputDetectionChannel::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
	DDX_Control(pDX, IDC_COMBO1, m_combox1_1);
	DDX_Control(pDX, IDC_COMBO4, m_combox1_2);
	DDX_Control(pDX, IDC_COMBO2, m_combox2_1);
	DDX_Control(pDX, IDC_COMBO12, m_combox2_2);
	DDX_Control(pDX, IDC_COMBO3, m_combox3_1);
	DDX_Control(pDX, IDC_COMBO13, m_combox3_2);
	DDX_Control(pDX, IDC_COMBO6, m_combox4_1);
	DDX_Control(pDX, IDC_COMBO7, m_combox4_2);
	DDX_Control(pDX, IDC_COMBO8, m_combox5_1);
	DDX_Control(pDX, IDC_COMBO14, m_combox5_2);
	DDX_Control(pDX, IDC_COMBO10, m_combox6_1);
	DDX_Control(pDX, IDC_COMBO15, m_combox6_2);
	DDX_Control(pDX, IDC_COMBO16, m_combox7_1);
	DDX_Control(pDX, IDC_COMBO17, m_combox7_2);
	DDX_Control(pDX, IDC_COMBO18, m_combox8_1);
	DDX_Control(pDX, IDC_COMBO19, m_combox8_2);
	DDX_Control(pDX, IDC_COMBO20, m_combox9_1);
	DDX_Control(pDX, IDC_COMBO21, m_combox9_2);
	DDX_Control(pDX, IDC_EDIT2, m_save_name);
}


BEGIN_MESSAGE_MAP(TestInputDetectionChannel, CDialogEx)
	ON_BN_CLICKED(IDC_BUTTON17, &TestInputDetectionChannel::OnBnClickedButton17)
	ON_BN_CLICKED(IDC_BUTTON18, &TestInputDetectionChannel::OnBnClickedButton18)
END_MESSAGE_MAP()


// TestInputDetectionChannel message handlers

// ±£¥Ê≈‰÷√
void TestInputDetectionChannel::OnBnClickedButton17()
{
	// TODO: Add your control notification handler code here
}

// »∑∂®
void TestInputDetectionChannel::OnBnClickedButton18()
{
	// TODO: Add your control notification handler code here
}
