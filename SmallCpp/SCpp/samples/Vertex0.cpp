// Thomas Cassebaum, 18.9.2008, all rights reserved
#include <iostream.h>
#include <algeo.h>
void main(int argc, char **argv)
{ glutInit(&argc, argv);            // GLUT initialisieren       
  A_Init("2D Grafik",A_ORTHO);      // ALGEO initialisieren                  
}
void justify(void){ A_sy+=.03f; }   // Justieren des Fensters
void display(void)
{ A_Model(A_NIGHT);                 // Modelltyp festlegen (auch: A_BOOK, A_DARK)
  GLfloat Rot[4] ={1.f,0.f,0.f,1.f};// Farbe Rot, undurchsichtig (RGBA-Darstellung)
  GLfloat Gelb[4]=A_YELLOW;         // Farbe Gelb, undurchsichtig (vordefiniert)
  // 2D-Primitive mit GL_LINE_STRIP, GL_POLYGON, GL_QUADS
  float a=4.f;                      // Länge a: das Dreifache einer LE (Längeneinheit)
  A_MatColor(Rot);                  // Materialfarbe setzen
  glBegin(GL_QUADS);           
    glVertex2f (-a,-a); glVertex2f ( a,-a);  // 1.u.2.Eckpunkt
    A_MatColor(Gelb);                        // Materialfarbe setzen
    glVertex2f ( a, a); glVertex2f (-a, a);  // 3.u.4.Eckpunkt
  glEnd ();
  A_Coord(3);                       // Koordinatensystem (Axunits, Negativ, Scaling, xyz)
}
