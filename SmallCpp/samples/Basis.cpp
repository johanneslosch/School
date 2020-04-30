#define  A_SPEED 5				   // Beschleunigung durch Rastervergrößerung 
#include <iostream.h>
#include <algeo.h>
void main(int argc, char **argv)
{ glutInit(&argc, argv);           // GLUT initialisieren       
  A_Init("3D Grafik",A_ORTHO,5,5); // ALGEO initialisieren (ORTHO/PERSP)
}
// ------------------------------------------------------------------------------
void justify(void)				  
{ // ... ab hier die Starteinstellung der Statusvariablen vornehmen
//  A_theta-=.2; A_phi-=.7; 
//  A_Positiv=true; 
//  A_xPlane=A_yPlane=A_zPlane=true; 
}
//-------------------------------------------------------------------------------          
void display(void)			// Renderfunktion
{ // ... ab hier eigene Zeichnungsfunktionen eingeben
  A_Model(A_NIGHT);          // Modelltyp festlegen (auch: A_NIGHT, A_DARK)
  A_Coord(5);               // Koordinatensystem (Axunits, Negativ, Scaling, xyz)
}

/*
unsigned int Arial16;

unsigned int CreateBitmapFont(char *fontName, int fontSize)
{
    HFONT hFont;         // windows font
    unsigned int base;

    base = glGenLists(96);      // create storage for 96 characters

    if(stricmp(fontName, "symbol") == 0)
        hFont = CreateFont(fontSize, 0, 0, 0, FW_BOLD, FALSE, FALSE, FALSE, SYMBOL_CHARSET, 
            OUT_TT_PRECIS, CLIP_DEFAULT_PRECIS, ANTIALIASED_QUALITY,
            FF_DONTCARE | DEFAULT_PITCH, fontName);
    else
        hFont = CreateFont(fontSize, 0, 0, 0, FW_BOLD, FALSE, FALSE, FALSE, 
            ANSI_CHARSET, OUT_TT_PRECIS, CLIP_DEFAULT_PRECIS, 
            ANTIALIASED_QUALITY, FF_DONTCARE | DEFAULT_PITCH, fontName);

    if (!hFont) return 0;
    HDC hdc;
    SelectObject(hdc, hFont);
    wglUseFontBitmaps(hdc, 32, 96, base);

    return base;
} // CreateBitmapFont


void PrintString(unsigned int base, char *str)
{
    if((base == 0) || (str == NULL))
        return;

    glPushAttrib(GL_LIST_BIT);
        glListBase(base - 32);
        glCallLists(strlen(str), GL_UNSIGNED_BYTE, str);
    glPopAttrib();
} // PrintString

 // **** Code entnommen aus "OpenGL Game Programming" ***


char Text[] = "Hallo du da";
unsigned int Arial16;
// [...]
Arial16 = CreateBitmapFont("Arial", 16);
// [...]
// glTranslatef(x, y, z);
 glRasterPos3f(0.0f, 0.0f, 0.0f);
PrintString(Arial16, Text);


*/