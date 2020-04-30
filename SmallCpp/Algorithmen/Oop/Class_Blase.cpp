// programmiert von Th.Cassebaum am 2.3.2003 gegen 12:05 Uhr
// all rights reserved 
#define W_BREIT 1024
#define W_HOCH  768
#define BKCOLOR GDI_HIMMEL
#define ANZAHL  500
#define A_GROESSE 10
#include <math.h>
#include <conio.h>
#include "newgdi.h"
class TBlase
{ public:  TBlase();                     // Konstruktor
           void Moving(void);            // Neue x,y-Werte erstellen
           bool CollDetect(TBlase bls);  // Blase mit der Parameter-Blase kollidiert?
           TBlase Verein(TBlase bls);    // Vereinigung der Blase mit einer zweiten
  private: void Zeichnen(void); 	 // Zeichnen einer Blase
           unsigned int x,y,r,c;         // Koordinaten, Radius, Farbe der Blase
           int vx,vy;                    // Bewegungsgeschwindigkeit
};
unsigned short bzahl=ANZAHL;             // Blasenzähler
TBlase b[ANZAHL];                        // Blasenobjekte

int APIENTRY WinMain( HINSTANCE hInstance,HINSTANCE hPrevInstance,LPSTR lpCmdLine,int nCmdShow) 
{ return Fenster(hInstance,hPrevInstance,lpCmdLine,nCmdShow ,"Blasen" // Name des Fensters 
  ,"Blasen zerplatzen" // Überschrift des Fensters 
  ,0,0                 // Fenster links, oben
  ,W_BREIT,W_HOCH      // Fenster breit, hoch
  );
}
LRESULT CALLBACK WndProc(HWND hWnd,UINT uiMessage, WPARAM wParam,LPARAM lParam) 
{ int i,j;  bool coll;
  switch (uiMessage) 
  { case WM_PAINT:
            randomize();
            hdc=BeginPaint(hWnd,&ps);                // Start der gdi-Anwendung
            { HBRUSH hOldBrush = (HBRUSH)SelectObject(hdc, CreateSolidBrush(0));
              Stift(GDI_WEISS,1);                    // RGB-Farbe des Stifts, Dicke
              while(bzahl)                           // Solange minimal eine Blase sichtbar
              { Delay(20);
                ClearArea(BKCOLOR);                  // nach Warten Hintergrund löschen
                for(i=0;i<bzahl;i++) b[i].Moving();  // bewegte Blasen neu zeichnen
                if(bzahl==1){Delay(1000);break;}     // letzte Blase --> Ende
                for(i=0;i<bzahl-1;i++)
                { for(j=i+1;j<bzahl;j++)
                    if(b[i].CollDetect(b[j]))        // falls Kollision:
                      b[j]=b[i].Verein(b[j]);        // Vereinigung
              } }
              DeleteObject(SelectObject(hdc, hOldBrush));
            }
            EndPaintGdi(hWnd); DestroyWindow(hWnd);  // Stop der gdi-Anwendung
            return 0;
    case WM_DESTROY:
            PostQuitMessage(0); return 0;
    default: return DefWindowProc(hWnd, uiMessage, wParam, lParam);
  }
}
TBlase:: TBlase() // Konstruktor 
{ x=random(W_BREIT-2*A_GROESSE-10)+A_GROESSE;
  y=random(W_HOCH-2*A_GROESSE-24)+A_GROESSE;
  r=A_GROESSE; c=random(256)*0x10000+random(256)*0x100+random(256);
}
void TBlase::Zeichnen(void) 	// Definitionen zu den externen Methoden
{ Circle(x,y,r,c);
}
void TBlase:: Moving(void)
{ switch(random(4))
  { case 0: vx--;break;
    case 1: vx++;break;
    case 2: vy--;break;
    case 3: vy++;break;
  }
  if(((x+vx+r)<W_BREIT)&&((x+vx)>r))x+=vx;else vx=-vx;
  if(((y+vy+r)<W_HOCH)&&((y+vy)>r))y+=vy;else vy=-vy;
  Zeichnen();
}
bool TBlase::CollDetect(TBlase bls)
{ if(sqrt((x-bls.x)*(x-bls.x)+(y-bls.y)*(y-bls.y))<(r+bls.r))
    return true;
  else return false;
}
TBlase TBlase::Verein(TBlase bls)
{ x=(x+bls.x)/2; y=(y+bls.y)/2;
  vx=vy=0; r=sqrt(r*r+bls.r*bls.r);
  c=(c+bls.c)/2;
  bls=b[--bzahl];
  return bls;
}
/* Liste der newgdi-Funktionen
void Circle(unsigned short x,unsigned short y,unsigned short r);
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
void Stift(long col, short d);  */

