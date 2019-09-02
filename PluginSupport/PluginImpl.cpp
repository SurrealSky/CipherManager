
#include "stdafx.h"
#include "PluginImpl.h"
#include "PluginSupport.h"
#include "PluginWrapper.h"

PLUGIN_EXPORT void PIInitPlugin(CWinApp* pApp)
{
#ifdef _AFXDLL
	AFX_MANAGE_STATE(AfxGetStaticModuleState());
#endif

	CPluginSupportApp* pThisApp = (CPluginSupportApp*)AfxGetApp();
	// load plugin
	pThisApp->SetMainApp(pApp);
	pThisApp->LoadPlugin(pApp);
}

// register plugin document templates
PLUGIN_EXPORT void PIRegisterDocTemplates()
{
#ifdef _AFXDLL
	AFX_MANAGE_STATE(AfxGetStaticModuleState());
#endif

	CPluginSupportApp* pApp = (CPluginSupportApp*)AfxGetApp();
	CWinApp* pMainApp = pApp->GetMainApp();

	const PluginArray& array = pApp->GetPluginArray();
	for (int i=0; i<array.GetSize(); i++)
	{
		CPluginWrapper* pPluginWrapper = array.GetAt(i);
		for (int j = 0; j < pPluginWrapper->GetDocTemplateCount(); j++)
		{
			CDocTemplate* pDocTemplate = pPluginWrapper->GetDocTemplate(j);
			// plugin said it had one, but didn't supply it
			ASSERT(pDocTemplate);
			pMainApp->AddDocTemplate(pDocTemplate);
		}
	}
}

PLUGIN_EXPORT void PICommand(UINT nCommandID, CCmdUI* pCmdUI)
{
#ifdef _AFXDLL
	AFX_MANAGE_STATE(AfxGetStaticModuleState());
#endif

	CPluginSupportApp* pApp = (CPluginSupportApp*)AfxGetApp();
	const PluginArray& array = pApp->GetPluginArray();
	for (int i=0; i<array.GetSize(); i++)
	{
		CPluginWrapper* pPluginWrapper = array.GetAt(i);
		UINT nFirstVirtualID = pPluginWrapper->GetFirstVirtualID();
		UINT nPluginCommandCount = pPluginWrapper->GetCommandCount();
		if (nCommandID >= nFirstVirtualID && nCommandID < nFirstVirtualID + nPluginCommandCount)
		{
			// calculate actual plugin id
			pPluginWrapper->ExecutePlugin(nCommandID, pCmdUI);
			return;
		}
	}

	TRACE(_T("Plugin: message CommandID = %d is not processed\n"), nCommandID);
}

PLUGIN_EXPORT int PIAddNewCommand(int nPluginIndex, UINT nActualID)
{
#ifdef _AFXDLL
	AFX_MANAGE_STATE(AfxGetStaticModuleState());
#endif

	CPluginSupportApp* pApp = (CPluginSupportApp*)AfxGetApp();
	CPluginWrapper* pPluginWrapper = pApp->GetPluginArray().GetAt(nPluginIndex);
	ASSERT(pPluginWrapper != NULL);

	// add new command
	return pPluginWrapper->AddCommand(nActualID);
}

PLUGIN_EXPORT void PIGetCommandString(UINT nCommandID, CString& str)
{
#ifdef _AFXDLL
	AFX_MANAGE_STATE(AfxGetStaticModuleState());
#endif

	CPluginSupportApp* pApp = (CPluginSupportApp*)AfxGetApp();
	const PluginArray& array = pApp->GetPluginArray();
	for (int i=0; i<array.GetSize(); i++)
	{
		CPluginWrapper* pPluginWrapper = array.GetAt(i);
		UINT nFirstVirtualID = pPluginWrapper->GetFirstVirtualID();
		UINT nPluginCommandCount = pPluginWrapper->GetCommandCount();
		if (nCommandID >= nFirstVirtualID && nCommandID < nFirstVirtualID + nPluginCommandCount)
		{
			pPluginWrapper->GetCommandString(nCommandID, str);
		}
	}
}

PLUGIN_EXPORT void PIDraw(CDC* pDC)
{
#ifdef _AFXDLL
	AFX_MANAGE_STATE(AfxGetStaticModuleState());
#endif

	CPluginSupportApp* pApp = (CPluginSupportApp*)AfxGetApp();
	const PluginArray& array = pApp->GetPluginArray();
	for (int i=0; i<array.GetSize(); i++)
	{
		CPluginWrapper* pPluginWrapper = array.GetAt(i);
		pPluginWrapper->Draw(pDC);
	}
}

PLUGIN_EXPORT BOOL PIHandleMessage(MSG* pMsg, CWnd* pSender)
{
#ifdef _AFXDLL
	AFX_MANAGE_STATE(AfxGetStaticModuleState());
#endif

	CPluginSupportApp* pApp = (CPluginSupportApp*)AfxGetApp();
	MessageMap& messageMap = pApp->GetPluginMessageMap();

	MESSAGEPROC pFNMessageProc = NULL;
	BOOL bReslut = messageMap.Lookup(pMsg->message, pFNMessageProc);
	if (bReslut)
	{
		ASSERT(pFNMessageProc != NULL);
		return BOOL(pFNMessageProc(pMsg));
	}
	else
	{
		return FALSE;
	}
}