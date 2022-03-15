#pragma once


// ProductItem dialog
class ProductItem : public CDialog
{
	DECLARE_DYNAMIC(ProductItem)

public:
	ProductItem(CWnd* pParent = NULL);   // standard constructor
	virtual ~ProductItem();

// Dialog Data
#ifdef AFX_DESIGN_TIME
	enum { IDD = IDD_PRODUCT_ITEM };
#endif

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV support

	DECLARE_MESSAGE_MAP()
public:
	CString serial;
	CString name;
	CString model;
	afx_msg void OnBnClickedOk();
	afx_msg void OnBnClickedCancel();
};
