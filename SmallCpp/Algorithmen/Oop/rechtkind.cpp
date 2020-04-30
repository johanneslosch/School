// programmiert von Th.Cassebaum am 15.2.2004 gegen 22:40 Uhr
// all rights reserved
// Basisklasse Rechteck und Kindklasse Quader 
#include <conio.h>; 
#include <iostream.h>; 
class recht 
{ public: recht(double ak, double bk); 	// Prototyp Konstruktor 
          recht &Area(void);
          recht &Umfang(void);
          void Zeige(void);
          double af(void) 	// intern definierte Methoden 
          { return a;
          }
          double bf(void) 
          { return b;
          }
          void set(double as, double bs) 
          { a=as;
            b=bs;
          }
  private: double a,b; 	 // private Prototypen und Member 
};
class quader : public recht   // Kindklasse Quader
{ public: quader(double aqu,double bqu, double cqu); // Konstruktor für quader
          double cf(void) 	// intern definierte Methoden
          { return c;
          }
          quader &Volumen(void);
  private: double a,b,c;
};
recht:: recht(double ak, double bk) // Konstruktor für recht
{ set(ak,bk);
}
quader:: quader(double aqu,double bqu, double cqu):recht(a,b) // Konstruktor für quader
{ a=aqu; b=bqu; c=cqu;
}
void recht:: Zeige(void) 	// Definitionen zu den externen Methoden
{ cout << "Laenge: " << a <<" Breite: " << b;
}
quader &quader::Volumen(void)
{ c=a*b*c;
  return *this;
}
recht &recht:: Area(void) 
{ a=a*b;
  return *this;
}
recht &recht:: Umfang(void) 
{ a=a+a+b+b;
  return *this;
}
void main(void) 
{ recht R1(2,3),R2(7,15);
  quader Q1(3,4,5) ;
  R1.Zeige();
  cout << endl;
  R2.Zeige();
  cout << endl<< "Inhalt Rechteck1: "<<R1.Area().af();
  cout << endl<< "Umfang Rechteck2: "<<R2.Umfang().af();
  cout << endl<< "Volumen Quader1 : "<<Q1.Volumen().cf();
  getch();
}
