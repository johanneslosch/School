// Summe von Eingabewerten bis zur Eingabe von Null.
// Th. Cassebaum, 15.2.2004, all rights reserved
#include <iostream>
using namespace std;
int main()
{ int n, s=0;
  do
  { cout << "Summand[0-Ende]: "; cin >> n;
    s+=n;
  } while(n);
  cout << "Summe: " << s;
  getchar();
  return 0;
}
