// Thomas Cassebaum, 18.9.2008, all rights reserved
#include <iostream.h>
#define A_SPEED 2               		// Bewegungsrastereinstellung nicht entfernen!
#include <algeo.h>
int main(int argc, char **argv) 		// Kommandozeilenargumente
{
	glutInit(&argc, argv);           	// GLUT + ALGEO initialisieren
	A_Init("Antialias",A_PERSP,4,8); 	// A_ORTHO, Axunits, Axdicke
	return 0;
}
void justify()				    		// Justieren des Grafikfensters
{
	A_sy+=0.5; A_1=0x10;				// Parameter A_1 auf Startwert setzen
}
void display(void)						// Rendern der Bildelemente
{
	A_Model(A_NIGHT);           		// Modelltyp festlegen (auch: A_BOOK, A_DARK)
	GLfloat Gelb[4] =A_YELLOW;			// Farbe Gelb, undurchsichtig (RGBA-Darstellung)
    GLfloat Weiss[4] =A_WHITE;			// Farbe Weiß, undurchsichtig (RGBA-Darstellung)
    // 2D-Primitive mit GL_LINE_STRIP, GL_POLYGON, GL_QUADS, GL_LINE_LOOP
	float a=.1f*(A_1)+.2f;          	// Darstellungsgröße a aus A_1 berechnen
	A_MatColor(Gelb);               	// Materialfarbe setzen
	glLineWidth(1.f);               	// Linienstärke
	glBegin(GL_LINE_LOOP);
	glVertex2f (-2.25f*a,-a);glVertex2f (-.25f*a,-a); // 1.u.2.Eckpunkt
	glVertex2f (-.25f*a,a); glVertex2f (-2.25f*a,a);  // 3.u.4.Eckpunkt
	glEnd ();
	glBegin(GL_LINE_LOOP);
	glVertex2f (2.25f*a,-a); glVertex2f (.25f*a,-a);  // 1.u.2.Eckpunkt
	glVertex2f (.25f*a,a);   glVertex2f (2.25f*a,a);  // 3.u.4.Eckpunkt
	glEnd ();

	glBegin(GL_QUADS);  							// Definition einer vierseitigen Fläche
	glTexCoord2f(0.0,0.0); glVertex3f(1.0,2.5,1.5);
	glTexCoord2f(0.0,0.0); glVertex3f(1.0,2.5,1.5);
    glTexCoord2f(0.0,0.0); glVertex3f(1.0,2.5,1.5);
	glEnd();

	GLfloat S[]={-1.75f*a,-.25f*a,0.f}, D[]={1.f*a,.5f*a,0.f};
	A_Line(S,D,Weiss,2.f+A_1);

	A_Coord();          							// Koordinatensystem (Axunits, Negativ, Scaling, xyz)
}


