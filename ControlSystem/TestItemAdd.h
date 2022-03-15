#pragma once
#include "afxwin.h"


// CTestItemAdd dialog

class CTestItemAdd : public CDialog
{
	DECLARE_DYNAMIC(CTestItemAdd)

public:
	CTestItemAdd(CWnd* pParent = NULL);   // standard constructor
	virtual ~CTestItemAdd();

// Dialog Data
#ifdef AFX_DESIGN_TIME
	enum { IDD = IDD_TEST_ITEM_ADD };
#endif

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV support

	DECLARE_MESSAGE_MAP()
public:
	afx_msg void OnBnClickedButton23();
	afx_msg void OnBnClickedButton28();
	afx_msg void OnBnClickedButton18();
	CComboBox CB1;  // 测试项名称
	CComboBox CB2;  // 检测类型
	CComboBox CB3;  // 通道
	CComboBox CB4;  // 通道类型
	CComboBox CB5;  // 状态位
	CComboBox CB6;  // 操做
	CComboBox CB7;  // 占空比
	CComboBox CB8;  // 延时
	CComboBox CB9;  // 静默时间
	CComboBox CB10; // 步骤
	CComboBox CB11; // 是否夹具
	CComboBox CB12; // 频率
	CComboBox CB13; // 波形
	CComboBox CB14; // 脉冲
	CComboBox CB15; // 电压
	CComboBox CB16; // 电流
	CComboBox CB17; // 电阻值
	CComboBox CB18; // 电平
	CComboBox CB19; // 预留1
	CComboBox CB20; // 预留2
	CComboBox CB21; // 预留3
	CComboBox CB22; // 预留4
	CComboBox CB23; // 预留5
	CComboBox CB24; // 预留6
	CComboBox CB25; // 预留7

	CString m_add_edit;    // 添加文本
	CString m_modify_edit; // 修改文本
	afx_msg void OnBnClickedButton29();
	afx_msg void OnBnClickedButton30();
	afx_msg void OnBnClickedButton31();
};
