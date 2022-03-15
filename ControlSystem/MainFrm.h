
// MainFrm.h : CMainFrame 类的接口
//

#pragma once
// 状态位
#define NM_A	(WM_USER + 100)
#define NM_B	(WM_USER + 101)
#define NM_C	(WM_USER + 102)
#define NM_D	(WM_USER + 103)

#define NM_C_ONE (WM_USER + 104)
#define NM_C_TWO (WM_USER + 105)
#define NM_C_THREE (WM_USER + 106)
#define NM_C_FOUR (WM_USER + 107)
#define NM_C_FIVE (WM_USER + 108)
#define NM_C_SIX (WM_USER + 109)
#define NM_C_SEVEN (WM_USER + 110)
#define NM_C_EIGHT (WM_USER + 111)
#define NM_C_NINE (WM_USER + 112)
#define NM_C_TEN  (WM_USER + 113)
#define NM_C_ELEVEN (WM_USER + 114)

#define NM_TV	(WM_USER + 115)

#define NM_USERLOGIN (WM_USER + 116)
#define NM_XIUGAI (WM_USER + 117)
#define NM_NEW (WM_USER + 118)
#define NM_DISPLAY (WM_USER + 119)

#define NM_LEFTVIEW (WM_USER + 120)
#define NM_TESTVIEW (WM_USER + 121)



class CMainFrame : public CFrameWnd
{
	
protected: // 仅从序列化创建
	CMainFrame();
	DECLARE_DYNCREATE(CMainFrame)

// 特性
public:

// 操作
public:

// 重写
public:
	virtual BOOL PreCreateWindow(CREATESTRUCT& cs);

// 实现
public:
	virtual ~CMainFrame();
#ifdef _DEBUG
	virtual void AssertValid() const;
	virtual void Dump(CDumpContext& dc) const;
#endif

protected:  // 控件条嵌入成员
	CToolBar          m_wndToolBar;
	CStatusBar        m_wndStatusBar;

// 生成的消息映射函数
protected:
	afx_msg int OnCreate(LPCREATESTRUCT lpCreateStruct);
	DECLARE_MESSAGE_MAP()

private:
	//CSplitterWnd m_spliter; // 切分窗口用对象
	CFrameWnd m_wnd;
	afx_msg LRESULT OnMyChange(WPARAM wParam, LPARAM lParam);

public:
	afx_msg void Onsize(UINT nType, int cx, int cy);
	afx_msg void resize();
	POINT Old;
};
