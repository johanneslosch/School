/*
    blend2.c

    - Zeichnet transparente Polygone in verschiedenen Blending-Modi.

    - q-Taste:  Programmabbruch
    - x-Taste:  Gitter-Hintergrund ein/aus
    - a-Taste:  alle Polygone zeichnen oder nur eines
    - < > - Tasten (oder , . - Tasten):
                Polygone verkleinern oder vergrößern
    - 1,2,3,4,5 - Tasten:
                verschiedene Blending-Modi.


    > Der Experimentierlust sind keine Grenzen gesetzt...
*/




# include       <stdio.h>
# include       <stdlib.h>
# include       <math.h>
# include       <GL/glut.h>




static GLuint   hintergrund_objekt,
                vordergrund_objekt;



static void     erzeuge_objekt_listen (void)
/******************************************/
{
    int         i,
                n_streifen = 20;

    hintergrund_objekt = glGenLists (1);
    glNewList (hintergrund_objekt, GL_COMPILE);
        for (i = -2; i < n_streifen + 2; i ++)
        {
            float hell = ((i + 2) % 4) / 3.5;
            glColor3f (hell, hell, hell);
            glRectf (-1, (i + 0.25) / (float) n_streifen,
                      8, (i + 1.15) / (float) n_streifen);
        }
    glEndList ();

    vordergrund_objekt = glGenLists (1);
    glNewList (vordergrund_objekt, GL_COMPILE);
        glBegin (GL_QUADS);
            glColor4f  (0.5, 1, 0.5, 0);
            glVertex2f (0, 0);
            glColor4f  (1.0, 1, 0.0, 0);
            glVertex2f (1, 0);
            glColor4f  (1.0, 1, 0.0, 1);
            glVertex2f (1, 1);
            glColor4f  (0.5, 1, 0.5, 1);
            glVertex2f (0, 1);
        glEnd ();
    glEndList ();
}


static void     display_func (void)
/*********************************/
{
    int         i, j,
                anzahl;

    /* printf ("display_func()\n"); */

    glLoadIdentity ();
    gluOrtho2D (-1, 8, -0.1, 1.1);

    glClearColor (0, 0, 0, 0);
    glClear (GL_COLOR_BUFFER_BIT);

    glCallList (hintergrund_objekt);

    /* 1. Ohne blending */
    glCallList (vordergrund_objekt);

    glEnable (GL_BLEND); /* Ab jetzt: alles mit blending */

    /* 2. Blending ohne Alpha: Additive Überlagerung */
    glBlendFunc (GL_ONE, GL_ONE);
    glTranslatef (2, 0, 0);
    glCallList (vordergrund_objekt);

    /* 3. normales Alpha-Blending */
    glBlendFunc (GL_SRC_ALPHA, GL_ONE_MINUS_SRC_ALPHA);
    glTranslatef (2, 0, 0);
    glCallList (vordergrund_objekt);

    /* 4. Maskierung (Multiplikation */
    glBlendFunc (GL_ZERO, GL_SRC_COLOR);
    glTranslatef (2, 0, 0);
    glCallList (vordergrund_objekt);


    glDisable (GL_BLEND);   /* Blending wieder ausschalten! */

    glutSwapBuffers ();
    glutReportErrors ();
}



static void     keyboard_func (unsigned char key, int x, int y)
/*************************************************************/
{
    /* switch (key) */
    /* { */
        /* case 'q': */
        /* case 'Q': */
            exit (0);
    /* } */

    glutPostRedisplay ();
}


extern int      main (int argc, char **argv)
/******************************************/
{
    glutInit (&argc, argv);
    glutInitDisplayMode (GLUT_RGB | GLUT_DOUBLE);

    glutInitWindowPosition (200, 100);
    glutInitWindowSize (600, 600);
    glutCreateWindow ("blend2");

    glutDisplayFunc (display_func);
    glutKeyboardFunc (keyboard_func);

    erzeuge_objekt_listen ();

    glutMainLoop ();

    return 0;
}


