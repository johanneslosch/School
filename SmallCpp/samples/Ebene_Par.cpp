// Thomas Cassebaum, 18.9.2008, all rights reserved
#define SPEED 20.f  // lower or higher set controls movement-speed
#include <iostream.h>
#include <algeo.h>
void main(int argc, char **argv)
{ glutInit(&argc, argv);              // GLUT initialisieren       
  A_Init("vektorielle Parametergleichung zur Ebene",A_PERSP,5,6);	  // ALGEO initialisieren
}
void justify(void)
{ A_yPlane=true;                      // x-/y-/z-Ebenen anzeigen
  A_phi-=0.3;                         // nach links drehen
  A_theta-=.2;                        // vorn nach unten drehen
  A_distance-=5.;                     // der Szene nähern
  A_sy+=1.8;                          // nach unten schieben
  A_sx+=.05;                          // nach links schieben
}
void display(void)
{ A_Model(A_NIGHT);                    // Modelltyp festlegen
  vect s(1.,1.,2.),s1(1.,1.,1.999),s2(1.,1.,2.001), r(0.,1.,-3.);
  vect n=s%r;
  A_Coord(4,false);                    // Koordinatensystem 6 Grids nicht negativ
  C_Vect0(s,C_YELLOW,5.);
  C_Vector(s,r,C_RED,5.);
  C_Vector(s,n,C_GREEN,5.);
  C_Disk(s,n%r,C_T_WHITE,30.);
  C_Rhombus E1(s1,r,n,C_T_WHITE,C_T_LIGHTGREEN,4.,true);
  C_Rhombus E2(s2,r,n,C_T_WHITE,C_T_LIGHTGREEN,4.,true);
}
