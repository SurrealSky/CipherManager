#pragma once

#include "PluginDefine.h"

// CPIView ��ͼ

class PLUGIN_EXT_CLASS CPIView : public CScrollView
{
	DECLARE_DYNCREATE(CPIView)

protected:
	CPIView();           // ��̬������ʹ�õ��ܱ����Ĺ��캯��
	virtual ~CPIView();

public:
#ifdef _DEBUG
	virtual void AssertValid() const;
#ifndef _WIN32_WCE
	virtual void Dump(CDumpContext& dc) const;
#endif
#endif

protected:
	virtual void OnDraw(CDC* pDC);      // ��д�Ի��Ƹ���ͼ
	virtual void OnInitialUpdate();     // �����ĵ�һ��
	virtual BOOL PreTranslateMessage(MSG* pMsg);

	DECLARE_MESSAGE_MAP()
public:
	LRESULT OnPrepareDCEvent(WPARAM wParam, LPARAM lParam);
};


