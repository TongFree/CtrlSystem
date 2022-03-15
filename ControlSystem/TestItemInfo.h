#pragma once

#include "afxcmn.h"
#include "Markup.h"
#include "TestItemAdd.h"
#include "FrameWork.h"

struct TestItem
{
	CString itemName;
	CString itemType;
	CString channel;
	CString channelType;
	CString state;
	CString option;
	CString bRate;
	CString delay;
	CString silent;
	CString step;
	CString isJig;
	CString hz;
	CString wave;
	CString pulse;
	CString v;
	CString a;
	CString r;
	CString dB;
	CString value1;
	CString value2;
	CString value3;
	CString value4;
	CString value5;
	CString value6;
	CString value7;

	CString tName;
	CString tSerial;
	int num;
};


class TestItemInfo
{
public:
	TestItemInfo();
	~TestItemInfo();

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

	vector<TestItem> m_vecData;
	vector<CString> m_vecDataType;
};

