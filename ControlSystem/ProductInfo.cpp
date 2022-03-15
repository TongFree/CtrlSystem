#include "ProductInfo.h"
#include "FileComm.h"


ProductInfo::ProductInfo()
{
}


ProductInfo::~ProductInfo()
{
}


void ProductInfo::SaveData()
{
	if (CommIsExistFile(m_xml))
	{
		if (xml.Load(m_xml))
		{
			xml.ResetMainPos();
			xml.FindElem();
			if (xml.FindChildElem(_T("��Ʒ�б�")))
			{
				xml.IntoElem();

				while (xml.FindChildElem(_T("��Ʒ")))
					xml.RemoveChildElem();

				xml.OutOfElem();
			}
			xml.ResetMainPos();
			xml.FindElem();
			CTime time = CTime::GetCurrentTime();
			CString timeRand;
			timeRand.Format(_T("%04d%02d%02d %02d:%02d:%02d"), time.GetYear(), time.GetMonth(), time.GetDay(), time.GetHour(), time.GetMinute(), time.GetSecond());

			//AfxMessageBox(str_time);
			if (xml.FindChildElem(_T("��Ʒ�б�")))
			{
				xml.IntoElem();

				for (vector<Product>::iterator it = m_vecData.begin(); it != m_vecData.end(); it++)
				{
					if (it->state != "ɾ��")
					{
						xml.AddChildElem(_T("��Ʒ"));
						xml.AddChildAttrib(_T("������"), it->serial);
						xml.AddChildAttrib(_T("����"), it->name);
						xml.AddChildAttrib(_T("�ͺ�"), it->model);
						xml.AddChildAttrib(_T("״̬"), it->state);
					}
				}

				xml.OutOfElem();
			}

			xml.Save(m_xml);
		}
	}
}

void ProductInfo::RefreshData()
{

	list->DeleteAllItems();

	CString strTimeBegin;
	CString strTimeEnd;
	CString strQueryText;

	strTimeBegin.Format(_T("%04d%02d%02d %02d:%02d:%02d"), m_timeBegin.GetYear(), m_timeBegin.GetMonth(), m_timeBegin.GetDay(), m_timeBegin.GetHour(), m_timeBegin.GetMinute(), m_timeBegin.GetSecond());
	strTimeEnd.Format(_T("%04d%02d%02d %02d:%02d:%02d"), m_timeEnd.GetYear(), m_timeEnd.GetMonth(), m_timeEnd.GetDay(), m_timeEnd.GetHour(), m_timeEnd.GetMinute(), m_timeEnd.GetSecond());
	//m_editQueryText.GetWindowText(strQueryText); // ��ѯ�ù���
	strQueryText = strQueryText.TrimLeft(_T(" ")).TrimRight(_T(" "));

	vector<CString> vecQueryText = CommStrSplit(strQueryText, ';');

	CString strIndex;
	BOOL bFind = TRUE;
	int tol = 0;
	for (vector<Product>::reverse_iterator it = m_vecData.rbegin(); it != m_vecData.rend(); it++)
	{
		if (it->state != "ɾ��")tol++;
	}
	for (vector<Product>::reverse_iterator it = m_vecData.rbegin(); it != m_vecData.rend(); it++)
	{
		if (it->state != "ɾ��")
		{
			if (vecQueryText.size() > 0)
			{
				for (vector<CString>::iterator it_query = vecQueryText.begin(); it_query != vecQueryText.end(); it_query++)
				{
					strQueryText = *it_query;
					if (it->name.Find(strQueryText, 0) >= 0 ||
						it->model.Find(strQueryText, 0) >= 0)
					{
						strIndex.Format(_T("%d"), list->GetItemCount() + 1);
						int iRow = list->InsertItem(0, strIndex);
						list->SetItemText(iRow, 1, it->name);
						list->SetItemText(iRow, 2, it->model);
						list->SetItemText(iRow, 3, it->model);
						list->SetItemText(iRow, 4, it->state);
						break;
					}
				}
			}
			else
			{
				strIndex.Format(_T("%d"), tol--);
				int iRow = list->InsertItem(0, strIndex);
				list->SetItemText(iRow, 1, it->serial);
				list->SetItemText(iRow, 2, it->name);
				list->SetItemText(iRow, 3, it->model);
				list->SetItemText(iRow, 4, it->state);
				SaveData();
			}
		}
	}
}

void ProductInfo::OnInitialUpdate()
{

	// ��ʼ����Ʒ���
	m_xml = CommGetAppPath() + _T("\\ProductInfo.xml");
	CMarkup xmlInfo;
	if (!CommIsExistFile(m_xml))
	{

		xmlInfo.ResetMainPos();
		//xml.SetDoc("<?xml version=\"1.0\" ?>\r\n");
		xmlInfo.AddElem(_T("ROOT"));
		xmlInfo.AddChildElem(_T("��Ʒ�б�"));

		xmlInfo.Save(m_xml);
	}
	if (xmlInfo.Load(m_xml))
	{
		xmlInfo.ResetMainPos();
		xmlInfo.FindElem();
		if (xmlInfo.FindChildElem(_T("��Ʒ�б�")))
		{
			xmlInfo.IntoElem();

			while (xmlInfo.FindChildElem(_T("��Ʒ")))
			{
				Product p;
				p.serial = xmlInfo.GetChildAttrib(_T("������"));
				p.name = xmlInfo.GetChildAttrib(_T("����"));
				p.model = xmlInfo.GetChildAttrib(_T("�ͺ�"));
				p.state = xmlInfo.GetChildAttrib(_T("״̬"));
				m_vecData.push_back(p);
			}
			xmlInfo.OutOfElem();
		}
	}
}
