#pragma once
#include "afxwin.h"


// TestItemAnalogSignal dialog

class TestItemAnalogSignal : public CDialogEx
{
	DECLARE_DYNAMIC(TestItemAnalogSignal)

public:
	TestItemAnalogSignal(CWnd* pParent = NULL);   // standard constructor
	virtual ~TestItemAnalogSignal();

// Dialog Data
#ifdef AFX_DESIGN_TIME
	enum { IDD = IDD_TEST_ITEM_SIGNAL };
#endif

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV support

	DECLARE_MESSAGE_MAP()
public:
	CComboBox m_s_combo1;
	CComboBox m_s_combo2;
	CComboBox m_s_combo3;
	CComboBox m_s_combo4;
	CComboBox m_s_combo5;
	CComboBox m_s_combo6;

	CComboBox m_e_combo1;
	CComboBox m_e_combo2;
	CComboBox m_e_combo3;
	CComboBox m_e_combo4;
	CComboBox m_e_combo5;
	CComboBox m_e_combo6;
	CString m_saveName;
	afx_msg void OnBnClickedButton17();
	afx_msg void OnBnClickedButton18();
};
