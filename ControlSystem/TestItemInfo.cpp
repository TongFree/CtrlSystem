#include "TestItemInfo.h"
#include "FileComm.h"


TestItemInfo::TestItemInfo()
{
}


TestItemInfo::~TestItemInfo()
{
}

void TestItemInfo::SaveData()
{
	if (CommIsExistFile(m_xml))
	{
		if (xml.Load(m_xml))
		{
			xml.ResetMainPos();
			xml.FindElem();
			if (xml.FindChildElem(_T("测试项列表")))
			{
				xml.IntoElem();

				while (xml.FindChildElem(_T("测试项")))
					xml.RemoveChildElem();

				xml.OutOfElem();
			}
			xml.ResetMainPos();
			xml.FindElem();
			CTime time = CTime::GetCurrentTime();
			CString timeRand;
			timeRand.Format(_T("%04d%02d%02d %02d:%02d:%02d"), time.GetYear(), time.GetMonth(), time.GetDay(), time.GetHour(), time.GetMinute(), time.GetSecond());

			//AfxMessageBox(str_time);
			if (xml.FindChildElem(_T("测试项列表")))
			{
				xml.IntoElem();

				for (vector<TestItem>::iterator it = m_vecData.begin(); it != m_vecData.end(); it++)
				{
					if (it->state != "删除")
					{
						xml.AddChildElem(_T("测试项"));
						xml.AddChildAttrib(_T("名称"), it->itemName);
						xml.AddChildAttrib(_T("类型"), it->itemType);
						xml.AddChildAttrib(_T("通道"), it->channel);
						xml.AddChildAttrib(_T("通道类型"), it->channelType);
						xml.AddChildAttrib(_T("状态位"), it->state);
						xml.AddChildAttrib(_T("操做"), it->option);
						xml.AddChildAttrib(_T("占空比"), it->bRate);
						xml.AddChildAttrib(_T("延时"), it->delay);
						xml.AddChildAttrib(_T("静默时间"), it->silent);
						xml.AddChildAttrib(_T("步骤"), it->step);
						xml.AddChildAttrib(_T("是否夹具"), it->isJig);
						xml.AddChildAttrib(_T("频率"), it->hz);
						xml.AddChildAttrib(_T("波形"), it->wave);
						xml.AddChildAttrib(_T("脉冲"), it->pulse);
						xml.AddChildAttrib(_T("电压"), it->v);
						xml.AddChildAttrib(_T("电流"), it->a);
						xml.AddChildAttrib(_T("电阻值"), it->r);
						xml.AddChildAttrib(_T("电平"), it->dB);
						xml.AddChildAttrib(_T("预留1"), it->value1);
						xml.AddChildAttrib(_T("预留2"), it->value2);
						xml.AddChildAttrib(_T("预留3"), it->value3);
						xml.AddChildAttrib(_T("预留4"), it->value4);
						xml.AddChildAttrib(_T("预留5"), it->value5);
						xml.AddChildAttrib(_T("预留6"), it->value6);
						xml.AddChildAttrib(_T("预留7"), it->value7);
						xml.AddChildAttrib(_T("测试名称"), it->tName);
						xml.AddChildAttrib(_T("测试序号"), it->tSerial);
						
					}
				}

				xml.OutOfElem();
			}

			xml.Save(m_xml);
		}
	}
}

void TestItemInfo::RefreshData()
{
	list->DeleteAllItems();
	CString strIndex;
	int tol = 0;
	for (vector<TestItem>::reverse_iterator it = m_vecData.rbegin(); it != m_vecData.rend(); it++)
	{
		if (it->state != "删除")tol++;
	}
	for (vector<TestItem>::reverse_iterator it = m_vecData.rbegin(); it != m_vecData.rend(); it++)
	{
		if (it->state != "删除")
		{
			strIndex.Format(_T("%d"), tol--);
			int iRow = list->InsertItem(0, strIndex);
			list->SetItemText(iRow, 1, it->itemName);
			list->SetItemText(iRow, 2, it->itemType);
			list->SetItemText(iRow, 3, it->channel);
			list->SetItemText(iRow, 4, it->channelType);
			list->SetItemText(iRow, 5, it->state);
			list->SetItemText(iRow, 6, it->option);
			list->SetItemText(iRow, 7, it->bRate);
			list->SetItemText(iRow, 8, it->delay);
			list->SetItemText(iRow, 9, it->silent);
			list->SetItemText(iRow, 10, it->step);
			list->SetItemText(iRow, 11, it->isJig);
			list->SetItemText(iRow, 12, it->hz);
			list->SetItemText(iRow, 13, it->wave);
			list->SetItemText(iRow, 14, it->pulse);
			list->SetItemText(iRow, 15, it->v);
			list->SetItemText(iRow, 16, it->a);
			list->SetItemText(iRow, 17, it->r);
			list->SetItemText(iRow, 18, it->dB);
			list->SetItemText(iRow, 19, it->value1);
			list->SetItemText(iRow, 20, it->value2);
			list->SetItemText(iRow, 21, it->value3);
			list->SetItemText(iRow, 22, it->value4);
			list->SetItemText(iRow, 23, it->value5);
			list->SetItemText(iRow, 24, it->value6);
			list->SetItemText(iRow, 25, it->value7);
			SaveData();
		}
	}
}

void TestItemInfo::OnInitialUpdate()
{
	// 初始化测试项
	m_xml = CommGetAppPath() + _T("\\TestItem.xml");
	CMarkup xmlInfo;
	if (!CommIsExistFile(m_xml))
	{

		xmlInfo.ResetMainPos();
		//xml.SetDoc("<?xml version=\"1.0\" ?>\r\n");
		xmlInfo.AddElem(_T("ROOT"));
		xmlInfo.AddChildElem(_T("测试项列表"));

		xmlInfo.Save(m_xml);
	}
	if (xmlInfo.Load(m_xml))
	{
		xmlInfo.ResetMainPos();
		xmlInfo.FindElem();
		if (xmlInfo.FindChildElem(_T("测试项列表")))
		{
			xmlInfo.IntoElem();

			while (xmlInfo.FindChildElem(_T("测试项")))
			{
				TestItem tItem;
				tItem.itemName = xmlInfo.GetChildAttrib(_T("名称"));
				tItem.itemType = xmlInfo.GetChildAttrib(_T("类型"));
				tItem.channel = xmlInfo.GetChildAttrib(_T("通道"));
				tItem.channelType = xmlInfo.GetChildAttrib(_T("通道类型"));
				tItem.state = xmlInfo.GetChildAttrib(_T("状态位"));
				tItem.option = xmlInfo.GetChildAttrib(_T("操作"));
				tItem.bRate = xmlInfo.GetChildAttrib(_T("占空比"));
				tItem.delay = xmlInfo.GetChildAttrib(_T("延迟"));
				tItem.silent = xmlInfo.GetChildAttrib(_T("静默时间"));
				tItem.step = xmlInfo.GetChildAttrib(_T("步骤"));
				tItem.isJig = xmlInfo.GetChildAttrib(_T("是否夹具"));
				tItem.hz = xmlInfo.GetChildAttrib(_T("频率"));
				tItem.wave = xmlInfo.GetChildAttrib(_T("波形"));
				tItem.pulse = xmlInfo.GetChildAttrib(_T("脉冲"));
				tItem.v = xmlInfo.GetChildAttrib(_T("电压"));
				tItem.a = xmlInfo.GetChildAttrib(_T("电流"));
				tItem.r = xmlInfo.GetChildAttrib(_T("电阻值"));
				tItem.dB = xmlInfo.GetChildAttrib(_T("电平"));
				tItem.value1 = xmlInfo.GetChildAttrib(_T("预留1"));
				tItem.value2 = xmlInfo.GetChildAttrib(_T("预留2"));
				tItem.value3 = xmlInfo.GetChildAttrib(_T("预留3"));
				tItem.value4 = xmlInfo.GetChildAttrib(_T("预留4"));
				tItem.value5 = xmlInfo.GetChildAttrib(_T("预留5"));
				tItem.value6 = xmlInfo.GetChildAttrib(_T("预留6"));
				tItem.value7 = xmlInfo.GetChildAttrib(_T("预留7"));
				tItem.tName = xmlInfo.GetChildAttrib(_T("测试名称"));
				tItem.tName = xmlInfo.GetChildAttrib(_T("测试序号"));
				m_vecData.push_back(tItem);
			}
			xmlInfo.OutOfElem();
		}
		RefreshData();
	}
}
