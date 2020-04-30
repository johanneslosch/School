// programmiert von Th.Cassebaum am 16.12.1999 gegen 19:47 Uhr
// all rights reserved
#include <iostream.h>
#include <conio.h>
void main(void)
{ char z; int i;
  for (i=32;i<=255;i++)
  { z=i;  cout.width(4);
    cout << i << " " << z << "\t";
  }
  getch();
}
