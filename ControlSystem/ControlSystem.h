
// ControlSystem.h : ControlSystem Ӧ�ó������ͷ�ļ�
//
#pragma once

#ifndef __AFXWIN_H__
	#error "�ڰ������ļ�֮ǰ���� 'pch.h' ������ PCH"
#endif

#include "resource.h"       // ������


// CControlSystemApp:
// �йش����ʵ�֣������ ControlSystem.cpp
//

class CControlSystemApp : public CWinApp
{
public:
	CControlSystemApp();

protected:
	CMultiDocTemplate* m_pDocTemplate;
public:

// ��д
public:
	virtual BOOL InitInstance();
	virtual int ExitInstance();

// ʵ��
	afx_msg void OnAppAbout();
	afx_msg void OnFileNewFrame();
	afx_msg void OnFileNew();
	DECLARE_MESSAGE_MAP()

//	CView* m_pFirstView;
//	CView* m_pAnotherView;

};

extern CControlSystemApp theApp;
