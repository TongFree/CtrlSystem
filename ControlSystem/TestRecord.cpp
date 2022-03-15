#include "TestRecord.h"
#include "FileComm.h"


TestRecord::TestRecord()
{
}


TestRecord::~TestRecord()
{
}


void TestRecord::OnInitialUpdate()
{
	// 初始化测试信息表格
	m_xml = CommGetAppPath() + _T("\\TestRecord.xml");
	CMarkup xmlInfo;
	if (!CommIsExistFile(m_xml))
	{

		xmlInfo.ResetMainPos();
		//xml.SetDoc("<?xml version=\"1.0\" ?>\r\n");
		xmlInfo.AddElem(_T("ROOT"));
		xmlInfo.AddChildElem(_T("测试记录"));

		xmlInfo.Save(m_xml);
	}
	if (xmlInfo.Load(m_xml))
	{
		xmlInfo.ResetMainPos();
		xmlInfo.FindElem();
		if (xmlInfo.FindChildElem(_T("测试记录")))
		{
			xmlInfo.IntoElem();

			while (xmlInfo.FindChildElem(_T("记录")))
			{
				RecordData rData;
				rData.tName = xmlInfo.GetChildAttrib(_T("测试名称"));
				rData.serial = xmlInfo.GetChildAttrib(_T("序号"));
				rData.record = xmlInfo.GetChildAttrib(_T("记录"));
				rData.recordTime = xmlInfo.GetChildAttrib(_T("时间"));

				rData.opUser = xmlInfo.GetChildAttrib(_T("操作员"));
				rData.state = xmlInfo.GetChildAttrib(_T("状态"));
				m_vecData.push_back(rData);
			}
			xmlInfo.OutOfElem();
		}
	}
}

void TestRecord::RefreshData(CString testName)
{
	list->DeleteAllItems();
	CString strIndex;
	BOOL bFind = TRUE;
	int tol = 0;
	for (vector<RecordData>::reverse_iterator it = m_vecData.rbegin(); it != m_vecData.rend(); it++)
	{
		if (it->tName == testName && it->state != "删除")tol++;
	}
	for (vector<RecordData>::reverse_iterator it = m_vecData.rbegin(); it != m_vecData.rend(); it++)
	{
		if (it->tName == testName && it->state != "删除")
		{
			strIndex.Format(_T("%d"), tol--);
			int iRow = list->InsertItem(0, strIndex);
			list->SetItemText(iRow, 1, it->tName);
			list->SetItemText(iRow, 2, it->serial);
			list->SetItemText(iRow, 3, it->record);
			list->SetItemText(iRow, 4, it->recordTime);
			list->SetItemText(iRow, 5, it->opUser);
			list->SetItemText(iRow, 6, it->state);
			SaveData();
		}
	}
}

// 保存信息
void TestRecord::SaveData()
{
	if (CommIsExistFile(m_xml))
	{
		if (xml.Load(m_xml))
		{
			xml.ResetMainPos();
			xml.FindElem();
			if (xml.FindChildElem(_T("测试记录")))
			{
				xml.IntoElem();

				while (xml.FindChildElem(_T("记录")))
					xml.RemoveChildElem();

				xml.OutOfElem();
			}
			xml.ResetMainPos();
			xml.FindElem();

			//AfxMessageBox(str_time);
			if (xml.FindChildElem(_T("测试记录")))
			{
				xml.IntoElem();
				for (vector<RecordData>::reverse_iterator it = m_vecData.rbegin(); it != m_vecData.rend(); it++)
				{
					if (it->state != "删除")
					{
						xml.AddChildElem(_T("记录"));
						xml.AddChildAttrib(_T("测试名称"), it->tName);
						xml.AddChildAttrib(_T("序号"), it->serial);
						xml.AddChildAttrib(_T("记录"), it->record);
						xml.AddChildAttrib(_T("时间"), it->recordTime);
						xml.AddChildAttrib(_T("操作员"), it->opUser);
						xml.AddChildAttrib(_T("状态"), it->state);


					}
				}

				xml.OutOfElem();
			}

			xml.Save(m_xml);
		}
	}
}