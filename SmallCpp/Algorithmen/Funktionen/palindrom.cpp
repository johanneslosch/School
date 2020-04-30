/* Thomas Cassebaum, 28.1.2009, all rights reserved
   Die palindrom-Funktion tauscht die Reihenfolge der Buch-
   staben und gibt das Ergebnis zurück
*/
#include <iostream.h>
using namespace std;
string palindrom(string);
int main()
{ cout << palindrom("ein esel lese nie") << endl;
  cout << palindrom("palindrom ist paperlapap");
  getchar();
  return 0;
}
string palindrom(string s)
{ int t=0,h=0; char z;       // tail- und head-Index- und Hilfsvariable z definieren
  while(s[h++])t++;          // Positions-Nr. der NULL in in t speichern
  t--;                       // tail für letztes Zeichen um 1 vermindern
  h=0;                       // head auf 0 für 1.Zeichen setzen
  while(h<t)                 // Schleife läuft, solange h<t
  { z=s[t];s[t--]=s[h];s[h++]=z; // Tausch der head-/tail-Zeichen...
  }                          // ...head vor-(++) und tail rücksetzen(--)
  return s;                  // Rückgabe des verdrehten Strings
}
