// BacnetWeb.cpp : ʵ���ļ�
//

#include "stdafx.h"
#include "T3000.h"
#include "BacnetWeb.h"
#include "afxdialogex.h"


// CBacnetWeb �Ի���

IMPLEMENT_DYNAMIC(CBacnetWeb, CDialogEx)

CBacnetWeb::CBacnetWeb(CWnd* pParent /*=NULL*/)
	: CDialogEx(IDD_DIALOG_WEB, pParent)
{

}

CBacnetWeb::~CBacnetWeb()
{
}

void CBacnetWeb::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
}


BEGIN_MESSAGE_MAP(CBacnetWeb, CDialogEx)
END_MESSAGE_MAP()


// CBacnetWeb ��Ϣ�������


BOOL CBacnetWeb::OnInitDialog()
{
    CDialogEx::OnInitDialog();

    // TODO:  �ڴ���Ӷ���ĳ�ʼ��

    CRect rectClient;
    GetClientRect(&rectClient);
    if (!m_browser.Create(NULL, NULL, WS_VISIBLE, rectClient, this, 101))
    {
        return 0;
    }

    // Initialize the first URL.
    COleVariant noArg;
    //
    //CString strURL("file:///Z:/Temp/1.png");
    CString strURL("https://temcocontrols.com/");
    m_browser.Navigate(strURL, &noArg, &noArg, &noArg, &noArg);


    return TRUE;  // return TRUE unless you set the focus to a control
                  // �쳣: OCX ����ҳӦ���� FALSE
}
