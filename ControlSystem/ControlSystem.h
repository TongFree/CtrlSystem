
// ControlSystem.h : ControlSystem 应用程序的主头文件
//
#pragma once

#ifndef __AFXWIN_H__
	#error "在包含此文件之前包含 'pch.h' 以生成 PCH"
#endif

#include "resource.h"       // 主符号


// CControlSystemApp:
// 有关此类的实现，请参阅 ControlSystem.cpp
//

class CControlSystemApp : public CWinApp
{
public:
	CControlSystemApp();

protected:
	CMultiDocTemplate* m_pDocTemplate;
public:

// 重写
public:
	virtual BOOL InitInstance();
	virtual int ExitInstance();

// 实现
	afx_msg void OnAppAbout();
	afx_msg void OnFileNewFrame();
	afx_msg void OnFileNew();
	DECLARE_MESSAGE_MAP()

//	CView* m_pFirstView;
//	CView* m_pAnotherView;

};

extern CControlSystemApp theApp;
