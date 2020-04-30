// Eingabeformatierung (C++)
// Th.Cassebaum 2004, all rights reserved
#include <stdio.h>                  // C I/O-Header
#include <conio.h>
int main()                   
{ unsigned int i; char s[256], z[256];          // Variablendefinitionen
  
  // Zahleneingabe hexadezimal
  printf("Hexadezimalzahl: "); scanf("%x",&i);
  printf("Eingegeben wurde dezimal %i",i); 
  printf("\nDezimalzahl: ");   scanf("%i",&i);
  printf("Eingegeben wurde dezimal %i",i); 

  getch();
  return 0;                  
}
