#pragma once
#include "afxwin.h"

// TestItemElectronicLoad dialog

class TestItemElectronicLoad : public CDialogEx
{
	DECLARE_DYNAMIC(TestItemElectronicLoad)

public:
	TestItemElectronicLoad(CWnd* pParent = NULL);   // standard constructor
	virtual ~TestItemElectronicLoad();

// Dialog Data
#ifdef AFX_DESIGN_TIME
	enum { IDD = IDD_TEST_ITEM_ERC_LOAD };
#endif

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV support

	DECLARE_MESSAGE_MAP()
public:
	CString SMV;
	CString EMV;
	CString SBV;
	CString EBV;
	CString m_saveName;
	afx_msg void OnBnClickedButton26();
	afx_msg void OnBnClickedButton27();
};
