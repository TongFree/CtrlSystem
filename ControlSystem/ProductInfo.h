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


	// 存储文件名
	CString m_xml;
	// xml操作工具
	CMarkup xml;

	// 列表
	CListCtrl *list;


	CTime m_timeEnd;
	CTime m_timeBegin;

	CEdit *m_editQueryText;


	vector<Product> m_vecData;
	vector<CString> m_vecDataType;
};

