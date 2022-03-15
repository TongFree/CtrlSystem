// TestItemAnalogSignal.cpp : implementation file
//

#include "stdafx.h"
#include "ControlSystem.h"
#include "TestItemAnalogSignal.h"
#include "afxdialogex.h"


// TestItemAnalogSignal dialog

IMPLEMENT_DYNAMIC(TestItemAnalogSignal, CDialogEx)

TestItemAnalogSignal::TestItemAnalogSignal(CWnd* pParent /*=NULL*/)
	: CDialogEx(IDD_TEST_ITEM_SIGNAL, pParent)
	, m_saveName(_T(""))
{

}

TestItemAnalogSignal::~TestItemAnalogSignal()
{
}

void TestItemAnalogSignal::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
	DDX_Control(pDX, IDC_COMBO1, m_s_combo1);
	DDX_Control(pDX, IDC_COMBO2, m_s_combo2);
	DDX_Control(pDX, IDC_COMBO3, m_s_combo3);
	DDX_Control(pDX, IDC_COMBO6, m_s_combo4);
	DDX_Control(pDX, IDC_COMBO8, m_s_combo5);
	DDX_Control(pDX, IDC_COMBO10, m_s_combo6);
	DDX_Control(pDX, IDC_COMBO4, m_e_combo1);
	DDX_Control(pDX, IDC_COMBO12, m_e_combo2);
	DDX_Control(pDX, IDC_COMBO13, m_e_combo3);
	DDX_Control(pDX, IDC_COMBO7, m_e_combo4);
	DDX_Control(pDX, IDC_COMBO14, m_e_combo5);
	DDX_Control(pDX, IDC_COMBO15, m_e_combo6);
	DDX_Text(pDX, IDC_EDIT2, m_saveName);
}


BEGIN_MESSAGE_MAP(TestItemAnalogSignal, CDialogEx)
	ON_BN_CLICKED(IDC_BUTTON17, &TestItemAnalogSignal::OnBnClickedButton17)
	ON_BN_CLICKED(IDC_BUTTON18, &TestItemAnalogSignal::OnBnClickedButton18)
END_MESSAGE_MAP()


// TestItemAnalogSignal message handlers

// ±£¥Ê≈‰÷√
void TestItemAnalogSignal::OnBnClickedButton17()
{
	// TODO: Add your control notification handler code here
}

// »∑∂®
void TestItemAnalogSignal::OnBnClickedButton18()
{
	// TODO: Add your control notification handler code here
}
