// Eingabeformatierung (C++)
// Th.Cassebaum 2004, all rights reserved
#include <iostream.h>                  // C++ I/O-Header
int main()                   
{ int i; string s; char c;             // Variablendefinitionen
  
  // Zahleneingabe hexadezimal
  cout << "Hexadezimalzahl: " ; cin >> hex >> i;
  cout << "Eingegeben wurde dezimal " << i << "."; 
  cout << "\nDezimalzahl: " ;   cin >> dec >> i;
  cout << "Eingegeben wurde dezimal " << i << "."; 

  // Texteingabe ohne führende Leerzeichen
  cout << "\n\nWort mit führenden Leerzeichen: ";
  cin >> ws >> s;
  cout << "Eingegeben wurde " << "\"" << s << "\"";    
  s="";
  
  // Texteingabe mit enthaltenen Leerzeichen
  cout << "\n\nSatz eingeben: "; 
  while(cin.get(c) && c!='\n') s+=c;   
  cout << "Text: " << s;
  getchar();                           // Warten auf Tasteneingabe
  return 0;                  
}
