// CbehaviorView.cpp : 实现文件
//

#include "stdafx.h"
#include "mini_hammer.h"
#include "CbehaviorView.h"
#include "misc/Cgdi.h"
#include "memdc.h"
#include "GlobalVar.h"

#include "atlimage.h"


// CbehaviorView

IMPLEMENT_DYNCREATE(CbehaviorView, CView)

CbehaviorView::CbehaviorView()
	: m_lpBuf(NULL)
{

}

CbehaviorView::~CbehaviorView()
{
}

BEGIN_MESSAGE_MAP(CbehaviorView, CView)
	ON_WM_ERASEBKGND()
	ON_WM_PAINT()
	ON_WM_DESTROY()
	ON_WM_TIMER()
END_MESSAGE_MAP()


// CbehaviorView 绘图
void CbehaviorView::OnDraw(CDC* pDC)
{
	CDocument* pDoc = GetDocument();
	// TODO: 在此添加绘制代码

	//CMemoryDC *pMemDC = NULL;
	//pDC = pMemDC = new CMemoryDC(pDC);

// 	RECT rect;
// 	GetClientRect(&rect);
// 	int nWidth = rect.right;
// 	int nHeight = rect.bottom;
// 
// 	pMemDC->FillSolidRect(0, 0, nWidth, nHeight, RGB(255, 255, 255));
// 	gdi->StartDrawing(pDC->GetSafeHdc());
	//gdi->TextAtPos(0, 0, "Hello");
	//list<Vehicle*>& vehicleList = GlobalVar::instance().GetGameWorld()->GetAllBots();
	//if (vehicleList.size() > 0)
	//{
	//	int xOffset = 0;
	//	int yOffset = 0;

	//	Vehicle* pFirstVehicle = (*vehicleList.begin());
	//	pFirstVehicle->GetBrain()->RenderText(xOffset, yOffset);
	//}
	//gdi->StopDrawing(pDC->GetSafeHdc());
	//
	//delete pMemDC;

	// 绘制图片
	CBitmap bitmap;  
	CDC dcMemory;  
	int result;  
	bitmap.CreateBitmap(128, 128, 1, 32, m_lpBuf);

	result = bitmap.SetBitmapBits(128 * 128 * 4, m_lpBuf);
	dcMemory.CreateCompatibleDC(pDC);
	CBitmap *pbmpOld = dcMemory.SelectObject(&bitmap);
	//m_pDC->StretchBlt(0,0,目宽,目高,&dcMemory,0,0,源宽,源高,SRCCOPY);  
	pDC->BitBlt(0, 0, 128, 128, &dcMemory, 0, 0, SRCCOPY);  
	pDC->StretchBlt(0, 0, 128 / 2, 128 / 2,&dcMemory, 0, 0, 128, 128, SRCCOPY);  
	dcMemory.SelectObject(pbmpOld);

	return ;
}


// CbehaviorView 诊断

#ifdef _DEBUG
void CbehaviorView::AssertValid() const
{
	CView::AssertValid();
}

#ifndef _WIN32_WCE
void CbehaviorView::Dump(CDumpContext& dc) const
{
	CView::Dump(dc);
}
#endif
#endif //_DEBUG


// CbehaviorView 消息处理程序


BOOL CbehaviorView::OnEraseBkgnd(CDC* pDC)
{
	// TODO: 在此添加消息处理程序代码和/或调用默认值

	//return CView::OnEraseBkgnd(pDC);

	return TRUE;
}


void CbehaviorView::OnPaint()
{
	CPaintDC dc(this); // device context for painting
	// TODO: 在此处添加消息处理程序代码
	// 不为绘图消息调用 CView::OnPaint()

	OnPrepareDC(&dc); 
	OnDraw(&dc); //调用了OnDraw
}


void CbehaviorView::OnInitialUpdate()
{
	CView::OnInitialUpdate();

	// TODO: 在此添加专用代码和/或调用基类
	SetTimer(2, 0.1, NULL);

	// 加载一幅图片
	LoadImage();
}


void CbehaviorView::OnDestroy()
{
	CView::OnDestroy();

	// TODO: 在此处添加消息处理程序代码
	KillTimer(2);
}


void CbehaviorView::OnTimer(UINT_PTR nIDEvent)
{
	// TODO: 在此添加消息处理程序代码和/或调用默认值
	Invalidate();

	CView::OnTimer(nIDEvent);
}

void CbehaviorView::LoadImage()
{
	HBITMAP hBitmap;  
	CString filename;  
	CString BMPFolder;  
	CString str;  

	CImage layerPng;  

	//str.Format("layer (%d).png", layernum);  

	//filename = BMPFolder + "\\" + str;  
	filename = "D:\\fish_editor\\mini_hammer-master\\workplace\\media\\fish_base\\plist\\8goldItem.png";

	layerPng.Load(filename);  
	hBitmap=layerPng.Detach();  
	CBitmap bmp;  
	BITMAP l_bitMap;  
	bmp.Attach(hBitmap);  
	bmp.GetBitmap(&l_bitMap);  

	int height = l_bitMap.bmHeight;  
	int width = l_bitMap.bmWidth;  

	bmp.GetBitmapBits(128 * 128 * 4, m_lpBuf);
}
