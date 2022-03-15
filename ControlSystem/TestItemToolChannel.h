#pragma once
#include "afxwin.h"


// TestItemToolChannel dialog

class TestItemToolChannel : public CDialogEx
{
	DECLARE_DYNAMIC(TestItemToolChannel)

public:
	TestItemToolChannel(CWnd* pParent = NULL);   // standard constructor
	virtual ~TestItemToolChannel();

// Dialog Data
#ifdef AFX_DESIGN_TIME
	enum { IDD = IDD_TEST_ITEM_TOOL };
#endif

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV support

	DECLARE_MESSAGE_MAP()
public:

	CComboBox r_out_channel1;
	CComboBox r_out_channel2;
	CComboBox r_out_channel3;
	CComboBox r_out_channel4;
	CComboBox v_out_channel5;
	CComboBox v_out_channel6;
	CComboBox v_out_channel7;
	CComboBox v_out_channel8;
	CComboBox v_out_channel9;
	CComboBox v_out_channel10;
	CComboBox v_out_channel11;
	CComboBox v_out_channel12;
	CComboBox v_out_channel13;
	CComboBox v_out_channel14;
	CComboBox v_out_channel15;
	CComboBox v_out_channel16;

	CComboBox in_channel1;
	CComboBox in_channel2;
	CComboBox in_channel3;
	CComboBox in_channel4;
	CComboBox in_channel5;
	CComboBox in_channel6;
	CComboBox in_channel7;
	CComboBox in_channel8;
	CComboBox in_channel9;
	CComboBox in_channel10;
	CComboBox in_channel11;
	CComboBox in_channel12;
	CComboBox in_channel13;
	CComboBox in_channel14;
	CComboBox in_channel15;
	CComboBox in_channel16;
	afx_msg void OnBnClickedButton1();
	afx_msg void OnBnClickedButton6();
	CString m_saveName;
	afx_msg void OnBnClickedButton26();
	afx_msg void OnBnClickedButton27();
};
