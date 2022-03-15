#include "TestInfo.h"
#include "FileComm.h"


TestInfo::TestInfo()
{
}


TestInfo::~TestInfo()
{
}


void TestInfo::OnInitialUpdate()
{
	// 初始化测试信息表格
	m_xml = CommGetAppPath() + _T("\\TestInfo.xml");
	CMarkup xmlInfo;
	if (!CommIsExistFile(m_xml))
	{

		xmlInfo.ResetMainPos();
		//xml.SetDoc("<?xml version=\"1.0\" ?>\r\n");
		xmlInfo.AddElem(_T("ROOT"));
		xmlInfo.AddChildElem(_T("测试信息列表"));

		xmlInfo.Save(m_xml);
	}
	if (xmlInfo.Load(m_xml))
	{
		xmlInfo.ResetMainPos();
		xmlInfo.FindElem();
		if (xmlInfo.FindChildElem(_T("测试信息列表")))
		{
			xmlInfo.IntoElem();

			while (xmlInfo.FindChildElem(_T("测试信息")))
			{
				TestData tData;
				tData.tName = xmlInfo.GetChildAttrib(_T("测试名称"));
				tData.startCondition = xmlInfo.GetChildAttrib(_T("开始条件"));
				tData.endCondition = xmlInfo.GetChildAttrib(_T("结束条件"));
				tData.tCeiling = xmlInfo.GetChildAttrib(_T("上限"));
				tData.tFloor = xmlInfo.GetChildAttrib(_T("下限"));
				tData.tResult = xmlInfo.GetChildAttrib(_T("结果"));
				tData.tTime = xmlInfo.GetChildAttrib(_T("测试时间"));
				tData.tState = xmlInfo.GetChildAttrib(_T("测试状态"));
				tData.tSerial = xmlInfo.GetChildAttrib(_T("测试序号"));
				tData.pName = xmlInfo.GetChildAttrib(_T("产品名称"));
				tData.pSerial = xmlInfo.GetChildAttrib(_T("产品序号"));
				tData.pModel = xmlInfo.GetChildAttrib(_T("产品型号"));

				m_vecData.push_back(tData);
			}
			xmlInfo.OutOfElem();
		}
	}
}
// 初始刷新
void TestInfo::RefreshData()
{
	list->DeleteAllItems();

	CString strTimeBegin;
	CString strTimeEnd;
	CString strQueryText;

	strTimeBegin.Format(_T("%04d%02d%02d %02d:%02d:%02d"), m_timeBegin.GetYear(), m_timeBegin.GetMonth(), m_timeBegin.GetDay(), m_timeBegin.GetHour(), m_timeBegin.GetMinute(), m_timeBegin.GetSecond());
	strTimeEnd.Format(_T("%04d%02d%02d %02d:%02d:%02d"), m_timeEnd.GetYear(), m_timeEnd.GetMonth(), m_timeEnd.GetDay(), m_timeEnd.GetHour(), m_timeEnd.GetMinute(), m_timeEnd.GetSecond());
	//m_editQueryText -> GetWindowText(strQueryText);
	strQueryText = strQueryText.TrimLeft(_T(" ")).TrimRight(_T(" "));

	vector<CString> vecQueryText = CommStrSplit(strQueryText, ';');

	CString strIndex;
	BOOL bFind = TRUE;
	int tol = 0;
	for (vector<TestData>::reverse_iterator it = m_vecData.rbegin(); it != m_vecData.rend(); it++)
	{
		if (it->tState != "删除")tol++;
	}
	for (vector<TestData>::reverse_iterator it = m_vecData.rbegin(); it != m_vecData.rend(); it++)
	{
		if (it->tState != "删除")
		{
			if (vecQueryText.size() > 0)
			{
				for (vector<CString>::iterator it_query = vecQueryText.begin(); it_query != vecQueryText.end(); it_query++)
				{
					strQueryText = *it_query;
					if (it->startCondition.Find(strQueryText, 0) >= 0 ||
						it->endCondition.Find(strQueryText, 0) >= 0 ||
						it->tName.Find(strQueryText, 0) >= 0 ||
						it->tResult.Find(strQueryText, 0) >= 0)
					{
						strIndex.Format(_T("%d"), list->GetItemCount() + 1);
						int iRow = list->InsertItem(0, strIndex);
						list->SetItemText(iRow, 1, it->tName);
						list->SetItemText(iRow, 2, it->startCondition);
						list->SetItemText(iRow, 3, it->endCondition);
						list->SetItemText(iRow, 4, it->tCeiling);
						list->SetItemText(iRow, 5, it->tFloor);
						list->SetItemText(iRow, 6, it->tResult);
						list->SetItemText(iRow, 7, it->tState);
						list->SetItemText(iRow, 8, it->tTime);
						break;
					}
				}
			}
			else
			{
				strIndex.Format(_T("%d"), tol--);
				int iRow = list->InsertItem(0, strIndex);
				list->SetItemText(iRow, 1, it->tName);
				list->SetItemText(iRow, 2, it->startCondition);
				list->SetItemText(iRow, 3, it->endCondition);
				list->SetItemText(iRow, 4, it->tCeiling);
				list->SetItemText(iRow, 5, it->tFloor);
				list->SetItemText(iRow, 6, it->tResult);
				list->SetItemText(iRow, 7, it->tState);
				list->SetItemText(iRow, 8, it->tTime);
			}
		}
	}
}

// 根据名称刷新
void TestInfo::RefreshData(CString pName)
{
	list->DeleteAllItems();

	CString strIndex;
	int tol = 0;
	for (vector<TestData>::reverse_iterator it = m_vecData.rbegin(); it != m_vecData.rend(); it++)
	{
		if (it->pName == pName && it->tState != "删除")tol++;
	}
	for (vector<TestData>::reverse_iterator it = m_vecData.rbegin(); it != m_vecData.rend(); it++)
	{
		if (it->pName == pName && it->tState != "删除")
		{
			strIndex.Format(_T("%d"), tol--);
			int iRow = list->InsertItem(0, strIndex);
			list->SetItemText(iRow, 1, it->tName);
			list->SetItemText(iRow, 2, it->startCondition);
			list->SetItemText(iRow, 3, it->endCondition);
			list->SetItemText(iRow, 4, it->tCeiling);
			list->SetItemText(iRow, 5, it->tFloor);
			list->SetItemText(iRow, 6, it->tResult);
			list->SetItemText(iRow, 7, it->tState);
			list->SetItemText(iRow, 8, it->tTime);
		}
	}
}


// 保存信息
void TestInfo::SaveData()
{
	if (CommIsExistFile(m_xml))
	{
		if (xml.Load(m_xml))
		{
			xml.ResetMainPos();
			xml.FindElem();
			if (xml.FindChildElem(_T("测试信息列表")))
			{
				xml.IntoElem();

				while (xml.FindChildElem(_T("测试信息")))
					xml.RemoveChildElem();

				xml.OutOfElem();
			}
			xml.ResetMainPos();
			xml.FindElem();
			CTime time = CTime::GetCurrentTime();
			CString timeRand;
			timeRand.Format(_T("%04d%02d%02d %02d:%02d:%02d"), time.GetYear(), time.GetMonth(), time.GetDay(), time.GetHour(), time.GetMinute(), time.GetSecond());

			//AfxMessageBox(str_time);
			if (xml.FindChildElem(_T("测试信息列表")))
			{
				xml.IntoElem();

				for (vector<TestData>::iterator it = m_vecData.begin(); it != m_vecData.end(); it++)
				{
					if (it->tState != "删除")
					{

						xml.AddChildElem(_T("测试信息"));
						xml.AddChildAttrib(_T("测试名称"), it->tName);
						xml.AddChildAttrib(_T("开始条件"), it->startCondition);
						xml.AddChildAttrib(_T("结束条件"), it->endCondition);
						xml.AddChildAttrib(_T("上限"), it->tCeiling);
						xml.AddChildAttrib(_T("下限"), it->tFloor);
						xml.AddChildAttrib(_T("结果"), it->tResult);
						xml.AddChildAttrib(_T("测试状态"), it->tState);
						xml.AddChildAttrib(_T("测试时间"), timeRand);
						xml.AddChildAttrib(_T("测试序号"), it->tSerial);
						xml.AddChildAttrib(_T("产品名称"), it->pName);
						xml.AddChildAttrib(_T("产品序号"), it->pSerial);
						xml.AddChildAttrib(_T("产品型号"), it->pModel);
					}
				}
				xml.OutOfElem();
			}

			xml.Save(m_xml);
		}
	}
}
