#include <conio>
#include <iostream>
using namespace std;
int i,x,y;
void addi(void);
void multi(void);
void faku(void);
void main(void)
{ char c;
  do
  { clrscr();
    cout << "\n\n\n\tMenueprogramm nach Th.Cassebaum 2001";
    cout << "\n\n\n\n\t\tF1 - Addition von 2 Zahlen";
    cout << "\n\t\tF2 - Multiplikation von 2 Zahlen";
    cout << "\n\t\tF3 - Berechnen von n Fakultaet";
    cout << "\n\n\t\tF4 - Ende des Programms";
    cout << "\n\n\n\tGeben Sie eine F-Taste ein!";
    c=getch();
    if (c==0)
     { c=getch();
       switch(c)
       { case 59:addi(); break;
         case 60:multi();break;
         case 61:faku(); break;
         case 62:break;
       }
     }
    else c=1;
  } while (c != 62);
}
void addi(void) // Additions-Unterprogramm
{ clrscr();
  cout << "\n\n\tAddition zweier Zahlen";
  cout << "\n\nGeben Sie Zahl 1 ein : "; cin >> x;
  cout << "Geben Sie Zahl 2 ein : "; cin >> y;
  cout << "\n" << x << " + " << y << " = " << x+y;
  getch();
}
void multi(void) // Multiplikations-Unterprogramm
{ clrscr();
  cout << "\n\n\tMultiplikation zweier Zahlen";
  cout << "\n\nGeben Sie Zahl 1 ein : "; cin >> x;
  cout << "Geben Sie Zahl 2 ein : "; cin >> y;
  cout << "\n" << x << " * " << y << " = " << x*y;
  getch();
}
void faku(void) // Fakultaet-Unterprogramm
{ int n, fak=1;
  clrscr();
  cout << "\n\n\tFakultaet der Zahl n";
  do
  { cout << "\n\nGeben Sie n ein : "; cin >> n;
  } while (n<0);
  if (!(n<2)) for(i=2;i<=n;i++) fak*=i;
  cout << "\n" << n << " ! = " << fak;
  getch();
}
