// Wuerfel Persp Modell NIGHT
#include <iostream.h>
#define A_SPEED .5f                     // Bewegungsgeschwindigkeit der ALGEO-Basisfunktionalität
#include <algeo.h>
void display()							// Renderfunktion 
{ A_Model(A_NIGHT);
  A_Coord();

  TextAus(vect(-10,4,4),"Perspektivisches Modell",vect(GELB));
  TextAus(vect(-10,3.5,4),"eines Wuerfels",vect(GELB));
// Würfel(Mittelpunkt,Richtung,FlächenFarbe,Linienfarbe,Seitenlänge,Liniendicke)
  Wuerfel(vect(ZERO),vect(1,0,0),vect(T_WEISS),vect(GELB),8,2);
}
void justify()							// Initialisierungsfunktion
{}
int main(int argc, char** argv) 		// Hauptfunktion mit Kommandozeilenparametern
{	glutInit(&argc, argv);				// Initialsierung der GLUT-Bibliothek
	A_Init("Perspektivisches Frustum",A_PERSP,6);
	return 0;							// Beenden des C++-Programmes, RC = 0
}