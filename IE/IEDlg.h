
// IEDlg.h : 头文件
//

#pragma once
#include "explorer1.h"
#include "Mshtml.h"
#include "afxwin.h"
#include "string"

using namespace std;
// CIEDlg 对话框
class CIEDlg : public CDialogEx
{
// 构造
public:
	CIEDlg(CWnd* pParent = NULL);	// 标准构造函数
	void ChangeSize(CWnd * pWnd, int cx, int cy);
	void AdjustControl();

	IHTMLElement*       GetHTMLElement(const CString& strID); //获取网页元素，通过ID  主要用来获得 button 和 text 控件
	IHTMLSelectElement* GetHTMLSelectElement(const CString& strID); //获取select 控件 元素
	IDispatch*          GetHTMLElemCollDispatch(const CString& strID);  //获取收集所有网页元素的Dispatch

	void SetWebEditText(const CString& strID, const CString& strText);
	void OnWebClick(const CString& strID);
	void OnWebSelect(const CString& strID, long lIndex);
	void OnWebRadio(const CString& strID);

	CRect m_rect;
	int fir_loding;
	bool sen_loding;
	long width;
	long height;

// 对话框数据
	enum { IDD = IDD_IE_DIALOG };

	protected:
	virtual void DoDataExchange(CDataExchange* pDX);	// DDX/DDV 支持
private:
	string m_url;
	string m_index;

// 实现
protected:
	HICON m_hIcon;

	// 生成的消息映射函数
	virtual BOOL OnInitDialog();
	afx_msg void OnPaint();
	afx_msg HCURSOR OnQueryDragIcon();
	DECLARE_MESSAGE_MAP()
public:
	CExplorer1 m_ie;
	DECLARE_EVENTSINK_MAP()
	void DocumentCompleteExplorer1(LPDISPATCH pDisp, VARIANT* URL);
	CExplorer1 m_ie_player;
	afx_msg void OnSize(UINT nType, int cx, int cy);
	afx_msg BOOL OnCopyData(CWnd* pWnd, COPYDATASTRUCT* pCopyDataStruct);
};
