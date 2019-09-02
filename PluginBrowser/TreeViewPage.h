#pragma once
#include "afxcmn.h"


// CTreeViewPage �Ի���

struct PluginPair
{
	int nIndex;
	CString strName;
};

class CTreeViewPage : public CDialogEx
{
	DECLARE_DYNAMIC(CTreeViewPage)

public:
	CTreeViewPage(CWnd* pParent = NULL);   // ��׼���캯��
	virtual ~CTreeViewPage();

public:
	void DisplayPluginInfo(const PluginInfoArray& array);

private:
	HTREEITEM SearchChildItem(CString strChildName);

	int GetItemIndex(HTREEITEM hItem);

private:
	// root item
	HTREEITEM m_hRootMenu;

	CArray<PluginPair, PluginPair> m_PairArray;

public:
// �Ի�������
	enum { IDD = IDD_TREE_VIEW_PAGE };

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV ֧��

	DECLARE_MESSAGE_MAP()
public:
	CTreeCtrl m_ctrlPluginTree;
	virtual BOOL OnInitDialog();
	afx_msg void OnTvnSelchangedPluginTree(NMHDR* pNMHDR, LRESULT* pResult);
	virtual void OnOK();
	virtual void OnCancel();
};
