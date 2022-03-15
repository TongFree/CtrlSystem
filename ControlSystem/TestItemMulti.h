#pragma once
#include "afxwin.h"


// TestItemMulti dialog

class TestItemMulti : public CDialogEx
{
	DECLARE_DYNAMIC(TestItemMulti)

public:
	TestItemMulti(CWnd* pParent = NULL);   // standard constructor
	virtual ~TestItemMulti();

// Dialog Data
#ifdef AFX_DESIGN_TIME
	enum { IDD = IDD_TEST_ITEM_OPTION };
#endif

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV support

	DECLARE_MESSAGE_MAP()
public:
	CString startHz;
	CString startB;
	CString endHz;
	CString endB;

	CComboBox s_d1_combo;
	CComboBox s_d2_combo;
	CComboBox e_d1_combo;
	CComboBox e_d2_combo;

	CComboBox s_u1_combo;
	CComboBox s_u2_combo;
	CComboBox e_u1_combo;
	CComboBox e_u2_combo;
	CString m_saveName;

	afx_msg void OnBnClickedButton17();
	afx_msg void OnBnClickedButton18();
	afx_msg void OnBnClickedCheck2();
	afx_msg void OnBnClickedCheck3();
	afx_msg void OnBnClickedCheck4();
	afx_msg void OnBnClickedCheck5();
	afx_msg void OnBnClickedCheck6();
	afx_msg void OnBnClickedCheck7();
	afx_msg void OnBnClickedCheck8();
	afx_msg void OnBnClickedCheck9();
};
