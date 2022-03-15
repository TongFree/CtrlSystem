#pragma once
#include "afxcmn.h"
#include "FrameWork.h"

class FileComm
{
public:
	FileComm();
	~FileComm();
};

// GetAppPath
CString CommGetAppPath();
// IsExistFile
BOOL CommIsExistFile(CString strFullPathName);

vector<CString> CommStrSplit(CString str, BYTE bSplitChar);