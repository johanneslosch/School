#include <windows.h>
void GraphicExec(void);
HDC hDC;
static RECT rect;
LRESULT CALLBACK WndProc(HWND, UINT, WPARAM, LPARAM);
int WINAPI WinMain(HINSTANCE hInstance, HINSTANCE hPrevInstance,
                   PSTR szCmdLine, int iCmdShow)
{  MSG msg;HWND hWnd;WNDCLASS wc;
   wc.cbClsExtra         = 0; wc.cbWndExtra         = 0;
   wc.hbrBackground      = (HBRUSH) GetStockObject(W_BkColor);
   wc.hCursor            = LoadCursor(NULL, IDC_ARROW);
   wc.hIcon              = LoadIcon(NULL, IDI_APPLICATION);
   wc.hInstance          = hInstance;
   wc.lpfnWndProc        = WndProc;
   wc.lpszClassName      = szAppName;
   wc.lpszMenuName       = NULL;
   wc.style              = CS_HREDRAW | CS_VREDRAW;
   RegisterClass(&wc);
   hWnd = CreateWindow(  szAppName,szAppName,WS_OVERLAPPEDWINDOW,
                         W_Left,W_Top,W_Width,W_Height,
                         NULL,NULL,hInstance,NULL);
   ShowWindow(hWnd, iCmdShow);UpdateWindow(hWnd);
   while(GetMessage(&msg,NULL,0,0)){TranslateMessage(&msg);DispatchMessage(&msg);}
   return msg.wParam;
}
LRESULT CALLBACK WndProc(HWND hWnd, UINT message, WPARAM wParam, LPARAM
 lParam) 
{ switch (message)
  { case WM_CREATE: return 0;
    case WM_SIZE: 
    { rect.right = LOWORD(lParam);
      rect.bottom = HIWORD(lParam);
      return 0;
    }
    case WM_PAINT: 
    { PAINTSTRUCT ps;
      hDC = BeginPaint(hWnd, &ps);
      GraphicExec();
      EndPaint(hWnd, &ps);
      return 0;
    }
    case WM_DESTROY: 
    { PostQuitMessage(0);
      return 0;
    }
  }
  return DefWindowProc(hWnd, message, wParam, lParam);
}

