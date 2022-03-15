#pragma once

#include "afxcmn.h"
#include "Markup.h"
#include "FrameWork.h"

enum DATA_STATUS
{
	DATA_OLD,
	DATA_NEW,
	DATA_MODIFY,
	DATA_DEL,
};


struct RecordData
{
	CString tName;
	CString serial;
	CString record;
	CString recordTime;
	CString opUser;
	CString state;

	CString tSerial;
};

class TestRecord
{
public:
	TestRecord();
	~TestRecord();

	void OnInitialUpdate();

	void SaveData();
	void RefreshData(CString testName);


	// 存储文件名
	CString m_xml;
	// xml操作工具
	CMarkup xml;

	// 列表
	CListCtrl *list;


	CTime m_timeEnd;
	CTime m_timeBegin;

	vector<RecordData> m_vecData;
	vector<CString> m_vecDataType;
};

