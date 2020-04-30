// Th. Cassebaum, 15.2.2004, all rights reserved
#include <windows.h>
LRESULT CALLBACK WndProc(HWND,UINT,WPARAM,LPARAM);
HINSTANCE hInstGlobal;
int APIENTRY WinMain(HINSTANCE hInstance,HINSTANCE hPrevInstance,LPSTR lpCmdLine,int nCmdShow)
{ hInstGlobal=hInstance;
  WNDCLASS WndClass;
  WndClass.style=0; WndClass.cbClsExtra=0; WndClass.cbWndExtra=0;
  WndClass.lpfnWndProc=WndProc; WndClass.hInstance=hInstance;
  WndClass.hbrBackground=(HBRUSH)(COLOR_BACKGROUND); // Hintergrundfarbe
  WndClass.hCursor=LoadCursor(NULL,IDC_ARROW);   // Cursor
  WndClass.hIcon=LoadIcon(NULL,IDI_APPLICATION); // Icon
  WndClass.lpszMenuName=0; WndClass.lpszClassName="WinProg";
  RegisterClass(&WndClass); HWND hWindow;
  hWindow=CreateWindow("WinProg"
  ,"Fenstertitel"             // Fenstertitel
  ,WS_OVERLAPPEDWINDOW
  ,100,0,400,300              // Left,Top,Width,Height
  ,NULL,NULL,hInstance,NULL);
  ShowWindow(hWindow, nCmdShow); UpdateWindow(hWindow);
  MSG Message;
  while (GetMessage(&Message,NULL,0,0)) { DispatchMessage(&Message); }
  return (Message.wParam);
}
LRESULT CALLBACK WndProc(HWND hWnd,UINT uiMessage,WPARAM wParam,LPARAM lParam)
{ switch(uiMessage)
  { case WM_CREATE: HWND hButton, hButtonExit;
      hButton= CreateWindow("BUTTON","OK",WS_CHILD|WS_VISIBLE|BS_PUSHBUTTON
         ,70,220,100,30     // Left,Top,Width,Height
         ,hWnd,(HMENU) 1,hInstGlobal,NULL);
      hButtonExit= CreateWindow("BUTTON","Exit",WS_CHILD|WS_VISIBLE|BS_PUSHBUTTON
         ,220,220,100,30     // Left,Top,Width,Height
         ,hWnd,(HMENU) 2,hInstGlobal,NULL);
    case WM_COMMAND:
      if (HIWORD(wParam)==BN_CLICKED)
      { if (LOWORD(wParam)==1)        // OK-Button
        { HDC hdc; char* str="Hello world!";
          hdc=GetDC(GetParent((HWND)lParam));
          SetBkColor(hdc,0xd0d0d0);SetTextColor(hdc,0xFF0000);
          TextOut(hdc,150,110,str,lstrlen(str));
        }     
        if (LOWORD(wParam)==2)        // Exit-Button
        { SendMessage(GetParent((HWND)lParam),WM_DESTROY,0,0);
        }
      }
      return 0;     
    case WM_DESTROY: PostQuitMessage(0); return 0;
    default: return DefWindowProc(hWnd,uiMessage,wParam,lParam);
  }
}
