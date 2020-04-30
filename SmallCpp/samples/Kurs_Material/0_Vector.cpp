// Thomas Cassebaum, 18.9.2008, all rights reserved
// ALGEO - default template
#define rot vect(ROT)
#define blau vect(BLAU)
#define schwarz vect(SCHWARZ)
#define SPEED 2.f                              // Bewegungsgeschwindigkeit der ALGEO-Basisfunktionalität
#include <iostream.h>                          // C++   header
#include <algeo.h>                             // ALGEO header
using namespace std;			               // Standard-Namensraum wählen
void main(int argc, char **argv)               // Hauptfunktion mit CMD-Line-Argumenten
{ glutInit(&argc, argv);                       // GLUT mit CMD-Line-Argumenten initialisieren        
  A_Init("Ortsvektor");	                   	   // ALGEO mit Fenstertitel initialisiern
}
void justify(void)                             // Einstellen der Statusvariablen von ALGEO (Veränderungen an den Standardvorgaben)
{ A_phi-=M_PI/4;                               // um Pi/3=45° nach links drehen
  A_theta-=M_PI/180*12;                        // um 12° nach unten drehen 
  A_xPlane=A_yPlane=A_zPlane=true;		       // Koordinatenebenen der zeigen
  A_Positiv=true;							   // nur den positiven Quadranten zeigen
  A_HelpLines=true;							   // Hilfslinien zum Vektor zeigen
  
  A_1=3; A_2=2; A_3=4;						   // Startwerte für die x,y,z-Koordinaten des Vektors v-> 
}
void display(void)
{ A_Model(A_BOOK);                             // Fenster zeigen, Modell "BOOK"
  vect v(A_1,A_2,A_3);                         // Vektor v->
  char T[100];								   // Textvariable
  strcpy(T,"Punktkoordinaten: ");
  strcat(T,v.vectstr());                       // Vektortext bilden
  TextAus(vect(-14,8,4),"Punktwerte verringern mit Gross 1(x),2(y),3(z)",schwarz);    
  TextAus(vect(-14,8.5,4),"xyz-Punktwerte erhoehen mit 1(x),2(y),3(z)",schwarz);    
  TextAus(vect(-14,9,4),"Hilfslinien de- oder re-aktivieren mit H und L",schwarz);    
  TextAus(vect(-14,9.5,4),"alle/ nur positive Quadranten aktivieren mit P",schwarz);    
  TextAus(vect(-14,10,4),"Koordinatenebenen aktivieren mit X,Y oder Z",blau);
  TextAus(vect(-14,7,4),T,rot);                // Textobjekt erzeugen
  Ortsvektor(v,rot,6);				           // Zeichne den Ortssvektor von v->
  Punkt(v,blau,3);						       // Zeichne den Punkt als Fadenkreuz
  A_Coord();								   // Zeichne das Koordinatensystem
  GLfloat black[4]=A_BLACK;					   // Startfarbe einstellen
  A_MatColor(black);
}
