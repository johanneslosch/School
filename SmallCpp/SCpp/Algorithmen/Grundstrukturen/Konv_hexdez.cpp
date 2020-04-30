// programmiert von Th.Cassebaum am 7.8.2002 gegen 16:41 Uhr
// all rights reserved
// Hexadezimalen 16-Bit-Wert dezimal anzeigen
#include <iostream>
#include <conio> 
using namespace std;
int main() 
{ char x;
  int i,k=0,z;
  cout << "Maximal 4 Hex-Ziffern eingeben: ";
  for( i=0; i<4; i++ ) 
  { x=getch();
    if ((x>='A') && (x<='F')) z=x-'A'+10;
    else if ((x>='a') && (x<='f')) z=x-'a'+10;
    else if ((x>='0') && (x<='9')) z=x-'0';
    else 
    { cout<<"\nKeine Hexziffer ->Eingabeabbruch!\n";
      break;
    }
    cout<<x;
    k=16*k+z;
  }
  cout<<"\nentspricht dem Dezimalwert: ";
  if(k>32767) cout<<"-"<<0xFFFF-k+1;
  else cout<<k;
  getch();
  return 0;
}
