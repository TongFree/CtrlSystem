
// ControlSystem.cpp : ����Ӧ�ó��������Ϊ��
//

#include "pch.h"
#include "framework.h"
#include "afxwinappex.h"
#include "afxdialogex.h"
#include "MainFrm.h"
#include "ControlSystem.h"
#include "ControlSystemDoc.h"
#include "ControlSystemView.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#endif


// CControlSystemApp

BEGIN_MESSAGE_MAP(CControlSystemApp, CWinApp)
	ON_COMMAND(ID_APP_ABOUT, &CControlSystemApp::OnAppAbout)
	// ON_COMMAND(ID_FILE_NEW_FRAME, &CControlSystemApp::OnFileNewFrame)

	// �����ļ��ı�׼�ĵ�����
	ON_COMMAND(ID_FILE_NEW, &CWinApp::OnFileNew)
	ON_COMMAND(ID_FILE_OPEN, &CWinApp::OnFileOpen)
	// ��׼��ӡ��������
	ON_COMMAND(ID_FILE_PRINT_SETUP, &CWinApp::OnFilePrintSetup)
END_MESSAGE_MAP()


// CControlSystemApp ����

CControlSystemApp::CControlSystemApp() 
{
	// ֧����������������
//	m_dwRestartManagerSupportFlags = AFX_RESTART_MANAGER_SUPPORT_ALL_ASPECTS;
//#ifdef _MANAGED
//	// ���Ӧ�ó��������ù�����������ʱ֧��(/clr)�����ģ���: 
//	//     1) �����д˸������ã�������������������֧�ֲ�������������
//	//     2) ��������Ŀ�У������밴������˳���� System.Windows.Forms ������á�
//	System::Windows::Forms::Application::SetUnhandledExceptionMode(System::Windows::Forms::UnhandledExceptionMode::ThrowException);
//#endif


	// ֧����������������
	m_dwRestartManagerSupportFlags = AFX_RESTART_MANAGER_SUPPORT_RESTART;
	
	// TODO: ������Ӧ�ó��� ID �ַ����滻ΪΨһ�� ID �ַ�����������ַ�����ʽ
	//Ϊ CompanyName.ProductName.SubProduct.VersionInformation
	SetAppID(_T("ControlSystem.AppID.NoVersion"));

	// TODO: �ڴ˴���ӹ�����룬
	// ��������Ҫ�ĳ�ʼ�������� InitInstance ��
}

// Ψһ��һ�� CControlSystemApp ����

CControlSystemApp theApp;


// CControlSystemApp ��ʼ��

BOOL CControlSystemApp::InitInstance()
{
	// ���һ�������� Windows XP �ϵ�Ӧ�ó����嵥ָ��Ҫ
	// ʹ�� ComCtl32.dll �汾 6 ����߰汾�����ÿ��ӻ���ʽ��
	//����Ҫ InitCommonControlsEx()��  ���򣬽��޷��������ڡ�
	INITCOMMONCONTROLSEX InitCtrls;
	InitCtrls.dwSize = sizeof(InitCtrls);
	// ��������Ϊ��������Ҫ��Ӧ�ó�����ʹ�õ�
	// �����ؼ��ࡣ
	InitCtrls.dwICC = ICC_WIN95_CLASSES;
	InitCommonControlsEx(&InitCtrls);

	//CHomeView dlg;
	//dlg.DoModal();

	CWinApp::InitInstance();


	// ��ʼ�� OLE ��
	if (!AfxOleInit())
	{
		AfxMessageBox(IDP_OLE_INIT_FAILED);
		return FALSE;
	}

	AfxEnableControlContainer();

	EnableTaskbarInteraction(FALSE);

	// ���� shell���������Է��Ի�������κ� shell����ͼ�ռ�� shell�б���ͼ�ؼ�
	CShellManager *pShellManager = new CShellManager;

	// ����"Windows Native" �Ӿ����������Ա��� MFC �ؼ�����������
	CMFCVisualManager::SetDefaultManager(RUNTIME_CLASS(CMFCVisualManagerWindows));

	// ʹ�� RichEdit �ؼ���Ҫ AfxInitRichEdit2()	
	// AfxInitRichEdit2();

	// ��׼��ʼ��
	// ���δʹ����Щ���ܲ�ϣ����С
	// ���տ�ִ���ļ��Ĵ�С����Ӧ�Ƴ�����
	// ����Ҫ���ض���ʼ������
	// �������ڴ洢���õ�ע�����
	// TODO: Ӧ�ʵ��޸ĸ��ַ�����
	// �����޸�Ϊ��˾����֯��
	SetRegistryKey(_T("Ӧ�ó��������ɵı���Ӧ�ó���"));
	LoadStdProfileSettings(0);  // ���ر�׼ INI �ļ�ѡ��(���� MRU)


	// ע��Ӧ�ó�����ĵ�ģ�塣  �ĵ�ģ��
	// �������ĵ�����ܴ��ں���ͼ֮�������
	CSingleDocTemplate* pDocTemplate;
	pDocTemplate = new CSingleDocTemplate(
		IDR_MAINFRAME,
		RUNTIME_CLASS(CControlSystemDoc),
		RUNTIME_CLASS(CMainFrame),       // �� SDI ��ܴ���
		RUNTIME_CLASS(CControlSystemView));// RUNTIME_CLASS(CControlSystemView)
	if (!pDocTemplate)
		return FALSE;
	// m_pDocTemplate = pDocTemplate;
	AddDocTemplate(pDocTemplate);


	// ������׼ shell ���DDE�����ļ�������������
	CCommandLineInfo cmdInfo;
	ParseCommandLine(cmdInfo);



	// ��������������ָ�������  ���
	// �� /RegServer��/Register��/Unregserver �� /Unregister ����Ӧ�ó����򷵻� FALSE��
	if (!ProcessShellCommand(cmdInfo))
		return FALSE;

	// Ψһ��һ�������ѳ�ʼ���������ʾ����������и���
	m_pMainWnd->ShowWindow(SW_SHOW);
	m_pMainWnd->UpdateWindow();
	return TRUE;
}

int CControlSystemApp::ExitInstance()
{
	//TODO: �����������ӵĸ�����Դ
	AfxOleTerm(FALSE);

	return CWinApp::ExitInstance();
}

// CControlSystemApp ��Ϣ�������


// ����Ӧ�ó��򡰹��ڡ��˵���� CAboutDlg �Ի���

class CAboutDlg : public CDialogEx
{
public:
	CAboutDlg() noexcept;

// �Ի�������
#ifdef AFX_DESIGN_TIME
	enum { IDD = IDD_ABOUTBOX };
#endif

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV ֧��

// ʵ��
protected:
	DECLARE_MESSAGE_MAP()
};

CAboutDlg::CAboutDlg() noexcept : CDialogEx(IDD_ABOUTBOX)
{
}

void CAboutDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
}

BEGIN_MESSAGE_MAP(CAboutDlg, CDialogEx)
END_MESSAGE_MAP()

// �������жԻ����Ӧ�ó�������
void CControlSystemApp::OnAppAbout()
{
	CAboutDlg aboutDlg;
	aboutDlg.DoModal();
}

// CControlSystemApp ��Ϣ�������

void CControlSystemApp::OnFileNewFrame() 
{
	ASSERT(m_pDocTemplate != NULL);

	CDocument* pDoc = NULL;
	CFrameWnd* pFrame = NULL;

	// ������ m_pDocTemplate ��Ա���õ��ĵ�
	//����ʵ����
	if (m_pDocTemplate != NULL)
		pDoc = m_pDocTemplate->CreateNewDocument();

	if (pDoc != NULL)
	{
		// �������������������ʹ����������
		// ���ĵ����¿�ܡ�
		pFrame = m_pDocTemplate->CreateNewFrame(pDoc, NULL);
		if (pFrame != NULL)
		{
			// ���ñ��Ⲣ��ʼ�����ĵ���
			// ����ĵ���ʼ��ʧ�ܣ�������
			// �˿�ܴ��ں��ĵ���

			m_pDocTemplate->SetDefaultTitle(pDoc);
			if (!pDoc->OnNewDocument())
			{
				pFrame->DestroyWindow();
				pFrame = NULL;
			}
			else
			{
				// ���򣬽����´˿��
				m_pDocTemplate->InitialUpdateFrame(pFrame, pDoc, TRUE);
			}
		}
	}

	// ���ʧ�ܣ���������ĵ�������
	// �û���ʾ��Ϣ��

	if (pFrame == NULL || pDoc == NULL)
	{
		delete pDoc;
		AfxMessageBox(AFX_IDP_FAILED_TO_CREATE_DOC);
	}
}

void CControlSystemApp::OnFileNew() 
{
	//CDocument* pDoc = NULL;
	//CFrameWnd* pFrame;
	//pFrame = DYNAMIC_DOWNCAST(CFrameWnd, CWnd::GetActiveWindow());
	//
	//if (pFrame != NULL)
	//	pDoc = pFrame->GetActiveDocument();

	//if (pFrame == NULL || pDoc == NULL)
	//{
	//	// ������ǵ�һ���ĵ���������ͨ��ʽ����
	//	CWinApp::OnFileNew();
	//}
	//else
	//{
	//	// ����ȷ���Ƿ���Ҫ�����޸ģ�
	//	// Ȼ��Ҫ���ĵ�����������³�ʼ����
	//	if (!pDoc->SaveModified())
	//		return;

	//	CDocTemplate* pTemplate = pDoc->GetDocTemplate();
	//	ASSERT(pTemplate != NULL);

	//	if (pTemplate != NULL)
	//		pTemplate->SetDefaultTitle(pDoc);
	//	pDoc->OnNewDocument();
	//}
}
