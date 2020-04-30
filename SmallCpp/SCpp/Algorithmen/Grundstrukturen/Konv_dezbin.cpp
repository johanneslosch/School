/* programmiert von Th.Cassebaum am 7.8.2002 all rights reserved
   Dezimalzahl als dualen 16-Bit-Wert anzeigen
*/
#include <iostream>
#include <conio>
using namespace std;
int main()
{ int x,k=0x8000;
  cout << "\nDezimalzahl = ";
  cin >> x;
  cout << "Dualer Wert = ";
  while(k>0)
  { if(x&k) cout <<"1";
    else cout <<"0";
    k=k>>1;
  }
  getch();
  return 0;
}
