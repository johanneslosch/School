// Mittelwert von Eingabewerten bis zur Eingabe von Null.
// Th. Cassebaum, 15.2.2004, all rights reserved
#include <iostream>
#include <conio>
using namespace std;
int main()
{ int n, s=0, z=0;
  do
  { cout << "\n\nWert [0-Ende]: "; cin >> n;
    s+=n; z++;
    clrscr();
    cout << "\nMittelwert: " << (double)s/z;
  } while(n);
  return 0;
}
