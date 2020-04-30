/* Th.Cassebaum 2004, all rights reserved 
   Tests zur Ausgabemanipulation (C++) 
   mit dem Header "iomanip"
*/
#include <iostream>          // C++ I/O-Header
#include <iomanip>           // C++ I/O-Manipulatoren
using namespace std;
int main()
{ double x = 202.2e-3;       // Variablendefinitionen
  int    i = 31;
  bool   l = true;
  cout << setprecision(1) << x << endl;          // Pr�zision
  cout << setprecision(2) << x << endl;
  cout << setprecision(3) << x << endl;
  cout << setprecision(4) << x << endl << endl;
  cout << scientific << x << endl << endl;       // Exponentialdarstellung
  // Andere Zahlenbasen
  cout << "hex(" << dec << i << ") = " << hex << i << endl;
  cout << "oct(" << dec << i << ") = " << oct << i << endl << endl;
  cout << "setbase(10)(" << dec << i << ") = " << setbase(10) << i << endl << endl;
  // Textformatierungen
  cout << right << setw(20) << "rechtsb�ndiger" << endl;  
  cout << setw(20) << "Text" << endl;  
  cout << left << setw(20) << "linksb�ndiger" << endl;  
  cout << setw(20) << "Text" << endl << endl;
  // boolsche Wertausgabe
  cout << l << " " << !l << endl;               // gibt "1" und "0" aus.
  cout << boolalpha << l << " " << !l << endl;  // gibt "true" und "false" aus!
  // Anf�hrungsstriche und Backslash
  cout << "\nAdresse: \"http:\\\\www.t-cassebaum.de\"";
  cout << "\nDatei  : \"c:\\programme\\SmallCpp\\SmallCpp.exe\"";
  // Umlaute 
  cout << "\n\n�������";     // Vorsicht nur "in" Anf�hrungsstrichen oder Apostrophen zul�ssig!
  char st[]="�������"; cout << endl;
  for(int i=0;st[i];i++) cout << (char) st[i] << ":" 
                              << (int) st[i] << "\t";
  cout <<  
  getchar();                 // Warten auf Tasteneingabe
  return 0;                  // R�ckgabewert f�r Erfolg
}
