#include "pch.h"
#include "InfoFile.h"
#include "CApplication.h"
//#include "CBorders.h"
//#include "CFont0.h"
#include <afxdb.h>

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif
CInfoFile::CInfoFile()
{
}

CInfoFile::~CInfoFile()
{
}

//��ȡ��Ʒ�ͺ��ļ�
void CInfoFile::ReadLogin(CString& name, CString& pwd)
{
	ifstream ifs; //�����ļ��������
	ifs.open(_F_LOGIN); //���ļ�

	char buf[1024] = { 0 };

	ifs.getline(buf, sizeof(buf)); //��ȡһ������
	name = CString(buf);			 //char *ת��ΪCString

	ifs.getline(buf, sizeof(buf));
	pwd = CString(buf);

	ifs.close(); //�ر��ļ�
}

//�޸��ͺ���Ϣ
void CInfoFile::WritePwd(char* name, char* pwd)
{
	ofstream ofs;	 //�����ļ��������
	ofs.open(_F_LOGIN); //���ļ�

	ofs << name << endl; //nameд���ļ�
	ofs << pwd << endl;	//pwdд���ļ�

	ofs.close();	//�ر��ļ�
}

//��ȡ�б���Ϣ
void CInfoFile::ReadDocline(string stock)
{
	/*
	CString file;
	ifstream ifs(stock); //���뷽ʽ���ļ�

	char buf[2048] = { 0 };
	num = 0;	//��ʼ������Ϊ0
	ls.clear();
	//ȡ����ͷ
	ifs.getline(buf, sizeof(buf));

	while (!ifs.eof()) //û���ļ���β
	{
	msg tmp;

	ifs.getline(buf, sizeof(buf)); //��ȡһ��
	num++;	//��Ŀ��һ

	//AfxMessageBox(CString(buf));
	char* sst = strtok(buf, "|"); //�ԡ�|���и�
	if (sst != NULL)
	{
	tmp.id = sst; //id
	}
	else
	{
	break;
	}

	sst = strtok(NULL, "|");
	tmp.name = sst;	//��������

	sst = strtok(NULL, "|");
	tmp.start = sst;	//��ʼ

	sst = strtok(NULL, "|");
	tmp.end = sst;	//����

	sst = strtok(NULL, "|");
	tmp.view1 = sst;	//��1

	sst = strtok(NULL, "|");
	tmp.view2 = sst;	//��2

	sst = strtok(NULL, "|");
	tmp.view3 = sst;	//��3

	sst = strtok(NULL, "|");
	tmp.view4 = sst;	//��4

	sst = strtok(NULL, "|");
	tmp.view5 = sst;	//��5

	sst = strtok(NULL, "|");
	tmp.view6 = sst;	//��6

	sst = strtok(NULL, "|");
	tmp.view7 = sst;	//��7

	sst = strtok(NULL, "|");
	tmp.view8 = sst;	//��8

	sst = strtok(NULL, "|");
	tmp.view9 = sst;	//��9

	sst = strtok(NULL, "|");
	tmp.view10 = sst;	//��10

	sst = strtok(NULL, "|");
	tmp.view11 = sst;	//��11

	ls.push_back(tmp); //��������ĺ���
	}

	ifs.close(); //�ر��ļ�
	*/
	/*
	CFileDialog dlg(TRUE, //TRUE��FALSE��TRUEΪ���ļ���FALSEΪ�����ļ�
	"xls", //Ϊȱʡ����չ��
	"FileList", //Ϊ��ʾ���ļ�����Ͽ�ı༭����ļ�����һ���ѡNULL
	OFN_HIDEREADONLY | OFN_OVERWRITEPROMPT,//Ϊ�Ի�����һ��ΪOFN_HIDEREADONLY   |   OFN_OVERWRITEPROMPT,������ֻ��ѡ��͸��������ļ�ǰ��ʾ��
	"Excel �ļ�(*.xls)|*.xls||"//Ϊ�����б�������ʾ�ļ�����
	);
	dlg.m_ofn.lpstrTitle = "��������";
	*/
	//if (dlg.DoModal() != IDOK)
	//return;
	//CString strFilePath;
	//����ļ�·����
	//strFilePath = stock;
	//�ж��ļ��Ƿ��Ѿ����ڣ���������ļ�
	ls.clear();
	DWORD dwRe = GetFileAttributes(stock.c_str());
	if (dwRe != (DWORD)-1)
	{
		//ShellExecute(NULL, NULL, strFilePath, NULL, NULL, SW_RESTORE);
	}
	else return;

	CDatabase db;//���ݿ����Ҫ����ͷ�ļ� #include <afxdb.h>
	CString sDriver = "MICROSOFT EXCEL DRIVER (*.XLS)"; // Excel����
	CString sSql, arr[16];

	sSql.Format("DRIVER={%s};DSN='';FIRSTROWHASNAMES=1;READONLY=FALSE;CREATE_DB=\"%s\";DBQ=%s", sDriver, stock.c_str(), stock.c_str());
	if (!db.OpenEx(sSql, CDatabase::noOdbcDialog))//��������ԴDJB��xls
	{
		//MessageBox("��EXCEL�ļ�ʧ��!", "����");
		return;
	}
	//��EXCEL��
	CRecordset pset(&db);
	//m_list.DeleteAllItems();

	//AfxMessageBox("OK");
	/* sSql = "SELECT ѧ��,����,�ɼ� "
	"FROM EXCELDEMO";      */
	// "ORDER BY ����";
	sSql.Format("SELECT ID,��������,��ʼ��ʽ,������ʽ,�ӱ�1,�ӱ�2,�ӱ�3,�ӱ�4,�ӱ�5,�ӱ�6,�ӱ�7,�ӱ�8,�ӱ�9,�ӱ�10,�ӱ�11 FROM DSO_DX");
	pset.Open(CRecordset::forwardOnly, sSql, CRecordset::readOnly);
	while (!pset.IsEOF())
	{


		msg tmp;
		num++;
		
		pset.GetFieldValue("ID", arr[0]);//ǰ���ֶα�������е���ͬ���������
		pset.GetFieldValue("��������", arr[1]);
		pset.GetFieldValue("��ʼ��ʽ", arr[2]);
		pset.GetFieldValue("������ʽ", arr[3]);
		pset.GetFieldValue("�ӱ�1", arr[4]);
		pset.GetFieldValue("�ӱ�2", arr[5]);
		pset.GetFieldValue("�ӱ�3", arr[6]);
		pset.GetFieldValue("�ӱ�4", arr[7]);
		pset.GetFieldValue("�ӱ�5", arr[8]);
		pset.GetFieldValue("�ӱ�6", arr[9]);
		pset.GetFieldValue("�ӱ�7", arr[10]);
		pset.GetFieldValue("�ӱ�8", arr[11]);
		pset.GetFieldValue("�ӱ�9", arr[12]);
		pset.GetFieldValue("�ӱ�10", arr[13]);
		pset.GetFieldValue("�ӱ�11", arr[14]);
		//pset.GetFieldValue("�ӱ�12", arr[15]);
		tmp.id = CT2A(arr[0].GetBuffer());
		tmp.name = CT2A(arr[1].GetBuffer());
		tmp.start = CT2A(arr[2].GetBuffer());
		tmp.end = CT2A(arr[3].GetBuffer());
		tmp.view1 = CT2A(arr[4].GetBuffer());
		tmp.view2 = CT2A(arr[5].GetBuffer());
		tmp.view3 = CT2A(arr[6].GetBuffer());
		tmp.view4 = CT2A(arr[7].GetBuffer());
		tmp.view5 = CT2A(arr[8].GetBuffer());
		tmp.view6 = CT2A(arr[9].GetBuffer());
		tmp.view7 = CT2A(arr[10].GetBuffer());
		tmp.view8 = CT2A(arr[11].GetBuffer());
		tmp.view9 = CT2A(arr[12].GetBuffer());
		tmp.view10 = CT2A(arr[13].GetBuffer());
		tmp.view11 = CT2A(arr[14].GetBuffer());
		//tmp.view12 = CT2A(arr[15].GetBuffer());
		//int count = m_list.GetItemCount();//���뵽ListCtrl��
		//m_list.InsertItem(count, arr[0]);
		//m_list.SetItemText(count, 1, arr[1]);
		//m_list.SetItemText(count, 2, arr[2]);
		ls.push_back(tmp);
		pset.MoveNext();
	}
	db.Close();

	//MessageBox("Excel���ݳɹ�����ϵͳ!", "����ɹ�");
}

//��ȡĿ¼�ļ�
void CInfoFile::ReadMenu()
{
	CString file;
	file = _F_MENU;
	ifstream ifs(file); //���뷽ʽ���ļ�

	char buf[1024] = { 0 };
	num = 0;	//��ʼ������Ϊ0
	mls.clear();
	//ȡ����ͷ
	ifs.getline(buf, sizeof(buf));

	while (!ifs.eof()) //û���ļ���β
	{
		menuMsg tmp;

		ifs.getline(buf, sizeof(buf)); //��ȡһ��
		num++;	//��Ŀ��һ

				//AfxMessageBox(CString(buf));
		char* sst = strtok(buf, "|"); //�ԡ�|���и�
		if (sst != NULL)
		{
			tmp.Mid = sst; //id
		}
		else
		{
			break;
		}

		sst = strtok(NULL, "|");
		tmp.MCname = sst;	//��������

		sst = strtok(NULL, "|");
		tmp.Mname = sst;	//����1

		sst = strtok(NULL, "|");
		tmp.Roud = sst;	//����2

		sst = strtok(NULL, "|");
		tmp.ExcelRoud = sst;	//����3

		mls.push_back(tmp); //��������ĺ���
	}

	ifs.close(); //�ر��ļ�
}

//��ȡ�浵�ļ�
void CInfoFile::saveMenu()
{
	//"./stock_save/save.txt"
	ifstream ifs("./stock_save/save.txt"); //���뷽ʽ���ļ�

	char buf[1024] = { 0 };
	num = 0;	//��ʼ������Ϊ0
	save.clear();
	//ȡ����ͷ
	ifs.getline(buf, sizeof(buf));

	while (!ifs.eof()) //û���ļ���β
	{
		saveFile tmp;

		ifs.getline(buf, sizeof(buf)); //��ȡһ��
		num++;	//��Ŀ��һ

				//AfxMessageBox(CString(buf));
		char* sst = strtok(buf, "|"); //�ԡ�|���и�
		if (sst != NULL)
		{
			tmp.name1 = sst; //id
		}
		else
		{
			break;
		}

		sst = strtok(NULL, "|");
		tmp.name2 = sst;	//��������

		sst = strtok(NULL, "|");
		tmp.view1 = sst;	//����1

		save.push_back(tmp); //��������ĺ���
	}

	ifs.close(); //�ر��ļ�
}

void CInfoFile::WirteSaveChild()
{
	ofstream ofs("./stock_save/save.txt");//�����ʽ���ļ�
	if (save.size() > 0)	//��Ʒ���������ݲ�ִ��
	{
		ofs << "�浵��|��Ŀ��|����" << endl; //д���ͷ

									 //ͨ��������ȡ���������ݣ�д���ļ����ԡ�|���ָ�����β�ӻ���
		for (list<saveFile>::iterator it = save.begin(); it != save.end(); it++)
		{
			ofs << it->name1 << "|";
			ofs << it->name2 << "|";
			ofs << it->view1 << endl;
		}
	}

	ofs.close();//�ر��ļ�
}

void CInfoFile::WirteChild(string stock)
{
	/*
	ofstream ofs(stock);//�����ʽ���ļ�

	if (ls.size() > 0)	//��Ʒ���������ݲ�ִ��
	{
	ofs << "ID|��������|��ʼ��ʽ|������ʽ|�ӱ�1|�ӱ�2|�ӱ�3|�ӱ�4|�ӱ�5|�ӱ�6|�ӱ�7|�ӱ�8|�ӱ�9|�ӱ�10|�ӱ�11" << endl; //д���ͷ

	//ͨ��������ȡ���������ݣ�д���ļ����ԡ�|���ָ�����β�ӻ���
	for (list<msg>::iterator it = ls.begin(); it != ls.end(); it++)
	{
	ofs << it->id << "|";
	ofs << it->name << "|";
	ofs << it->start << "|";
	ofs << it->end << "|";
	ofs << it->view1 << "|";
	ofs << it->view2 << "|";
	ofs << it->view3 << "|";
	ofs << it->view4 << "|";
	ofs << it->view5 << "|";
	ofs << it->view6 << "|";
	ofs << it->view7 << "|";
	ofs << it->view8 << "|";
	ofs << it->view9 << "|";
	ofs << it->view10 << "|";
	ofs << it->view11 << endl;
	}
	}

	ofs.close();//�ر��ļ�

	*/

	//�����Ϊ�Ի��� ����Ҫ���� #include <Afxdlgs.h>

	CString strFilePath;
	//����ļ�·����
	strFilePath = stock.c_str();
	//�ж��ļ��Ƿ��Ѿ����ڣ�������ɾ���ؽ�
	DWORD dwRe = GetFileAttributes(strFilePath);
	if (dwRe != (DWORD)-1)
	{
		DeleteFile(strFilePath);
	}

	CDatabase database;//���ݿ����Ҫ����ͷ�ļ� #include <afxdb.h>
	CString sDriver = "MICROSOFT EXCEL DRIVER (*.XLS)"; // Excel����
	CString sSql, strInsert;
	TRY
	{
		// �������д�ȡ���ַ���
		sSql.Format("DRIVER={%s};DSN='';FIRSTROWHASNAMES=1;READONLY=FALSE;CREATE_DB=\"%s\";DBQ=%s",sDriver, strFilePath, strFilePath);

	// �������ݿ� (��Excel����ļ�)
	if (database.OpenEx(sSql,CDatabase::noOdbcDialog))
	{
		//����б��������
		//int iColumnNum,iRowCount;
		LVCOLUMN lvCol;
		CString strColName; //���ڱ����б�������
							//int i,j; //�С���ѭ������

							//iColumnNum = m_list.GetHeaderCtrl()->GetItemCount();
							//iRowCount = m_list.GetItemCount();

		sSql = " CREATE TABLE DSO_DX ( ";
		strInsert = " INSERT INTO DSO_DX ( ";
		//����б�������
		lvCol.mask = LVCF_TEXT; //�������ã�˵��LVCOLUMN������pszText������Ч
		lvCol.cchTextMax = 399; //���裬pszText������ָ����ַ����Ĵ�С
		lvCol.pszText = strColName.GetBuffer(399); //���裬pszText ��ָ����ַ�����ʵ�ʴ洢λ�á�
												   //���������������ú����ͨ�� GetColumn()��������б��������
		int i = 0;
		if (ls.size() > 0)
		{
			strInsert = strInsert + "ID" + " , ";
			strInsert = strInsert + "��������" + " , ";
			strInsert = strInsert + "��ʼ��ʽ" + " , ";
			strInsert = strInsert + "������ʽ" + " , ";
			strInsert = strInsert + "�ӱ�1" + " , ";
			strInsert = strInsert + "�ӱ�2" + " , ";
			strInsert = strInsert + "�ӱ�3" + " , ";
			strInsert = strInsert + "�ӱ�4" + " , ";
			strInsert = strInsert + "�ӱ�5" + " , ";
			strInsert = strInsert + "�ӱ�6" + " , ";
			strInsert = strInsert + "�ӱ�7" + " , ";
			strInsert = strInsert + "�ӱ�8" + " , ";
			strInsert = strInsert + "�ӱ�9" + " , ";
			strInsert = strInsert + "�ӱ�10" + " , ";
			//strInsert = strInsert + "�ӱ�11" + " , ";
			strInsert = strInsert + "�ӱ�11" + " )  VALUES ( ";
			sSql = sSql + lvCol.pszText + "ID TEXT , ";
			sSql = sSql + lvCol.pszText + "�������� TEXT , ";
			sSql = sSql + lvCol.pszText + "��ʼ��ʽ TEXT , ";
			sSql = sSql + lvCol.pszText + "������ʽ TEXT , ";
			sSql = sSql + lvCol.pszText + "�ӱ�1 TEXT , ";
			sSql = sSql + lvCol.pszText + "�ӱ�2 TEXT , ";
			sSql = sSql + lvCol.pszText + "�ӱ�3 TEXT , ";
			sSql = sSql + lvCol.pszText + "�ӱ�4 TEXT , ";
			sSql = sSql + lvCol.pszText + "�ӱ�5 TEXT , ";
			sSql = sSql + lvCol.pszText + "�ӱ�6 TEXT , ";
			sSql = sSql + lvCol.pszText + "�ӱ�7 TEXT , ";
			sSql = sSql + lvCol.pszText + "�ӱ�8 TEXT , ";
			sSql = sSql + lvCol.pszText + "�ӱ�9 TEXT , ";
			sSql = sSql + lvCol.pszText + "�ӱ�10 TEXT , ";
			//sSql = sSql + lvCol.pszText + "�ӱ�11 TEXT , ";
			sSql = sSql + lvCol.pszText + "�ӱ�11 TEXT ) ";
			//����Excel����ļ�
			database.ExecuteSQL(sSql);

			sSql = strInsert;
			char chTemp[400];
			string view;
			string viewname;
			string viewstart;
			string viewend;
			string view1;
			string view2;
			string view3;
			string view4;
			string view5;
			string view6;
			string view7;
			string view8;
			string view9;
			string view10;
			string view11;
			//string view12;
			for (list<msg>::iterator it = ls.begin(); it != ls.end(); it++)
			{
				view = (CString)it->id.c_str();
				viewname = (CString)it->name.c_str();
				viewstart = (CString)it->start.c_str();
				viewend = (CString)it->end.c_str();
				view1 = (CString)it->view1.c_str();
				view2 = (CString)it->view2.c_str();
				view3 = (CString)it->view3.c_str();
				view4 = (CString)it->view4.c_str();
				view5 = (CString)it->view5.c_str();
				view6 = (CString)it->view6.c_str();
				view7 = (CString)it->view7.c_str();
				view8 = (CString)it->view8.c_str();
				view9 = (CString)it->view9.c_str();
				view10 = (CString)it->view10.c_str();
				view11 = (CString)it->view11.c_str();
				//view12 = (CString)it->view12.c_str();
				sSql = sSql + "'" + view.data() + "' , ";
				sSql = sSql + "'" + viewname.data() + "' , ";
				sSql = sSql + "'" + viewstart.data() + "' , ";
				sSql = sSql + "'" + viewend.data() + "' , ";
				sSql = sSql + "'" + view1.data() + "' , ";
				sSql = sSql + "'" + view2.data() + "' , ";
				sSql = sSql + "'" + view3.data() + "' , ";
				sSql = sSql + "'" + view4.data() + "' , ";
				sSql = sSql + "'" + view5.data() + "' , ";
				sSql = sSql + "'" + view6.data() + "' , ";
				sSql = sSql + "'" + view7.data() + "' , ";
				sSql = sSql + "'" + view8.data() + "' , ";
				sSql = sSql + "'" + view9.data() + "' , ";
				sSql = sSql + "'" + view10.data() + "' , ";
				//sSql = sSql + "'" + view11.data() + "' , ";
				sSql = sSql + "'" + view11.data() + "' ) ";
				database.ExecuteSQL(sSql);
				sSql = strInsert;
			}
		}


		//ѭ����ȡ��¼�����뵽EXCEL��

	}

	// �ر�Excel����ļ�
	database.Close();

	//AfxMessageBox("�����ѯ���ΪExcel�ļ��ɹ���");
	}
		CATCH_ALL(e)
	{
		//�������ͺܶ࣬������Ҫ���б���
		AfxMessageBox("Excel�ļ�����ʧ�ܡ�");
	}
	END_CATCH_ALL;


}

//д��Ŀ¼
void CInfoFile::WirteMenu()
{
	ofstream ofs("./stock_save/menu.txt");//�����ʽ���ļ�

	if (mls.size() > 0)	//��Ʒ���������ݲ�ִ��
	{
		ofs << "���|��Ʒ����|����|�ļ�·��|EXCEL�ļ�·��" << endl; //д���ͷ

													//ͨ��������ȡ���������ݣ�д���ļ����ԡ�|���ָ�����β�ӻ���
		for (list<menuMsg>::iterator it = mls.begin(); it != mls.end(); it++)
		{
			ofs << it->Mid << "|";
			ofs << it->MCname << "|";
			ofs << it->Mname << "|";
			ofs << it->Roud << "|";
			ofs << it->ExcelRoud << endl;
		}
	}

	ofs.close();//�ر��ļ�
}

//д��浵�ļ�
void CInfoFile::WirteSave(CString name1A[], CString name2A[], CString view1A[])
{
	save.clear();
	for (int i = 0; i < num - 1; i++)
	{
		saveFile tmp;
		tmp.name1 = CT2A(name1A[i].GetBuffer());
		tmp.name2 = CT2A(name2A[i].GetBuffer());
		tmp.view1 = CT2A(view1A[i].GetBuffer());
		save.push_back(tmp);
	}
	ofstream ofs("./stock_save/save.txt");//�����ʽ���ļ�
	if (save.size() > 0)	//���������ݲ�ִ��
	{
		ofs << "�浵��|��Ŀ��|����" << endl; //д���ͷ
									 //ͨ��������ȡ���������ݣ�д���ļ����ԡ�|���ָ�����β�ӻ���
		for (list<saveFile>::iterator it = save.begin(); it != save.end(); it++)
		{
			ofs << it->name1 << "|";
			ofs << it->name2 << "|";
			ofs << it->view1 << endl;
		}
	}
	ofs.close();//�ر��ļ�
}

//д���ļ�
void CInfoFile::WirteDocline(string stock, CString idA[], CString nameA[], CString startA[], CString endA[], CString view1A[], CString view2A[], CString view3A[], CString view4A[], CString view5A[], CString view6A[], CString view7A[], CString view8A[], CString view9A[], CString view10A[], CString view11A[])
{
	//allRoad = stock.c_str();
	ls.clear();
	for (int i = 0; i < num - 1; i++)
	{
		msg tmp;
		tmp.id = CT2A(idA[i].GetBuffer());
		tmp.name = CT2A(nameA[i].GetBuffer());
		tmp.start = CT2A(startA[i].GetBuffer());
		tmp.end = CT2A(endA[i].GetBuffer());
		tmp.view1 = CT2A(view1A[i].GetBuffer());
		tmp.view2 = CT2A(view2A[i].GetBuffer());
		tmp.view3 = CT2A(view3A[i].GetBuffer());
		tmp.view4 = CT2A(view4A[i].GetBuffer());
		tmp.view5 = CT2A(view5A[i].GetBuffer());
		tmp.view6 = CT2A(view6A[i].GetBuffer());
		tmp.view7 = CT2A(view7A[i].GetBuffer());
		tmp.view8 = CT2A(view8A[i].GetBuffer());
		tmp.view9 = CT2A(view9A[i].GetBuffer());
		tmp.view10 = CT2A(view10A[i].GetBuffer());
		tmp.view11 = CT2A(view11A[i].GetBuffer());
		//tmp.view12 = CT2A(view12A[i].GetBuffer());
		ls.push_back(tmp);
	}
	ofstream ofs(stock);//�����ʽ���ļ�
	if (ls.size() > 0)	//���������ݲ�ִ��
	{
		ofs << "ID|��������|��ʼ��ʽ|������ʽ|�ӱ�1|�ӱ�2|�ӱ�3|�ӱ�4|�ӱ�5|�ӱ�6|�ӱ�7|�ӱ�8|�ӱ�9|�ӱ�10|�ӱ�11" << endl; //д���ͷ

																						  //ͨ��������ȡ���������ݣ�д���ļ����ԡ�|���ָ�����β�ӻ���
		for (list<msg>::iterator it = ls.begin(); it != ls.end(); it++)
		{
			ofs << it->id << "|";
			ofs << it->name << "|";
			ofs << it->start << "|";
			ofs << it->end << "|";
			ofs << it->view1 << "|";
			ofs << it->view2 << "|";
			ofs << it->view3 << "|";
			ofs << it->view4 << "|";
			ofs << it->view5 << "|";
			ofs << it->view6 << "|";
			ofs << it->view7 << "|";
			ofs << it->view8 << "|";
			ofs << it->view9 << "|";
			ofs << it->view10 << "|";
			//ofs << it->view11 << "|";
			ofs << it->view11 << endl;
		}
	}
	ofs.close();//�ر��ļ�
}

//������תվ
void CInfoFile::midRoad(string stock, string ExcelStock, string name, int test3)
{
	ofstream ofs("./stock_save/midRoad.txt");
	if (stock == "")
	{
		stock = "./stock_save/stock.xls";
	}
	if (ExcelStock == "")
	{
		stock = "./stock_save/stock.txt";

	}
	ofs << ExcelStock << endl;
	ofs << stock << endl;
	ofs << name << endl;
	ofs << test3 << endl;


	ofs.close(); //�ر��ļ�

}

//ȡ����תվ
void CInfoFile::ReadmidRoad()
{
	ifstream ifs("./stock_save/midRoad.txt");
	char buf[1024] = { 0 };
	//int m_test3;
	num = 0;
	slss.clear();
	//ifs.getline(buf, sizeof(buf));

	sls tmp;
	ifs.getline(buf, sizeof(buf)); //��ȡһ��
	num++;
	tmp.ExcelRoad = buf;	//��������
	ifs.getline(buf, sizeof(buf)); //��ȡһ��
	tmp.road = buf;	//��������
	ifs.getline(buf, sizeof(buf)); //��ȡһ��
	tmp.name = buf;	//����1
	ifs.getline(buf, sizeof(buf)); //��ȡһ��
	tmp.test3 = atoi(buf);	//����1

	slss.push_back(tmp); //��������ĺ���
	ifs.close(); //�ر��ļ�
}

//�������Ŀ
void CInfoFile::Addline(CString name, CString start, CString end)
{
	msg tmp;

	tmp.id = "22";	//id�Զ���1
	CStringA str;
	str = name;	//CStringתCStirngA
	tmp.name = str.GetBuffer(); //CStirngAתchar *����Ʒ����
	tmp.start = start;	//����2
	tmp.end = end;	//����1
	tmp.view1 = "00000000000000000000000000000000000000000";
	tmp.view2 = "0000000000000";
	tmp.view3 = "0000000#0#0#0#0#0#0#0#0#0#0#0#0";
	tmp.view4 = "00000000000000000#0#0#0#0";
	tmp.view5 = "00#0#0";
	tmp.view6 = "0000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000#0#0";
	tmp.view7 = "0000000#0#0#0#0#0#0#0#0#0#0#0#0";
	tmp.view8 = "00000000000000000000000000000000000000000000000000000000000000000";
	tmp.view9 = "0#0#0#0#0";
	tmp.view10 = "00000000000000000#��������#0#��������#0#��������#0#��������#0";
	tmp.view11 = "0#0";
	//tmp.view12 = "0000000000000000#��������#0#��������#0#��������#0#��������#0";
	ls.push_back(tmp);	//��������ĺ���
}

//����´浵
void CInfoFile::AddSave(CString name1, CString name2, CString view1)
{
	saveFile tmp;
	//CStringA str;
	//str = name;	//CStringתCStirngA
	tmp.name1 = name1; //CStirngAתchar *����Ʒ����
	tmp.name2 = name2;	//����2
	tmp.view1 = view1;	//����1

	save.push_back(tmp);	//��������ĺ���
}


//����²�Ʒ�ļ�
void CInfoFile::AddMenu(CString Nuwname, CString newid, CString newroad, CString newexcelroad)
{
	menuMsg tmp;

	tmp.Mid = "22";	//id�Զ���1
	CStringA str;
	str = newid;	//CStringתCStirngA
	tmp.MCname = str.GetBuffer(); //CStirngAתchar *
	tmp.Mname = Nuwname;	//����2
	tmp.Roud = newroad;	//����1
	tmp.ExcelRoud = newexcelroad;	//����1

	mls.push_back(tmp);	//��������ĺ���
}

