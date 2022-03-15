#pragma once
#include "afxwin.h"


// TestItemJig dialog

class TestItemJig : public CDialogEx
{
	DECLARE_DYNAMIC(TestItemJig)

public:
	TestItemJig(CWnd* pParent = NULL);   // standard constructor
	virtual ~TestItemJig();

// Dialog Data
#ifdef AFX_DESIGN_TIME
	enum { IDD = IDD_TEST_ITEM_JIG };
#endif

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV support

	DECLARE_MESSAGE_MAP()
public:
	CString s1_name;
	CString s2_name;
	CString s3_name;
	CString s4_name;
	CString s1_delay;
	CString s2_delay;
	CString s3_delay;
	CString s4_delay;
	CComboBox s1_combo1;
	CComboBox s1_combo2;
	CComboBox s1_combo3;
	CComboBox s2_combo1;
	CComboBox s2_combo2;
	CComboBox s2_combo3;
	CComboBox s3_combo1;
	CComboBox s3_combo2;
	CComboBox s3_combo3;
	CComboBox s4_combo1;
	CComboBox s4_combo2;
	CComboBox s4_combo3;
	afx_msg void OnBnClickedButton17();
	CString m_saveName;
	afx_msg void OnBnClickedButton18();
};
