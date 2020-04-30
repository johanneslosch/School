// programmiert von Th.Cassebaum am 3.5.2002 gegen 19:33 Uhr
// all rights reserved
#include <windows.h> 
#include <time.h>
#define GDI_SCHWARZ  0x000000
#define GDI_WEISS    0xFFFFFF
#define GDI_OLIV     0xFFFF00
#define GDI_GELB     0x00FFFF
#define GDI_LILA     0xFF00FF
#define GDI_ROT      0x0000FF
#define GDI_GRUEN    0x00FF00
#define GDI_BLAU     0xFF0000
#define GDI_MARINE   0x440000
#define GDI_HIMMEL   0xFFAAAA
#define GDI_GRAU     0x888888
#define GDI_HELLGRAU 0xCCCCCC
void Circle(unsigned short x,unsigned short y,unsigned short r);
void Circle(unsigned short x,unsigned short y,unsigned short r,unsigned int c);
void ClearArea(long W_Color);
void ClearArea(long W_Color,unsigned int l,unsigned int t,
               unsigned int b,unsigned int h);
void Delay(unsigned short Msec) ;
void EndPaintGdi(HWND hWnd);
void FillRect(unsigned short l,unsigned short t,unsigned short r,unsigned short u);
void LineTo(unsigned short x,unsigned short y);
void MoveTo(unsigned short x,unsigned short y);
void Pinsel(long col);
void Rectangle(unsigned short l,unsigned short t,unsigned short r,unsigned short u);
void RoundRect(unsigned short l,unsigned short t,unsigned short r,
               unsigned short u,unsigned short k1,unsigned short k2);
void Stift(long col, short d);
LRESULT CALLBACK WndProc(HWND, UINT, WPARAM, LPARAM);
      WNDCLASS WndClass;
      HPEN hPen;
      HPEN hPenalt;
      HBRUSH hBrush;
      HBRUSH hBrushalt;
      HDC hdc;
      PAINTSTRUCT ps;
WPARAM Fenster(HINSTANCE hInstance,HINSTANCE hPrevInstance,
               LPSTR lpCmdLine,int nCmdShow,
               LPCTSTR Classname, LPCSTR Fenster,
               int links, int oben, int breit, int hoch)
{ WndClass.style = 0;
  WndClass.cbClsExtra = 0;
  WndClass.cbWndExtra = 0;
  WndClass.lpfnWndProc = WndProc;
  WndClass.hInstance = hInstance;
  WndClass.hbrBackground = (HBRUSH)(COLOR_WINDOW+1);
  WndClass.hCursor = LoadCursor(NULL, IDC_ARROW);;
  WndClass.hIcon = LoadIcon(NULL, IDI_APPLICATION);
  WndClass.lpszMenuName = 0;
  WndClass.lpszClassName = Classname;
  RegisterClass(&WndClass);
  HWND hWindow;
  hWindow = CreateWindow(Classname,Fenster,WS_OVERLAPPEDWINDOW,
                          links,oben,breit,hoch,NULL,NULL,hInstance,NULL );
  ShowWindow(hWindow, nCmdShow);
  UpdateWindow(hWindow);
  MSG Message;
  while(GetMessage(&Message, NULL, 0, 0))
    DispatchMessage(&Message);
  return Message.wParam;
}
void MoveTo(unsigned short x,unsigned short y)
{ MoveToEx(hdc,x,y,NULL);
}
void LineTo(unsigned short x,unsigned short y)
{ LineTo(hdc,x,y);
}
void Rectangle(unsigned short l,unsigned short t,unsigned short r,unsigned short u)
{ Rectangle(hdc,l,t,r,u);
}
void RoundRect(unsigned short l,unsigned short t,unsigned short r,
               unsigned short u,unsigned short k1,unsigned short k2)
{ RoundRect(hdc,l,t,r,u,k1,k2);
}
void FillRect(unsigned short l,unsigned short t,unsigned short r,unsigned short u)
{ RECT rect;
  SetRect(&rect,l,t,r,u);
  FillRect(hdc,&rect,hBrush);
}
void Ellipse(unsigned short l,unsigned short t,unsigned short r,unsigned short u)
{ Ellipse(hdc,l,t,r,u);
}
void Circle(unsigned short x,unsigned short y,unsigned short r)
{ Ellipse(hdc,x-r,y-r,x+r,y+r);
}
void Circle(unsigned short x,unsigned short y,unsigned short r,unsigned int c)
{ Pinsel(c);
  Ellipse(hdc,x-r,y-r,x+r,y+r);
}
void Pinsel(long col)
{ DeleteObject(SelectObject(hdc,hBrushalt));
  hBrush=CreateSolidBrush(col);
  hBrushalt=(HBRUSH)SelectObject(hdc,hBrush);
}
void Stift(long col, short d)
{ DeleteObject(SelectObject(hdc,hPenalt));
  hPen=CreatePen(PS_SOLID,d,col);
  hPenalt=(HPEN)SelectObject(hdc,hPen);
}
void EndPaintGdi(HWND hWnd)
{     SelectObject(hdc,hBrushalt);
      SelectObject(hdc,hPenalt);
      DeleteObject(hPen);
      DeleteObject(hBrush);
      EndPaint(hWnd, &ps);
}
// Löschen der Zeichenfläche
void ClearArea(long W_Color,unsigned int l,unsigned int t,
               unsigned int b,unsigned int h)
{ Pinsel(W_Color); FillRect(l,t,b+l,t+h);
}
void ClearArea(long W_Color)
{ Pinsel(W_Color); FillRect(0,0,W_BREIT,W_HOCH);
}
void Delay(unsigned short Msec) 
{ int zeit=clock();
  while(clock()<zeit+Msec);
}

