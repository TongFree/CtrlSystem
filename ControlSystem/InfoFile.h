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
	string name;	//测试名称
	string start;			//开始
	string end;			//结束
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

	//读取产品型号
	void ReadLogin(CString& name, CString& pwd);

	//修改产品型号
	void WritePwd(char* name, char* pwd);

	//读取文件数据
	void ReadDocline(string stock);

	//夹具文件读取
	//void ReadJiaju();

	//中转站
	void midRoad(string stock, string ExcelStock, string name, int test3);
	//取出路径
	void ReadmidRoad();
	//读取目录
	void ReadMenu();
	//读取存档文件
	void saveMenu();
	//写入存档文件
	void WirteSave(CString name1A[], CString name2A[], CString view1A[]);
	//写入文件
	void WirteDocline(string stock, CString idA[], CString nameA[], CString startA[], CString endA[], CString view1A[], CString view2A[], CString view3A[], CString view4A[], CString view5A[], CString view6A[], CString view7A[], CString view8A[], CString view9A[], CString view10A[], CString view11A[]);


	//子项写入文件
	void WirteChild(string stock);
	//新增存档文件
	void WirteSaveChild();
	//写入目录
	void WirteMenu();
	//添加新测试项
	void Addline(CString name, CString start, CString end);
	//添加新存档
	void AddSave(CString name1, CString name2, CString view1);
	//添加新目录文件
	void AddMenu(CString mewname, CString newid, CString newroad, CString newexcelroad);

	void ReadExcel();


	list<msg> ls;	//存储容器
	list<menuMsg> mls;	//存储容器
	int num;			//用来记录个数
	int m_num;
	//CString allRoad;
	list<sls> slss;
	list<saveFile> save;

};