/* programmiert von Th.Cassebaum am 7.8.2002 all rights reserved
   Dualen 16-Bit-Integerwert dezimal anzeigen
*/
#include <iostream>
#include <conio> 
using namespace std;
int main() 
{ char x;
  int i,k=0,z;
  cout << "Maximal 16 Dualziffern eingeben: ";
  for( i=0; i<16; i++ )
  { x=getch();
    if ((x>='0') && (x<='1')) z=x-'0';
    else
    { // cout<<"\nKeine Dualziffer ->Eingabeabbruch!\n";
      break;
    }
    cout<<x;
    k=2*k+z;
  }
  cout<<"\nentspricht dem Dezimalwert: ";
  if(k>32767) cout<<"-"<<0xFFFF-k+1;
  else cout<<k;

  getch();
  return 0;
}
