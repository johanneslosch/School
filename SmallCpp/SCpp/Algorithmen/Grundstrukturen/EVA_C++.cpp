/* Th.Cassebaum 2004, all rights reserved
   E-V-A Eingabe-Verarbeitung-Ausgabe (C++) 
   Geschwindigkeitsberechnung
*/
#include <iostream>          // Header für cout,cin (ohne .h!)
using namespace std;         // std zum Namensraum bestimmen
int main()                   // Hauptfunktion nach ANSI-Standard
{ double s,t,v;              // Variablendefinition für reelle s,t,v
  // *** Eingabe **********  // Kommentar 
  cout << "Weg [m]: ";       // Ausgabe der Eingabeaufforderung für den Weg
  cin  >> s;                 // Eingabe als reelle Zahl
  cout << "Zeit[s]: ";       // Ausgabe der Eingabeaufforderung für die Zeit
  cin  >> t;                 // Eingabe als reelle Zahl
  // *** Verarbeitung *****  // Kommentar
  v = s/t;                   // Ergebniserrechnung
  // *** Ausgabe **********  // Kommentar
  cout << "\n\nGeschwindigkeit : " << v << " m/s\n\t   oder : "
                                   << v*3.6 << " km/h";
  getchar();                 // Warten auf Tasteneingabe
  return 0;                  // Rückgabewert für Erfolg
}
