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

//读取产品型号文件
void CInfoFile::ReadLogin(CString& name, CString& pwd)
{
	ifstream ifs; //创建文件输入对象
	ifs.open(_F_LOGIN); //打开文件

	char buf[1024] = { 0 };

	ifs.getline(buf, sizeof(buf)); //读取一行内容
	name = CString(buf);			 //char *转换为CString

	ifs.getline(buf, sizeof(buf));
	pwd = CString(buf);

	ifs.close(); //关闭文件
}

//修改型号信息
void CInfoFile::WritePwd(char* name, char* pwd)
{
	ofstream ofs;	 //创建文件输出对象
	ofs.open(_F_LOGIN); //打开文件

	ofs << name << endl; //name写入文件
	ofs << pwd << endl;	//pwd写入文件

	ofs.close();	//关闭文件
}

//读取列表信息
void CInfoFile::ReadDocline(string stock)
{
	/*
	CString file;
	ifstream ifs(stock); //输入方式打开文件

	char buf[2048] = { 0 };
	num = 0;	//初始化数据为0
	ls.clear();
	//取出表头
	ifs.getline(buf, sizeof(buf));

	while (!ifs.eof()) //没到文件结尾
	{
	msg tmp;

	ifs.getline(buf, sizeof(buf)); //读取一行
	num++;	//数目加一

	//AfxMessageBox(CString(buf));
	char* sst = strtok(buf, "|"); //以“|”切割
	if (sst != NULL)
	{
	tmp.id = sst; //id
	}
	else
	{
	break;
	}

	sst = strtok(NULL, "|");
	tmp.name = sst;	//测试名称

	sst = strtok(NULL, "|");
	tmp.start = sst;	//开始

	sst = strtok(NULL, "|");
	tmp.end = sst;	//结束

	sst = strtok(NULL, "|");
	tmp.view1 = sst;	//表1

	sst = strtok(NULL, "|");
	tmp.view2 = sst;	//表2

	sst = strtok(NULL, "|");
	tmp.view3 = sst;	//表3

	sst = strtok(NULL, "|");
	tmp.view4 = sst;	//表4

	sst = strtok(NULL, "|");
	tmp.view5 = sst;	//表5

	sst = strtok(NULL, "|");
	tmp.view6 = sst;	//表6

	sst = strtok(NULL, "|");
	tmp.view7 = sst;	//表7

	sst = strtok(NULL, "|");
	tmp.view8 = sst;	//表8

	sst = strtok(NULL, "|");
	tmp.view9 = sst;	//表9

	sst = strtok(NULL, "|");
	tmp.view10 = sst;	//表10

	sst = strtok(NULL, "|");
	tmp.view11 = sst;	//表11

	ls.push_back(tmp); //放在链表的后面
	}

	ifs.close(); //关闭文件
	*/
	/*
	CFileDialog dlg(TRUE, //TRUE或FALSE。TRUE为打开文件；FALSE为保存文件
	"xls", //为缺省的扩展名
	"FileList", //为显示在文件名组合框的编辑框的文件名，一般可选NULL
	OFN_HIDEREADONLY | OFN_OVERWRITEPROMPT,//为对话框风格，一般为OFN_HIDEREADONLY   |   OFN_OVERWRITEPROMPT,即隐藏只读选项和覆盖已有文件前提示。
	"Excel 文件(*.xls)|*.xls||"//为下拉列表枢中显示文件类型
	);
	dlg.m_ofn.lpstrTitle = "导入数据";
	*/
	//if (dlg.DoModal() != IDOK)
	//return;
	//CString strFilePath;
	//获得文件路径名
	//strFilePath = stock;
	//判断文件是否已经存在，存在则打开文件
	ls.clear();
	DWORD dwRe = GetFileAttributes(stock.c_str());
	if (dwRe != (DWORD)-1)
	{
		//ShellExecute(NULL, NULL, strFilePath, NULL, NULL, SW_RESTORE);
	}
	else return;

	CDatabase db;//数据库库需要包含头文件 #include <afxdb.h>
	CString sDriver = "MICROSOFT EXCEL DRIVER (*.XLS)"; // Excel驱动
	CString sSql, arr[16];

	sSql.Format("DRIVER={%s};DSN='';FIRSTROWHASNAMES=1;READONLY=FALSE;CREATE_DB=\"%s\";DBQ=%s", sDriver, stock.c_str(), stock.c_str());
	if (!db.OpenEx(sSql, CDatabase::noOdbcDialog))//连接数据源DJB．xls
	{
		//MessageBox("打开EXCEL文件失败!", "错误");
		return;
	}
	//打开EXCEL表
	CRecordset pset(&db);
	//m_list.DeleteAllItems();

	//AfxMessageBox("OK");
	/* sSql = "SELECT 学号,姓名,成绩 "
	"FROM EXCELDEMO";      */
	// "ORDER BY 姓名";
	sSql.Format("SELECT ID,测试名称,开始方式,结束方式,子表1,子表2,子表3,子表4,子表5,子表6,子表7,子表8,子表9,子表10,子表11 FROM DSO_DX");
	pset.Open(CRecordset::forwardOnly, sSql, CRecordset::readOnly);
	while (!pset.IsEOF())
	{


		msg tmp;
		num++;
		
		pset.GetFieldValue("ID", arr[0]);//前面字段必须与表中的相同，否则出错。
		pset.GetFieldValue("测试名称", arr[1]);
		pset.GetFieldValue("开始方式", arr[2]);
		pset.GetFieldValue("结束方式", arr[3]);
		pset.GetFieldValue("子表1", arr[4]);
		pset.GetFieldValue("子表2", arr[5]);
		pset.GetFieldValue("子表3", arr[6]);
		pset.GetFieldValue("子表4", arr[7]);
		pset.GetFieldValue("子表5", arr[8]);
		pset.GetFieldValue("子表6", arr[9]);
		pset.GetFieldValue("子表7", arr[10]);
		pset.GetFieldValue("子表8", arr[11]);
		pset.GetFieldValue("子表9", arr[12]);
		pset.GetFieldValue("子表10", arr[13]);
		pset.GetFieldValue("子表11", arr[14]);
		//pset.GetFieldValue("子表12", arr[15]);
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
		//int count = m_list.GetItemCount();//插入到ListCtrl中
		//m_list.InsertItem(count, arr[0]);
		//m_list.SetItemText(count, 1, arr[1]);
		//m_list.SetItemText(count, 2, arr[2]);
		ls.push_back(tmp);
		pset.MoveNext();
	}
	db.Close();

	//MessageBox("Excel数据成功导入系统!", "导入成功");
}

//读取目录文件
void CInfoFile::ReadMenu()
{
	CString file;
	file = _F_MENU;
	ifstream ifs(file); //输入方式打开文件

	char buf[1024] = { 0 };
	num = 0;	//初始化数据为0
	mls.clear();
	//取出表头
	ifs.getline(buf, sizeof(buf));

	while (!ifs.eof()) //没到文件结尾
	{
		menuMsg tmp;

		ifs.getline(buf, sizeof(buf)); //读取一行
		num++;	//数目加一

				//AfxMessageBox(CString(buf));
		char* sst = strtok(buf, "|"); //以“|”切割
		if (sst != NULL)
		{
			tmp.Mid = sst; //id
		}
		else
		{
			break;
		}

		sst = strtok(NULL, "|");
		tmp.MCname = sst;	//测试名称

		sst = strtok(NULL, "|");
		tmp.Mname = sst;	//数据1

		sst = strtok(NULL, "|");
		tmp.Roud = sst;	//数据2

		sst = strtok(NULL, "|");
		tmp.ExcelRoud = sst;	//数据3

		mls.push_back(tmp); //放在链表的后面
	}

	ifs.close(); //关闭文件
}

//读取存档文件
void CInfoFile::saveMenu()
{
	//"./stock_save/save.txt"
	ifstream ifs("./stock_save/save.txt"); //输入方式打开文件

	char buf[1024] = { 0 };
	num = 0;	//初始化数据为0
	save.clear();
	//取出表头
	ifs.getline(buf, sizeof(buf));

	while (!ifs.eof()) //没到文件结尾
	{
		saveFile tmp;

		ifs.getline(buf, sizeof(buf)); //读取一行
		num++;	//数目加一

				//AfxMessageBox(CString(buf));
		char* sst = strtok(buf, "|"); //以“|”切割
		if (sst != NULL)
		{
			tmp.name1 = sst; //id
		}
		else
		{
			break;
		}

		sst = strtok(NULL, "|");
		tmp.name2 = sst;	//测试名称

		sst = strtok(NULL, "|");
		tmp.view1 = sst;	//数据1

		save.push_back(tmp); //放在链表的后面
	}

	ifs.close(); //关闭文件
}

void CInfoFile::WirteSaveChild()
{
	ofstream ofs("./stock_save/save.txt");//输出方式打开文件
	if (save.size() > 0)	//商品链表有内容才执行
	{
		ofs << "存档名|项目名|数据" << endl; //写入表头

									 //通过迭代器取出链表内容，写入文件，以“|”分隔，结尾加换行
		for (list<saveFile>::iterator it = save.begin(); it != save.end(); it++)
		{
			ofs << it->name1 << "|";
			ofs << it->name2 << "|";
			ofs << it->view1 << endl;
		}
	}

	ofs.close();//关闭文件
}

void CInfoFile::WirteChild(string stock)
{
	/*
	ofstream ofs(stock);//输出方式打开文件

	if (ls.size() > 0)	//商品链表有内容才执行
	{
	ofs << "ID|测试名称|开始方式|结束方式|子表1|子表2|子表3|子表4|子表5|子表6|子表7|子表8|子表9|子表10|子表11" << endl; //写入表头

	//通过迭代器取出链表内容，写入文件，以“|”分隔，结尾加换行
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

	ofs.close();//关闭文件

	*/

	//打开另存为对话框 ，需要包含 #include <Afxdlgs.h>

	CString strFilePath;
	//获得文件路径名
	strFilePath = stock.c_str();
	//判断文件是否已经存在，存在则删除重建
	DWORD dwRe = GetFileAttributes(strFilePath);
	if (dwRe != (DWORD)-1)
	{
		DeleteFile(strFilePath);
	}

	CDatabase database;//数据库库需要包含头文件 #include <afxdb.h>
	CString sDriver = "MICROSOFT EXCEL DRIVER (*.XLS)"; // Excel驱动
	CString sSql, strInsert;
	TRY
	{
		// 创建进行存取的字符串
		sSql.Format("DRIVER={%s};DSN='';FIRSTROWHASNAMES=1;READONLY=FALSE;CREATE_DB=\"%s\";DBQ=%s",sDriver, strFilePath, strFilePath);

	// 创建数据库 (既Excel表格文件)
	if (database.OpenEx(sSql,CDatabase::noOdbcDialog))
	{
		//获得列别框总列数
		//int iColumnNum,iRowCount;
		LVCOLUMN lvCol;
		CString strColName; //用于保存列标题名称
							//int i,j; //列、行循环参数

							//iColumnNum = m_list.GetHeaderCtrl()->GetItemCount();
							//iRowCount = m_list.GetItemCount();

		sSql = " CREATE TABLE DSO_DX ( ";
		strInsert = " INSERT INTO DSO_DX ( ";
		//获得列标题名称
		lvCol.mask = LVCF_TEXT; //必需设置，说明LVCOLUMN变量中pszText参数有效
		lvCol.cchTextMax = 399; //必设，pszText参数所指向的字符串的大小
		lvCol.pszText = strColName.GetBuffer(399); //必设，pszText 所指向的字符串的实际存储位置。
												   //以上三个参数设置后才能通过 GetColumn()函数获得列标题的名称
		int i = 0;
		if (ls.size() > 0)
		{
			strInsert = strInsert + "ID" + " , ";
			strInsert = strInsert + "测试名称" + " , ";
			strInsert = strInsert + "开始方式" + " , ";
			strInsert = strInsert + "结束方式" + " , ";
			strInsert = strInsert + "子表1" + " , ";
			strInsert = strInsert + "子表2" + " , ";
			strInsert = strInsert + "子表3" + " , ";
			strInsert = strInsert + "子表4" + " , ";
			strInsert = strInsert + "子表5" + " , ";
			strInsert = strInsert + "子表6" + " , ";
			strInsert = strInsert + "子表7" + " , ";
			strInsert = strInsert + "子表8" + " , ";
			strInsert = strInsert + "子表9" + " , ";
			strInsert = strInsert + "子表10" + " , ";
			//strInsert = strInsert + "子表11" + " , ";
			strInsert = strInsert + "子表11" + " )  VALUES ( ";
			sSql = sSql + lvCol.pszText + "ID TEXT , ";
			sSql = sSql + lvCol.pszText + "测试名称 TEXT , ";
			sSql = sSql + lvCol.pszText + "开始方式 TEXT , ";
			sSql = sSql + lvCol.pszText + "结束方式 TEXT , ";
			sSql = sSql + lvCol.pszText + "子表1 TEXT , ";
			sSql = sSql + lvCol.pszText + "子表2 TEXT , ";
			sSql = sSql + lvCol.pszText + "子表3 TEXT , ";
			sSql = sSql + lvCol.pszText + "子表4 TEXT , ";
			sSql = sSql + lvCol.pszText + "子表5 TEXT , ";
			sSql = sSql + lvCol.pszText + "子表6 TEXT , ";
			sSql = sSql + lvCol.pszText + "子表7 TEXT , ";
			sSql = sSql + lvCol.pszText + "子表8 TEXT , ";
			sSql = sSql + lvCol.pszText + "子表9 TEXT , ";
			sSql = sSql + lvCol.pszText + "子表10 TEXT , ";
			//sSql = sSql + lvCol.pszText + "子表11 TEXT , ";
			sSql = sSql + lvCol.pszText + "子表11 TEXT ) ";
			//创建Excel表格文件
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


		//循环提取记录并插入到EXCEL中

	}

	// 关闭Excel表格文件
	database.Close();

	//AfxMessageBox("保存查询结果为Excel文件成功！");
	}
		CATCH_ALL(e)
	{
		//错误类型很多，根据需要进行报错。
		AfxMessageBox("Excel文件保存失败。");
	}
	END_CATCH_ALL;


}

//写入目录
void CInfoFile::WirteMenu()
{
	ofstream ofs("./stock_save/menu.txt");//输出方式打开文件

	if (mls.size() > 0)	//商品链表有内容才执行
	{
		ofs << "编号|产品件号|名称|文件路径|EXCEL文件路径" << endl; //写入表头

													//通过迭代器取出链表内容，写入文件，以“|”分隔，结尾加换行
		for (list<menuMsg>::iterator it = mls.begin(); it != mls.end(); it++)
		{
			ofs << it->Mid << "|";
			ofs << it->MCname << "|";
			ofs << it->Mname << "|";
			ofs << it->Roud << "|";
			ofs << it->ExcelRoud << endl;
		}
	}

	ofs.close();//关闭文件
}

//写入存档文件
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
	ofstream ofs("./stock_save/save.txt");//输出方式打开文件
	if (save.size() > 0)	//链表有内容才执行
	{
		ofs << "存档名|项目名|数据" << endl; //写入表头
									 //通过迭代器取出链表内容，写入文件，以“|”分隔，结尾加换行
		for (list<saveFile>::iterator it = save.begin(); it != save.end(); it++)
		{
			ofs << it->name1 << "|";
			ofs << it->name2 << "|";
			ofs << it->view1 << endl;
		}
	}
	ofs.close();//关闭文件
}

//写入文件
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
	ofstream ofs(stock);//输出方式打开文件
	if (ls.size() > 0)	//链表有内容才执行
	{
		ofs << "ID|测试名称|开始方式|结束方式|子表1|子表2|子表3|子表4|子表5|子表6|子表7|子表8|子表9|子表10|子表11" << endl; //写入表头

																						  //通过迭代器取出链表内容，写入文件，以“|”分隔，结尾加换行
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
	ofs.close();//关闭文件
}

//存入中转站
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


	ofs.close(); //关闭文件

}

//取出中转站
void CInfoFile::ReadmidRoad()
{
	ifstream ifs("./stock_save/midRoad.txt");
	char buf[1024] = { 0 };
	//int m_test3;
	num = 0;
	slss.clear();
	//ifs.getline(buf, sizeof(buf));

	sls tmp;
	ifs.getline(buf, sizeof(buf)); //读取一行
	num++;
	tmp.ExcelRoad = buf;	//测试名称
	ifs.getline(buf, sizeof(buf)); //读取一行
	tmp.road = buf;	//测试名称
	ifs.getline(buf, sizeof(buf)); //读取一行
	tmp.name = buf;	//数据1
	ifs.getline(buf, sizeof(buf)); //读取一行
	tmp.test3 = atoi(buf);	//数据1

	slss.push_back(tmp); //放在链表的后面
	ifs.close(); //关闭文件
}

//添加新项目
void CInfoFile::Addline(CString name, CString start, CString end)
{
	msg tmp;

	tmp.id = "22";	//id自动加1
	CStringA str;
	str = name;	//CString转CStirngA
	tmp.name = str.GetBuffer(); //CStirngA转char *，商品名称
	tmp.start = start;	//数据2
	tmp.end = end;	//数据1
	tmp.view1 = "00000000000000000000000000000000000000000";
	tmp.view2 = "0000000000000";
	tmp.view3 = "0000000#0#0#0#0#0#0#0#0#0#0#0#0";
	tmp.view4 = "00000000000000000#0#0#0#0";
	tmp.view5 = "00#0#0";
	tmp.view6 = "0000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000#0#0";
	tmp.view7 = "0000000#0#0#0#0#0#0#0#0#0#0#0#0";
	tmp.view8 = "00000000000000000000000000000000000000000000000000000000000000000";
	tmp.view9 = "0#0#0#0#0";
	tmp.view10 = "00000000000000000#输入名称#0#输入名称#0#输入名称#0#输入名称#0";
	tmp.view11 = "0#0";
	//tmp.view12 = "0000000000000000#输入名称#0#输入名称#0#输入名称#0#输入名称#0";
	ls.push_back(tmp);	//放在链表的后面
}

//添加新存档
void CInfoFile::AddSave(CString name1, CString name2, CString view1)
{
	saveFile tmp;
	//CStringA str;
	//str = name;	//CString转CStirngA
	tmp.name1 = name1; //CStirngA转char *，商品名称
	tmp.name2 = name2;	//数据2
	tmp.view1 = view1;	//数据1

	save.push_back(tmp);	//放在链表的后面
}


//添加新产品文件
void CInfoFile::AddMenu(CString Nuwname, CString newid, CString newroad, CString newexcelroad)
{
	menuMsg tmp;

	tmp.Mid = "22";	//id自动加1
	CStringA str;
	str = newid;	//CString转CStirngA
	tmp.MCname = str.GetBuffer(); //CStirngA转char *
	tmp.Mname = Nuwname;	//数据2
	tmp.Roud = newroad;	//数据1
	tmp.ExcelRoud = newexcelroad;	//数据1

	mls.push_back(tmp);	//放在链表的后面
}

