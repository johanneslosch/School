// Th. Cassebaum, 23.4.2004, all rights reserved
#include <iostream.h>
int main()
{ double a[5],*z=a; int i;
  randomize();
  for(i=0; i<5; i++)
  { *z++=random(10000)/100.;
  }
  z = a;
  for(i=0; i<5; i++)
  { cout << i+1 << ".Adresse: 0x" << z
         << ", Inhalt: " << *z++ << endl;
  }
  getchar();
  return 0;
}
