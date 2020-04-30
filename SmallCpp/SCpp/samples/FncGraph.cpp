#define  A_SPEED 2					// Beschleunigung durch Rastervergrößerung 
#include "string.h"					// Header für die Stringfunktionen
#include <iostream.h>
#include <algeo.h>
void main(int argc, char **argv)
{ glutInit(&argc, argv);          	// GLUT initialisieren
  A_Init("3D Grafik",A_ORTHO,5,5);	// ALGEO initialisieren (ORTHO/PERSP)
}
// ------------------------------------------------------------------------------
void justify(void)				  
{ // ... ab hier die Starteinstellung der Statusvariablen vornehmen
  A_sy+=.3;	                		// Kamera näher führen
  A_zPlane=true; A_1=0; A_2=0;	// z-Gatter zeigen, Variablen A_0 und A_1 initialisieren
  A_Foggy=false;					      // Nebel abschalten
}
float A_f1(float x) {return (x+A_1)*(x+A_1)+A_2;};
float A_f2(float x) {return 0.2*x*x*x;};
//-------------------------------------------------------------------------------          
GLfloat rot[]=A_RED, blau[]=A_BLUE;
void display(void)			// Renderfunktion
{ // ... ab hier eigene Zeichnungsfunktionen eingeben
  A_Model(A_BOOK);          // Modelltyp festlegen (auch: A_NIGHT, A_DARK)
  A_Coord(5);               // Koordinatensystem (Axunits, Negativ, Scaling, xyz)
  A_Func2D1(-12,12,rot,6);
  A_Func2D2(-12,12,blau,.06);
  GLfloat P[]={6,2};
  char s[2],t[2],e[20] = "f(x) = (x"; int a1=A_1,a2=A_2;
  if(a1 <0){strcat(e,"-"); a1=-a1;} else strcat(e,"+"); s[1]=t[1]=NULL; s[0]=0x30+a1; strcat(e,s); strcat(e,")*(x"); 
  if(A_1<0) strcat(e,"-"); else strcat(e,"+"); strcat(e,s);strcat(e,")"); 
  if(a2 <0){strcat(e,"-"); a2=-a2;} else strcat(e,"+"); t[0]=0x30+a2; strcat(e,t); 
  A_MatColor(blau);
  //A_TextOut(P,e); P[0]-=9.5; P[1]-=7.6;
  //A_TextOut(P,"Mit den Tasten 1, Shift/1, 2, Shift/2 die Parameter steuern!");
}