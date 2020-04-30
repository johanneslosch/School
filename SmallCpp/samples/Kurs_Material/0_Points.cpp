// Erstes OpenGL-Programm mit maximaler Kommentierung 

#include <glut.h>						// Header für GLUT

void display()							// Renderfunktion 
{	glClear(GL_COLOR_BUFFER_BIT|GL_DEPTH_BUFFER_BIT); // Pufferinhalte mit Standardfarbe füllen
	glColor3f(1.0f, 0.0f, 0.0f);		// Farbe (hier: rot)
	glPointSize(10.f);					// Strichdicke (hier: 5)
	glBegin(GL_POINTS);					// Vertexblock für eine Linie
		glVertex2f( 0.5f, 0.5f);		//		Punkt 1 (hier: x=+0.5, y=+0.5f)
		glVertex2f(-0.5f,-0.5f);		//		Punkt 2 (hier: x=-0.5, y=-0.5f)
	glEnd();							// Ende des Vertex-Blockes
	glFlush();							// Warten auf das Beenden aller Operationen
	glutSwapBuffers();					// Tauscht Back- und Front-Puffer
}

void justify()							// Initialisierungsfunktion
{	glClearColor(1.0f,1.0f,1.0f,1.0f);	// Hintergrundfarben setzen (hier: weiß)
	glMatrixMode(GL_PROJECTION);		// Projektionsmatrix einstellen
	glLoadIdentity();					// Einheitsmatrix zum Beginn setzen
	glOrtho(-1.0f,1.0f,-1.0f,1.0f,0,0); // Orthogonales Frustum für 2D setzen x:-1...+1, y:-1...+1
	glMatrixMode(GL_MODELVIEW);			// Modellmatrix einstellen
}

int main(int argc, char** argv) 		// Hauptfunktion mit Kommandozeilenparametern
{	glutInit(&argc, argv);				// Initialsierung der GLUT-Bibliothek
	glutInitDisplayMode( GLUT_DOUBLE |	// Doppelter Puffer (unsichtbare Bildaufbauphase) 
	                     GLUT_DEPTH |	// Tiefenpuffer (z-Puffer) ist für 3D aktiviert
	                     GLUT_RGB);		// Farbpuffer mit Rot, Grün und Blau verwenden
	glutInitWindowSize(700, 700);		// Größe des OpenGL-Fensters [in Pixeln]
	glutInitWindowPosition(0,0);	// Position der rechten oberen Ecke des OpenGL-Fensters
	glutCreateWindow("OpenGL: Ein diagonaler Strich"); // Festlegung Bildschirmtitel
	justify();							// Initialisierungsfunktion starten
	glutDisplayFunc(display);			// Displayfunktionsnamen definieren
	glutMainLoop();						// Neustart der OpenGL-Hauptschleife
	return 0;							// Beenden des C++-Programmes, RC = 0
}