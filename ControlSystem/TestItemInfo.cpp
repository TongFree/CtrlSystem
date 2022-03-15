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
			if (xml.FindChildElem(_T("�������б�")))
			{
				xml.IntoElem();

				while (xml.FindChildElem(_T("������")))
					xml.RemoveChildElem();

				xml.OutOfElem();
			}
			xml.ResetMainPos();
			xml.FindElem();
			CTime time = CTime::GetCurrentTime();
			CString timeRand;
			timeRand.Format(_T("%04d%02d%02d %02d:%02d:%02d"), time.GetYear(), time.GetMonth(), time.GetDay(), time.GetHour(), time.GetMinute(), time.GetSecond());

			//AfxMessageBox(str_time);
			if (xml.FindChildElem(_T("�������б�")))
			{
				xml.IntoElem();

				for (vector<TestItem>::iterator it = m_vecData.begin(); it != m_vecData.end(); it++)
				{
					if (it->state != "ɾ��")
					{
						xml.AddChildElem(_T("������"));
						xml.AddChildAttrib(_T("����"), it->itemName);
						xml.AddChildAttrib(_T("����"), it->itemType);
						xml.AddChildAttrib(_T("ͨ��"), it->channel);
						xml.AddChildAttrib(_T("ͨ������"), it->channelType);
						xml.AddChildAttrib(_T("״̬λ"), it->state);
						xml.AddChildAttrib(_T("����"), it->option);
						xml.AddChildAttrib(_T("ռ�ձ�"), it->bRate);
						xml.AddChildAttrib(_T("��ʱ"), it->delay);
						xml.AddChildAttrib(_T("��Ĭʱ��"), it->silent);
						xml.AddChildAttrib(_T("����"), it->step);
						xml.AddChildAttrib(_T("�Ƿ�о�"), it->isJig);
						xml.AddChildAttrib(_T("Ƶ��"), it->hz);
						xml.AddChildAttrib(_T("����"), it->wave);
						xml.AddChildAttrib(_T("����"), it->pulse);
						xml.AddChildAttrib(_T("��ѹ"), it->v);
						xml.AddChildAttrib(_T("����"), it->a);
						xml.AddChildAttrib(_T("����ֵ"), it->r);
						xml.AddChildAttrib(_T("��ƽ"), it->dB);
						xml.AddChildAttrib(_T("Ԥ��1"), it->value1);
						xml.AddChildAttrib(_T("Ԥ��2"), it->value2);
						xml.AddChildAttrib(_T("Ԥ��3"), it->value3);
						xml.AddChildAttrib(_T("Ԥ��4"), it->value4);
						xml.AddChildAttrib(_T("Ԥ��5"), it->value5);
						xml.AddChildAttrib(_T("Ԥ��6"), it->value6);
						xml.AddChildAttrib(_T("Ԥ��7"), it->value7);
						xml.AddChildAttrib(_T("��������"), it->tName);
						xml.AddChildAttrib(_T("�������"), it->tSerial);
						
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
		if (it->state != "ɾ��")tol++;
	}
	for (vector<TestItem>::reverse_iterator it = m_vecData.rbegin(); it != m_vecData.rend(); it++)
	{
		if (it->state != "ɾ��")
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
	// ��ʼ��������
	m_xml = CommGetAppPath() + _T("\\TestItem.xml");
	CMarkup xmlInfo;
	if (!CommIsExistFile(m_xml))
	{

		xmlInfo.ResetMainPos();
		//xml.SetDoc("<?xml version=\"1.0\" ?>\r\n");
		xmlInfo.AddElem(_T("ROOT"));
		xmlInfo.AddChildElem(_T("�������б�"));

		xmlInfo.Save(m_xml);
	}
	if (xmlInfo.Load(m_xml))
	{
		xmlInfo.ResetMainPos();
		xmlInfo.FindElem();
		if (xmlInfo.FindChildElem(_T("�������б�")))
		{
			xmlInfo.IntoElem();

			while (xmlInfo.FindChildElem(_T("������")))
			{
				TestItem tItem;
				tItem.itemName = xmlInfo.GetChildAttrib(_T("����"));
				tItem.itemType = xmlInfo.GetChildAttrib(_T("����"));
				tItem.channel = xmlInfo.GetChildAttrib(_T("ͨ��"));
				tItem.channelType = xmlInfo.GetChildAttrib(_T("ͨ������"));
				tItem.state = xmlInfo.GetChildAttrib(_T("״̬λ"));
				tItem.option = xmlInfo.GetChildAttrib(_T("����"));
				tItem.bRate = xmlInfo.GetChildAttrib(_T("ռ�ձ�"));
				tItem.delay = xmlInfo.GetChildAttrib(_T("�ӳ�"));
				tItem.silent = xmlInfo.GetChildAttrib(_T("��Ĭʱ��"));
				tItem.step = xmlInfo.GetChildAttrib(_T("����"));
				tItem.isJig = xmlInfo.GetChildAttrib(_T("�Ƿ�о�"));
				tItem.hz = xmlInfo.GetChildAttrib(_T("Ƶ��"));
				tItem.wave = xmlInfo.GetChildAttrib(_T("����"));
				tItem.pulse = xmlInfo.GetChildAttrib(_T("����"));
				tItem.v = xmlInfo.GetChildAttrib(_T("��ѹ"));
				tItem.a = xmlInfo.GetChildAttrib(_T("����"));
				tItem.r = xmlInfo.GetChildAttrib(_T("����ֵ"));
				tItem.dB = xmlInfo.GetChildAttrib(_T("��ƽ"));
				tItem.value1 = xmlInfo.GetChildAttrib(_T("Ԥ��1"));
				tItem.value2 = xmlInfo.GetChildAttrib(_T("Ԥ��2"));
				tItem.value3 = xmlInfo.GetChildAttrib(_T("Ԥ��3"));
				tItem.value4 = xmlInfo.GetChildAttrib(_T("Ԥ��4"));
				tItem.value5 = xmlInfo.GetChildAttrib(_T("Ԥ��5"));
				tItem.value6 = xmlInfo.GetChildAttrib(_T("Ԥ��6"));
				tItem.value7 = xmlInfo.GetChildAttrib(_T("Ԥ��7"));
				tItem.tName = xmlInfo.GetChildAttrib(_T("��������"));
				tItem.tName = xmlInfo.GetChildAttrib(_T("�������"));
				m_vecData.push_back(tItem);
			}
			xmlInfo.OutOfElem();
		}
		RefreshData();
	}
}
