#pragma once
#include "afxwin.h"


// TestItemSignalGenerator dialog

class TestItemSignalGenerator : public CDialogEx
{
	DECLARE_DYNAMIC(TestItemSignalGenerator)

public:
	TestItemSignalGenerator(CWnd* pParent = NULL);   // standard constructor
	virtual ~TestItemSignalGenerator();

// Dialog Data
#ifdef AFX_DESIGN_TIME
	enum { IDD = IDD_TEST_ITEM_SIGNAL_OC };
#endif

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV support

	DECLARE_MESSAGE_MAP()
public:
	CComboBox s1_combo;
	CComboBox s2_combo;
	CComboBox e1_combo;
	CComboBox e2_combo;

	CString startOneHz;
	CString startTwoHz;
	CString endOneHz;
	CString endTwoHz;

	CString startOneV;
	CString endOneV;
	CString startTwoV;
	CString endTwoV;

	CString startOneB;
	CString endOneB;
	CString startTwoB;
	CString endTwoB;
	CString m_saveName;
	afx_msg void OnBnClickedButton17();
	afx_msg void OnBnClickedButton18();
};
