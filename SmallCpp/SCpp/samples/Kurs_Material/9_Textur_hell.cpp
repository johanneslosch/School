/*
    texture1.c

    - Texture-Mapping, als Texture werden Zufallswerte benutzt
    - Programm-Ende durch Drücken einer beliebigen Taste


    > Was passiert, wenn man eine kleinere Textur (BREITE, HOEHE) einstellt?
      z.B. nur 8 x 8? Oder das texturierte Polygon vergrössert?

    > Welche Unterschiede kann man sehen, wenn die Parameter für
      GL_TEXTURE_MAG_FILTER und GL_TEXTURE_MIN_FILTER
      von GL_LINEAR auf GL_NEAREST gesetzt werden?
      (-> Siehe Aufruf von glTexParameteri(...).)
      Hinweis: Der GL_TEXTURE_MAG_FILTER wirkt bei Vergrößerungen,
      also wenn ein Textur-Pixel beim Rendern größer ist als ein
      Bildschirm-Pixel. Beim GL_TEXTURE_MIN_FILTER ist es umgekehrt.

    > Um bessere Bildqualität beim Verkleinern zu erzielen,
      muss man vorgefilterte Texturen benutzen (Mipmapping).
      Diese kann man von gluBuild2DMipmaps(...) automatisch
      erzeugen und laden lassen; gluBuild2DMipmaps(...) ersetzt
      dann den Aufruf von glTexImage2D(...). Die Parameter
      sind ähnlich, genaues steht in der man-Page zu gluBuild2DMipmaps.
      Als GL_TEXTURE_MIN_FILTER muss dann z.B. GL_LINEAR_MIPMAP_LINEAR
      verwendet werden; mehr steht in der man-Page zu glTexParameter.

    > Was passiert, wenn das texturierte Polygon gedreht wird?
      (Wie war das mit dem Drehen bei glDrawPixels() in pixels.c?)
*/
# include       <iostream.h>
# include       <GL/glut.h>
# define        BREITE      64      
# define        HOEHE       64
static void     display()
{   GLubyte     pixels[HOEHE][BREITE][3];
    int         i,n = 8,h, b;
    float       x, y,phi,d;
    cout << "display()\n";
    // Textur vorbereiten
    randomize();
    for (h = 0; h < HOEHE; h ++) for (b = 0; b < HOEHE; b ++)
    {   pixels[h][b][0] = 255 * random(256);     // rot  = Zufall
        pixels[h][b][1] = 255 * random(256);     // grün = Zufall
        pixels[h][b][2] = 255 * random(256);;    // blau = Zufall
    }
    glPixelStorei(GL_UNPACK_ALIGNMENT, 1);
    glTexImage2D (GL_TEXTURE_2D, 0, GL_RGB,BREITE, HOEHE, 0,GL_RGB, GL_UNSIGNED_BYTE, pixels);
    glTexParameteri (GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_LINEAR);
    glTexParameteri (GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_LINEAR);
    glTexEnvi (GL_TEXTURE_ENV, GL_TEXTURE_ENV_MODE, GL_DECAL);
    // Rendern: 
    glLoadIdentity ();
    gluOrtho2D (-2, 2, -2, 2);
    glClearColor (1, 1, 1, 0);
    glClear (GL_COLOR_BUFFER_BIT);
    glPointSize (10);
    for (i = 0; i < n; i ++)
    {   phi = 2 * M_PI * i / (float) n;
        x = cos (phi);
        y = sin (phi);
        d =  (i + 1) / (float) n;
		glColor3f (1, 1, 0);
        glEnable (GL_TEXTURE_2D);
        glBegin (GL_QUADS);
            glTexCoord2f (    0,     0);
              glVertex2f (    x,     y);
            glTexCoord2f (    1,     0);
              glVertex2f (x + d,     y);
            glTexCoord2f (    1,     1);
              glVertex2f (x + d, y + d);
            glTexCoord2f (    0,     1);
              glVertex2f (    x, y + d);
        glEnd ();
        glDisable (GL_TEXTURE_2D);
        glColor3f (0, 0, 0);
        glBegin (GL_POINTS);
            glVertex2f (x, y);
        glEnd ();
    }
    glFlush ();
    glutReportErrors ();
}
static void     keyboard (unsigned char key, int x, int y)
{   printf ("keyboard_func (key='%c', x=%d, y=%d)\n", key, x, y); 
    exit (0);
}
extern int      main (int argc, char **argv)
{   glutInit (&argc, argv);
    glutInitDisplayMode (GLUT_RGB);
    glutInitWindowPosition (200, 100);
    glutInitWindowSize (600, 600);
    glutCreateWindow ("texture1");
    glutDisplayFunc (display);
    glutKeyboardFunc (keyboard);
    glutMainLoop ();
    return 0;
}