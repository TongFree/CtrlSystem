#pragma once

#pragma once
#include "afxcmn.h"
#include "Markup.h"
#include "ProductItem.h"
#include "FrameWork.h"
struct Product
{
	CString name;
	CString serial;
	CString model;
	CString state;
	CString createTime;
	CString updateTime;
};

class ProductInfo
{
public:
	ProductInfo();
	~ProductInfo();


	void SaveData();
	void RefreshData();
	void OnInitialUpdate();


	// �洢�ļ���
	CString m_xml;
	// xml��������
	CMarkup xml;

	// �б�
	CListCtrl *list;


	CTime m_timeEnd;
	CTime m_timeBegin;

	CEdit *m_editQueryText;


	vector<Product> m_vecData;
	vector<CString> m_vecDataType;
};

