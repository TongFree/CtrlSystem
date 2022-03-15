#include "FileComm.h"



FileComm::FileComm()
{
}


FileComm::~FileComm()
{
}


CString CommGetAppPath()
{
	CString strPath;
	GetModuleFileName(NULL, strPath.GetBufferSetLength(MAX_PATH + 1), MAX_PATH);
	strPath.ReleaseBuffer();
	int pos = strPath.ReverseFind('\\');
	strPath = strPath.Left(pos);
	return strPath;
}

// ����ļ��Ƿ����
BOOL CommIsExistFile(CString strFullPathName)
{
	if (::GetFileAttributes(strFullPathName) == 0xFFFFFFFF)
	{
		return FALSE;
	}
	else
	{
		return TRUE;
	}
}

// ��һ���ַ�����Ϊvector, ��bSplitChar�ָ�.
vector<CString> CommStrSplit(CString str, BYTE bSplitChar)
{
	vector<CString> vecList;

	CString strTemp = str; //�˸�ֵ������
	CString strText = _T("");
	int nIndex = 0; //  
	while (1)
	{
		nIndex = strTemp.Find(bSplitChar);
		if (nIndex >= 0)
		{
			strText = strTemp.Left(nIndex);
			vecList.push_back(strText);
			strTemp = strTemp.Right(strTemp.GetLength() - nIndex - 1);
		}
		else
		{
			//strText = strTemp;
			//vecList.push_back(strText);
			break;
		}
	}

	return vecList;
}
