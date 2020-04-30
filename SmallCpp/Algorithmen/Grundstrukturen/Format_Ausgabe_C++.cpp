/* Ausgabeformatierung (C++)
   Th.Cassebaum 2004, all rights reserved 
*/
#include <iostream>          // C++ I/O-Header
#include <iomanip>           // C++ I/O-Manipulatoren
using namespace std;
int doppel(int x)
{ return 2*x;
}
int main()                   
{ double x = 202.2e-3;       // Variablendefinitionen
  int    i = 31;
  bool   l = true;
  cout << setprecision(1) << x << endl;          // Präzision
  cout << setprecision(2) << x << endl;
  cout << setprecision(3) << x << endl;
  cout << setprecision(4) << x << endl << endl;
  cout << scientific << x << endl << endl;       // Exponentialdarstellung
  // Andere Zahlenbasen
  cout << "hex(" << dec << i << ") = " << hex << i << endl;
  cout << "oct(" << dec << i << ") = " << oct << i << endl << endl;
  cout << "setbase(10)(" << dec << i << ") = " << setbase(10) << i << endl << endl;
  // Textformatierungen
  cout << right << setw(20) << "rechtsbndiger" << endl;  
  cout << setw(20) << "Text" << endl;  
  cout << left << setw(20) << "linksbndiger" << endl;  
  cout << setw(20) << "Text" << endl << endl;
  // boolsche Wertausgabe
  cout << l << " " << !l << endl;               // gibt "1" und "0" aus.
  cout << boolalpha << l << " " << !l << endl;  // gibt "true" und "false" aus!
  // Anführungsstriche und Backslash
  cout << "\nAdresse: \"http:\\\\www.t-cassebaum.de\"";
  cout << "\nDatei  : \"c:\\programme\\cpptrain\\binbpl\\cpptrain.exe\"";
  // Umlaute 
  // Vorsicht, nur "in" Anführungsstrichen oder Apostrophen zulässig!
  cout << "\n\nDeutsche Umlaute: Ž™š„”á";     
   
  getchar();                 // Warten auf Tasteneingabe
  return 0;                  // Rückgabewert für Erfolg
}
