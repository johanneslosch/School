  /* Schrittlänge der ALGEO-Bewegungsfunktionen einstellen
     1 - langsam/ glatt , 20 - schnell/ holprig
   
     Thomas Cassebaum, 2010, all rights reserved
  */
#define SPEED 10 
#include <iostream.h>
#include <algeo.h>
void main(int argc, char **argv) {
  /* GLUT initialisieren
     argc - int-Variable (Anzahl der Kommandozeilen-Argumente)
     argv - Zeiger Kommandozeilen-Argumente, 1.Argument: argv[0]
  */
  glutInit(&argc, argv);                      
  /* Engine initialisieren 
     Parameter 1 - perspektivisches Modell (alternativ: A_FLAT)
     		   2 - Anzahl der Achseinheiten
     		   3 - Achsenstärke 
  */
  A_Init("3D Grafik",A_PERSP,5,6);	    
}
  /* Starteinstellung der ALGEO-Zustandsvariablen
     A_xPlane	  - (Tasten xyz)  Ebenen anzeigen(true) / verstecken(false)
     A_Positiv  - (Taste P)     nur positiver Quadrant(true) / alle Quadranten(false)
     A_phi      - (Tasten A/D)  nach links drehen(Winkel verkleinern), nach rechts(vergrößern)
     A_theta	  - (Tasten W/S)  vorn nach unten drehen(verkleinern), nach oben(vergrößern)
     A_distance - (Tasten +/-)  Kameraabstand verkleinern/vergrößern
     A_sx		  - (Pfeiltasten) Kamera nach links schieben(verkleinern), nach rechts(vergrößern) 
     A_sy		  - (Pfeiltasten) Kamera nach oben schieben(verkleinern), nach unten(vergrößern)
     A_Foggy	  - (Taste F)     Nebel ein(true) / aus(false) 
  */
void justify(void) { 
  A_xPlane=A_yPlane=A_zPlane=true; A_Positiv=true;
  A_phi-=.5; A_theta-=.45; A_distance+=3.5;
  A_sx+=.05; A_sy-=1.3; A_Foggy=false;
}
  /* Rendern der Szene
     ALGEO-Funktionen A_...   z.B. A_Coord(4);
     ALGEO-Klassen	  C_...   z.B. C_Vector(...);
     OpenGl-Anweisungen gl... z.B. glPushMatrix();
      
  */
void display(void) { 
  A_Model(A_BOOK);              	       			// Modelltyp festlegen
  A_Turn(A_turn);                      			    // Wechsel der Achsenrichtungen x->z z->y y->x 
  vect Hs(0,0,4),Hr1(2.67,0,-1.33),Hr2(0,2.67,-1.33);
  vect E1s(0,0,0),E1r1(0,4,4),E1r2(4,0,4);		    // 1.Ebene Stütz-& Richtungsvektoren
  vect E2s(0,0,4),E2r1(4,0,-2),E2r2(0,4,-2);        // 2.Ebene Stütz-& Richtungsvektoren
  glPushMatrix();        
    A_Coord(4);                  			        // Koordinatensystem 4 Grideinheiten
    C_Vector(vect(2,2,2),vect(-2,-2,-2),C_T_BLUE,6);
    C_Triangle H(Hs,Hr1,Hr2,C_DARKMAGENTA,C_T_MAGENTA,1);
    C_Triangle E1(E1s,E1r1,E1r2,C_DARKGREEN,C_T_GREEN,1);
    C_Rhombus E2(E2s,E2r1,E2r2,C_DARKMAGENTA,C_T_MAGENTA,1,true);
  glPopMatrix();        
}
