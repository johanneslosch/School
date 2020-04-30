/*    blend2.c
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
# define        N_QUADS         20
# define        N_GITTER        8
enum {
    KEIN_BLENDING,
    ADDITIVES_BLENDING,
    ALPHA_BLENDING,
    ALPHA_HINTERGRUND,
    ALPHA_VORDERGRUND,
    MULT_BLENDING
} blending_modus;
static GLfloat  positionen[N_QUADS][2], farben[N_QUADS][3], skalierung = 2;
static int neues_bild_erzeugen = 1,gitter_zeichnen = 1,alle_zeichnen = 0;
static void     display_func (void)
/*********************************/
{   int         i, j,anzahl;
    /* printf ("display_func()\n"); */
    if (neues_bild_erzeugen)
    {   /* zufällige Farben und Positionen: */
        for (i = 0; i < N_QUADS; i ++)
        {   farben[i][0] = rand();
            farben[i][1] = rand();
            farben[i][2] = rand();
            positionen[i][0] = rand();
            positionen[i][1] = rand();
        }
        /* aber das erste genau in die Mitte: */
        positionen[0][0] = 0.5;
        positionen[0][1] = 0.5;
        neues_bild_erzeugen = 0;
    }
    glLoadIdentity ();
    gluOrtho2D (0, 1, 0, 1);
    if (gitter_zeichnen)
    {   glClearColor (0.5, 0.5, 0.5, 0);
        glClear (GL_COLOR_BUFFER_BIT);
        glColor3f (0.0, 0.0, 0.0);
        glLineWidth (15);
        glBegin (GL_LINES);
        for (i = 0; i < N_GITTER; i ++)
        { GLfloat a =  (i + 0.5) / (float) N_GITTER;
            /* vertikale Linie */
            glVertex2f (a, 0);
            glVertex2f (a, 1);
            /* horizontale Linie */
            glVertex2f (0, a);
            glVertex2f (1, a);
        }
        glEnd ();
    }
    else if (blending_modus == MULT_BLENDING)
    {   glClearColor (1, 1, 1, 0);
        glClear (GL_COLOR_BUFFER_BIT);
    }
    else
    {   glClearColor (0, 0, 0, 0);
        glClear (GL_COLOR_BUFFER_BIT);
    }
    switch (blending_modus)
    {   case KEIN_BLENDING:
            break; /* kein Blending */
        case ADDITIVES_BLENDING:
            glEnable (GL_BLEND);
            /* Blending ohne Alpha: Additive Überlagerung */
            glBlendFunc (GL_ONE, GL_ONE);
            break;
        case ALPHA_BLENDING:
            glEnable (GL_BLEND);
            /* normales Alpha-Blending */
            glBlendFunc (GL_SRC_ALPHA, GL_ONE_MINUS_SRC_ALPHA);
            break;
        case ALPHA_HINTERGRUND:
            glEnable (GL_BLEND);
            /* Alpha nur für "Hintergrund" */
            glBlendFunc (GL_ONE, GL_ONE_MINUS_SRC_ALPHA);
            break;
        case ALPHA_VORDERGRUND:
            glEnable (GL_BLEND);
            /* Alpha nur für "Vordergrund" */
            glBlendFunc (GL_SRC_ALPHA, GL_ONE);
            break;
        case MULT_BLENDING:
            glEnable (GL_BLEND);
            /* Alpha nur für "Vordergrund" */
            glBlendFunc (GL_ZERO, GL_SRC_COLOR);
            break;
        default:
            printf ("Falscher Wert (%d) für blending_modus!\n", blending_modus);
            break;
    }
    if (alle_zeichnen) anzahl = N_QUADS;
    else anzahl = 1;
    for (i = 0; i < anzahl; i ++)
    {       glPushMatrix ();
            glTranslatef (positionen[i][0], positionen[i][1], 0);
            glScalef (skalierung, skalierung, 1);
            glBegin (GL_QUADS);
                glColor4f (farben[i][0], farben[i][1], farben[i][2], 0);
                glVertex2f (-0.1, -0.2);
                glVertex2f (+0.1, -0.2);
                glColor4f (farben[i][0], farben[i][1], farben[i][2], 1);
                glVertex2f (+0.1, +0.2);
                glVertex2f (-0.1, +0.2);
            glEnd ();
        glPopMatrix ();
    }
    glDisable (GL_BLEND);   /* Blending wieder ausschalten! */
    glutSwapBuffers ();
    /* glFlush (); nicht mehr nötig, wenn glutSwapBuffers() benutzt wird. */
    glutReportErrors ();
}
static void     keyboard_func (unsigned char key, int x, int y)
/*************************************************************/
{   switch (key)
    {   case ' ':   /* Leertaste */
            neues_bild_erzeugen = 1;
            break;
        case 'x':
        case 'X':
            gitter_zeichnen = ! gitter_zeichnen;
            break;
        case 'a':
        case 'A':
            alle_zeichnen = ! alle_zeichnen;
            break;
        case ',':
        case '<':
            skalierung /= 1.1;
            break;
        case '.':
        case '>':
            skalierung *= 1.1;
            break;
        case '1':   blending_modus = KEIN_BLENDING;       break;
        case '2':   blending_modus = ADDITIVES_BLENDING;  break;
        case '3':   blending_modus = ALPHA_BLENDING;      break;
        case '4':   blending_modus = ALPHA_HINTERGRUND;   break;
        case '5':   blending_modus = ALPHA_VORDERGRUND;   break;
        case '6':   blending_modus = MULT_BLENDING;       break;
        case 'q':
        case 'Q':
            exit (0);
    }
    glutPostRedisplay ();
}
extern int      main (int argc, char **argv)
/******************************************/
{   glutInit (&argc, argv);
    glutInitDisplayMode (GLUT_RGB | GLUT_DOUBLE);
    glutInitWindowPosition (200, 100);
    glutInitWindowSize (600, 600);
    glutCreateWindow ("blend2");
    glutDisplayFunc (display_func);
    glutKeyboardFunc (keyboard_func);
    glutMainLoop ();
    return 0;
}
