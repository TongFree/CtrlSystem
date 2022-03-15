#pragma once


// TestItemSwitch dialog

class TestItemSwitch : public CDialogEx
{
	DECLARE_DYNAMIC(TestItemSwitch)

public:
	TestItemSwitch(CWnd* pParent = NULL);   // standard constructor
	virtual ~TestItemSwitch();

// Dialog Data
#ifdef AFX_DESIGN_TIME
	enum { IDD = IDD_TEST_ITEM_SWITCH };
#endif

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV support

	DECLARE_MESSAGE_MAP()
public:
	CString m_saveName;
	afx_msg void OnBnClickedButton17();
	afx_msg void OnBnClickedButton18();
	CString strV1;
	CString strV2;
};
