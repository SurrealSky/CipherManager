// PIView.cpp : ʵ���ļ�
//

#include "stdafx.h"
#include "PIView.h"
#include "PluginImpl.h"

// CPIView

IMPLEMENT_DYNCREATE(CPIView, CScrollView)

CPIView::CPIView()
{

}

CPIView::~CPIView()
{

}

BEGIN_MESSAGE_MAP(CPIView, CScrollView)
	ON_MESSAGE(WM_PREPARE_DC_EVENT, &CPIView::OnPrepareDCEvent)
END_MESSAGE_MAP()

// CPIView ��ͼ

void CPIView::OnInitialUpdate()
{
	CScrollView::OnInitialUpdate();

	CSize sizeTotal;
	// TODO: �������ͼ�ĺϼƴ�С
	sizeTotal.cx = sizeTotal.cy = 300;
	SetScrollSizes(MM_TEXT, sizeTotal);
}

void CPIView::OnDraw(CDC* pDC)
{
	CDocument* pDoc = GetDocument();
	// TODO: �ڴ���ӻ��ƴ���
	PIDraw(pDC);
}

// CPIView ���

#ifdef _DEBUG
void CPIView::AssertValid() const
{
	CScrollView::AssertValid();
}

#ifndef _WIN32_WCE
void CPIView::Dump(CDumpContext& dc) const
{
	CScrollView::Dump(dc);
}
#endif
#endif //_DEBUG

// CPIView ��Ϣ�������

BOOL CPIView::PreTranslateMessage(MSG* pMsg)
{
	// TODO: �ڴ����ר�ô����/����û���
	BOOL bResult = PIHandleMessage(pMsg, this);
	if (bResult)
	{
		return TRUE;
	}
	else
	{
		return CScrollView::PreTranslateMessage(pMsg);
	}
}

LRESULT CPIView::OnPrepareDCEvent(WPARAM wParam, LPARAM lParam)
{
	CDC* pDC = (CDC*)lParam;
	ASSERT(pDC != NULL);
	OnPrepareDC(pDC);

	return 0;
}