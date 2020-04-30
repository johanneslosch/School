#include <GL/glut2.h> 

/* Scherungsfaktoren in x- und y-Richtung */ 
#define SHX 0.25 
#define SHY 0.25 

/* Scherungs-Matrizen */ 
const GLfloat SCHERUNG_X[]={  1, 0, 0, 0, 
			      SHX, 1, 0, 0, 
			      0, 0, 1, 0, 
			      0, 0, 0, 1 };

const GLfloat SCHERUNG_Y[]={  1,SHY, 0, 0, 
			      0,  1, 0, 0, 
			      0,  0, 1, 0,
			      0,  0, 0, 1 }; 

void zeichne(); /* Zeichenfunktion */ 

int main(int argc, char **argv) { 
  /* GLUT initialisieren */ 
  glutInit(&argc, argv); 
  glutInitDisplayMode(GLUT_RGB|GLUT_SINGLE); 
  /* Fenster anlegen */ 
  glutInitWindowSize(400, 300); 
  glutCreateWindow("Scherungsdemo"); 
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
  /* Bildschirm loeschen */ 
  glClear(GL_COLOR_BUFFER_BIT); 
  /* Trennlinien zeichnen */ 
  glBegin(GL_LINES); 
    glColor3f(1, 1, 1); 
    glVertex2f(-8, 0); 
    glVertex2f( 8, 0); 
    glVertex2f( 0, -6); 
    glVertex2f( 0, 6); 
  glEnd(); 
  /* Farbe der Rechtecke */ 
  glColor3f(1, 1, 0); 
  /* Original zeichnen */ 
  glPushMatrix(); 
    glTranslatef(-4, 3, 0); 
    glRectf(-1.5, -1.0, 1.5, 1.0); 
  glPopMatrix(); 
  /* Scherung nach x zeichnen */ 
  glPushMatrix(); 
    glTranslatef( 4, 3, 0); 
    glMultMatrixf(SCHERUNG_X); 
    glRectf(-1.5, -1.0, 1.5, 1.0); 
  glPopMatrix(); 
  /* Scherung nach y zeichnen */ 
  glPushMatrix(); 
    glTranslatef(-4, -3, 0); 
    glMultMatrixf(SCHERUNG_Y); 
    glRectf(-1.5, -1.0, 1.5, 1.0); 
  glPopMatrix(); 
  /* Scherung nach x und y zeichnen */ 
  glPushMatrix(); 
    glTranslatef( 4, -3, 0); 
    glMultMatrixf(SCHERUNG_X); 
    glMultMatrixf(SCHERUNG_Y); 
    glRectf(-1.5, -1.0, 1.5, 1.0); 
  glPopMatrix(); 
  /* Zeichenschritte ausfuehren */ 
  glFlush(); 
} 
