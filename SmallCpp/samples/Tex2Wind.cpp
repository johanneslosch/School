#include <string.h>
#include <stdio.h>
#include <glut.h>
#include <GL/gl.h>
// Windows-Parameter
#define WIDTH  600
#define HEIGHT 600
#define TITLE  "OpenGL & GLUT: Text und Unterfenster"
int winIdMain;
int winIdSub;
// Animations-Statusvariablen
#define SMALL_ANGLE  5.0
#define TIME_STEP    0.0025
static double time = 0.0;
static double spin = 0.0;
static char label[100];

// Kleinen Text an der aktuellen Position zeichnen
void drawString (char *s)
{ unsigned int i;
  for (i = 0; i < strlen (s); i++)
    glutBitmapCharacter (GLUT_BITMAP_HELVETICA_10, s[i]);
}
// Großen Text an der aktuellen Position zeichnen
void drawStringBig (char *s)
{ unsigned int i;
  for (i = 0; i < strlen (s); i++)
    glutBitmapCharacter (GLUT_BITMAP_HELVETICA_18, s[i]);
}

// Renderfunktion des Hauptfensters
void mainDisplay (void)
{ // Löschen des Grafikfensters
  glutSetWindow (winIdMain);
  glClear (GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
  glLoadIdentity ();
  /* glColor3f (1.0F, 1.0F, 1.0F);
     sprintf (label, "Thomas Cassebaum 1997");
     glRasterPos2f (-0.80F, -0.80F);
     drawString (label); */  
  // Zeichnen des rotierenden Dreiecks 
  glPushMatrix ();
  glRotatef (spin, 0.0, 0.0, 1.0);
  glBegin (GL_POLYGON);
  glColor3f (1.0F, 0.0F, 0.0F);
  glVertex2f (0.0F, 0.5F);
  glColor3f (0.0F, 1.0F, 0.0F);
  glVertex2f (-0.4330F, -0.25F);
  glColor3f (0.0F, 0.0F, 1.0F);
  glVertex2f (0.433F, -0.25F);
  glEnd ();
  glPopMatrix ();

  glutSwapBuffers ();
}
// Zweite Displayfunktion zum aktualisieren des Unterfensters
void subDisplay ()
{ // Löschen des Unterfensters
  glutSetWindow (winIdSub);
  glClearColor (0.25, 0.25, 0.25, 0.0);
  glClear (GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
  // Aufbau des Unterfenster-Rahmens
  glColor3f (0.0F, 1.0F, 0.0F);
  glBegin (GL_LINE_LOOP);
  glVertex2f (0.0F, 0.0F);
  glVertex2f (0.0F, 0.99F);
  glVertex2f (0.999F, 0.99F);
  glVertex2f (0.999F, 0.0F);
  glEnd ();
  glColor3f (1.0F, 1.0F, 1.0F);

  sprintf (label, "Zeit = %8.3f ", time);
  glRasterPos2f (0.05F, 0.65F);
  drawString (label);

  sprintf (label, "Rotationswinkel = %8.3f ", spin);
  glRasterPos2f (0.05F, 0.45F);
  drawString (label);

  sprintf (label, "Rotations-Speed = %8.3f ", spin / time);
  glRasterPos2f (0.05F, 0.25F);
  drawString (label);

  /* Type Banner and info */
  glColor3f (1.0F, 0.0F, 1.0F);
  sprintf (label, " Das ist ein Unterfenster. ");
  glRasterPos2f (0.44F, 0.60F);
  drawStringBig (label);

  sprintf (label, " Es hat einen eigenen OpenGL-Kontext ");
  glRasterPos2f (0.33F, 0.23F);
  drawStringBig (label);

  glutSwapBuffers ();
}
// Callbackfunktion zum Neuzeichnen des Hauptfensters
void mainReshape (int w, int h)
{ glViewport (0, 0, w, h);
  glMatrixMode (GL_PROJECTION);
  glLoadIdentity ();
  gluOrtho2D (-1.0F, 1.0F, -1.0F, 1.0F);
  glMatrixMode (GL_MODELVIEW);
  glLoadIdentity ();
  glutSetWindow (winIdSub);
  glutReshapeWindow (w - 10, h / 10);
  glutPositionWindow (5, 5);
  glutSetWindow (winIdMain);
}
// Callbackfunktion zum Neuzeichnen des Unterfensters
void subReshape (int w, int h)
{ glViewport (0, 0, w, h);
  glMatrixMode (GL_PROJECTION);
  glLoadIdentity ();
  gluOrtho2D (0.0F, 1.0F, 0.0F, 1.0F);
}
// Funktion der Tastaturereignisse 
void keyboard (unsigned char key, int x, int y)
{ static int info_banner = 1;
  switch (key)
  { case 'i':
    case 'I': glutSetWindow (winIdSub);
              if (info_banner) glutHideWindow (); else glutShowWindow ();
              info_banner = !info_banner; break;
    case 'q':
    case 'Q': exit (0);break;
  }
}
/* Es darf nur eine idle() Callbackfunktion geben.
   Diese idle() Funktion muss das Haupt- und alle Unter-
   fenster erneuern.
*/
void idle (void)
{ spin += SMALL_ANGLE;
  time += TIME_STEP;
  glutSetWindow (winIdMain);
  glutPostRedisplay ();
  glutSetWindow (winIdSub);
  glutPostRedisplay ();
}
int main (int argc, char **argv)
{ glutInit (&argc, argv);
  glutInitDisplayMode (GLUT_DOUBLE | GLUT_RGBA | GLUT_DEPTH);
  glutInitWindowPosition (5, 5);
  glutInitWindowSize (WIDTH, HEIGHT);
  // Hauptfester-Aufbau und Einrichtung
  winIdMain = glutCreateWindow (TITLE); 
  glutDisplayFunc (mainDisplay);
  glutReshapeFunc (mainReshape);
  glutKeyboardFunc (keyboard);
  glutIdleFunc (idle);
  // Unterfenster-Aufbau und Einrichtung
  winIdSub = glutCreateSubWindow (winIdMain, 5, 5, WIDTH - 10, HEIGHT / 10);
  glutDisplayFunc (subDisplay);
  glutReshapeFunc (subReshape);
  glutMainLoop ();
  return 0;
}
