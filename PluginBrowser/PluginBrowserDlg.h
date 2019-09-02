#pragma once

#include "afxcmn.h"
#include "ListViewPage.h"
#include "TreeViewPage.h"

// CPluginBrowserDlg �Ի���

typedef CPlugin* (*GETINSTANCE)();

class CPluginBrowserDlg : public CDialogEx
{
	DECLARE_DYNAMIC(CPluginBrowserDlg)

public:
	CPluginBrowserDlg(CWnd* pParent = NULL);   // ��׼���캯��
	virtual ~CPluginBrowserDlg();

public:
	// display plugin's number
	void DisplayPluginNum();

	// display plugin info in RichEdit
	void PrintPluginInfo(int nIndex = 0);

private:
	// search plugin
	void SearchPlugin();

	CString GetApplicationPath();

	// load dll
	void LoadDLL(CString strFileName);

private:
	// �洢�����Ϣ��ָ������
	PluginInfoArray m_PluginInfoArray;

	// �洢���ҵ��İ����ı��༭����������ı��Ĳ����Ϣ��ָ������
	PluginInfoArray m_FindArray;

	// current active array
	PluginInfoArray* m_pActiveArray;

public:
// �Ի�������
	enum { IDD = IDD_PLUGIN_BROWSER_DLG };

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV ֧��

	DECLARE_MESSAGE_MAP()
public:
	virtual BOOL OnInitDialog();
	CTabCtrl m_TabCtrl;
	CListViewPage m_PageList;
	CTreeViewPage m_PageTree;
	afx_msg void OnTcnSelchangeTab1(NMHDR* pNMHDR, LRESULT* pResult);
	afx_msg void OnEnChangeSearchEdit();
	afx_msg void OnBnClickedClear();
};
