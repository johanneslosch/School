#include <windows.h> 
LRESULT CALLBACK WndProc(HWND, UINT, WPARAM, LPARAM);
LRESULT CALLBACK ChildProc(HWND, UINT, WPARAM, LPARAM);
const char szChildName[] = "Farbtabelle";
const UINT PM_COLORCHANGED = WM_APP + 1;
int WINAPI WinMain(HINSTANCE hInstance, HINSTANCE hPrevInstance, PSTR szCmdLine,
 int iCmdShow) 
{ MSG msg;
  HWND hWnd;
  WNDCLASS wc;
  char szAppName[] = "Linke Maustaste auf Hintergrundfarbe klicken!";
  wc.cbClsExtra = 0;
  wc.cbWndExtra = 0;
  wc.hbrBackground = (HBRUSH) GetStockObject(WHITE_BRUSH);
  wc.hCursor = LoadCursor(NULL, IDC_ARROW);
  wc.hIcon = LoadIcon(NULL, IDI_APPLICATION);
  wc.hInstance = hInstance;
  wc.lpfnWndProc = WndProc;
  wc.lpszClassName = szAppName;
  wc.lpszMenuName = NULL;
  wc.style = CS_HREDRAW | CS_VREDRAW;
  RegisterClass(&wc);
  wc.hbrBackground = (HBRUSH) GetStockObject(LTGRAY_BRUSH);
  wc.hIcon = NULL;
  wc.lpfnWndProc = ChildProc;
  wc.lpszClassName = szChildName;
  RegisterClass(&wc);
  hWnd = CreateWindow( szAppName, szAppName, WS_OVERLAPPEDWINDOW, CW_USEDEFAULT,
  CW_USEDEFAULT, CW_USEDEFAULT, CW_USEDEFAULT, NULL, NULL, hInstance, NULL);
  
  ShowWindow(hWnd, iCmdShow);
  UpdateWindow(hWnd);
  while (GetMessage(&msg, NULL, 0, 0)) 
  { TranslateMessage(&msg);
    DispatchMessage(&msg);
  }
  return msg.wParam;
}
LRESULT CALLBACK WndProc(HWND hWnd, UINT message, WPARAM wParam, LPARAM
 lParam) 
{ static HWND hChild;
  static RECT rect;
  static int iColor = RGB(255, 255, 255);
  switch (message) 
  { case WM_CREATE: 
    { GetClientRect(hWnd, &rect);
      hChild = CreateWindow( szChildName, NULL, WS_CHILD | WS_VISIBLE |
       WS_DLGFRAME, 5, rect.bottom - 35, rect.right - 10, 30, hWnd, NULL,
      ((LPCREATESTRUCT) lParam)->hInstance, NULL);
      return 0;
    }
    case WM_SIZE: 
    { rect.right = LOWORD(lParam);
      rect.bottom = HIWORD(lParam);
      MoveWindow(hChild, 5, rect.bottom - 35, rect.right - 10, 30, TRUE);
      
      return 0;
    }
    case PM_COLORCHANGED: 
    { iColor = wParam;
      InvalidateRect(hWnd, NULL, FALSE);
      return 0;
    }
    case WM_PAINT: 
    { PAINTSTRUCT ps;
      HDC hDC;
      hDC = BeginPaint(hWnd, &ps);
      
      { HBRUSH hOldBrush = (HBRUSH) SelectObject(hDC, CreateSolidBrush(iColor));
        
        Rectangle(hDC, 0, 0, rect.right, rect.bottom);
        DeleteObject(SelectObject(hDC, hOldBrush));
      }
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
LRESULT CALLBACK ChildProc(HWND hWnd, UINT message, WPARAM wParam, LPARAM
 lParam) 
{ static RECT rect;
  static int iAnzFarben;
  const int iKasten = 12;
  const int iKastenOffset = 15;
  switch (message) 
  { case WM_SIZE: 
    { rect.right = LOWORD(lParam);
      rect.bottom = HIWORD(lParam);
      iAnzFarben = (rect.right / iKastenOffset) - 2;
      return 0;
    }
    case WM_LBUTTONDOWN: 
    { for (int i = 0; i < iAnzFarben; i++) 
      { if (15 + i * iKastenOffset <= LOWORD(lParam) && 15 + i * iKastenOffset
         + iKasten >= LOWORD(lParam) && rect.bottom / 2 - iKasten / 2 <=
         HIWORD(lParam) && rect.bottom / 2 - iKasten / 2 + iKasten >= HIWORD(lParam))
        
        { int iColor = 255 * i / (iAnzFarben - 1);
          SendMessage(GetParent(hWnd), PM_COLORCHANGED, RGB(iColor, iColor,
           iColor), 0);
          return 0;
        }
      }
      return 0;
    }
    case WM_PAINT: 
    { HDC hDC;
      PAINTSTRUCT ps;
      hDC = BeginPaint(hWnd, &ps);
      
      { for (int i = 0; i < iAnzFarben; i++) 
        { int iColor = 255 * i / (iAnzFarben - 1);
          HBRUSH hOldBrush = (HBRUSH) SelectObject(hDC, CreateSolidBrush(RGB(iColor,
           iColor, iColor)));
          Rectangle(hDC, 15 + i * iKastenOffset, rect.bottom / 2 - iKasten
           / 2, 15 + i * iKastenOffset + iKasten, rect.bottom / 2 - iKasten
           / 2 + iKasten);
          DeleteObject(SelectObject(hDC, hOldBrush));
        }
      }
      EndPaint(hWnd, &ps);
      return 0;
    }
  }
  return DefWindowProc(hWnd, message, wParam, lParam);
}
