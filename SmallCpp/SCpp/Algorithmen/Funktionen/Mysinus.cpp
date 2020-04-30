/* programmiert von Th.Cassebaum 2000 all rights reserved
   Mysinus(double alpha) liefert den reellen Sinuswert des 
   Winkels alpha zurück. double faku(unsignd int f) liefert 
   den reellen Wert f! ("f fakultät") zurück.
*/
#include <iostream>
#include <conio>
using namespace std;
double faku(unsigned int f)
{ return(f<=1?1:f*faku(f-1));
}
double mysin(double alpha) // Sinusberechnung
{ unsigned int i=1; double ergneu=0.,ergalt;
  //              (i-1)        (2i-1)
  //          (-1)       * alpha
  // neu=alt+ --------------------
  //                  (2i-1)!
  do
  { ergalt=ergneu;
    ergneu=ergneu+pow(-1,(i-1))*(pow(alpha,2*i-1)/faku((2*i-1))); 
    i++;
  } while (fabs(ergneu-ergalt)>1E-6);
  return(ergneu);
}
int main()                 // Hauptfunktion
{ char fehl;char ant[20];
  double al,el,erg;
  cout.precision(6);       // auf 6 Stellen Genauigkeit
  cout << "Sinus für einen Winkel alpha bestimmen\n";
  do
  { fehl = 0;
    cout << "alpha (in °) : "; cin >> ant;
    if((ant[0]<'0'||ant[0]>'9')&&ant[0]!='+'&&ant[0]!='-')
    { cout << "\tUngueltige Eingabe! Wiederholen Sie:\n";
      fehl=1;
    }
    el = atof(ant); al = el/180*M_PI;
  }
  while(fehl != 0);
  erg=mysin(al); if(fabs(erg)<=1E-6) erg=0.;
  cout << "\ngerundet auf 6 Stellen:"
       << "\tmysin(" << el << "°) = " << erg << "\n"
       << "nur zum Vergleich     :\t  sin(" << el
       << "°) = " << sin(al) << "\n" ;  //vgl. sin(alpha)
  getch();
  return 0;
}
