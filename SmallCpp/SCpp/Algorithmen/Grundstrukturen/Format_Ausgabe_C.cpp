/* Th.Cassebaum 2004, all rights reserved
   Ausgabeformatierung (C)
*/
#include <stdio.h>           // C I/O-Header
int main()                   
{ double x = 202.234e-1;     // Variablendefinitionen
  int    i = 31;
  bool   l = true;
  printf("Normal: %g\n",x);          // Präzision
  printf("1.3g  : %1.3g\n",x);
  printf("4.1f  : %4.1f\n",x);
  printf("4.1g  : %4.1g\n",x);
  printf("2.5g  : %2.5g\n",x);
  printf("0.8g  : %0.8g\n",x);
  printf("\nDez   : %i\n",i);          // Andere Zahlenbasen
  printf("Hex   : %x\n",i);
  printf("HEX   : %X\n",i);
  printf("#Hex  : %#x\n",i);
  printf("Oktal : %o\n",i);
  // Textformatierungen
  printf("\n%20.14s\n","rechtsbndiger");
  printf("%20.14s\n","Text");  
  printf("%-20.14s\n","linksbndiger");
  printf("%-20.14s\n","Text");  
  // boolsche Wertausgabe
  printf("\n%i %i",l,!l);  
  // Prozentzeichen, Anführungsstriche
  printf("\n\"%i%%\"",i);

  getchar();                 // Warten auf Tasteneingabe
  return 0;                  // Rückgabewert für Erfolg
}
