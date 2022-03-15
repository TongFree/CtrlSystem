
// ControlSystemView.h : CControlSystemView ��Ľӿ�
//

#pragma once
#include "CnComm.h"
#include "ControlSystemDoc.h"
#include "afxwin.h"
#include "ProductInfo.h"

class CControlSystemView : public CFormView
{
protected: // �������л�����
	CControlSystemView() ;
	DECLARE_DYNCREATE(CControlSystemView);
// ����
public:
#ifdef AFX_DESIGN_TIME
	enum { IDD = IDD_CONTROL_FORM };
#endif

// ����
public:
	CControlSystemDoc* GetDocument() const;

// ����
public:

// ��д
public:
	virtual void OnDraw(CDC* pDC);  // ��д�Ի��Ƹ���ͼ
	virtual BOOL PreCreateWindow(CREATESTRUCT& cs);
	virtual void OnInitialUpdate(); // ���ڹ����Ĵ��ڴ�С
protected:
	virtual BOOL OnPreparePrinting(CPrintInfo* pInfo);
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV ֧��
	virtual void OnBeginPrinting(CDC* pDC, CPrintInfo* pInfo);
	virtual void OnEndPrinting(CDC* pDC, CPrintInfo* pInfo);

// ʵ��
public:
	virtual ~CControlSystemView();
#ifdef _DEBUG
	virtual void AssertValid() const;
	virtual void Dump(CDumpContext& dc) const;
#endif

protected:
// ���ɵ���Ϣӳ�亯��
protected:
	DECLARE_MESSAGE_MAP();

public:
	
	// ��Ϣ����
	CnComm m_comm;
	CString CPID;
	CString CPNAME;

	// ��Ʒ����
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

	// ��Ʒ
	ProductInfo pInfo;


	//afx_msg void OnSize(UINT nType, int cx, int cy);
	//void resize();
	CBitmapButton m_CancelBitmap;

	CComboBox pComBox;
	afx_msg void OnCbnSelchangeCombo1();
};

#ifndef _DEBUG  // ControlSystemView.cpp �еĵ��԰汾
inline CControlSystemDoc* CControlSystemView::GetDocument() const
   { return reinterpret_cast<CControlSystemDoc*>(m_pDocument); }
#endif

