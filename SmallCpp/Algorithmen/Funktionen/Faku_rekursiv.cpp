/* programmiert von Th.Cassebaum am 15.2.2004 gegen all rights reserved
   faku1(f)..faku4(f) bestimmen f! (f "fakultät")
   Die Zeitdauer der Ergebnisermittlung wird errechnet.
*/
#include <iostream>
#include <conio>
using namespace std;
double faku1(unsigned int f)
{ return(f<=1?1:f*faku1(f-1));
}
double faku2(unsigned int f)
{ if (f<2) return 1; 
  else return faku2(f-1)*f;
}
double faku3(unsigned int f)
{ double e=1.; unsigned int i;
  if (f<2) return 1.;
  for(i=2;i<=f;i++) e*=i; 
  return e;
}

double faku4(unsigned int f)
{ double e=1.; 
  if (f<2) return 1.;
  for(;f>=2;f--) e*=f; 
  return e;
}
void main(void)
{ int i,w; long Zeit; char a; double f;
  do
  { do
    { cout << "\nWert: ";
      cin >> w;
    } while (w<0);
    Zeit=clock();
    for(i=0;i<1000000;i++) 
      f=faku1(w);
    cout << "\nDie Errechnung der Fakultät1 benötigte " 
         << difftime(clock(),Zeit) << " Nanosekunden";
    Zeit=clock();
    for(i=0;i<1000000;i++) 
      f=faku2(w);
    cout << "\nDie Errechnung der Fakultät2 benötigte " 
         << difftime(clock(),Zeit) << " Nanosekunden";
    Zeit=clock();
    for(i=0;i<1000000;i++) 
      f=faku3(w);
    cout << "\nDie Errechnung der Fakultät3 benötigte " 
         << difftime(clock(),Zeit) << " Nanosekunden";
    Zeit=clock();
    for(i=0;i<1000000;i++) 
      f=faku4(w);
    cout << "\nDie Errechnung der Fakultät4 benötigte " 
         << difftime(clock(),Zeit) << " Nanosekunden";
    cout << endl << w << "! = " << f;
    cout << "\nNochmal? [j/n]: ";  a=getch();
  } while (a!='n');
}
