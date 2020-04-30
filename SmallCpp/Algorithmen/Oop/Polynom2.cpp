// Th. Cassebaum, 10.1.2008, all rights reserved
#include <iostream.h>
#include <iomanip.h>
#include <conio.h>
#define grad 4
// Erstelle eine Klasse zur Speicherung von Polynomen max. 4.Grades mit 
// natürlichen Exponenten. Erstelle öffentliche Methoden zum Anzeigen des 
// Polynomtextes und zur Bestimmung der 1.Ableitung der enthaltenen Poly-
// nomfunktion (Rückgabe eines neuen Polynom-Objekts).

// Erweiterung 1:
// Erstelle eine weitere Methode zur Bestimmung des Polynomgrades (0...grad) 
// und eine zum Füllen der Attribute mit Koeffizientenwerten und zum Bestim-
// men des Wertes der zugehörigen Polynomfunktion für einen als Parameter zu 
// übergebenen x-Wert. 

class Polynom                   // Klasse zur Bildung eines Polynomobjektes
{ public:
    Polynom();                  // Konstruktor ohne Parameter (Nullfüllung)
    Polynom(double*);           // Konstruktor mit Parametern(Koeffizienten)
    void Show();                // Polynomausgabe am Bildschirm
    Polynom Abl();              // Bestimmung der Ableitung des Polynoms
    short Grad();               // Bestimmung des Grades des Polynoms
    double Wert(double x);      // Bestimmung des Wertes der Polynomfunktion für x=...
  private:
    double Koeff[grad+1];       // grad+1 Koeffizienten zum Polynom
};

int main()
{ double *koeff = new double[grad+1];
  randomize();
  for(int i=0;i<(grad+1);i++)
    koeff[i]=random(19)-9;      // Zufällige Koeffizienten (-9...+9) bilden  
  Polynom P(koeff); 
  double x, xn, s, m; char ant;
  cout << "\nf(x)    = "; P.Show();         // Bildschirmanzeige der Funktion
  cout << "\nf'(x)   = "; P.Abl().Show();   // Bildschirmanzeige der Ableitungsfunktion
  cout << "\nGrad f  = " << P.Grad();
  cout << "\nGrad f' = " << P.Abl().Grad();
  cout << "\nf(-1)   = " << P.Wert(-1)<< "\tf(0)  = " << P.Wert(0)<< "\tf(1)  = " << P.Wert(1);
  cout << "\nf'(-1)  = " << P.Abl().Wert(-1)<< "\tf'(0) = " << P.Abl().Wert(0)<< "\tf'(1) = " << P.Abl().Wert(1);
  getchar();
  return 0;
}
Polynom::Polynom()              // Konstruktor 1
{ for(int i=0; i<grad+1; i++) Koeff[i]=0.;
}
Polynom::Polynom(double* k)     // Konstruktor 2
{ for(int i=0; i<grad+1; i++) Koeff[i]=k[i];
}
void Polynom::Show()            // Anzeige des Polynoms am Bildschirm (^ für "hoch") 
{ bool first=true, nix=true;
  for(int i=grad;i>=0;i--)
  { if(Koeff[i])
    { if(nix) nix=false;
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
double Polynom::Wert(double x)  // Bestimmung des Wertes der Polynomfunktion für x=...
{ double s=0.; short i=0, pot=1;                                                
  for(i=0;i<=grad;i++)
  { s+=Koeff[i]*pot;
    pot*=x;
  }
  return s;
}
