// Thomas Cassebaum, 18.9.2008, all rights reserved
#include <iostream.h>
#include <algeo.h>
void main(int argc, char **argv)
{ glutInit(&argc, argv);           // GLUT initialisieren       
  A_Init("Vertex2",A_ORTHO,6);     // ALGEO initialisieren
}
void justify()
{
}
void display(void)
{ A_Model(A_NIGHT);                // Modelltyp festlegen
  GLfloat Red[4]={1,0,0,1};        // Farbe Rot, undurchsichtig
  GLfloat Yellow[4] = A_YELLOW;    // Farbe Gelb, undurchsichtig
  GLfloat Green[4]  = A_T_GREEN;   // Farbe Gelb, durchsichtig
  glLineWidth(4.);                 // Liniendicke
  A_MatColor(Yellow);
  glBegin(GL_POLYGON);             // OpenGL-Primitive
    glVertex2f (-1,-4);     glVertex2f ( 1,-4);
    glVertex2f ( 1, 4);     glVertex2f (-1, 4);
  glEnd ();
  A_MatColor(Red);
  glBegin(GL_LINE_LOOP);           // OpenGL-Primitive
    glVertex2f (-2,-3);     glVertex2f (2 ,-3);
    glVertex2f (2 ,3 );     glVertex2f (-2, 3);
  glEnd ();
  A_MatColor(Green);
  glBegin(GL_QUADS);               // OpenGL-Primitive
    glVertex2f (-2.5,-2.5); glVertex2f (2.5 ,-2.5);
    glVertex2f ( 2.5, 2.5); glVertex2f (-2.5, 2.5);
  glEnd ();
  A_Coord(5);                      // Koordinatensystem (Axunits, Negativ, Scaling, xyz)
}
