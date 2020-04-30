// Th. Cassebaum, 27.4.2004, all rights reserved
// Es ist bekannt: Die Nummer des Zugangscodes steht als 
// int-Wert gespeichert. Die Adresse „a“ der Adresse die-
// ses int-Wertes wird einer Funktion „… Code(…)“ als Pa-
// rameter übergeben. Die Funktion „Code“ gibt den dezima-
// len Zugangscode als String zurück. Schreiben Sie die 
// Funktion Code(…) und einen passenden main()-Testrahmen!
#include <iostream.h>
string Code(int **a)
{ char s[10];
  itoa(**a,s,10);
  return string(s);
}
int main()
{ int c=4711, *cp, **cpp;
  cp=&c; cpp=&cp;
  cout << "Der Zugangscode lautet: "+Code(cpp);
  getchar();
  return 0;
}
