// PIDocument.cpp : ʵ���ļ�
//

#include "stdafx.h"
#include "PluginLibrary.h"
#include "PIDocument.h"


// CPIDocument

IMPLEMENT_DYNCREATE(CPIDocument, CDocument)

CPIDocument::CPIDocument()
	: m_pImage(NULL)
{

}

BOOL CPIDocument::OnNewDocument()
{
	if (!CDocument::OnNewDocument())
		return FALSE;
	return TRUE;
}

CPIDocument::~CPIDocument()
{
	if (m_pImage)
	{
		delete m_pImage;
		m_pImage = NULL;
	}
}

BEGIN_MESSAGE_MAP(CPIDocument, CDocument)
END_MESSAGE_MAP()

// CPIDocument ���

#ifdef _DEBUG
void CPIDocument::AssertValid() const
{
	CDocument::AssertValid();
}

#ifndef _WIN32_WCE
void CPIDocument::Dump(CDumpContext& dc) const
{
	CDocument::Dump(dc);
}
#endif
#endif //_DEBUG

#ifndef _WIN32_WCE
// CPIDocument ���л�

void CPIDocument::Serialize(CArchive& ar)
{
	if (ar.IsStoring())
	{
		// TODO: �ڴ���Ӵ洢����
	}
	else
	{
		// TODO: �ڴ���Ӽ��ش���
	}
}
#endif

// CPIDocument ����
