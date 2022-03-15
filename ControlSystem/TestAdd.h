#pragma once
#include "afxwin.h"


// TestAdd dialog

class TestAdd : public CDialog
{
	DECLARE_DYNAMIC(TestAdd)

public:
	TestAdd(CWnd* pParent = NULL); // standard constructor
	virtual ~TestAdd();

// Dialog Data
	enum { IDD = IDD_TEST_ADD };

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV support
	virtual BOOL OnInitDialog();

	DECLARE_MESSAGE_MAP()
public:
	CString test_name;
	CString test_condition;
	CString test_end_condition;
	CString test_ceiling;
	CString test_floor;
	CString test_result;
	CEdit edit_name;
	CEdit edit_condition;

	CComboBox m_comboxType;


	afx_msg void OnBnClickedOk();
	afx_msg void OnBnClickedButton3();
};