// SmallC++ 2010, all rights reserved
#include <iostream.h>
int main()   
{ string suf[]={"zwan","dreis","vier","fuenf","sechs","sieb","acht","neun"};
  string prae[] ={"","ein","zwei","drei","vier","fuenf","sechs","sieben","acht","neun"};
  int x=0; 
  do
  { cout << "\nNatuerliche Zahl [20...99, Ende mit Strg/C]: "; cin >> x;
    if(x>=20 && x<=99)
    { if(x%10) cout << prae[x%10]+"und"+suf[x/10-2]+"zig";
      else     cout << suf[x/10-2]+"zig"; 
    }
    else cout << "Unzulaessiger Eingabewert!";
  } while(true);
  getchar();
  return 0; 
}