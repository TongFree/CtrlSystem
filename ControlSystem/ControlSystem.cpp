
// ControlSystem.cpp : 定义应用程序的类行为。
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

	// 基于文件的标准文档命令
	ON_COMMAND(ID_FILE_NEW, &CWinApp::OnFileNew)
	ON_COMMAND(ID_FILE_OPEN, &CWinApp::OnFileOpen)
	// 标准打印设置命令
	ON_COMMAND(ID_FILE_PRINT_SETUP, &CWinApp::OnFilePrintSetup)
END_MESSAGE_MAP()


// CControlSystemApp 构造

CControlSystemApp::CControlSystemApp() 
{
	// 支持重新启动管理器
//	m_dwRestartManagerSupportFlags = AFX_RESTART_MANAGER_SUPPORT_ALL_ASPECTS;
//#ifdef _MANAGED
//	// 如果应用程序是利用公共语言运行时支持(/clr)构建的，则: 
//	//     1) 必须有此附加设置，“重新启动管理器”支持才能正常工作。
//	//     2) 在您的项目中，您必须按照生成顺序向 System.Windows.Forms 添加引用。
//	System::Windows::Forms::Application::SetUnhandledExceptionMode(System::Windows::Forms::UnhandledExceptionMode::ThrowException);
//#endif


	// 支持重新启动管理器
	m_dwRestartManagerSupportFlags = AFX_RESTART_MANAGER_SUPPORT_RESTART;
	
	// TODO: 将以下应用程序 ID 字符串替换为唯一的 ID 字符串；建议的字符串格式
	//为 CompanyName.ProductName.SubProduct.VersionInformation
	SetAppID(_T("ControlSystem.AppID.NoVersion"));

	// TODO: 在此处添加构造代码，
	// 将所有重要的初始化放置在 InitInstance 中
}

// 唯一的一个 CControlSystemApp 对象

CControlSystemApp theApp;


// CControlSystemApp 初始化

BOOL CControlSystemApp::InitInstance()
{
	// 如果一个运行在 Windows XP 上的应用程序清单指定要
	// 使用 ComCtl32.dll 版本 6 或更高版本来启用可视化方式，
	//则需要 InitCommonControlsEx()。  否则，将无法创建窗口。
	INITCOMMONCONTROLSEX InitCtrls;
	InitCtrls.dwSize = sizeof(InitCtrls);
	// 将它设置为包括所有要在应用程序中使用的
	// 公共控件类。
	InitCtrls.dwICC = ICC_WIN95_CLASSES;
	InitCommonControlsEx(&InitCtrls);

	//CHomeView dlg;
	//dlg.DoModal();

	CWinApp::InitInstance();


	// 初始化 OLE 库
	if (!AfxOleInit())
	{
		AfxMessageBox(IDP_OLE_INIT_FAILED);
		return FALSE;
	}

	AfxEnableControlContainer();

	EnableTaskbarInteraction(FALSE);

	// 创建 shell管理器，以防对话框包含任何 shell树视图空间或， shell列表视图控件
	CShellManager *pShellManager = new CShellManager;

	// 激活"Windows Native" 视觉管理器，以便在 MFC 控件中启用主题
	CMFCVisualManager::SetDefaultManager(RUNTIME_CLASS(CMFCVisualManagerWindows));

	// 使用 RichEdit 控件需要 AfxInitRichEdit2()	
	// AfxInitRichEdit2();

	// 标准初始化
	// 如果未使用这些功能并希望减小
	// 最终可执行文件的大小，则应移除下列
	// 不需要的特定初始化例程
	// 更改用于存储设置的注册表项
	// TODO: 应适当修改该字符串，
	// 例如修改为公司或组织名
	SetRegistryKey(_T("应用程序向导生成的本地应用程序"));
	LoadStdProfileSettings(0);  // 加载标准 INI 文件选项(包括 MRU)


	// 注册应用程序的文档模板。  文档模板
	// 将用作文档、框架窗口和视图之间的连接
	CSingleDocTemplate* pDocTemplate;
	pDocTemplate = new CSingleDocTemplate(
		IDR_MAINFRAME,
		RUNTIME_CLASS(CControlSystemDoc),
		RUNTIME_CLASS(CMainFrame),       // 主 SDI 框架窗口
		RUNTIME_CLASS(CControlSystemView));// RUNTIME_CLASS(CControlSystemView)
	if (!pDocTemplate)
		return FALSE;
	// m_pDocTemplate = pDocTemplate;
	AddDocTemplate(pDocTemplate);


	// 分析标准 shell 命令、DDE、打开文件操作的命令行
	CCommandLineInfo cmdInfo;
	ParseCommandLine(cmdInfo);



	// 调度在命令行中指定的命令。  如果
	// 用 /RegServer、/Register、/Unregserver 或 /Unregister 启动应用程序，则返回 FALSE。
	if (!ProcessShellCommand(cmdInfo))
		return FALSE;

	// 唯一的一个窗口已初始化，因此显示它并对其进行更新
	m_pMainWnd->ShowWindow(SW_SHOW);
	m_pMainWnd->UpdateWindow();
	return TRUE;
}

int CControlSystemApp::ExitInstance()
{
	//TODO: 处理可能已添加的附加资源
	AfxOleTerm(FALSE);

	return CWinApp::ExitInstance();
}

// CControlSystemApp 消息处理程序


// 用于应用程序“关于”菜单项的 CAboutDlg 对话框

class CAboutDlg : public CDialogEx
{
public:
	CAboutDlg() noexcept;

// 对话框数据
#ifdef AFX_DESIGN_TIME
	enum { IDD = IDD_ABOUTBOX };
#endif

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV 支持

// 实现
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

// 用于运行对话框的应用程序命令
void CControlSystemApp::OnAppAbout()
{
	CAboutDlg aboutDlg;
	aboutDlg.DoModal();
}

// CControlSystemApp 消息处理程序

void CControlSystemApp::OnFileNewFrame() 
{
	ASSERT(m_pDocTemplate != NULL);

	CDocument* pDoc = NULL;
	CFrameWnd* pFrame = NULL;

	// 创建由 m_pDocTemplate 成员引用的文档
	//的新实例。
	if (m_pDocTemplate != NULL)
		pDoc = m_pDocTemplate->CreateNewDocument();

	if (pDoc != NULL)
	{
		// 如果创建操作正常，则使用它来创建
		// 该文档的新框架。
		pFrame = m_pDocTemplate->CreateNewFrame(pDoc, NULL);
		if (pFrame != NULL)
		{
			// 设置标题并初始化该文档。
			// 如果文档初始化失败，则清理
			// 此框架窗口和文档。

			m_pDocTemplate->SetDefaultTitle(pDoc);
			if (!pDoc->OnNewDocument())
			{
				pFrame->DestroyWindow();
				pFrame = NULL;
			}
			else
			{
				// 否则，将更新此框架
				m_pDocTemplate->InitialUpdateFrame(pFrame, pDoc, TRUE);
			}
		}
	}

	// 如果失败，则清理该文档，并向
	// 用户显示消息。

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
	//	// 如果这是第一个文档，则以普通方式创建
	//	CWinApp::OnFileNew();
	//}
	//else
	//{
	//	// 否则，确定是否需要保存修改，
	//	// 然后要求文档自身进行重新初始化。
	//	if (!pDoc->SaveModified())
	//		return;

	//	CDocTemplate* pTemplate = pDoc->GetDocTemplate();
	//	ASSERT(pTemplate != NULL);

	//	if (pTemplate != NULL)
	//		pTemplate->SetDefaultTitle(pDoc);
	//	pDoc->OnNewDocument();
	//}
}
