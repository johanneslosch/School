/* programmiert von Th.Cassebaum am 7.8.2002 all rights reserved
   Dezimalzahl als hexadezimalen 16-Bit-Wert anzeigen
*/
#include <iostream> 
#include <conio> 
using namespace std;
int main() 
{ int i,j,x,k=0xF000;
  char s;
  cout << "\nx = ";
  cin >> x;
  for(i=3;i>=0;i--) 
  { j=(x&k)>>(i*4);
    if(j<10) cout<<j;
    else 
    { s='A'+j-10;
      cout<<s;
    }
    k=k>>4;
  }
  getch();
  return 0;
}
