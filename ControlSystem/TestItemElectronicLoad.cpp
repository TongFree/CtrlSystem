// TestItemElectronicLoad.cpp : implementation file
//

#include "stdafx.h"
#include "ControlSystem.h"
#include "TestItemElectronicLoad.h"
#include "afxdialogex.h"


// TestItemElectronicLoad dialog

IMPLEMENT_DYNAMIC(TestItemElectronicLoad, CDialogEx)

TestItemElectronicLoad::TestItemElectronicLoad(CWnd* pParent /*=NULL*/)
	: CDialogEx(IDD_TEST_ITEM_ERC_LOAD, pParent)
	, SMV(_T(""))
	, EMV(_T(""))
	, SBV(_T(""))
	, EBV(_T(""))
	, m_saveName(_T(""))
{

}

TestItemElectronicLoad::~TestItemElectronicLoad()
{
}

void TestItemElectronicLoad::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
	DDX_Text(pDX, IDC_EDIT1, SMV);
	DDX_Text(pDX, IDC_EDIT3, EMV);
	DDX_Text(pDX, IDC_EDIT6, SBV);
	DDX_Text(pDX, IDC_EDIT7, EBV);
	DDX_Text(pDX, IDC_EDIT30, m_saveName);
}


BEGIN_MESSAGE_MAP(TestItemElectronicLoad, CDialogEx)
	ON_BN_CLICKED(IDC_BUTTON26, &TestItemElectronicLoad::OnBnClickedButton26)
	ON_BN_CLICKED(IDC_BUTTON27, &TestItemElectronicLoad::OnBnClickedButton27)
END_MESSAGE_MAP()


// TestItemElectronicLoad message handlers

// ±£¥Ê≈‰÷√
void TestItemElectronicLoad::OnBnClickedButton26()
{
	// TODO: Add your control notification handler code here
}

// »∑∂®
void TestItemElectronicLoad::OnBnClickedButton27()
{
	// TODO: Add your control notification handler code here
}
