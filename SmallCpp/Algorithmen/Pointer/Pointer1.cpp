#include <iostream.h>
int main()
{ int a=3, b=4, *p1, *p2;

  p1=&a; p2=&b;
  cout << "\nZeiger 1 zeigt auf " 
       << p1 << " Inhalt: " << *p1;
  cout << "\nZeiger 2 zeigt auf " 
       << p2 << " Inhalt: " << *p2;
  cout << endl << &p1 
       << " "  << &p2;
  getchar();
  return 0;
}
