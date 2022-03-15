#pragma once
#include "afxcmn.h"
#include "CnComm.h"
#include "afxwin.h"

#include "ProductInfo.h"
#include "TestInfo.h"
#include "TestRecord.h"



// CTestView dialog

class CTestView : public CFormView
{
	DECLARE_DYNCREATE(CTestView)

protected:
	CTestView();   // standard constructor
	virtual ~CTestView();

public:
// Dialog Data
#ifdef AFX_DESIGN_TIME
	enum { IDD = IDD_TESTVIEW};
#endif
protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV support

	DECLARE_MESSAGE_MAP()
public:
	CString m_user;
	CString test_Msg;
	CString test_total;
	CString test_current;

	CListCtrl test_list_left;
	CListCtrl test_list_right;

	// 添加窗口绘制
	CPoint m_pointOld;
	CRect  m_rect;
	CRect  m_rectBtn;

	// 列表管理
	ProductInfo pInfo;
	TestInfo info;
	TestRecord record;

	CTime m_timeEnd;
	CTime m_timeBegin;

	UUID uuid;

	CnComm comm;
	afx_msg void OnInitialUpdate();
	void OnBnClickedButton3();
	afx_msg void OnBnClickedButton5();
	afx_msg void OnBnClickedButton2();
	afx_msg void OnBnClickedButton6();
	CButton m_btnAdd;
	CButton m_btnDel;
	afx_msg void OnLvnItemchangedList1(NMHDR *pNMHDR, LRESULT *pResult);
	afx_msg void OnBnClickedButton1();

	afx_msg void OnBnClickedButtonquery();
	void OnBnClickedButton9();
	HBRUSH OnCtlColor(CDC * pDC, CWnd * pWnd, UINT nCtlColor);
	CEdit m_editQueryText;
	afx_msg void OnLvnItemchangedList2(NMHDR *pNMHDR, LRESULT *pResult);
	
	CString pEdit;

	CComboBox pComBox;
	// 保存颜色配置
	CBrush m_brush;
	afx_msg void OnCbnSelchangeCombo1();
};
