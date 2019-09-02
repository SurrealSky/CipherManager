#pragma once
#include "afxcmn.h"


// CListViewPage �Ի���

class CListViewPage : public CDialogEx
{
	DECLARE_DYNAMIC(CListViewPage)

public:
	CListViewPage(CWnd* pParent = NULL);   // ��׼���캯��
	virtual ~CListViewPage();

public:
	void DisplayPluginInfo(const PluginInfoArray& array);

public:
// �Ի�������
	enum { IDD = IDD_LIST_VIEW_PAGE };

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV ֧��

	DECLARE_MESSAGE_MAP()
public:
	CListCtrl m_ctrlPluginList;
	virtual BOOL OnInitDialog();
	afx_msg void OnNMClickPluginList(NMHDR* pNMHDR, LRESULT* pResult);
	virtual void OnOK();
	virtual void OnCancel();
};
