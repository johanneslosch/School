// Th. Cassebaum, 23.4.2004, all rights reserved
#include <iostream.h>
int main()
{ int a = 1, b = 2, c = 3;
  int *p1[3], **p2 = p1;
  p1[0]=&a; p1[1]=&b; p1[2]=&c;
  while( p2 <= &p1[2] )
  { cout << **p2++ << endl;
  }
  getchar();
  return 0;
}

