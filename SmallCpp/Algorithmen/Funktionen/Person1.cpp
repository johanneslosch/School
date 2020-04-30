/* Th. Cassebaum, 1.4.2004, all rights reserved
   Mit Hilfe von Funktionen werden Personendaten
   ein- und ausgegeben.
*/
#include <iostream>
using namespace std;
void Person_eingeben();
void Person_ausgeben();
string Personenangaben();
string name,vorname,geb; bool frau; 
int main()
{ Person_eingeben();                 // Funktionsaufruf 1
  Person_ausgeben();                 // Funktionsaufruf 2
  cout << endl << Personenangaben(); // Funktionsaufruf 3
  getchar();
  return 0;
}
string Personenangaben()             // Anfragefunktion (Rückgabe erwartet)
{ string s;
  if(frau) s="Frau "; else s="Herr ";
  s+=vorname+" "+name+" wurde am "+geb+" geboren";
  return s;
}
void Person_eingeben()               // Auftragsfunktion (keine Rückgabe)
{ char wbl;
  cout << "\nFamiliennname : "; cin >> name;
  cout <<   "Vorname       : "; cin >> vorname;
  cout <<   "geboren am    : "; cin >> geb;
  cout <<   "weiblich[j/n] : "; cin >> wbl;
  if(wbl=='j'||wbl=='J') frau = true; 
  else frau = false;
}
void Person_ausgeben()
{ char wbl;
  cout << "\nFamiliennname : " << name;
  cout << "\nVorname       : " << vorname;
  cout << "\ngeboren am    : " << geb;
  if(frau) cout << "\nGeschlecht    : weiblich";
  else cout << "\nGeschlecht    : männlich";
}