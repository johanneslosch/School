#include <windows.h>

#define title "Draw"
#define wi 600 /* dialog width */
#define he 400 /* dialog height */
#define pencolor 0xff0000UL /* color of the pen: blue */

HDC memdc; /* memory dc */
HBITMAP membm; /* bitmap for memdc */
HBRUSH membrush; /* brush for memdc */
HPEN mempen; /* pen for memdc */

RECT rcold; /* struct for the focus rect */
RECT rccl; /* client rect */

int down = 0; /* indicates that mouse button is pressed */
int init = 0; /* inidicates the memdc was created */
int penwidth = 1; /* pen width */
enum drawmode {dmline, dmellipse, dmrect, dmfree};
int dm = dmline; /* draw mode */

WNDPROC oldproc;

#define oldbm "membmold" /* string-hashes where we store old gdi objects */
#define oldbrush "membrushold"
#define oldpen "mempenold"

/* this function creates the memory dc */
void initdlg(HWND hWnd) {
	HDC dc = GetDC(hWnd);
	GetClientRect(hWnd, &rccl); /* Get the client area coordinates */
	OffsetRect(&rccl, -rccl.left, -rccl.top); /* move origin to 0,0 (where it should already be)*/
	memdc = CreateCompatibleDC(dc);
	membm = CreateCompatibleBitmap(dc, rccl.right, rccl.bottom);
	/* select the whole stuff into dc and store old objects */
	SetProp(hWnd, oldbm, SelectObject(memdc, membm));
	membrush = (HBRUSH) GetStockObject(WHITE_BRUSH);
	FillRect(memdc, &rccl, membrush); /* fill the rectangle */
	SetProp(hWnd, oldbrush, SelectObject(memdc, membrush));
	mempen = (HPEN) CreatePen(PS_SOLID, penwidth, pencolor);
	SetProp(hWnd, oldpen, SelectObject(memdc, mempen));
	ReleaseDC(hWnd, dc);
	init = 1; /* initialized now */
}

/* this function draws a focus rect (if not in mode: freehand) in the window */
void focusrect(RECT* rc, HDC dc) {
	RECT rcnew;
	if (dm == dmfree) return;
	rcnew.left = min(rc->left, rc->right);
	rcnew.right = max(rc->left, rc->right);
	rcnew.top = min(rc->top, rc->bottom);
	rcnew.bottom = max(rc->top, rc->bottom);
	DrawFocusRect(dc, &rcnew);
	DrawFocusRect(dc, rc);
}

/* The subclass function of the dialog
 * window messages will be served here.
 */
int __stdcall cb(HWND hWnd, UINT msg, WPARAM wParam, LPARAM lParam) {
	HDC dc;
	switch(msg) {
		/* The window needs to be repainted */
		case WM_PAINT: {
			PAINTSTRUCT ps;
			if (!init) initdlg(hWnd);
			dc = BeginPaint(hWnd, &ps);
			BitBlt(dc, 0, 0, rccl.right, rccl.bottom, memdc, 0, 0, SRCCOPY); /* copy memdc to dc */
			EndPaint(hWnd, &ps);
			return TRUE;
		}
		/* The window will be destroed */
		case WM_DESTROY: /* delete the gdi objects */
			SelectObject(memdc, (HGDIOBJ) GetProp(hWnd, oldbm));
			SelectObject(memdc, (HGDIOBJ) GetProp(hWnd, oldbrush));
			SelectObject(memdc, (HGDIOBJ) GetProp(hWnd, oldpen));
			DeleteObject(membm);
			DeleteObject(mempen);
			DeleteDC(memdc);
			PostQuitMessage(0);
			return 0;
		/* The left mousebutton was pushed down */
		case WM_LBUTTONDOWN:
			SetCapture(hWnd);
			rcold.left = rcold.right = lParam & 0xffffUL;
			rcold.top = rcold.bottom = (lParam & 0xffff0000UL) >> 0x10UL;
			down = 1;
			MoveToEx(memdc, rcold.right, rcold.bottom, NULL);
			return TRUE;
		/* The cursor is moved over the window */
		case WM_MOUSEMOVE:
			if (down) {
				dc = GetDC(hWnd);
				focusrect(&rcold, dc);
				rcold.right = lParam & 0xffffUL;
				rcold.bottom = (lParam & 0xffff0000UL) >> 0x10UL;
				if (dm == dmfree) { /* no focus rect for free hand, but draw immediately */
					LineTo(memdc, rcold.right, rcold.bottom);
					BitBlt(dc, 0, 0, rccl.right, rccl.bottom, memdc, 0, 0, SRCCOPY);
				}
				focusrect(&rcold, dc);
				ReleaseDC(hWnd, dc);
			}
			return TRUE;
		/* The left mouse button was released */
		case WM_LBUTTONUP:
			dc = GetDC(hWnd);
			focusrect(&rcold, dc);
			switch(dm) { /* determine what to do */
				case dmline: LineTo(memdc, rcold.right, rcold.bottom); break;
				case dmellipse: Ellipse(memdc, rcold.left, rcold.top, rcold.right, rcold.bottom); break;
				case dmrect: Rectangle(memdc, rcold.left, rcold.top, rcold.right, rcold.bottom); break;
			}
			/* copy now memdc to dc again (we don't need to call repaint)*/
			BitBlt(dc, 0, 0, rccl.right, rccl.bottom, memdc, 0, 0, SRCCOPY);
			ReleaseCapture();
			ReleaseDC(hWnd, dc);
			down = 0;
			return TRUE;
		/* A system key on the keyboard was stroke */
		case WM_KEYDOWN:
			if (wParam >= VK_F1 && wParam <= VK_F4) {
				dm = wParam - VK_F1;
				return TRUE;
			}
			break;
		/* The systemmenu quit command was invoked */
		case WM_SYSCOMMAND: /* dialog specific implementation */
			if (wParam == SC_CLOSE) SendMessage(hWnd, WM_DESTROY, 0, 0);
			break;
		/* A character key on the keyboard was stroke */
		case WM_CHAR:
			if (wParam == '+' || wParam == '-') {
				penwidth += (wParam == '+')?1:-1;
				if (penwidth < 1) penwidth = 1;
				mempen = CreatePen(PS_SOLID, penwidth, pencolor);
				DeleteObject(SelectObject(memdc, mempen));
				return TRUE;
			}
			break;
	} /* end switch */
	return oldproc(hWnd, msg, wParam, lParam);
}

/* Windows main procedure */
int __stdcall WinMain (HINSTANCE hInst, HINSTANCE hPrev, LPSTR lpszCmd, int nCmdShow) {
	MSG msg;
	int style = WS_OVERLAPPED + WS_DLGFRAME + WS_CAPTION + WS_SYSMENU;
	char *n1="doof",*n2="lieb";
	HWND wnd = CreateWindowEx(0, "#32770", title, style, 0,0,wi,he, 0, 0, hInst, 0);
	if (!wnd) return 0;
  MessageBox(wnd,n1,n2,MB_OK);
	ShowWindow(wnd, SW_NORMAL);
	oldproc = (WNDPROC) SetWindowLong(wnd, GWL_WNDPROC, (long)cb);
	while (GetMessage(&msg, 0, 0, 0)) {
		TranslateMessage(&msg);
		DispatchMessage(&msg);
	}
	SetWindowLong(wnd, GWL_WNDPROC, (long)oldproc);
	return msg.wParam;
}
