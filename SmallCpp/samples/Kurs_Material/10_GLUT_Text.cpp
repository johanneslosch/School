/*    gluttext.c
    - Glut-Funktionen zum Rendern von Text, zeigt die von Glut
      bereitgestellten Bitmap- und Stroke(Vektor)-Fonts.
    - Programm-Ende durch Drücken einer Taste.
*/
# include       <stdio.h>
# include       <stdlib.h>
# include       <math.h>
# include       <GL/glut.h>
static void     bitmap_text (float x, float y, float z,
                             void *font, const char *text)
/********************************************************/
{    glRasterPos3f (x, y, z);
    while (*text)
    {
        glutBitmapCharacter (font, *text);
        text ++;
    }
}
static void stroke_text (float x, float y, float z, float scale,
                        void *font, const char *text)
/********************************************************/
{    glPushMatrix ();
        glTranslatef (x, y, z);
        glScalef (0.002 * scale, 0.002 * scale, 1);
        while (*text)
        {   glutStrokeCharacter (font, *text);
            text ++;
        }
    glPopMatrix();
}
static void     display_func (void)
/*********************************/
{    int         y = 11;
    /* printf ("display_func()\n"); */
    glClearColor (1, 1, 1, 0);
    glClear (GL_COLOR_BUFFER_BIT);
    glLoadIdentity ();
    gluOrtho2D (0, 12, 0, 12);
    glColor3f (0, 0, 0);
    bitmap_text (1, y --, 0, GLUT_BITMAP_8_BY_13, "Hamburg 8x13");
    bitmap_text (1, y --, 0, GLUT_BITMAP_9_BY_15, "Hamburg 9x15");
    bitmap_text (1, y --, 0, GLUT_BITMAP_TIMES_ROMAN_10, "Hamburg Times 10");
    bitmap_text (1, y --, 0, GLUT_BITMAP_TIMES_ROMAN_24, "Hamburg Times 24");
    bitmap_text (1, y --, 0, GLUT_BITMAP_HELVETICA_10, "Hamburg Helvetica 10");
    bitmap_text (1, y --, 0, GLUT_BITMAP_HELVETICA_12, "Hamburg Helvetica 12");
    bitmap_text (1, y --, 0, GLUT_BITMAP_HELVETICA_18, "Hamburg Helvetica 18");
    stroke_text (1, y --, 0, 1, GLUT_STROKE_ROMAN, "Hamburg Stroke-Roman");
    stroke_text (1, y --, 0, 2, GLUT_STROKE_ROMAN, "Hamburg Stroke-Roman");
    stroke_text (1, y --, 0, 1, GLUT_STROKE_MONO_ROMAN,
                                            "Hamburg Stroke-Mono-Roman");
    stroke_text (1, y --, 0, 2, GLUT_STROKE_MONO_ROMAN,
                                            "Hamburg Stroke-Mono-Roman");
    glFlush ();
    glutReportErrors ();
}
static void     keyboard_func (unsigned char key, int x, int y)
/*************************************************************/
{ exit (0);
}
extern int      main (int argc, char **argv)
/******************************************/
{   glutInit (&argc, argv);
    glutInitDisplayMode (GLUT_RGB);
    glutInitWindowPosition (200, 100);
    glutInitWindowSize (600, 600);
    glutCreateWindow ("points1");
    glutDisplayFunc (display_func);
    glutKeyboardFunc (keyboard_func);
    glutMainLoop ();
    return 0;
}
