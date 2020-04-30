// Th. Cassebaum, 10.1.2008, all rights reserved
#include <iostream.h>
#include <iomanip.h>
#include <conio.h>
#define grad  4    // H�chste Polynompotenz
#define genau 8    // Stellenzahl f�r Nullstellen (Genauigkeit)

// Erstelle eine Klasse zur Speicherung von Polynomen max. 4.Grades mit 
// nat�rlichen Exponenten. Erstelle �ffentliche Methoden zum Anzeigen des 
// Polynomtextes und zur Bestimmung der 1.Ableitung der enthaltenen Poly-
// nomfunktion (R�ckgabe eines neuen Polynom-Objekts).

// Erweiterung 1:
// Erstelle eine weitere Methode zur Bestimmung des Polynomgrades (0...grad) 
// und eine zum F�llen der Attribute mit Koeffizientenwerten und zum Bestim-
// men des Wertes der zugeh�rigen Polynomfunktion f�r einen als Parameter zu 
// �bergebenen x-Wert. 
 
// Erweiterung 2:
// Benutze die fertige Programmkonstruktion dazu, f�r einzugebende Poly-
// nome anhand einer dazu weiter einzugebenden Startstelle x0 mit Hilfe 
// des Newton-Verfahrens eine Nullstelle mit einer bestimmten Genauig-
// keit zu finden.

class Polynom                   // Klasse zur Bildung eines Polynomobjektes
{ public:
    Polynom();                  // Konstruktor ohne Parameter (Nullf�llung)
    Polynom(double*);           // Konstruktor mit Parametern(Koeffizienten)
    void Show();                // Polynomausgabe am Bildschirm
    Polynom Abl();              // Bestimmung der Ableitung des Polynoms
    short Grad();               // Bestimmung des Grades des Polynoms
    double Wert(double x);      // Bestimmung des Wertes der Polynomfunktion f�r x=...
    double Newton(double x0);   // Nullstellenbestimmung mit erster N�herung x0
  //private:
    double Koeff[grad+1];       // grad+1 Koeffizienten zum Polynom
};

int main()
{ double *koeff = new double[grad+1],nwt; char zuf;
  randomize();
  cout << "Zuf�lliges Polynom bilden? [j/n] : "; zuf=getch(); // Eingabe j oder n
  cout << "\n";
  for(int i=grad;i>=0;i--) 
  { if(zuf=='j'||zuf=='J') koeff[i]=random(19)-9;             // Zuf�llige Koeffizienten (-9...+9) bilden
    else { cout << "x^" << i << " = "; cin >> koeff[i];  }    // Handeingabe der Koeffizienten
  }
  Polynom P(koeff), A=P.Abl(); 
  double x, xn, s, m; char ant;
  cout << "\nf(x)    = "; P.Show();         // Bildschirmanzeige der Funktion
  cout << "\nf'(x)   = "; P.Abl().Show();   // Bildschirmanzeige der Ableitungsfunktion
  cout << "\nGrad f  = " << P.Grad();
  cout << "\nGrad f' = " << P.Abl().Grad();
  cout << "\nf(-1)   = " << P.Wert(-1)<< "\tf(0)  = " << P.Wert(0)<< "\tf(1)  = " << P.Wert(1);
  cout << "\nf'(-1)  = " << A.Wert(-1)<< "\tf'(0) = " << A.Wert(0)<< "\tf'(1) = " << A.Wert(1);
  cout << "\n\nStartwert f�r Newton-Verfahren : "; cin >> nwt;
  nwt=P.Newton(nwt);
  cout << "\nNullst. = " ;
  if(nwt==1e300) cout << "keine";
  else cout << setprecision(9) << nwt;       // Ausgabe mit passender Stellenzahl
  getchar();
  return 0;
}
Polynom::Polynom()              // Konstruktor 1
{ for(int i=0; i<grad+1; i++) Koeff[i]=0.;
}
Polynom::Polynom(double* k)     // Konstruktor 2
{ for(int i=0; i<grad+1; i++) Koeff[i]=k[i];
}
void Polynom::Show()            // Anzeige des Polynoms am Bildschirm (^ f�r "hoch") 
{ bool first=true, nix=true;
  for(int i=grad;i>=0;i--)
  { if(Koeff[i])
    { cout << "\t";
      if(nix) nix=false;
      if((Koeff[i]>0)&&(!first)) cout << "+"; 
      if(first) first=false;
      if((Koeff[i]!=1)||(!i)) cout << Koeff[i];  
      if(i) cout << "x"; 
      if(i>1) cout << "^" << i;
    }
  } 
  if(nix) cout << 0;
}
Polynom Polynom::Abl()          // Bestimmung des Polynoms der Ableitungsfunktion
{ Polynom abl;
  abl.Koeff[grad]=0;
  for(int i=grad-1;i>=0;i--)
    abl.Koeff[i] = Koeff[i+1]*(i+1);
  return abl;
}
short Polynom::Grad()           // Bestimmung des Polynomgrads
{ short i=grad;
  while((i>=0)&&(!Koeff[i--]));
  return ++i;  
}
double Polynom::Wert(double x)  // Bestimmung des Wertes der Polynomfunktion f�r x=...
{ double s=0., pot=1; short i;                                                
  for(i=0;i<=grad;i++)
  { s+=Koeff[i]*pot;
    pot*=x;
  }
  return s;
}
double Polynom::Newton(double x0)     // Nullstellenbestimmung mit erster N�herung x0
{ double x,maxlf=5000000;
  do                                  // Schleife zum Newton-Verfaheren
  { x=x0;
    x0 = x - (Wert(x) / Abl().Wert(x));    // Newton-Formel
    maxlf--;
  } while((fabs(x-x0)>0.000000001)&&maxlf); // Vergleich Wertdifferenz |altx-neux| > 10^-8
  if(!maxlf) x0=1e300;
  return x0;
}
