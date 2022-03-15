#pragma once
#include "afxwin.h"

// TestItemResistance dialog

class TestItemResistance : public CDialogEx
{
	DECLARE_DYNAMIC(TestItemResistance)

public:
	TestItemResistance(CWnd* pParent = NULL);   // standard constructor
	virtual ~TestItemResistance();

// Dialog Data
#ifdef AFX_DESIGN_TIME
	enum { IDD = IDD_TEST_ITEM_RESISTANCE };
#endif

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV support

	DECLARE_MESSAGE_MAP()
public:
	CString sv1;
	CString sv2;
	CString sv3;
	CString sv4;
	CString sv5;
	CString sv6;
	CString ev1;
	CString ev2;
	CString ev3;
	CString ev4;
	CString ev5;
	CString ev6;
	CString m_saveName;
	afx_msg void OnBnClickedButton17();
	afx_msg void OnBnClickedButton18();
};
