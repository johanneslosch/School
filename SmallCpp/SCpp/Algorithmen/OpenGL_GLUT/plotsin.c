#include <stdio.h> 
#include <math.h> 
#include <GL/glut2.h> 

const GLfloat Df[]={-2*M_PI, 2*M_PI}; /* Definitionsbereich */ 
const GLfloat Wf[]={-2, 2};	      /* Wertebereich */ 
const GLfloat dx=0.1;		      /* Schrittweite */ 
GLfloat f(GLfloat x);		      /* Funktion f(x) */ 

void plotfunc();		      /* Zeichenfunktion */ 

int main(int argc, char **argv) { 
  /* GLUT initialisieren */ 
  glutInit(&argc, argv); 
  glutInitDisplayMode(GLUT_RGB|GLUT_SINGLE); 
  /* Fenster anlegen */ 
  glutInitWindowSize(400, 300); 
  glutCreateWindow("Funktionsplotter"); 
  /* Weltkoordinatensystem festlegen */ 
  glMatrixMode(GL_PROJECTION); 
  gluOrtho2D(Df[0], Df[1], Wf[0], Wf[1]); 
  /* Zeichenfunktion festlegen */ 
  glutDisplayFunc(plotfunc); 
  /* GLUT-Hauptschleife aufrufen */ 
  glutMainLoop(); 
  return 0; 
} 

/* Funktion f(x) */ 
GLfloat f(GLfloat x) { 
  return sin(x); 
} 

/* Zeichenfunktion */ 
void plotfunc() { 
  GLfloat x, y; 
  /* Fensterinhalt loeschen */ 
  glClear(GL_COLOR_BUFFER_BIT); 
  /* Koordinatenkreuz zeichnen */ 
  glBegin(GL_LINES); 
    glColor3f(1, 1, 1); 
    glVertex2f(Df[0], 0); 
    glVertex2f(Df[1], 0); 
    glVertex2f( 0, Wf[0]); 
    glVertex2f( 0, Wf[1]); 
  glEnd(); 
  /* f(x) zeichnen */ 
  glBegin(GL_LINE_STRIP); 
    glColor3f(0.2, 0.2, 1.0); 
    for (x=Df[0]; x<=Df[1]+dx; x+=dx) { 
      y=f(x); 
      glVertex2f(x, y); 
    } 
  glEnd(); 
  /* Zeichenfunktionen ausfuehren */ 
  glFlush(); 
} 
