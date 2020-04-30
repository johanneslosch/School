// Wuerfel Ortho Modell BOOK
#include <iostream.h>
#define A_SPEED .5f                     // Bewegungsgeschwindigkeit der ALGEO-Basisfunktionalität
#include <algeo.h>
void display()							// Renderfunktion 
{   A_Model(A_BOOK);
    A_Coord();
    TextAus(vect(-10,4,4),"Orthogonales Modell",vect(DUNKELBLAU));
    TextAus(vect(-10,3.5,4),"eines Wuerfels",vect(DUNKELBLAU));
//  Wuerfel(Mittelpunkt,Richtung,FlächenFarbe,Linienfarbe,Seitenlänge,Liniendicke)
    Wuerfel(vect(ZERO),vect(1,0,0),vect(0.0,0.0,1.0,0.1),vect(SCHWARZ),8,2);
}
void justify()							// Initialisierungsfunktion
{}
int main(int argc, char** argv) 		// Hauptfunktion mit Kommandozeilenparametern
{	glutInit(&argc, argv);				// Initialsierung der GLUT-Bibliothek
	A_Init("Würfel",A_ORTHO,6);
	return 0;							// Beenden des C++-Programmes, RC = 0
}