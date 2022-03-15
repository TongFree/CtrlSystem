#pragma once
#include "afxwin.h"

// TestItemCurrent dialog

class TestItemCurrent : public CDialogEx
{
	DECLARE_DYNAMIC(TestItemCurrent)

public:
	TestItemCurrent(CWnd* pParent = NULL);   // standard constructor
	virtual ~TestItemCurrent();

// Dialog Data
#ifdef AFX_DESIGN_TIME
	enum { IDD = IDD_TEST_ITEM_AMP_STATIC };
#endif

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV support

	DECLARE_MESSAGE_MAP()
public:
	CString m_silent_time;
	afx_msg void OnBnClickedButton1();
};
