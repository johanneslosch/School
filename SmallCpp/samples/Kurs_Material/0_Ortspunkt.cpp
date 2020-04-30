// Wuerfel Persp Modell NIGHT
#include <iostream.h>
#include <algeo.h>
void display()							// Renderfunktion 
{ A_Model(A_BOOK);
  A_Coord();
  TextAus(vect(0,4,4),"Der OrtsPunkt",vect(DUNKELBLAU));
  TextAus(vect(0,3.7,4),"( 3 | 2.5 | 4 )",vect(DUNKELROT));
// Würfel(Mittelpunkt,Richtung,FlächenFarbe,Linienfarbe,Seitenlänge,Liniendicke)
  Ortsvektor(vect(3,2.5,4),vect(ROT),5);
}
void justify()							// Initialisierungsfunktion
{ A_Positiv = true;
  A_theta-=.15; A_phi-=.4;
  A_HelpLines=true;
  A_yPlane=true;
  A_sy-=.6;
}
int main(int argc, char** argv) 		// Hauptfunktion mit Kommandozeilenparametern
{	glutInit(&argc, argv);				// Initialsierung der GLUT-Bibliothek
	A_Init("Ortspunkt",A_PERSP,5);
	return 0;							// Beenden des C++-Programmes, RC = 0
}