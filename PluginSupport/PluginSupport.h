// PluginSupport.h : PluginSupport DLL ����ͷ�ļ�
//

#pragma once

#ifndef __AFXWIN_H__
	#error "�ڰ������ļ�֮ǰ������stdafx.h�������� PCH �ļ�"
#endif

#include "resource.h"		// ������


// CPluginSupportApp
// �йش���ʵ�ֵ���Ϣ������� PluginSupport.cpp
//

class CPluginWrapper;

typedef CArray<CPluginWrapper*, CPluginWrapper*> PluginArray;
typedef LRESULT (__cdecl* MESSAGEPROC)(MSG* pMsg);
typedef CMap<UINT, UINT, MESSAGEPROC, MESSAGEPROC> MessageMap;

class CPluginSupportApp : public CWinApp
{
public:
	CPluginSupportApp();

public:
	// record main app
	void SetMainApp(CWinApp* pApp);

	// return main app
	CWinApp* GetMainApp() const;

	// load plugin
	void LoadPlugin(CWinApp* pApp);

	// return plugin array
	const PluginArray& GetPluginArray() const;

	// return plugin message map
	MessageMap& GetPluginMessageMap();

private:
	CString GetApplicationPath();

private:
	// main app point
	CWinApp* m_pMainApp;

	// plugin array
	PluginArray m_PluginArray;

	// plugin message map
	MessageMap m_MessageMap;

// ��д
public:
	virtual BOOL InitInstance();
	virtual int ExitInstance();

	DECLARE_MESSAGE_MAP()
};
