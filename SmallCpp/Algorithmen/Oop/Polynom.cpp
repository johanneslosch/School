// Th. Cassebaum, 10.1.2008, all rights reserved
#include <iostream.h>
#include <iomanip.h>
#include <conio.h>

// Erstelle eine Klasse zur Speicherung von x-Polynomen mit natürlichen 
// Exponenten. Verwende dabei die Technologie einfach verketteter Listen. 
// Erstelle öffentliche Methoden zum Anzeigen des Polynomtextes, zum 
// Füllen mit Koeffizientenwerten und zum Bestimmen des Wertes der zuge-
// hörigen Polynomfunktion für ein als Parameter zu übergebenen x-Wert. 
// Erstelle weiter Methoden zur Bestimmung des Polynomgrades und zur 
// Schaffung eines Objektes, das die Ableitung der enthaltenen Polynom-
// funktion in einem neuen Polynom-Objekt zurück gibt.

// Benutze die fertige Programmkonstruktion dazu, für einzugebende Poly-
// nome anhand einer dazu weiter einzugebenden Startstelle x0 mit Hilfe 
// des Newton-Verfahrens eine Nullstelle mit einer bestimmten Genauig-
// keit zu finden.

struct Potenz                   // Struktur eines Listenelementes 
{   double koeff;               // Koeffizient (Der Exponent ergibt sich aus der Stellung in der Liste)
    Potenz *next;               // Listenzeiger
};
class Polynom                   // Klasse zur Bildung eines Polynomobjektes
{ public:
    Polynom();                  // Konstruktor ohne Parameter (Grad wird abgefragt)
    Polynom(short);             // Konstruktor mit Parameter (Grad des Polynoms)
    void Show();                // Polynomausgabe am Bildschirm
    void Fill();                // Füllen des Polynoms mit Werten
    double Wert(double);        // Wert des Polynoms für einen x-Wert
    Polynom Abl();              // Bestimmung der Ableitung des Polynoms
  private:
    Potenz *root,*act;          // Standardzeiger der Potenzliste zum Polynom
    void NewPoly(short);
    short Anz();  
};

int main()
{ Polynom P; double x, xn, g=1, s, m; char ant;
  do                                        // Schleife mit gleichem Polynomgrad
  { clrscr();
    P.Fill();                               // Wertfüllung des Polynoms
    cout << "\nf(x)  = "; P.Show();         // Bildschirmanzeige der Funktion
    cout << "\nf'(x) = "; P.Abl().Show();   // Bildschirmanzeige der Ableitungsfunktion
    cout << "\n\nNullstelle für f(x)=0 beginnend mit der Startstelle x0 = "; cin >> xn;
    cout << "\nGenauigkeit in Stellen (<16) : "; cin >> s; m=s;
    while(s--) g/=10;                       // Vergleichswert zur Stellenzahl passend
    do                                      // Schleife zum Newton-Verfaheren
    { x = xn;                               // Das neue x wird das alte x
      xn = x - P.Wert(x) / P.Abl().Wert(x); // Newton-Formel
      cout << setprecision(m+3) << xn << "\n";  // Ausgabe mit passender Stellenzahl
    } while( fabs(x-xn) > g );              // Vergleich der Wertdifferenz |alt x - neu x|
    cout << "\n\n***  Weiter? (j/n) : "; ant=getch(); 
  } while(ant!='n');                        // Evtl. Schleifenabbruch
  return 0;
}

Polynom::Polynom()              // Konstruktor 1
{ short g;
  cout << "Grad des Polynoms (höchste Potenz von x): ";
  cin >> g;
  NewPoly(g);
}
Polynom::Polynom(short g)       // Konstruktor 2
{ NewPoly(g);  
}
double Polynom::Wert(double x)  // Wertbestimmung für ein x
{ Potenz *help=root; double w=0.;
  short g=this->Anz()-1;
  while(help)
  { w += help->koeff * pow(x,g--);
    help = help->next; 
  }
  return w;
}
void Polynom::NewPoly(short g)  // Herstellung eines leeren Polynoms
{ root = act = new Potenz;      // mit dem Grad g (Parameter)
  while((--g)+1) 
  { act->next = new Potenz;
    act = act->next;
  }
  act->next=NULL;
}
void Polynom::Fill()            // Füllung des Polynoms mit reellen Koeffizientenwerten
{ Potenz *help=root;
  short g=this->Anz()-1;
  cout << "\nGeben Sie jetzt die Koeffizienten für die passende x-Potenz ein.\n\n";
  while(help)
  { cout << "für x^" << g-- << "\t: ";
    cin >> help->koeff;
    help = help->next; 
  }
}
short Polynom::Anz()            // Bestimmung der Anzahl der Listenelemente (Grad+1)
{ Potenz *help=root; short i=0;
  if(help) 
  { i++;
    while(help->next) 
    {i++; help=help->next;}
  }
  return i;
}
void Polynom::Show()            // Anzeige des Polynoms am Bildschirm (^ für "hoch") 
{ Potenz *help=root; short g=this->Anz()-1; 
  cout<<help->koeff << "x^" << g--;
  while(help->next)
  { help=help->next;
    //cout << " ";
    if(help->koeff>0) cout << "+";
    if(help->koeff)
    { if(help->koeff!=1) cout << help->koeff;  
      else if(!g) cout << help->koeff;
      if(g) cout << "x"; 
      if(g>1) cout << "^" << g;
    }
    g--;    
  }
}
Polynom Polynom::Abl()          // Bestimmung des Polynoms der Ableitungsfunktion
{ short g = this->Anz()-1;
  Polynom abl(g-1);
  Potenz *help1=root,*help2=abl.root;
  while(help1->next)
  { help2->koeff = help1->koeff*g--;
    help1 = help1->next;  
    help2 = help2->next;  
  }
  return abl;
}

