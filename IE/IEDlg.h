
// IEDlg.h : ͷ�ļ�
//

#pragma once
#include "explorer1.h"
#include "Mshtml.h"
#include "afxwin.h"
#include "string"

using namespace std;
// CIEDlg �Ի���
class CIEDlg : public CDialogEx
{
// ����
public:
	CIEDlg(CWnd* pParent = NULL);	// ��׼���캯��
	void ChangeSize(CWnd * pWnd, int cx, int cy);
	void AdjustControl();

	IHTMLElement*       GetHTMLElement(const CString& strID); //��ȡ��ҳԪ�أ�ͨ��ID  ��Ҫ������� button �� text �ؼ�
	IHTMLSelectElement* GetHTMLSelectElement(const CString& strID); //��ȡselect �ؼ� Ԫ��
	IDispatch*          GetHTMLElemCollDispatch(const CString& strID);  //��ȡ�ռ�������ҳԪ�ص�Dispatch

	void SetWebEditText(const CString& strID, const CString& strText);
	void OnWebClick(const CString& strID);
	void OnWebSelect(const CString& strID, long lIndex);
	void OnWebRadio(const CString& strID);

	CRect m_rect;
	int fir_loding;
	bool sen_loding;
	long width;
	long height;

// �Ի�������
	enum { IDD = IDD_IE_DIALOG };

	protected:
	virtual void DoDataExchange(CDataExchange* pDX);	// DDX/DDV ֧��
private:
	string m_url;
	string m_index;

// ʵ��
protected:
	HICON m_hIcon;

	// ���ɵ���Ϣӳ�亯��
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
