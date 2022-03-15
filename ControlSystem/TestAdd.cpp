// TestAdd.cpp : implementation file
//

#include "stdafx.h"
#include "ControlSystem.h"
#include "TestAdd.h"
#include "afxdialogex.h"
#include "TestView.h"


// TestAdd dialog

IMPLEMENT_DYNAMIC(TestAdd, CDialog)

TestAdd::TestAdd(CWnd* pParent /*=NULL*/)
	: CDialog(TestAdd::IDD, pParent)
	, test_name(_T(""))
	, test_condition(_T(""))
	, test_end_condition(_T(""))
	, test_ceiling(_T(""))
	, test_floor(_T(""))
	, test_result(_T(""))
{

}

TestAdd::~TestAdd()
{
}

void TestAdd::DoDataExchange(CDataExchange* pDX)
{
	CDialog::DoDataExchange(pDX);
	DDX_Text(pDX, IDC_EDIT1, test_name);
	DDX_Text(pDX, IDC_EDIT2, test_condition);
	DDX_Text(pDX, IDC_EDIT4, test_end_condition);
	DDX_Text(pDX, IDC_EDIT5, test_ceiling);
	DDX_Text(pDX, IDC_EDIT3, test_floor);
	DDX_Text(pDX, IDC_EDIT7, test_result);
	DDX_Control(pDX, IDC_EDIT1, edit_name);
	DDX_Control(pDX, IDC_EDIT4, edit_condition);
}


BEGIN_MESSAGE_MAP(TestAdd, CDialog)
	ON_BN_CLICKED(IDC_OK, &TestAdd::OnBnClickedOk)
	ON_BN_CLICKED(IDC_BUTTON3, &TestAdd::OnBnClickedButton3)
END_MESSAGE_MAP()






void TestAdd::OnBnClickedOk()
{
	// TODO: Add your control notification handler code here
	UpdateData();

	if (test_name == _T(""))
	{
		AfxMessageBox(_T("亲，你没有输入测试类型！"));
		edit_name.SetFocus();
		return;
	}
	if (test_condition == _T(""))
	{
		AfxMessageBox(_T("亲，没有输入开始条件！"));
		edit_condition.SetFocus();
		return;
	}

	CDialog::OnOK();
}


BOOL TestAdd::OnInitDialog()
{
	CDialog::OnInitDialog();

	this->UpdateData(FALSE);
	return TRUE;  // return TRUE unless you set the focus to a control
				  // EXCEPTION: OCX Property Pages should return FALSE
}


void TestAdd::OnBnClickedButton3()
{
	// TODO: Add your control notification handler code here
	CDialog::OnCancel();
}


