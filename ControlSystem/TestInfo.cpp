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
	// ��ʼ��������Ϣ���
	m_xml = CommGetAppPath() + _T("\\TestInfo.xml");
	CMarkup xmlInfo;
	if (!CommIsExistFile(m_xml))
	{

		xmlInfo.ResetMainPos();
		//xml.SetDoc("<?xml version=\"1.0\" ?>\r\n");
		xmlInfo.AddElem(_T("ROOT"));
		xmlInfo.AddChildElem(_T("������Ϣ�б�"));

		xmlInfo.Save(m_xml);
	}
	if (xmlInfo.Load(m_xml))
	{
		xmlInfo.ResetMainPos();
		xmlInfo.FindElem();
		if (xmlInfo.FindChildElem(_T("������Ϣ�б�")))
		{
			xmlInfo.IntoElem();

			while (xmlInfo.FindChildElem(_T("������Ϣ")))
			{
				TestData tData;
				tData.tName = xmlInfo.GetChildAttrib(_T("��������"));
				tData.startCondition = xmlInfo.GetChildAttrib(_T("��ʼ����"));
				tData.endCondition = xmlInfo.GetChildAttrib(_T("��������"));
				tData.tCeiling = xmlInfo.GetChildAttrib(_T("����"));
				tData.tFloor = xmlInfo.GetChildAttrib(_T("����"));
				tData.tResult = xmlInfo.GetChildAttrib(_T("���"));
				tData.tTime = xmlInfo.GetChildAttrib(_T("����ʱ��"));
				tData.tState = xmlInfo.GetChildAttrib(_T("����״̬"));
				tData.tSerial = xmlInfo.GetChildAttrib(_T("�������"));
				tData.pName = xmlInfo.GetChildAttrib(_T("��Ʒ����"));
				tData.pSerial = xmlInfo.GetChildAttrib(_T("��Ʒ���"));
				tData.pModel = xmlInfo.GetChildAttrib(_T("��Ʒ�ͺ�"));

				m_vecData.push_back(tData);
			}
			xmlInfo.OutOfElem();
		}
	}
}
// ��ʼˢ��
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
		if (it->tState != "ɾ��")tol++;
	}
	for (vector<TestData>::reverse_iterator it = m_vecData.rbegin(); it != m_vecData.rend(); it++)
	{
		if (it->tState != "ɾ��")
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

// ��������ˢ��
void TestInfo::RefreshData(CString pName)
{
	list->DeleteAllItems();

	CString strIndex;
	int tol = 0;
	for (vector<TestData>::reverse_iterator it = m_vecData.rbegin(); it != m_vecData.rend(); it++)
	{
		if (it->pName == pName && it->tState != "ɾ��")tol++;
	}
	for (vector<TestData>::reverse_iterator it = m_vecData.rbegin(); it != m_vecData.rend(); it++)
	{
		if (it->pName == pName && it->tState != "ɾ��")
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


// ������Ϣ
void TestInfo::SaveData()
{
	if (CommIsExistFile(m_xml))
	{
		if (xml.Load(m_xml))
		{
			xml.ResetMainPos();
			xml.FindElem();
			if (xml.FindChildElem(_T("������Ϣ�б�")))
			{
				xml.IntoElem();

				while (xml.FindChildElem(_T("������Ϣ")))
					xml.RemoveChildElem();

				xml.OutOfElem();
			}
			xml.ResetMainPos();
			xml.FindElem();
			CTime time = CTime::GetCurrentTime();
			CString timeRand;
			timeRand.Format(_T("%04d%02d%02d %02d:%02d:%02d"), time.GetYear(), time.GetMonth(), time.GetDay(), time.GetHour(), time.GetMinute(), time.GetSecond());

			//AfxMessageBox(str_time);
			if (xml.FindChildElem(_T("������Ϣ�б�")))
			{
				xml.IntoElem();

				for (vector<TestData>::iterator it = m_vecData.begin(); it != m_vecData.end(); it++)
				{
					if (it->tState != "ɾ��")
					{

						xml.AddChildElem(_T("������Ϣ"));
						xml.AddChildAttrib(_T("��������"), it->tName);
						xml.AddChildAttrib(_T("��ʼ����"), it->startCondition);
						xml.AddChildAttrib(_T("��������"), it->endCondition);
						xml.AddChildAttrib(_T("����"), it->tCeiling);
						xml.AddChildAttrib(_T("����"), it->tFloor);
						xml.AddChildAttrib(_T("���"), it->tResult);
						xml.AddChildAttrib(_T("����״̬"), it->tState);
						xml.AddChildAttrib(_T("����ʱ��"), timeRand);
						xml.AddChildAttrib(_T("�������"), it->tSerial);
						xml.AddChildAttrib(_T("��Ʒ����"), it->pName);
						xml.AddChildAttrib(_T("��Ʒ���"), it->pSerial);
						xml.AddChildAttrib(_T("��Ʒ�ͺ�"), it->pModel);
					}
				}
				xml.OutOfElem();
			}

			xml.Save(m_xml);
		}
	}
}
