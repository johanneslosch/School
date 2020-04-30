// Wuerfel Persp Modell BOOK
#include <iostream.h>					// C++ Standard-Header
#define A_SPEED .5f                     // Bewegungsgeschwindigkeit der ALGEO-Basisfunktionalität
#include <algeo.h>						// ALGEO-Header
void display()							// Renderfunktion 
{   A_Model(A_BOOK);
    A_Coord();
    TextAus(vect(-10,4,4),"Perspektivisches Modell",vect(DUNKELBLAU));
    TextAus(vect(-10,3.5,4),"eines Wuerfels",vect(DUNKELBLAU));
//  Wuerfel(Mittelpunkt,Richtung,FlächenFarbe,Linienfarbe,Seitenlänge,Liniendicke)
    Wuerfel(vect(ZERO),vect(1,0,0),vect(0.0,0.0,1.0,0.1),vect(DUNKELBLAU),8,2);
    A_Coord();
}
void justify()							// Initialisierungsfunktion
{}
int main(int argc, char** argv) 		// Hauptfunktion mit Kommandozeilenparametern
{	glutInit(&argc, argv);				// Initialsierung der GLUT-Bibliothek
	A_Init("Würfel",A_PERSP,6);
	return 0;							// Beenden des C++-Programmes, RC = 0
}