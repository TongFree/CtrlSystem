#pragma once
#include "afxcmn.h"
#include "afxwin.h"

#include "ProductItem.h"
#include "TestAdd.h"
#include "TestItemAdd.h"

#include "ProductInfo.h"
#include "TestInfo.h"
#include "TestItemInfo.h"
#include "TestRecord.h"

#include "FrameWork.h"
// CAdmainView form view

class CAdmainView : public CFormView
{
	DECLARE_DYNCREATE(CAdmainView)

protected:
	CAdmainView();           // protected constructor used by dynamic creation
	virtual ~CAdmainView();

public:
#ifdef AFX_DESIGN_TIME
	enum { IDD = IDD_ADMIN };
#endif

#ifdef _DEBUG
	virtual void AssertValid() const;
#ifndef _WIN32_WCE
	virtual void Dump(CDumpContext& dc) const;
#endif
#endif
	void OnInitialUpdate();

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV support

	DECLARE_MESSAGE_MAP()
public:
	// 文档名称
	CString m_xmlProduct;
	CString m_xmlInfo;
	CString m_xmlItem;


	// 拆分

	CListCtrl m_left_list;
	CListCtrl m_mid_list;
	CListCtrl m_right_list;

	// 列表
	ProductInfo pInfo;
	TestInfo info;
	TestItemInfo item;
	TestRecord record;

	afx_msg void OnBnClickedButton1();
	afx_msg void OnBnClickedButton2();
	afx_msg void OnBnClickedButton13();
	afx_msg void OnBnClickedButton3();
	afx_msg void OnBnClickedButton6();
	afx_msg void OnBnClickedButton7();
	afx_msg void OnBnClickedButton8();
	afx_msg void OnBnClickedButton9();
	afx_msg void OnBnClickedButton10();
	afx_msg void OnBnClickedButton17();
	afx_msg void OnBnClickedButton18();
	afx_msg void OnBnClickedButton11();
	afx_msg void OnBnClickedButton12();
	afx_msg void OnBnClickedButton15();
	afx_msg void OnBnClickedButton16();
	afx_msg void OnLvnItemchangedList4(NMHDR *pNMHDR, LRESULT *pResult);
	afx_msg void OnLvnItemchangedList5(NMHDR *pNMHDR, LRESULT *pResult);
	afx_msg void OnLvnItemchangedList6(NMHDR *pNMHDR, LRESULT *pResult);
};


