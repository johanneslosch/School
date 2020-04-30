// Koordinaten des Nikolaushauses 
#include <GL/glut2.h> 
GLint haus[][2]={{1, 1}, {3, 3}, {1, 3}, {2, 4}, {3, 3}, 
		 {3, 1}, {1, 3}, {1, 1}, {3, 1}}; 
// Anzahl der Zeichenschritte 
int schritt=9; 
void zeichneHaus();                             /* Haus zeichnen */ 
void tastatur(unsigned char key, int x, int y); /* Tastaturhandler */ 
void drawstring(char *s);                       /* Sring ausgeben */ 

int main(int argc, char **argv) { 
  /* OpenGL und GLUT initialisieren */ 
  glutInit(&argc, argv); 
  glutInitDisplayMode(GLUT_SINGLE|GLUT_RGB); 
  /* Fenster anlegen */ 
  glutInitWindowSize(250, 350); 
  glutCreateWindow("Haus vom Nikolaus"); 
  /* Ereignishandler registrieren */ 
  glutDisplayFunc(zeichneHaus); 
  glutKeyboardFunc(tastatur); 
  /* Weltkoordinatensystem festlegen */ 
  glMatrixMode(GL_PROJECTION); 
  gluOrtho2D(0.75, 3.25, 0.75, 4.25); 
  /* GLUT-Hauptschleife aufrufen */ 
  glutMainLoop(); 
  return 0; 
} 

/* Zeichenfunktion */ 
void zeichneHaus() { 
  int s; 
  glClear(GL_COLOR_BUFFER_BIT); 
  /* Zeichenposition festlegen */ 
  glRasterPos2f(0.75, 0.75); 
  /* String ausgeben */ 
  drawstring("+/-: Zeichenschritte"); 
  /* gewünschte Anzahl von Zeichenschritten ausfuehren */ 
  glBegin(GL_LINE_STRIP); 
    for (s=0; s<schritt; s++) 
      glVertex2iv(haus[s]); 
  glEnd(); 
  /* Zeichenschritte ausfhren */ 
  glFlush(); 
} 

/* Tastaturhandler */ 
void tastatur(unsigned char key, int x, int y) { 
  switch (key) { 
  case '+': 
    if (++schritt>9) 
      schritt=1; 
    break; 
  case '-': 
    if (--schritt<1) 
      schritt=9; 
    break; 
  } 
  /* Neuzeichnen veranlassen */ 
  glutPostRedisplay(); 
}

/* String im Fenster ausgeben */ 
void drawstring(char *s) { 
  int i; 
  for (i=0; s[i]!='\0'; i++) 
    glutBitmapCharacter(GLUT_BITMAP_9_BY_15, s[i]); 
}
