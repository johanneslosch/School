// k5_2_3_2.cpp Klasse bruch weiterentwickelt um Lsg. Aufg. 2 bis 4
// angepasst f. C++ Trainer v. Th.Cassebaum

// Gebrochene Zahl durch Zähler und Nenner dargestellt

#include <iostream.h>
#include <conio.h>

class bruch
{ public:
    bruch(long z, long n = 1L);    // Prototyp Konstruktor
    bruch &Prod(bruch &x);         // Protypen der Methoden
    bruch &Summ(bruch &x);
    void zeige(void);
    long zaehler(void)             // intern definierte Methoden
    { return zaehl;}
    long nenner(void)
    { return nenn;}
    void set(long z, long n)
    { zaehl=z; nenn=n;}
  private:
    long zaehl,nenn;               // private Prototypen
    void Kuerze(void);
};
bruch::bruch(long z, long n)       // Konstruktor für class bruch
{ zaehl = z;
  if (!(nenn=n)) { cerr << "\n\7Nenner = 0!\n"; exit(1); }
}
void bruch::zeige(void)            // Definitionen zu den externen Methoden
{ cout << zaehl; if (!(nenn==1)) cout << "/" << nenn;
}
void bruch::Kuerze(void)
{ int mx=sqrt(nenn);               // ganzzahliger Teil der Wurzel
  for (int i=2;i <= mx;i++)
    while (!(nenn%i)&&!(zaehl%i))
    {  zaehl /= i; nenn /= i;
    };
}
bruch &bruch::Prod(bruch &x)
{ zaehl *= x.zaehl; nenn *= x.nenn; Kuerze();
  return *this;
}
bruch &bruch::Summ(bruch &x)
{ int h;
  h = nenn*x.zaehl; nenn *= x.nenn;
  zaehl *= x.nenn; zaehl+=h;
  Kuerze();
  return *this;
}
int main(void)
{ bruch zahl1(2),zahl2(7,15);

  clrscr();
  zahl1.zeige(); cout << " * "; zahl2.zeige();
  cout << " = "; zahl1.Prod(zahl2).zeige();
  cout << "\n";

  zahl1.set(2,3); zahl2.set(20,15);
  zahl1.zeige();cout << " + "; zahl2.zeige();
  cout << " = "; zahl1.Summ(zahl2).zeige();
  getch();
  return 0;
}
