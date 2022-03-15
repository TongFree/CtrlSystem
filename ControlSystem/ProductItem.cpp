// ProductItem.cpp : implementation file
//

#include "stdafx.h"
#include "ControlSystem.h"
#include "ProductItem.h"
#include "afxdialogex.h"


// ProductItem dialog

IMPLEMENT_DYNAMIC(ProductItem, CDialog)

ProductItem::ProductItem(CWnd* pParent /*=NULL*/)
	: CDialog(IDD_PRODUCT_ITEM, pParent)
	, serial(_T(""))
	, name(_T(""))
	, model(_T(""))
{

}

ProductItem::~ProductItem()
{
}

void ProductItem::DoDataExchange(CDataExchange* pDX)
{
	CDialog::DoDataExchange(pDX);
	DDX_Text(pDX, IDC_EDIT1, serial);
	DDX_Text(pDX, IDC_EDIT2, name);
	DDX_Text(pDX, IDC_EDIT4, model);
}


BEGIN_MESSAGE_MAP(ProductItem, CDialog)
	ON_BN_CLICKED(IDOK, &ProductItem::OnBnClickedOk)
	ON_BN_CLICKED(IDCANCEL, &ProductItem::OnBnClickedCancel)
END_MESSAGE_MAP()


// ProductItem message handlers


void ProductItem::OnBnClickedOk()
{
	// TODO: Add your control notification handler code here
	CDialog::OnOK();
}


void ProductItem::OnBnClickedCancel()
{
	// TODO: Add your control notification handler code here
	CDialog::OnCancel();
}
