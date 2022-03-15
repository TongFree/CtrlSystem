#pragma once
#include "afxcmn.h"
#include "stdafx.h"
#include "ControlSystem.h"
#include "afxdialogex.h"
#include "TestInfo.h"
#include "TestItemInfo.h"
#include "TestItemView.h"
#include "TestItemAdd.h"

#include "TestInputDetectionChannel.h"
#include "TestItemAnalogSignal.h"
#include "TestItemSignalGenerator.h"
#include "TestItemMulti.h"
#include "TestItemTriState.h"
#include "TestItemResistance.h"
#include "TestItemToolChannel.h"
#include "TestItemElectronicLoad.h"
#include "TestItemJig.h"
#include "TestItemSwitch.h"

#include "TestItemCurrent.h"

// TestItemView dialog

class TestItemView : public CDialogEx
{
	DECLARE_DYNAMIC(TestItemView)

public:
	TestItemView(CWnd* pParent = NULL);   // standard constructor
	virtual ~TestItemView();

// Dialog Data
#ifdef AFX_DESIGN_TIME
	enum { IDD = IDD_TEST_ITEM };
#endif

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV support

	DECLARE_MESSAGE_MAP()
public:
	// 列表
	CListCtrl m_item_list;
	
	// 与前一视图关联数据
	TestData tData;

	// 主要数据源
	TestItemInfo item;


	BOOL OnInitDialog();
	afx_msg	void OnBnClickedButton1();
	afx_msg void OnBnClickedButton2();
	afx_msg void OnBnClickedButton3();
	afx_msg void OnBnClickedButton5();
	afx_msg void OnBnClickedButton10();
	afx_msg void OnBnClickedButton11();
	afx_msg void OnBnClickedButton12();
	afx_msg void OnBnClickedButton13();
	afx_msg void OnBnClickedButton14();
	afx_msg void OnBnClickedButton16();
	afx_msg void OnBnClickedButton19();
	afx_msg void OnBnClickedButton22();
	afx_msg void OnBnClickedButton20();
	afx_msg void OnBnClickedButton21();
	afx_msg void OnBnClickedButton23();
	afx_msg void OnLvnItemchangedList1(NMHDR *pNMHDR, LRESULT *pResult);
	afx_msg void OnBnClickedButton8();
};
