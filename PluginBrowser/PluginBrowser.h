// PluginBrowser.h : PluginBrowser DLL ����ͷ�ļ�
//

#pragma once

#ifndef __AFXWIN_H__
	#error "�ڰ������ļ�֮ǰ������stdafx.h�������� PCH �ļ�"
#endif

#include "resource.h"		// ������


// CPluginBrowserApp
// �йش���ʵ�ֵ���Ϣ������� PluginBrowser.cpp
//

class CPluginBrowserApp : public CWinApp
{
public:
	CPluginBrowserApp();

// ��д
public:
	virtual BOOL InitInstance();

	DECLARE_MESSAGE_MAP()
	afx_msg void OnPluginBrowser();
};
