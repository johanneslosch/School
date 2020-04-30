// Minimum und Maximum von Eingabewerten bis zur Eingabe von Null.
// Th. Cassebaum, 15.2.2004, all rights reserved
#include <iostream>
#include <conio>
using namespace std;
int main()
{ unsigned int n, mi=0, ma=0; bool start=true;
  do
  { cout << "Natürliche Zahl [0-Ende]: "; cin >> n;
    if(start) { mi=n; ma=n; start=false; }
    else 
    { if(n>ma) ma=n; 
      if(n<mi) mi=n;
    }
    clrscr();
    cout << "Maximum: "<<ma<<"\tMinimum: "<<mi<<"\n\n";
  } while(n);
  return 0;
}
