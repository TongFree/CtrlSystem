// TestItemTriState.cpp : implementation file
//

#include "stdafx.h"
#include "ControlSystem.h"
#include "TestItemTriState.h"
#include "afxdialogex.h"


// TestItemTriState dialog

IMPLEMENT_DYNAMIC(TestItemTriState, CDialogEx)

TestItemTriState::TestItemTriState(CWnd* pParent /*=NULL*/)
	: CDialogEx(IDD_TEST_ITEM_TRI_STATE, pParent)
	, leftV(_T(""))
	, rightV(_T(""))
	, m_saveName(_T(""))
{

}

TestItemTriState::~TestItemTriState()
{
}

void TestItemTriState::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
	DDX_Text(pDX, IDC_EDIT1, leftV);
	DDX_Text(pDX, IDC_EDIT27, rightV);
	DDX_Control(pDX, IDC_COMBO1, sc1);
	DDX_Control(pDX, IDC_COMBO8, sc2);
	DDX_Control(pDX, IDC_COMBO20, sc3);
	DDX_Control(pDX, IDC_COMBO30, sc4);
	DDX_Control(pDX, IDC_COMBO38, sc5);
	DDX_Control(pDX, IDC_COMBO2, sc6);
	DDX_Control(pDX, IDC_COMBO10, sc7);
	DDX_Control(pDX, IDC_COMBO24, sc8);
	DDX_Control(pDX, IDC_COMBO32, sc9);
	DDX_Control(pDX, IDC_COMBO40, sc10);
	DDX_Control(pDX, IDC_COMBO3, sc11);
	DDX_Control(pDX, IDC_COMBO16, sc12);
	DDX_Control(pDX, IDC_COMBO26, sc13);
	DDX_Control(pDX, IDC_COMBO34, sc14);
	DDX_Control(pDX, IDC_COMBO42, sc15);
	DDX_Control(pDX, IDC_COMBO6, sc16);
	DDX_Control(pDX, IDC_COMBO18, sc17);
	DDX_Control(pDX, IDC_COMBO28, sc18);
	DDX_Control(pDX, IDC_COMBO36, sc19);
	DDX_Control(pDX, IDC_COMBO44, sc20);
	DDX_Control(pDX, IDC_COMBO46, sc21);
	DDX_Control(pDX, IDC_COMBO54, sc22);
	DDX_Control(pDX, IDC_COMBO62, sc23);
	DDX_Control(pDX, IDC_COMBO70, sc24);
	DDX_Control(pDX, IDC_COMBO78, sc25);
	DDX_Control(pDX, IDC_COMBO48, sc26);
	DDX_Control(pDX, IDC_COMBO56, sc27);
	DDX_Control(pDX, IDC_COMBO64, sc28);
	DDX_Control(pDX, IDC_COMBO72, sc29);
	DDX_Control(pDX, IDC_COMBO80, sc30);
	DDX_Control(pDX, IDC_COMBO50, sc31);
	DDX_Control(pDX, IDC_COMBO58, sc32);
	DDX_Control(pDX, IDC_COMBO66, sc33);
	DDX_Control(pDX, IDC_COMBO74, sc34);
	DDX_Control(pDX, IDC_COMBO82, sc35);
	DDX_Control(pDX, IDC_COMBO52, sc36);
	DDX_Control(pDX, IDC_COMBO60, sc37);
	DDX_Control(pDX, IDC_COMBO68, sc38);
	DDX_Control(pDX, IDC_COMBO76, sc39);
	DDX_Control(pDX, IDC_COMBO84, sc40);
	DDX_Control(pDX, IDC_COMBO4, ec1);
	DDX_Control(pDX, IDC_COMBO9, ec2);
	DDX_Control(pDX, IDC_COMBO21, ec3);
	DDX_Control(pDX, IDC_COMBO31, ec4);
	DDX_Control(pDX, IDC_COMBO39, ec5);
	DDX_Control(pDX, IDC_COMBO12, ec6);
	DDX_Control(pDX, IDC_COMBO15, ec7);
	DDX_Control(pDX, IDC_COMBO25, ec8);
	DDX_Control(pDX, IDC_COMBO33, ec9);
	DDX_Control(pDX, IDC_COMBO41, ec10);
	DDX_Control(pDX, IDC_COMBO13, ec11);
	DDX_Control(pDX, IDC_COMBO17, ec12);
	DDX_Control(pDX, IDC_COMBO27, ec13);
	DDX_Control(pDX, IDC_COMBO35, ec14);
	DDX_Control(pDX, IDC_COMBO43, ec15);
	DDX_Control(pDX, IDC_COMBO22, ec16);
	DDX_Control(pDX, IDC_COMBO23, ec17);
	DDX_Control(pDX, IDC_COMBO29, ec18);
	DDX_Control(pDX, IDC_COMBO37, ec19);
	DDX_Control(pDX, IDC_COMBO45, ec20);
	DDX_Control(pDX, IDC_COMBO47, ec21);
	DDX_Control(pDX, IDC_COMBO55, ec22);
	DDX_Control(pDX, IDC_COMBO63, ec23);
	DDX_Control(pDX, IDC_COMBO71, ec24);
	DDX_Control(pDX, IDC_COMBO79, ec25);
	DDX_Control(pDX, IDC_COMBO49, ec26);
	DDX_Control(pDX, IDC_COMBO57, ec27);
	DDX_Control(pDX, IDC_COMBO65, ec28);
	DDX_Control(pDX, IDC_COMBO73, ec29);
	DDX_Control(pDX, IDC_COMBO81, ec30);
	DDX_Control(pDX, IDC_COMBO51, ec31);
	DDX_Control(pDX, IDC_COMBO59, ec32);
	DDX_Control(pDX, IDC_COMBO67, ec33);
	DDX_Control(pDX, IDC_COMBO75, ec34);
	DDX_Control(pDX, IDC_COMBO83, ec35);
	DDX_Control(pDX, IDC_COMBO53, ec36);
	DDX_Control(pDX, IDC_COMBO61, ec37);
	DDX_Control(pDX, IDC_COMBO69, ec38);
	DDX_Control(pDX, IDC_COMBO77, ec39);
	DDX_Control(pDX, IDC_COMBO85, ec40);
	DDX_Text(pDX, IDC_EDIT28, m_saveName);
}


BEGIN_MESSAGE_MAP(TestItemTriState, CDialogEx)
	ON_BN_CLICKED(IDC_BUTTON24, &TestItemTriState::OnBnClickedButton24)
	ON_BN_CLICKED(IDC_BUTTON25, &TestItemTriState::OnBnClickedButton25)
END_MESSAGE_MAP()


// TestItemTriState message handlers

// ±£´æ
void TestItemTriState::OnBnClickedButton24()
{
	// TODO: Add your control notification handler code here
}

// È·¶¨
void TestItemTriState::OnBnClickedButton25()
{
	// TODO: Add your control notification handler code here
}
