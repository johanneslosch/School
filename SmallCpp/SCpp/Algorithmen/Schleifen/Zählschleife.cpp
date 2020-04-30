// Zählschleife mit for
// programmiert von Th.Cassebaum am 16.12.1999 gegen 19:47 Uhr
// all rights reserved
#include <iostream.h>
void main(void)
{ int i; // Zählvariable
  int b,e,s;
  cout << "\nBeginnwert  : "; cin >> b;
  cout << "Endwert     : "; cin >> e;
  cout << "Schrittweite: "; cin >> s;
  cout << endl;
  if(e>=b) 
  { for (i=b/*Beginnwert*/; 
         i<=e/*Endwert*/; 
         i+=s/*Schrittweite*/) cout << i << " "<< " ";
  }
  else for (i=b; i>=e; i+=s) cout << i << " "<< " ";
  getchar();
}
