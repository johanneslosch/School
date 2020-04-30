// Th. Cassebaum, 22.4.2004, all rights reserved
#include <iostream.h>
int main()
{ int a=3,b[2]={5,6},**p,*p1,*p2;
  p1 = &a; p2 = &b; p = &p1;
  cout << "\nZeiger p zeigt auf " 
       << p << " Inhalt: " << *p
       << " und weiter auf " << **p;
  cout << "\nZeiger p1 zeigt auf " 
       << p1 << " Inhalt: " << *p1;
  getchar();
  return 0;
}

