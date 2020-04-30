#include <GL/glut2.h> 

/* Rotationswinkel um die jeweiligen Achsen */ 
GLfloat rotx=0, roty=0, rotz=0; 

void init();     /* Initialisierung */ 
void wuerfel();  /* W�rfel zeichnen */ 
void zeichnen(); /* Zeichenfunktion */ 
void animiere(); /* W�rfel animieren */ 

int main(int argc, char **argv) { 
  /* OpenGL und GLUT initialisieren */ 
  glutInit(&argc, argv); 
  /* Ben�tigt werden ein RGB-Bild mit Tiefenpuffer und Doppelpufferung 
   * zur Vermeidung von Bildschirmflackern 
   */ 
  glutInitDisplayMode(GLUT_RGB|GLUT_DEPTH|GLUT_DOUBLE); 
  /* Fenster �ffnen */ 
  glutInitWindowSize(400, 400); 
  glutCreateWindow("Farbw�rfel"); 
  /* Ausgabe vorbereiten */ 
  init(); 
  /* Zeichenfunktion festlegen */ 
  glutDisplayFunc(zeichnen); 
  /* Animationsfunktion festlegen */ 
  glutIdleFunc(animiere); 
  glutMainLoop(); 
  return 0; 
} 

/* Initialisierung */ 
void init() { 
  /* Tiefentest einschalten */ 
  glEnable(GL_DEPTH_TEST); 
  /* weiche Farbverl�ufe einschalten */ 
  glShadeModel(GL_SMOOTH); 
  /* Blickwinkel einrichten */ 
  glMatrixMode(GL_PROJECTION); 
  gluPerspective(40, 1, 1, 10); 
  gluLookAt(3, 0, 0, 0, 0, 0, 0, 1, 0); 
  glMatrixMode(GL_MODELVIEW); 
  /* W�rfel erzeugen und in Liste abspeichern */ 
  glNewList(1, GL_COMPILE); 
  glTranslatef(-0.5, -0.5, -0.5); 
  wuerfel(); 
  glEndList(); 
} 

/* erzeugt einen Farbw�rfel */ 
void wuerfel() { 
  glBegin(GL_QUADS); 
    /* Boden */ 
    glColor3f(0, 0, 0); 
    glVertex3i(0, 0, 0); 
    glColor3f(0, 1, 0); 
    glVertex3i(0, 1, 0); 
    glColor3f(1, 1, 0); 
    glVertex3i(1, 1, 0); 
    glColor3f(1, 0, 0); 
    glVertex3i(1, 0, 0); 
    /* Deckel */ 
    glColor3f(0, 0, 1); 
    glVertex3i(0, 0, 1); 
    glColor3f(1, 0, 1); 
    glVertex3i(1, 0, 1); 
    glColor3f(1, 1, 1); 
    glVertex3i(1, 1, 1); 
    glColor3f(0, 1, 1); 
    glVertex3i(0, 1, 1); 
  glEnd(); 
  glBegin(GL_QUAD_STRIP); 
    /* Mantel */ 
    glColor3f(0, 0, 0); 
    glVertex3i(0, 0, 0); 
    glColor3f(0, 0, 1); 
    glVertex3i(0, 0, 1); 
    glColor3f(1, 0, 0); 
    glVertex3i(1, 0, 0); 
    glColor3f(1, 0, 1); 
    glVertex3i(1, 0, 1); 
    glColor3f(1, 1, 0); 
    glVertex3i(1, 1, 0); 
    glColor3f(1, 1, 1); 
    glVertex3i(1, 1, 1); 
    glColor3f(0, 1, 0); 
    glVertex3i(0, 1, 0); 
    glColor3f(0, 1, 1); 
    glVertex3i(0, 1, 1); 
    glColor3f(0, 0, 0); 
    glVertex3i(0, 0, 0); 
    glColor3f(0, 0, 1); 
    glVertex3i(0, 0, 1); 
  glEnd(); 
} 

/* Zeichenfunktion */ 
void zeichnen() { 
  /* sowohl Farb- als auch Tiefenpuffer l�schen */ 
  glClear(GL_COLOR_BUFFER_BIT|GL_DEPTH_BUFFER_BIT); 
  /* W�rfel aufrufen */ 
  glCallList(1); 
  /* neues Bild zeigen */ 
  glutSwapBuffers(); 
} 

/* W�rfel animieren */ 
void animiere() { 
  /* Rotationswinkel erh�hen */ 
  rotx+=1; 
  roty+=2; 
  rotz+=3; 
  /* Neue Transformationsmatrix erzeugen */ 
  glMatrixMode(GL_MODELVIEW); 
  glLoadIdentity(); 
  glRotatef(rotx, 1, 0, 0); 
  glRotatef(roty, 0, 1, 0); 
  glRotatef(rotz, 0, 0, 1); 
  /* Neuzeichnen veranlassen */ 
  glutPostRedisplay(); 
} 
