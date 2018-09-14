
// IEDlg.cpp : ʵ���ļ�
//

#include "stdafx.h"
#include "IE.h"
#include "IEDlg.h"
#include "afxdialogex.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#endif


// CIEDlg �Ի���



CIEDlg::CIEDlg(CWnd* pParent /*=NULL*/)
	: CDialogEx(CIEDlg::IDD, pParent)
{
	m_hIcon = AfxGetApp()->LoadIcon(IDR_MAINFRAME);
	
	m_index = "http://127.0.0.1:8080";
//	m_url = "http://www.baidu.com";
	m_url = "https://ie.icoa.cn/";
	if ((__argv[0] != NULL) && (__argv[1] != NULL))
	{
		m_url = __argv[0];
		m_index = __argv[1];
	}
	
	
	
	fir_loding = 0;
	sen_loding = false;
}


void CIEDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
	DDX_Control(pDX, IDC_EXPLORER1, m_ie);
	DDX_Control(pDX, IDC_EXPLORER_PLAYER, m_ie_player);
}

BEGIN_MESSAGE_MAP(CIEDlg, CDialogEx)
	ON_WM_PAINT()
	ON_WM_QUERYDRAGICON()
	ON_WM_SIZE()
	ON_WM_COPYDATA()
END_MESSAGE_MAP()


// CIEDlg ��Ϣ�������

BOOL CIEDlg::OnInitDialog()
{
	CDialogEx::OnInitDialog();

	// ���ô˶Ի����ͼ�ꡣ  ��Ӧ�ó��������ڲ��ǶԻ���ʱ����ܽ��Զ�
	//  ִ�д˲���
	SetIcon(m_hIcon, TRUE);			// ���ô�ͼ��
	SetIcon(m_hIcon, FALSE);		// ����Сͼ��

//	ShowWindow(SW_MAXIMIZE);

	// TODO:  �ڴ���Ӷ���ĳ�ʼ������
	ModifyStyleEx(WS_EX_APPWINDOW, WS_EX_TOOLWINDOW);
	SetWindowText(_T("SOARSOFTPlayer"));
//	AfxMessageBox("in1");
	GetClientRect(&m_rect);
	CWnd *pWnd;
	pWnd = GetDlgItem(IDC_EXPLORER_PLAYER);
	pWnd->MoveWindow(m_rect);
	int cx = GetSystemMetrics(SM_CXSCREEN);
	int cy = GetSystemMetrics(SM_CYSCREEN);
	CWnd::SetWindowPos(&wndTop, cx * 0.23, cy * 0.3, cx * 0.75, cy * 0.68, SWP_SHOWWINDOW);
//	CWnd::SetWindowPos(&wndTop, NULL, NULL, NULL, NULL, SWP_SHOWWINDOW);
	CWnd::ShowWindow(SW_MAXIMIZE);
	COleVariant vaUrl = _T(m_index.c_str());
//	MessageBox(m_index.c_str());//localhost
//	MessageBox(m_url.c_str());//smg
	m_ie.put_Silent(true);
	m_ie_player.put_Silent(true);
//	::ShowWindow(m_ie.GetSafeHwnd(), SW_HIDE);
//	AfxMessageBox(m_index.c_str());
	m_ie.Navigate2(vaUrl, NULL, NULL, NULL, NULL);
	
//	AfxMessageBox("in3");
	//	out <<"��½��֤��"<<m_index.c_str() << endl;
	return TRUE;  // ���ǽ��������õ��ؼ������򷵻� TRUE
}

// �����Ի��������С����ť������Ҫ����Ĵ���
//  �����Ƹ�ͼ�ꡣ  ����ʹ���ĵ�/��ͼģ�͵� MFC Ӧ�ó���
//  �⽫�ɿ���Զ���ɡ�

void CIEDlg::OnPaint()
{
	if (IsIconic())
	{
		CPaintDC dc(this); // ���ڻ��Ƶ��豸������

		SendMessage(WM_ICONERASEBKGND, reinterpret_cast<WPARAM>(dc.GetSafeHdc()), 0);

		// ʹͼ���ڹ����������о���
		int cxIcon = GetSystemMetrics(SM_CXICON);
		int cyIcon = GetSystemMetrics(SM_CYICON);
		CRect rect;
		GetClientRect(&rect);
		int x = (rect.Width() - cxIcon + 1) / 2;
		int y = (rect.Height() - cyIcon + 1) / 2;

		// ����ͼ��
		dc.DrawIcon(x, y, m_hIcon);
	}
	else
	{
		CDialogEx::OnPaint();
	}
}

//���û��϶���С������ʱϵͳ���ô˺���ȡ�ù��
//��ʾ��
HCURSOR CIEDlg::OnQueryDragIcon()
{
	return static_cast<HCURSOR>(m_hIcon);
}

BEGIN_EVENTSINK_MAP(CIEDlg, CDialogEx)
	ON_EVENT(CIEDlg, IDC_EXPLORER1, 259, CIEDlg::DocumentCompleteExplorer1, VTS_DISPATCH VTS_PVARIANT)
END_EVENTSINK_MAP()

//#include "fstream"
void CIEDlg::DocumentCompleteExplorer1(LPDISPATCH pDisp, VARIANT* URL)
{
	// TODO:  �ڴ˴������Ϣ����������
	
//	ofstream out;
//	out.open("out.txt", ios::app | ios::out);
	
	if (fir_loding == 0)
	{
		CString id = _T("account");
		CString text = _T("3dzhuanyong");
		SetWebEditText(id, text);
		id = _T("password");
		text = _T("3d111");
		SetWebEditText(id, text);

		CString ra_id = _T("manager");
		OnWebRadio(ra_id);
		CString login = _T("loginForSystem");
		OnWebClick(login);
//				out << "fir_loding" << endl;
	}
		//����Զ���½��
		//VARIANT vt;
		if (fir_loding == 1)
		{
			//Sleep(5000);
			COleVariant vaUrl = _T(m_url.c_str());
			//		MessageBox(_T(m_url.c_str()));
//					out << "sen_loding" <<" "<<m_url.c_str() << endl;
			SetActiveWindow();
			m_ie_player.Navigate2(vaUrl, NULL, NULL, NULL, NULL);
			sen_loding = true;
		}
		fir_loding ++;
//		out.close();
}
//#include "fstream"
BOOL CIEDlg::OnCopyData(CWnd* pWnd, COPYDATASTRUCT* pCopyDataStruct)//�Ѵ򿪶Ի�������µ���ת
{
	CString strRecievedText = (LPCSTR)(pCopyDataStruct->lpData);
//	ofstream out;
//	out.open("out.txt", ios::app | ios::out);
//	string *rmsg = (string *)l;
	//if (rmsg->c_str() != NULL)
	//	MessageBox("NOT NULL");
	COleVariant vaUrl = strRecievedText;
//	out << strRecievedText << endl;
//	out.close();
	SetForegroundWindow();
	m_ie_player.Navigate2(vaUrl, NULL, NULL, NULL, NULL);
	return 0;
}


void CIEDlg::OnSize(UINT nType, int cx, int cy)
{
	CDialogEx::OnSize(nType, cx, cy);

	// TODO:  �ڴ˴������Ϣ����������
	if (nType == 1) return; //��С����ʲô������ 
	CWnd *pWnd;
	pWnd = GetDlgItem(IDC_EXPLORER_PLAYER);
	if (pWnd)
	{
		CRect rect;
		GetClientRect(&rect);
		//	ScreenToClient(&rect);

		//rect.left = rect.left*cx / m_rect.Width();//�����ؼ���С
		//rect.right = rect.right*cx / m_rect.Width();
		//rect.top = rect.top*cy / m_rect.Height();
		//rect.bottom = rect.bottom*cy / m_rect.Height();
		pWnd->MoveWindow(rect);//���ÿؼ���С
	}
	GetClientRect(&m_rect);
}


IDispatch* CIEDlg::GetHTMLElemCollDispatch(const CString& strID)
{
	HRESULT hr = S_OK;
	IDispatch* pDispath = NULL;
	IHTMLElement* pElem = NULL;

	pDispath = m_ie.get_Document();         //m_web��CExplorer Ҳ����webbrowser�ؼ�

	if (pDispath == NULL)
	{
		TRACE(L"pDispath = m_web.get_Document() = NULL");
	}

	IHTMLDocument2* pDoc = NULL;
	hr = pDispath->QueryInterface(IID_IHTMLDocument2, (void**)&pDoc);
	pDispath->Release();
	pDispath = NULL;

	if (pDoc == NULL || hr != S_OK)
	{
		TRACE(L"IHTMLDocument2 pDoc  NULL or hr != S_OK");
		return NULL;
	}

	IHTMLElementCollection* pColl = NULL;
	hr = pDoc->get_all(&pColl);
	pDoc->Release();
	pDoc = NULL;

	ASSERT(pColl != NULL);
	if (pColl == NULL || hr != S_OK)
	{
		TRACE(L"IHTMLElementCollection pColl = NULL or hr != S_OK");
		return NULL;
	}

	IDispatch* pDispath2 = NULL;

	VARIANT index = { 0 };
	V_VT(&index) = VT_I4;
	V_I4(&index) = 0;

	VARIANT varID = { 0 };
	VariantInit(&varID);
	varID.vt = VT_BSTR;

	varID.bstrVal = strID.AllocSysString();

	hr = pColl->item(varID, index, &pDispath2);
	pColl->Release();
	pColl = NULL;

	if (hr != S_OK)
	{
		TRACE(L"");
		pDispath2 = NULL;
	}

	return pDispath2;
}

IHTMLElement* CIEDlg::GetHTMLElement(const CString& strID)
{
	HRESULT hr = S_OK;
	IDispatch* pDispath = NULL;
	IHTMLElement* pElem = NULL;

	pDispath = GetHTMLElemCollDispatch(strID);

	if (pDispath != NULL)
	{
		hr = pDispath->QueryInterface(IID_IHTMLElement, (void**)&pElem); // ��ѯ��IID_IHTMLElement�Ľӿڣ�������ӿڷ��أ���������ִ��click ��������������

		if (hr != S_OK)
		{
			pElem = NULL;
		}
		pDispath->Release();

	}
	return pElem;
}

IHTMLSelectElement* CIEDlg::GetHTMLSelectElement(const CString& strID)
{
	HRESULT hr = S_OK;
	IDispatch* pDispath = NULL;
	IHTMLSelectElement* pSelectElem = NULL;

	pDispath = GetHTMLElemCollDispatch(strID);

	if (pDispath != NULL)
	{
		hr = pDispath->QueryInterface(IID_IHTMLSelectElement, (void**)&pSelectElem);
		if (hr != S_OK)
		{
			pSelectElem = NULL;
		}
		pDispath->Release();
	}

	return pSelectElem;
}


void CIEDlg::SetWebEditText(const CString& strID, const CString& strText)
{
	HRESULT hr = S_OK;
	IHTMLElement* pElem = NULL;
	pElem = GetHTMLElement(strID);
	if (pElem != NULL)
	{
		BSTR s = ::SysAllocString(L"value");
		VARIANT varValue;
		varValue.vt = VT_BSTR;
		varValue.bstrVal = (_bstr_t)strText;
		hr = pElem->setAttribute(s, varValue);
		//	hr = pElem->put_innerText(strText.AllocSysString());
		pElem->Release();
	}
	pElem = NULL;
}

void CIEDlg::OnWebClick(const CString& strID)
{
	HRESULT hr = S_OK;
	IHTMLElement* pElem = NULL;
	pElem = GetHTMLElement(strID);
	if (pElem != NULL)
	{
		hr = pElem->click();
		pElem->Release();
	}
	pElem = NULL;
}

void CIEDlg::OnWebSelect(const CString& strID, long lIndex)
{
	HRESULT hr = S_OK;
	IHTMLSelectElement* pSelectElem = NULL;
	pSelectElem = GetHTMLSelectElement(strID);
	if (pSelectElem != NULL)
	{
		hr = pSelectElem->put_selectedIndex(lIndex);
		pSelectElem->Release();
	}
	pSelectElem = NULL;
}

void CIEDlg::OnWebRadio(const CString& strID)
{
	HRESULT hr = S_OK;
	IHTMLElement* pElem = NULL;
	pElem = GetHTMLElement(strID);
	if (pElem != NULL)
	{
		hr = pElem->click();
		pElem->Release();
	}
	pElem = NULL;
}