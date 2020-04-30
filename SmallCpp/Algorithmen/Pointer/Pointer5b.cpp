// Th. Cassebaum, 23.4.2004, all rights reserved
#include <iostream.h>
int main()
{ char a[10][30],*z; int i,j,l;
  randomize();
  for(i=0; i<10; i++)
  { z=a[i]; l=random(26)+5;
    *z++=(char)random(26)+'A';  // 1.Buchstabe
    for(j=1;j<l;j++)
      *z++=(char)random(26)+'a';// weitere Buchstaben
    *z=0;                       // Terminator
  }
  for(i=0; i<10; i++)
  { cout << i+1 << ".\t" << a[i] << endl;
  }
  getchar();
  return 0;
}

