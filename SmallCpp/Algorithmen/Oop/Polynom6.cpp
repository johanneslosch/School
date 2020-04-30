// Th. Cassebaum, 10.1.2008, all rights reserved
#define  A_SPEED 2					// Beschleunigung durch Rastervergrößerung 
#include "string.h"					// Header für die Stringfunktionen
#include <iostream.h>
#include <algeo.h>
#include <iomanip.h>
#include <conio.h>
#define grad  4    // Höchste Polynompotenz
#define genau 8    // Stellenzahl für Nullstellen (Genauigkeit)
/* 
	Aufgabenstellung
	
	Erstelle eine Klasse zur Speicherung von Polynomen max. 4.Grades mit 
	natürlichen Exponenten. Erstelle öffentliche Methoden zum Anzeigen des 
	Polynomtextes und zur Bestimmung der 1.Ableitung der enthaltenen Poly-
	nomfunktion (Rückgabe eines neuen Polynom-Objekts).
	
	Erweiterung 1:
	Erstelle eine weitere Methode zur Bestimmung des Polynomgrades (0...grad) 
	und eine zum Füllen der Attribute mit Koeffizientenwerten und zum Bestim-
	men des Wertes der zugehörigen Polynomfunktion für einen als Parameter zu 
	übergebenen x-Wert. 
	
	Erweiterung 2:
	Benutze die fertige Programmkonstruktion dazu, für einzugebende Polynome 
	anhand einer dazu weiter einzugebenden Startstelle x0 mit Hilfe des 
	Newton-Verfahrens eine Nullstelle mit einer bestimmten Genauigkeit zu 
	finden.
	
	Erweiterung 3:
	Erzeuge Methoden für die Addition, Subtraktion und Multiplikation von 
	Objekten der Klasse Polynom, die als Ergebnis wieder ein Polynom zurückgeben. 
	Erzeuge für +, - und * passende Operatorüberladungen für Objekte der Klasse 
	Polynom.  
*/
class Polynom                   // Klasse zur Bildung eines Polynomobjektes
{ public:
    Polynom();                  // Konstruktor ohne Parameter (Nullfüllung)
    Polynom(double*);           // Konstruktor mit Parametern(Koeffizienten)
    void Polynom::Set(double*); // Setzen der Parameter im Polynom
    void Show();                // Polynomausgabe am Bildschirm
    void Render();              // Zeichnen des Grafen
    Polynom Abl();              // Bestimmung der Ableitung des Polynoms
    short Grad();               // Bestimmung des Grades des Polynoms
    double Wert(double x);      // Bestimmung des Wertes der Polynomfunktion für x=...
    double Newton(double x0);   // Nullstellenbestimmung mit erster Näherung x0
    Polynom operator+(Polynom S);   // Methode zur Addition
    Polynom operator-(Polynom S);   // Methode zur Subtraktion
  private:
    double Koeff[grad+1];       // grad+1 Koeffizienten zum Polynom
} P,A,B;
int main(int argc, char **argv)
{ double *koeff = new double[grad+1],nwt; char zuf,antw;
  randomize();
  cout << "Zufälliges Polynom bilden? [j/n] : "; zuf=getch(); // Eingabe j oder n
  cout << "\n";
  for(int i=grad;i>=0;i--) 
  { if(zuf=='j'||zuf=='J') koeff[i]=random(19)-9;             // Zufällige Koeffizienten (-9...+9) bilden
    else { cout << "x^" << i << " = "; cin >> koeff[i];  }    // Handeingabe der Koeffizienten
  }
  P.Set(koeff);
  A=P.Abl(); 
  double x, xn, s, m; char ant;
  cout << "\nf(x)    = "; P.Show();         // Bildschirmanzeige der Funktion
  cout << "\nf'(x)   = "; P.Abl().Show();   // Bildschirmanzeige der Ableitungsfunktion
  cout << "\nf+f'(x) = "; (P+P.Abl()).Show();//P.Add(P.Abl()).Show();
  cout << "\nf-f'(x) = "; (P-P.Abl()).Show();//P.Sub(P.Abl()).Show();
  cout << "\nf'-f(x) = "; (P.Abl()-P).Show();//P.Abl().Sub(P).Show();
  cout << "\nGrad f  = " << P.Grad();
  cout << "\nGrad f' = " << P.Abl().Grad();
  cout << "\nf(-1)   = " << P.Wert(-1)<< "\tf(0)  = " << P.Wert(0)<< "\tf(1)  = " << P.Wert(1);
  cout << "\nf'(-1)  = " << A.Wert(-1)<< "\tf'(0) = " << A.Wert(0)<< "\tf'(1) = " << A.Wert(1);
  cout << "\nZeichnen? [j/n]: "; antw=getch();
  glutInit(&argc, argv);          	// GLUT initialisieren
  A_Init("3D Grafik",A_ORTHO,5,5);	// ALGEO initialisieren (ORTHO/PERSP)
  //cout << "\n\nStartwert für Newton-Verfahren : "; cin >> nwt;
  nwt = 1;
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
{ Set(k);
}
void Polynom::Set(double* k)
{ for(int i=0; i<grad+1; i++) Koeff[i]=k[i];
}
void Polynom::Show()            // Anzeige des Polynoms am Bildschirm (^ für "hoch") 
{ bool first=true, nix=true;
  for(int i=grad;i>=0;i--)
  { if(Koeff[i])
    { if(i<grad) cout << "\t";
      if(nix) nix=false;
      if(Koeff[i]>0) cout << first?" ":"+";
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
{ double s=0., pot=1; short i;                                                
  for(i=0;i<=grad;i++)
  { s+=Koeff[i]*pot;
    pot*=x;
  }
  return s;
}
double Polynom::Newton(double x0)     // Nullstellenbestimmung mit erster Näherung x0
{ double x,maxlf=5000000;
  do                                  // Schleife zum Newton-Verfaheren
  { x=x0;
    x0 = x - (Wert(x) / Abl().Wert(x));    // Newton-Formel
    maxlf--;
  } while((fabs(x-x0)>0.000000001)&&maxlf); // Vergleich Wertdifferenz |altx-neux| > 10^-8
  if(!maxlf) x0=1e300;
  return x0;
}
Polynom Polynom::operator+(Polynom S)       // Methode zur Addition
{ Polynom E;
  for(int i=0;i<=grad;i++)
    E.Koeff[i]=Koeff[i]+S.Koeff[i];
  return E;  
}
Polynom Polynom::operator-(Polynom S)       // Methode zur Subtraktion
{ Polynom E;
  for(int i=0;i<=grad;i++)
    E.Koeff[i]=Koeff[i]-S.Koeff[i];
  return E;  
}

void justify(void)				  
{ // ... ab hier die Starteinstellung der Statusvariablen vornehmen
  A_sy+=.3;	                		// Kamera näher führen
  A_zPlane=true; A_1=0; A_2=0;		// z-Gatter zeigen, Variablen A_0 und A_1 initialisieren
  A_Foggy=false;					// Nebel abschalten
}
float A_f1(float x) {return (x+A_1)*(x+A_1)+A_2;};
float A_f2(float x) {return 0.2*x*x*x;};

GLfloat rot[]=A_RED, blau[]=A_BLUE;
void display(void)			// Renderfunktion
{ // ... ab hier eigene Zeichnungsfunktionen eingeben
  A_Model(A_BOOK);          // Modelltyp festlegen (auch: A_NIGHT, A_DARK)
  A_Coord(5);               // Koordinatensystem (Axunits, Negativ, Scaling, xyz)
  A_Func2D1(-12,12,rot,6);
  A_Func2D2(-12,12,blau,.06);
  GLfloat P[]={6,2};
  char s[2],t[2],e[20] = "f(x) = (x"; int a1=A_1,a2=A_2;
  if(a1 <0){strcat(e,"-"); a1=-a1;} else strcat(e,"+"); s[1]=t[1]=NULL; s[0]=0x30+a1; strcat(e,s); strcat(e,")*(x"); 
  if(A_1<0) strcat(e,"-"); else strcat(e,"+"); strcat(e,s);strcat(e,")"); 
  if(a2 <0){strcat(e,"-"); a2=-a2;} else strcat(e,"+"); t[0]=0x30+a2; strcat(e,t); 
  A_MatColor(blau);
  //A_TextOut(P,e); P[0]-=9.5; P[1]-=7.6;
  //A_TextOut(P,"Mit den Tasten 1, Shift/1, 2, Shift/2 die Parameter steuern!");
}