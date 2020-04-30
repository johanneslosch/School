#include <iostream.h> // fuer Ein- und Ausgabe 
#include <conio.h>    // fuer getch 
class Form 
{ // abstrakte Basisklasse 
  public: // nach aussen sichtbar 
          virtual void lesen() = 0; // reine virt. Funktionen 
          virtual void schreiben() = 0;
  protected: // public fuer abg. Klasse, ansonsten private 
  private:   // nach aussen unsichtbar 
};
class Flaeche : public Form 
{ // abgel. abstr. Klasse 
  public: Flaeche() { u = i = 0;} // Constructor 
          void schreiben() 
          { cout << "Umfang = " << u << endl;
            cout << "Inhalt = " << i << endl;
          }
  protected: double u, i;
          virtual double umfang(double, double) = 0; // rein virtuelle Fkt. 
          virtual double inhalt(double, double) = 0;
  private: 
};
class Koerper : public Form 
{ // abgel. abstr. Klasse 
  public: Koerper() { f = v = 0; }
          // Constructor 
          void schreiben() 
          { cout << "Oberflaeche = " << f << endl;
            cout << "Volumen = " << v << endl;
          }
  protected: double f, v;
          virtual double flaeche(double, double, double) = 0; // rein virtuelle Fkt. 
          virtual double volumen(double, double, double) = 0;
  private: 
};
class Kreis : public Flaeche 
{ // abgel. konkr. Klasse 
  public: Kreis() { a = x = y = 0;}
          // Constructor 
          void lesen() 
          { cout << "Radius: ";
            cin >> a;
            u = umfang(a, a);
            i = inhalt(a, a);
          }
  protected: private: double a, x, y;
          double umfang(double x, double y) 
          { return(M_PI * (x + y));
          }
          double inhalt(double x, double y) 
          { return(M_PI * x * y);
          }
};
class Rechteck : public Flaeche 
{ // abgel. konkr. Klasse 
  public: Rechteck() { a = b = x = y = 0;}
          void lesen() 
          { cout << "Laenge: "; cin >> a;
            cout << "Breite: "; cin >> b;
            u = umfang(a, b);
            i = inhalt(a, b);
          }
  protected: double umfang(double x, double y) 
          { return(2 * (x + y));
          }
          double inhalt(double x, double y) 
          { return(x * y);
          }
  private: double a, b, x, y;
};
class Quadrat : public Rechteck 
{ // abgel. konkr. Klasse 
  public: Quadrat() 
          { a = 0;
          }
          // Constructor 
          void lesen() 
          { cout << "Laenge: ";
            cin >> a;
            u = umfang(a, a);
            i = inhalt(a, a);
          }
  protected: private: double a;
};
class Kugel : public Koerper 
{ // abgel. konkr. Klasse 
  public: Kugel() 
          { a = x = y = z = 0;
          }
          // Constructor 
          void lesen() 
          { cout << "Radius: ";
            cin >> a;
            f = flaeche(a, a, a);
            v = volumen(a, a, a);
          }
  protected: private: double a, x, y, z;
          double flaeche(double x, double y, double z) 
          { return(2 * M_PI * x * (y + z));
          }
          double volumen(double x, double y, double z) 
          { return(4 * M_PI * x * y * z / 3);
          }
};
class Quader : public Koerper 
{ // abgel. konkr. Klasse 
  public: Quader() 
          { a = b = c = x = y = z = 0;
          }
          // Constructor 
          void lesen() 
          { cout << "Laenge: ";
            cin >> a;
            cout << "Breite: ";
            cin >> b;
            cout << "Hoehe: ";
            cin >> c;
            f = flaeche(a, b, c);
            v = volumen(a, b, c);
          }
  protected: double flaeche(double x, double y, double z) 
          { return(2 * (x * y + x * z + y * z));
          }
          double volumen(double x, double y, double z) 
          { return(x * y * z);
          }
  private: double a, b, c, x, y, z;
};
class Wuerfel : public Quader 
{ // abgel. konkr. Klasse 
  public: Wuerfel() 
          { a = 0;
          }
          // Constructor 
          void lesen() 
          { cout << "Laenge: ";
            cin >> a;
            f = flaeche(a, a, a);
            v = volumen(a, a, a);
          }
  protected: private: double a;
};
// Hauptprogramm 
int main() 
{ int x = 0;
  char figur[32];
  cout << "\nFlaechen- und Koerperberechnung\n";
  cout << "\nKreis, Rechteck, Quadrat, Kugel, Quader, Würfel\n";
  cout << "\nWelche Figur? ";
  cin >> figur;
  cout << "\nFigur: " << figur << endl;
  // Stringvergleiche, erforderlich, weil in der 
  // switch-Anweisung nur eine int-Variable stehen kann. 
  if (!(strcmp(figur, "Kreis"))) x = 21;
  if (!(strcmp(figur, "Rechteck"))) x = 22;
  if (!(strcmp(figur, "Quadrat"))) x = 23;
  if (!(strcmp(figur, "Kugel"))) x = 31;
  if (!(strcmp(figur, "Quader"))) x = 32;
  if (!(strcmp(figur, "Wuerfel"))) x = 33;
  // Erzeugen des passenden Objektes f. Gilt wie 
  // jede Deklaration nur innerhalb des Blockes {}, 
  // weshalb die Methoden lesen() und schreiben() 
  // in jedem Block vorkommen muessen. 
  switch (x) 
  { case 21: 
            { Kreis f; // Erzeugen des Objektes f 
              f.lesen();
              f.schreiben();
              break;
            }
    case 22: 
            { Rechteck f;
              f.lesen();
              f.schreiben();
              break;
            }
    case 23: 
            { Quadrat f;
              f.lesen();
              f.schreiben();
              break;
            }
    case 31: 
            { Kugel f;
              f.lesen();
              f.schreiben();
              break;
            }
    case 32: 
            { Quader f;
              f.lesen();
              f.schreiben();
              break;
            }
    case 33: 
            { Wuerfel f;
              f.lesen();
              f.schreiben();
              break;
            }
    default: cout << "Keine gueltige Figur." << endl;
            exit(-1);
  }
  getch();
  return 0;
}
