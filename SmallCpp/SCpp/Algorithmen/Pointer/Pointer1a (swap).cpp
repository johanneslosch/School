// Th. Cassebaum, 19.3.2002, all rights reserved
#include <iostream.h>
int main()
{ int a=3,b=4;
  int *p1,*p2,*h;
  p1=&a; p2=&b;
  cout << "\na = " << a << "\tb = " << b;
  cout << "\nPointer 1 zeigt auf " << p1 
       << " Inhalt: " << *p1;
  cout << "\nPointer 2 zeigt auf " << p2 
       << " Inhalt: " << *p2;

  h=p1;p1=p2;p2=h; // Tausch der Pointeradressen
  cout << "\n\n\t-- nach dem Tausch --\n";

  cout << "\na = " << a << "\tb = " << b;
  cout << "\nPointer 1 zeigt auf " << p1 
       << " Inhalt: " << *p1;
  cout << "\nPointer 2 zeigt auf " << p2 
       << " Inhalt: " << *p2;
  getchar();
  return 0;
}
