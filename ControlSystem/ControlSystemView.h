
// ControlSystemView.h : CControlSystemView 类的接口
//

#pragma once
#include "CnComm.h"
#include "ControlSystemDoc.h"
#include "afxwin.h"
#include "ProductInfo.h"

class CControlSystemView : public CFormView
{
protected: // 仅从序列化创建
	CControlSystemView() ;
	DECLARE_DYNCREATE(CControlSystemView);
// 定义
public:
#ifdef AFX_DESIGN_TIME
	enum { IDD = IDD_CONTROL_FORM };
#endif

// 特性
public:
	CControlSystemDoc* GetDocument() const;

// 操作
public:

// 重写
public:
	virtual void OnDraw(CDC* pDC);  // 重写以绘制该视图
	virtual BOOL PreCreateWindow(CREATESTRUCT& cs);
	virtual void OnInitialUpdate(); // 调节构造后的窗口大小
protected:
	virtual BOOL OnPreparePrinting(CPrintInfo* pInfo);
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV 支持
	virtual void OnBeginPrinting(CDC* pDC, CPrintInfo* pInfo);
	virtual void OnEndPrinting(CDC* pDC, CPrintInfo* pInfo);

// 实现
public:
	virtual ~CControlSystemView();
#ifdef _DEBUG
	virtual void AssertValid() const;
	virtual void Dump(CDumpContext& dc) const;
#endif

protected:
// 生成的消息映射函数
protected:
	DECLARE_MESSAGE_MAP();

public:
	
	// 消息解释
	CnComm m_comm;
	CString CPID;
	CString CPNAME;

	// 产品名称
	CString pName;

	afx_msg void OnBnClickedButtonH1();
	afx_msg void OnBnClickedButtonH2();
	afx_msg void OnBnClickedButtonH3();
	afx_msg void OnBnClickedButtonH4();

	CFont m_editFont;
	CFont m_MainUIFont;


	CButton BUTTONH1;
	CButton BUTTONH2;
	CButton BUTTONH3;
	CButton BUTTONH4;
	CEdit EDITH1;
	CEdit EDITH2;

	CStatic staticH1;
	POINT Old;

	// 产品
	ProductInfo pInfo;


	//afx_msg void OnSize(UINT nType, int cx, int cy);
	//void resize();
	CBitmapButton m_CancelBitmap;

	CComboBox pComBox;
	afx_msg void OnCbnSelchangeCombo1();
};

#ifndef _DEBUG  // ControlSystemView.cpp 中的调试版本
inline CControlSystemDoc* CControlSystemView::GetDocument() const
   { return reinterpret_cast<CControlSystemDoc*>(m_pDocument); }
#endif

