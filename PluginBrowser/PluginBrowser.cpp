// PluginBrowser.cpp : ���� DLL �ĳ�ʼ�����̡�
//

#include "stdafx.h"
#include "PluginBrowser.h"
#include "PluginBrowserDlg.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#endif

//
//TODO: ����� DLL ����� MFC DLL �Ƕ�̬���ӵģ�
//		��Ӵ� DLL �������κε���
//		MFC �ĺ������뽫 AFX_MANAGE_STATE ����ӵ�
//		�ú�������ǰ�档
//
//		����:
//
//		extern "C" BOOL PASCAL EXPORT ExportedFunction()
//		{
//			AFX_MANAGE_STATE(AfxGetStaticModuleState());
//			// �˴�Ϊ��ͨ������
//		}
//
//		�˺������κ� MFC ����
//		������ÿ��������ʮ����Ҫ������ζ��
//		��������Ϊ�����еĵ�һ�����
//		���֣������������ж������������
//		������Ϊ���ǵĹ��캯���������� MFC
//		DLL ���á�
//
//		�й�������ϸ��Ϣ��
//		����� MFC ����˵�� 33 �� 58��
//

// CPluginBrowserApp

BEGIN_MESSAGE_MAP(CPluginBrowserApp, CWinApp)
	ON_COMMAND(ID_PLUGIN_BROWSER, &CPluginBrowserApp::OnPluginBrowser)
END_MESSAGE_MAP()


// CPluginBrowserApp ����

CPluginBrowserApp::CPluginBrowserApp()
{
	// TODO: �ڴ˴���ӹ�����룬
	// ��������Ҫ�ĳ�ʼ�������� InitInstance ��
}


// Ψһ��һ�� CPluginBrowserApp ����

CPluginBrowserApp theApp;


// CPluginBrowserApp ��ʼ��

BOOL CPluginBrowserApp::InitInstance()
{
	CWinApp::InitInstance();

	//��ʼ��RichEdit Control
	AfxInitRichEdit2();

	return TRUE;
}

void CPluginBrowserApp::OnPluginBrowser()
{
	CPluginBrowserDlg dlg;
	dlg.DoModal();
}
