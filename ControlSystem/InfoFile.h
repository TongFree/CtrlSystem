#pragma once
#include <list>
#include <iostream>
#include <string>
#include <fstream>

#define _F_LOGIN "./login.ini"
#define _F_MENU "./stock_save/menu.txt"
#define _F_STOCK1 "./stock_save/stock.txt"
#define _F_STOCK2 "./stock_save/stock2.txt"
#define _F_STOCK3 "./stock_save/stock3.txt"
#define _F_STOCK4 "./stock_save/stock4.txt"

using namespace std;

struct menuMsg
{
	string Mid;
	string MCname;
	string Mname;
	string Roud;
	string ExcelRoud;
};

//string allRoad1;
struct sls
{
	string road;
	string ExcelRoad;
	string name;
	int test3;
};


struct msg
{
	string id;				//id
	string name;	//��������
	string start;			//��ʼ
	string end;			//����
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
};

struct saveFile
{
	string name1;
	string name2;
	string view1;
};

class CInfoFile
{
public:
	CInfoFile();
	~CInfoFile();

	//��ȡ��Ʒ�ͺ�
	void ReadLogin(CString& name, CString& pwd);

	//�޸Ĳ�Ʒ�ͺ�
	void WritePwd(char* name, char* pwd);

	//��ȡ�ļ�����
	void ReadDocline(string stock);

	//�о��ļ���ȡ
	//void ReadJiaju();

	//��תվ
	void midRoad(string stock, string ExcelStock, string name, int test3);
	//ȡ��·��
	void ReadmidRoad();
	//��ȡĿ¼
	void ReadMenu();
	//��ȡ�浵�ļ�
	void saveMenu();
	//д��浵�ļ�
	void WirteSave(CString name1A[], CString name2A[], CString view1A[]);
	//д���ļ�
	void WirteDocline(string stock, CString idA[], CString nameA[], CString startA[], CString endA[], CString view1A[], CString view2A[], CString view3A[], CString view4A[], CString view5A[], CString view6A[], CString view7A[], CString view8A[], CString view9A[], CString view10A[], CString view11A[]);


	//����д���ļ�
	void WirteChild(string stock);
	//�����浵�ļ�
	void WirteSaveChild();
	//д��Ŀ¼
	void WirteMenu();
	//����²�����
	void Addline(CString name, CString start, CString end);
	//����´浵
	void AddSave(CString name1, CString name2, CString view1);
	//�����Ŀ¼�ļ�
	void AddMenu(CString mewname, CString newid, CString newroad, CString newexcelroad);

	void ReadExcel();


	list<msg> ls;	//�洢����
	list<menuMsg> mls;	//�洢����
	int num;			//������¼����
	int m_num;
	//CString allRoad;
	list<sls> slss;
	list<saveFile> save;

};