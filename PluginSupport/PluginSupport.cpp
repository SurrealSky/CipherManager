// PluginSupport.cpp : ���� DLL �ĳ�ʼ�����̡�
//

#include "stdafx.h"
#include "PluginSupport.h"
#include "PluginWrapper.h"

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

// CPluginSupportApp

BEGIN_MESSAGE_MAP(CPluginSupportApp, CWinApp)
END_MESSAGE_MAP()


// CPluginSupportApp ����

CPluginSupportApp::CPluginSupportApp()
{
	// TODO: �ڴ˴���ӹ�����룬
	// ��������Ҫ�ĳ�ʼ�������� InitInstance ��
}


// Ψһ��һ�� CPluginSupportApp ����

CPluginSupportApp theApp;


// CPluginSupportApp ��ʼ��

BOOL CPluginSupportApp::InitInstance()
{
	CWinApp::InitInstance();

	return TRUE;
}

int CPluginSupportApp::ExitInstance()
{
	for (int i=0; i<m_PluginArray.GetSize(); i++)
	{
		CPluginWrapper* pPluginWrapper = m_PluginArray.GetAt(i);
		pPluginWrapper->ReleasePlugin();
		delete pPluginWrapper;
	}
	m_PluginArray.RemoveAll();

	m_pMainApp = NULL;

	return CWinApp::ExitInstance();
}

// record main app
void CPluginSupportApp::SetMainApp(CWinApp* pApp)
{
	m_pMainApp = pApp;
}

// return main app
CWinApp* CPluginSupportApp::GetMainApp() const
{
	return m_pMainApp;
}

// load plugin
void CPluginSupportApp::LoadPlugin(CWinApp* pApp)
{
	CString strPath = GetApplicationPath();
	strPath += _T("plugins\\");
	strPath += _T("*.dll");
	OutputDebugString(L"���·��:");
	OutputDebugString(strPath);
	CFileFind find;
	BOOL bIsFind = find.FindFile(strPath);
	while (bIsFind)
	{
		bIsFind = find.FindNextFile();

		if (find.IsDots())
			continue;
		else if (find.IsDirectory())
			continue;
		else
		{
			CString strFileName = find.GetFileName();
			CString strFile = strPath;
			strFile.Replace(_T("*.dll"), strFileName);
			OutputDebugString(L"�ҵ����:");
			OutputDebugString(strFile);
			CPluginWrapper* pPluginWrapper = new CPluginWrapper();
			BOOL bReslut = pPluginWrapper->LoadDLL(strFile);
			if (bReslut)
			{
				m_PluginArray.Add(pPluginWrapper);
				OutputDebugString(L"���سɹ�");
			}
			else
			{
				delete pPluginWrapper;
				OutputDebugString(L"����ʧ��");
			}
		}
	}

	// initialization plugin
	for (int i=0; i<m_PluginArray.GetSize(); i++)
	{
		m_PluginArray.GetAt(i)->InitPlugin(pApp, i);
		m_PluginArray.GetAt(i)->QueryPlugin();
	}
}

// return plugin array
const PluginArray& CPluginSupportApp::GetPluginArray() const
{
	return m_PluginArray;
}

// return plugin message map
MessageMap& CPluginSupportApp::GetPluginMessageMap()
{
	return m_MessageMap;
}

CString CPluginSupportApp::GetApplicationPath()
{
	TCHAR filename[_MAX_PATH];
	TCHAR drive[_MAX_DRIVE];
	TCHAR path[_MAX_PATH];

	GetModuleFileName(AfxGetInstanceHandle(), filename, MAX_PATH);
	_wsplitpath_s(filename, drive, _MAX_DRIVE, path, _MAX_PATH, NULL, 0, NULL, 0);

	CString strLocation(drive);
	strLocation += path;

	return strLocation;
}