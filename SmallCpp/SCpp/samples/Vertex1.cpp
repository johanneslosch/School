// Thomas Cassebaum, 18.9.2008, all rights reserved
#include <iostream.h>
#include <algeo.h>
void main(int argc, char **argv)
{ glutInit(&argc, argv);           // GLUT initialisieren       
  A_Init("Vertex1",A_ORTHO,3,2);   // ALGEO initialisieren
}
void justify(void)
{ // A_zPlane=true;                // z-Ebene anzeigen
  // A_Foggy=false;                // Nebel inaktiv
  // A_Positiv=true;               // nur positiven Quadrant zeigen
  // A_phi-=M_PI/9.;               // 20° vorn nach links drehen -A_PI()...+A_PI()
  // A_theta-=M_PI/180.f*5.;       // 5° vorn nach unten drehen -A_PI()/2...+A_PI()/2.
  // A_distance+=.05f;             // entfernen -3...+3
   A_sy+=.04f;                     // nach unten schieben -1...1
  // A_sx+=.04f;                   // nach links schieben
}
void display(void)
{ A_Model(A_NIGHT);                  // Modelltyp festlegen (auch: A_BOOK, A_DARK)
  GLfloat Rot[4] ={1.f,0.f,0.f,1.f}; // Farbe Rot, undurchsichtig (RGBA-Darstellung)
  GLfloat Gelb[4]=A_YELLOW;          // Farbe Gelb, undurchsichtig (vordefiniert)
  GLfloat Hellblau[4]=A_LIGHTBLUE;   // Farbe Hellblau, undurchsichtig (vordefiniert)
  // 2D-Primitive mit GL_LINE_STRIP, GL_POLYGON, GL_QUADS
  float a=2.f;                       // Länge a: 2
  A_MatColor(Gelb);                  // Materialfarbe setzen
  glPointSize(32.f);                 // Punktgröße
  glBegin(GL_POINTS);           
    glVertex2f (-2.f*a,a/2.f);       // Punkt als Ortsvektor (x,y)
    glPointSize(16.f);               // ändert alle Punktgrößen im Vertexblock
    glVertex2f (-a,a/3.f);   
    A_MatColor(Hellblau);            // Farbe darf im Vertexblock gewechselt werden
    for(float i=0.f;i<3.f;i++) 
      glVertex2f (a/2.f*i,a*2.f/3.f);// 3 hellblaue Punkte zeichnen   
  glEnd ();
  glPointSize(64.f);                 // Punktgröße außerhalb des Blocks änderbar
  A_MatColor(Rot);
  glBegin(GL_POINTS);           
    glVertex2f (a,a/3.f);            // Punkt als Ortsvektor (x,y)
  glEnd ();
  
  A_MatColor(Rot);                   // Materialfarbe setzen
  glLineWidth(3.f);                  // Linienstärke
  glBegin(GL_LINES);           
    glVertex2f (-a,-a);   // 1.Punkt
    glVertex2f ( a, a);   // 2.Punkt
  glEnd ();
  A_MatColor(Gelb); glLineWidth(5.f);
  glBegin(GL_LINE_LOOP);           
    glVertex2f (-a,-a);   // 1.Punkt
    glVertex2f ( a,-a);   // 2.Punkt
    glVertex2f ( a, a);   // 3.Punkt
    glVertex2f (-a, a);   // 4.Punkt
  glEnd ();
  // A_Coord(5);                      // Koordinatensystem (Axunits, Negativ, Scaling, xyz)
}
