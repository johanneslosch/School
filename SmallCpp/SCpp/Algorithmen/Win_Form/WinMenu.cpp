#include <windows.h> 
LRESULT CALLBACK WndProc(HWND, UINT, WPARAM, LPARAM);
int APIENTRY WinMain( HINSTANCE hInstance,
                      HINSTANCE hPrevInstance,
                      LPSTR lpCmdLine,
                      int nCmdShow)
{ WNDCLASS WndClass;
  WndClass.style = 0;
  WndClass.cbClsExtra = 0;
  WndClass.cbWndExtra = 0;
  WndClass.lpfnWndProc = WndProc;
  WndClass.hInstance = hInstance;
  WndClass.hbrBackground = (HBRUSH) (COLOR_WINDOW+1);
  WndClass.hCursor = LoadCursor(NULL, IDC_ARROW);;
  WndClass.hIcon = LoadIcon(NULL, IDI_APPLICATION);
  WndClass.lpszMenuName = 0;
  WndClass.lpszClassName = "MenuProg";
  RegisterClass(&WndClass);
  HWND hWindow;
  hWindow = CreateWindow("MenuProg","Fenster",WS_OVERLAPPEDWINDOW,
                          0,0,400,260,NULL,NULL,hInstance,NULL );
  ShowWindow(hWindow, nCmdShow);
  UpdateWindow(hWindow);
  MSG Message;
  while(GetMessage(&Message, NULL, 0, 0))
    DispatchMessage(&Message);
  return (Message.wParam);
}
LRESULT CALLBACK WndProc(HWND hWnd,UINT uiMessage,
                         WPARAM wParam,LPARAM lParam)
{ switch (uiMessage)
  { case WM_CREATE:
      HMENU hMenu;
      hMenu=CreateMenu();
      MENUITEMINFO mii;
      mii.cbSize=sizeof(MENUITEMINFO);
      mii.fMask=MIIM_TYPE|MIIM_ID;
      mii.fType=MFT_STRING;
      char *string;
      string=new char[40];
      lstrcpy(string,"Zeichne Rechteck");
      mii.dwTypeData=string;
      mii.cch= lstrlen(string);
      mii.fState=MFS_ENABLED;
      mii.wID=1;
      InsertMenuItem(hMenu,0,FALSE,&mii);

        HMENU hMenu2;
        hMenu2=CreatePopupMenu();
        lstrcpy(string,"Beenden");
        mii.wID=2;
        InsertMenuItem(hMenu2,0,FALSE,&mii);

      lstrcpy(string,"Datei");
      mii.fMask=MIIM_TYPE|MIIM_SUBMENU;
      mii.hSubMenu=hMenu2;
      InsertMenuItem(hMenu,0,FALSE,&mii);

        HMENU hMenu2_;
        hMenu2_=CreatePopupMenu();
        lstrcpy(string,"Autor");
        mii.fMask=MIIM_TYPE|MIIM_ID;
        mii.wID=3;
        InsertMenuItem(hMenu2_,0,FALSE,&mii);

          HMENU hMenu3;
          hMenu3=CreatePopupMenu();
          lstrcpy(string,"Farbtiefe");
          mii.fMask=MIIM_TYPE|MIIM_ID;
          mii.wID=4;
          InsertMenuItem(hMenu3,0,FALSE,&mii);
          lstrcpy(string,"Aufloesung");
          mii.wID=5;
          InsertMenuItem(hMenu3,0,FALSE,&mii);
 
          HMENU hMenu3_;
          hMenu3_=CreatePopupMenu();
          lstrcpy(string,"Windows Verzeichnis");
          mii.wID=6;
          InsertMenuItem(hMenu3_,0,FALSE,&mii);
          lstrcpy(string,"Aktuelles Verzeichnis");
          mii.wID=8;
          InsertMenuItem(hMenu3,0,FALSE,&mii);

        lstrcpy(string,"Grafik");
        mii.fMask=MIIM_TYPE|MIIM_SUBMENU;
        mii.hSubMenu=hMenu3;
        InsertMenuItem(hMenu2_,0,FALSE,&mii);
        lstrcpy(string,"Festplatte");
        mii.hSubMenu=hMenu3_;
        InsertMenuItem(hMenu2_,0,FALSE,&mii);

      lstrcpy(string,"Information");
      mii.hSubMenu=hMenu2_;
      InsertMenuItem(hMenu,0,FALSE,&mii);

      SetMenu(hWnd, hMenu);

      delete string;

      return 0;
    case WM_COMMAND:
      if (HIWORD(wParam) == 0)
      { switch (LOWORD(wParam))
        { case 1:
            HDC hdc;
            hdc=GetDC(hWnd);
            Rectangle(hdc,10,10,100,100);
            ReleaseDC(hWnd,hdc);
            return 0;
          case 2:
            DestroyWindow(hWnd);
            return 0;
          case 3:
            hdc=GetDC(hWnd);
            char *string1;
            string1=new char[80];
            lstrcpy(string1,"Autor Th.Cassebaum");
            TextOut(hdc,120,10,string1,lstrlen(string1));
            ReleaseDC(hWnd,hdc);
            delete string1;
            return 0;
          case 4:
            hdc=GetDC(hWnd);
            string1=new char[80];
            lstrcpy(string1,"Farbtiefe: ");
            int BitsPixel;
            BitsPixel=GetDeviceCaps(hdc,BITSPIXEL);
            char *string2;
            string2=new char[80];
            itoa(BitsPixel,string2,10);
            lstrcat(string1,string2);
            TextOut(hdc,120,30,string1,lstrlen(string1));
            ReleaseDC(hWnd,hdc);
            delete string1;
            delete string2;
            return 0;
          case 5:
            hdc=GetDC(hWnd);
            string1=new char[80];
            lstrcpy(string1,"Aufloesung: ");
            int HRes,VRes;
            HRes=GetDeviceCaps(hdc,HORZRES);
            string2=new char[80];
            itoa(HRes,string2,10);
            lstrcat(string1,string2);
            lstrcat(string1,"x");
            VRes=GetDeviceCaps(hdc,VERTRES);
            itoa(VRes,string2,10);
            lstrcat(string1,string2);
            TextOut(hdc,120,50,string1,lstrlen(string1));
            ReleaseDC(hWnd,hdc);
            delete string1;
            delete string2;
            return 0;
          case 6:
            hdc=GetDC(hWnd);
            string1=new char[80];
            lstrcpy(string1,"Windows Verzeichnis: ");
            string2=new char[80];
            GetWindowsDirectory(string2,500);
            lstrcat(string1,string2);
            TextOut(hdc,120,70,string1,lstrlen(string1));
            ReleaseDC(hWnd,hdc);
            delete string1;
            delete string2;
            return 0;
/*          case 7:
            hdc=GetDC(hWnd);
            string1=new char[80];
            ReleaseDC(hWnd,hdc);
            delete string1;
            delete string2;
            return 0;
*/          case 8:
            hdc=GetDC(hWnd);
            string1=new char[80];
            lstrcpy(string1,"Aktuelles Verzeichnis: ");
            string2=new char[80];
            GetCurrentDirectory(500,string2);
            lstrcat(string1,string2);
            TextOut(hdc,120,90,string1,lstrlen(string1));
            ReleaseDC(hWnd,hdc);
            delete string1;
            delete string2;
            return 0;
          default:
            return 0;
        }
      }
      return 0;
    case WM_DESTROY: PostQuitMessage(0);
                     return 0;;
    default: return DefWindowProc(hWnd, uiMessage, wParam, lParam);
  }
}
