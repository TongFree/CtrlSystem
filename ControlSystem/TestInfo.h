#pragma once
#include "afxcmn.h"
#include "Markup.h"
#include "FrameWork.h"

struct TestData
{
	CString tName;
	CString tSerial;
	CString startCondition;
	CString endCondition;
	CString tCeiling;
	CString tFloor;
	CString tResult;
	CString tTime;
	CString tState;

	CString pName;
	CString pModel;
	CString pSerial;
};


class TestInfo
{
public:
	TestInfo();
	~TestInfo();


	void SaveData();
	void OnInitialUpdate();
	void RefreshData();
	void RefreshData(CString pName);



	// 存储文件
	CString m_xml;
	// xml操作工具
	CMarkup xml;

	// 列表
	CListCtrl *list;


	CTime m_timeEnd;
	CTime m_timeBegin;

	CEdit *m_editQueryText;

	vector<TestData> m_vecData;
	vector<CString> m_vecDataType;

};

