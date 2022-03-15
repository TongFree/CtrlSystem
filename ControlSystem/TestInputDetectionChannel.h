#pragma once
#include "afxwin.h"


// TestInputDetectionChannel dialog

class TestInputDetectionChannel : public CDialogEx
{
	DECLARE_DYNAMIC(TestInputDetectionChannel)

public:
	TestInputDetectionChannel(CWnd* pParent = NULL);   // standard constructor
	virtual ~TestInputDetectionChannel();

// Dialog Data
#ifdef AFX_DESIGN_TIME
	enum { IDD = IDD_TEST_ITEM_CHANNEL };
#endif

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV support

	DECLARE_MESSAGE_MAP()
public:
	CComboBox m_combox1_1;
	CComboBox m_combox1_2;
	CComboBox m_combox2_1;
	CComboBox m_combox2_2;
	CComboBox m_combox3_1;
	CComboBox m_combox3_2;
	CComboBox m_combox4_1;
	CComboBox m_combox4_2;
	CComboBox m_combox5_1;
	CComboBox m_combox5_2;
	CComboBox m_combox6_1;
	CComboBox m_combox6_2;
	CComboBox m_combox7_1;
	CComboBox m_combox7_2;
	CComboBox m_combox8_1;
	CComboBox m_combox8_2;
	CComboBox m_combox9_1;
	CComboBox m_combox9_2;
	CEdit m_save_name;
	afx_msg void OnBnClickedButton17();
	afx_msg void OnBnClickedButton18();
};
