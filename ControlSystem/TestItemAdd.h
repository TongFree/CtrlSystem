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
	CComboBox CB1;  // ����������
	CComboBox CB2;  // �������
	CComboBox CB3;  // ͨ��
	CComboBox CB4;  // ͨ������
	CComboBox CB5;  // ״̬λ
	CComboBox CB6;  // ����
	CComboBox CB7;  // ռ�ձ�
	CComboBox CB8;  // ��ʱ
	CComboBox CB9;  // ��Ĭʱ��
	CComboBox CB10; // ����
	CComboBox CB11; // �Ƿ�о�
	CComboBox CB12; // Ƶ��
	CComboBox CB13; // ����
	CComboBox CB14; // ����
	CComboBox CB15; // ��ѹ
	CComboBox CB16; // ����
	CComboBox CB17; // ����ֵ
	CComboBox CB18; // ��ƽ
	CComboBox CB19; // Ԥ��1
	CComboBox CB20; // Ԥ��2
	CComboBox CB21; // Ԥ��3
	CComboBox CB22; // Ԥ��4
	CComboBox CB23; // Ԥ��5
	CComboBox CB24; // Ԥ��6
	CComboBox CB25; // Ԥ��7

	CString m_add_edit;    // ����ı�
	CString m_modify_edit; // �޸��ı�
	afx_msg void OnBnClickedButton29();
	afx_msg void OnBnClickedButton30();
	afx_msg void OnBnClickedButton31();
};
