// Th. Cassebaum, 10.1.2008, all rights reserved
#include <iostream.h>
#include <iomanip.h>
#include <conio.h>
#define grad 4
// Erstelle eine Klasse zur Speicherung von Polynomen max. 4.Grades mit 
// natürlichen Exponenten. Erstelle öffentliche Methoden zum Anzeigen des 
// Polynomtextes und zur Bestimmung der 1.Ableitung der enthaltenen Poly-
// nomfunktion (Rückgabe eines neuen Polynom-Objekts).

class Polynom                   // Klasse zur Bildung eines Polynomobjektes
{ public:
    Polynom();                  // Konstruktor ohne Parameter (Nullfüllung)
    Polynom(double*);           // Konstruktor mit Parametern(Koeffizienten)
    void Show();                // Polynomausgabe am Bildschirm
    Polynom Abl();              // Bestimmung der Ableitung des Polynoms
  private:
    double Koeff[grad+1];       // grad+1 Koeffizienten zum Polynom
};

int main()
{ double *koeff = new double[grad+1];
  randomize();
  for(int i=0;i<(grad+1);i++)
    koeff[i]=random(19)-9;        // Zufällige Koeffizienten (-9...+9) bilden  
  Polynom P(koeff); 
  double x, xn, s, m; char ant;
  cout << "\nf(x)  = "; P.Show();         // Bildschirmanzeige der Funktion
  cout << "\nf'(x) = "; P.Abl().Show();   // Bildschirmanzeige der Ableitungsfunktion
  getchar();
  return 0;
}

Polynom::Polynom()              // Konstruktor 1
{ for(int i=0; i<grad+1; i++) Koeff[i]=0.;
}
Polynom::Polynom(double* k)       // Konstruktor 2
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
