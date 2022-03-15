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
	// ��ʼ��������Ϣ���
	m_xml = CommGetAppPath() + _T("\\TestRecord.xml");
	CMarkup xmlInfo;
	if (!CommIsExistFile(m_xml))
	{

		xmlInfo.ResetMainPos();
		//xml.SetDoc("<?xml version=\"1.0\" ?>\r\n");
		xmlInfo.AddElem(_T("ROOT"));
		xmlInfo.AddChildElem(_T("���Լ�¼"));

		xmlInfo.Save(m_xml);
	}
	if (xmlInfo.Load(m_xml))
	{
		xmlInfo.ResetMainPos();
		xmlInfo.FindElem();
		if (xmlInfo.FindChildElem(_T("���Լ�¼")))
		{
			xmlInfo.IntoElem();

			while (xmlInfo.FindChildElem(_T("��¼")))
			{
				RecordData rData;
				rData.tName = xmlInfo.GetChildAttrib(_T("��������"));
				rData.serial = xmlInfo.GetChildAttrib(_T("���"));
				rData.record = xmlInfo.GetChildAttrib(_T("��¼"));
				rData.recordTime = xmlInfo.GetChildAttrib(_T("ʱ��"));

				rData.opUser = xmlInfo.GetChildAttrib(_T("����Ա"));
				rData.state = xmlInfo.GetChildAttrib(_T("״̬"));
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
		if (it->tName == testName && it->state != "ɾ��")tol++;
	}
	for (vector<RecordData>::reverse_iterator it = m_vecData.rbegin(); it != m_vecData.rend(); it++)
	{
		if (it->tName == testName && it->state != "ɾ��")
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

// ������Ϣ
void TestRecord::SaveData()
{
	if (CommIsExistFile(m_xml))
	{
		if (xml.Load(m_xml))
		{
			xml.ResetMainPos();
			xml.FindElem();
			if (xml.FindChildElem(_T("���Լ�¼")))
			{
				xml.IntoElem();

				while (xml.FindChildElem(_T("��¼")))
					xml.RemoveChildElem();

				xml.OutOfElem();
			}
			xml.ResetMainPos();
			xml.FindElem();

			//AfxMessageBox(str_time);
			if (xml.FindChildElem(_T("���Լ�¼")))
			{
				xml.IntoElem();
				for (vector<RecordData>::reverse_iterator it = m_vecData.rbegin(); it != m_vecData.rend(); it++)
				{
					if (it->state != "ɾ��")
					{
						xml.AddChildElem(_T("��¼"));
						xml.AddChildAttrib(_T("��������"), it->tName);
						xml.AddChildAttrib(_T("���"), it->serial);
						xml.AddChildAttrib(_T("��¼"), it->record);
						xml.AddChildAttrib(_T("ʱ��"), it->recordTime);
						xml.AddChildAttrib(_T("����Ա"), it->opUser);
						xml.AddChildAttrib(_T("״̬"), it->state);


					}
				}

				xml.OutOfElem();
			}

			xml.Save(m_xml);
		}
	}
}