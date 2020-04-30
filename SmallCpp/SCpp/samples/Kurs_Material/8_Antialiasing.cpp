/*    antialias.c
    - Zeichnet Linien mit Kantenglättung (Anti-alias).
    - Kantenglättung ein-/ausschalten mit Leertaste.
    - Programm-Ende mit q-Taste.
*/
# include       <stdio.h>
# include       <stdlib.h>
# include       <math.h>
# include       <GL/glut.h>
static int      antialias = 1;
static void     display_func (void)
/*********************************/
{ int i,n = 100;
  float phi,r = 0.9,x,y;
  // printf ("display_func()\n");
    glClearColor (1, 1, 1, 0);
    glClear (GL_COLOR_BUFFER_BIT);
    glPushAttrib (GL_ENABLE_BIT);
        if (antialias)
        {   /* Normales Alpha-Blending: */
            glBlendFunc(GL_SRC_ALPHA, GL_ONE_MINUS_SRC_ALPHA);
            glEnable(GL_BLEND);
            /* Antialias für  Linien einschalten: */
            glEnable(GL_LINE_SMOOTH);
        }
        /* Linien zeichnen: */
        glColor3f (0, 0, 0);
        glBegin (GL_LINES);
        for (i = 0; i < n; i ++)
        {   phi = 2 * M_PI * i / (float) n;
            x = r * cos (phi);
            y = r * sin (phi);
            glVertex2f (x, y);
            glVertex2f (-x, -y);
        }
        glEnd ();
    glPopAttrib ();
    glFlush ();
    glutReportErrors ();
}
static void     keyboard_func (unsigned char key, int x, int y)
/*************************************************************/
{   switch (key)
    {   case ' ':   /* Leertaste */
            if (antialias) antialias = 0;
            else antialias = 1;
            printf ("Antialias %s\n", antialias ? "ein" : "aus");
            glutPostRedisplay ();
            break;
        case 'q':
        case 'Q': exit (0);
    }
}
extern int      main (int argc, char **argv)
// *****************************************
{   glutInit (&argc, argv);
    glutInitDisplayMode (GLUT_RGB);
    glutInitWindowPosition (200, 100);
    glutInitWindowSize (600, 600);
    glutCreateWindow ("lines1");
    glutDisplayFunc (display_func);
    glutKeyboardFunc (keyboard_func);
    glutMainLoop ();
    return 0;
}
