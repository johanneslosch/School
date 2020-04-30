// Thomas Cassebaum, 19.3.2011, all rights reserved
// ALGEO-Template für 2D
#include <iostream>                           // Allgemeiner C++ Header
using namespace std;                          // Standard-Namensraum wählen
#include <algeo.h>                            // ALGEO-Header
void main(int argc, char **argv)
{ glutInit(&argc, argv);                      // GLUT initialisieren       
  A_Init("ALGEO 2D Grafik",A_ORTHO,6);        // ALGEO mit Titel initialisieren, A_ORTHO: orthogonal für 2D, A_PERSP: Perspektive für 3D 
}                                             // Vollbild: mit "V" umschaltbar zu einem Windows-Fenster, Standard: 6 Einheiten im Koordinatensystem                 
void justify(void)                            // Funktion "justify" (läuft genau einmal vor dem Rendern)
{ A_sy+=.5;									  // z.B. Status-Variable A_sy voreinstellen (verschiebt die Szene leicht nach unten)
}   			
void display(void)                            // Funktion "display" realisiert die Render-Schleife (läuft im Dauerzyklus) 
{ A_Model(A_BOOK);                            // Modelltyp festlegen (auch: A_BOOK, A_DARK)
  A_Coord();                                  // 2D-Koordinatensystem (lässt sich nach dem Start mit Eingabe von "C" entfernen)
  Dreieck(vect(-3,-3),vect(0,6),vect(5,3),vect(ROT),vect(GELB),10);
}
