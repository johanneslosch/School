#include <GL/glut2.h> 
void zeichne(); /* Zeichenfunktion */ 

int main(int argc, char **argv) { 
  /* GLUT initialisieren */ 
  glutInit(&argc, argv); 
  glutInitDisplayMode(GLUT_RGB|GLUT_SINGLE); 
  /* Fenster anlegen */ 
  glutInitWindowSize(400, 300); 
  glutCreateWindow("Standardtransformationen"); 
  /* Weltkoordinatensystem festlegen */ 
  glMatrixMode(GL_PROJECTION); 
  gluOrtho2D(-8, 8, -6, 6); 
  glMatrixMode(GL_MODELVIEW); 
  /* Zeichenfunktion festlegen */ 
  glutDisplayFunc(zeichne); 
  /* GLUT-Hauptschleife aufrufen */ 
  glutMainLoop(); 
  return 0; 
} 

/* Zeichenfunktion */ 
void zeichne() { 
  glClear(GL_COLOR_BUFFER_BIT); // Bildschirm loeschen 
  glBegin(GL_LINES);            // Trennlinien zeichnen
    glColor3f(1, 1, 1);         // Linienfarbe weiß
    glVertex2f(-8, 0);  glVertex2f( 8, 0); // x-Achse
    glVertex2f( 0, -6); glVertex2f( 0, 6); // y-Achse
  glEnd();  
// ------------------------------> Original zeichnen 
  glColor3f( 1, 1, 0);          // Rechteckfarbe gelb 
  glPushMatrix(); 
    glTranslatef(-4, 3, 0); 
    glRectf(-1.5, -1.0, 1.5, 1.0); 
  glPopMatrix(); 
// -------------> Translation um 1 in x-/y- Richtung 
  glColor3f( 1, 0, 0); 
  glPushMatrix(); 
    glTranslatef( 4, 3, 0); 
    glTranslatef( 1, 1, 0); 
    glRectf(-1.5, -1.0, 1.5, 1.0); 
  glPopMatrix(); 
// ------------------------> Rotation um 45ø z-Achse 
  glColor3f( 0, 1, 1); 
  glPushMatrix(); 
    glTranslatef(-4, -3, 0); 
   glRotatef(45, 0, 0, 1); 
    glRectf(-1.5, -1.0, 1.5, 1.0); 
  glPopMatrix(); 
// --------> Skalierung um den Faktor 2 in x-Richtung 
  glColor3f( 1, 0, 1); 
  glPushMatrix(); 
    glTranslatef( 4, -3, 0); 
    glScalef( 2, 1, 1); 
    glRectf(-1.5, -1.0, 1.5, 1.0); 
  glPopMatrix(); 
// ----------------------> Zeichenschritte ausfuehren 
  glFlush(); 
} 
