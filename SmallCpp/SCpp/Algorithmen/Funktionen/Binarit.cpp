/* programmiert von Th.Cassebaum am 26.8.2002 all rights reserved
   Binäre Ein- und Ausgaben, Binärarithmetik
*/
#include <iostream>
#include <conio>
using namespace std;
int binein();
void binaus(int x);

int main()
{ char op; int a,b;
  cout << "\n1.Operand\n"; a=binein();
  cout << "\n2.Operand\n"; b=binein();
  cout<<endl;
  do
  { cout << "\nOperation [+-*/] : ";
    op=getch();
  }
  while(op!='+'&&op!='-'&&op!='*'&&op!='/');
  cout <<op <<endl<<endl;
  switch( op )          // Auswahlausdruck
  { case  '+' : binaus(a);
                cout << " + ";binaus(b);
                cout << " = ";binaus(a+b);
                break;
    case  '-' : binaus(a);
                cout << " - ";binaus(b);
                cout << " = ";binaus(a-b);
                break;
    case  '*' : binaus(a);
                cout << " * ";binaus(b);
                cout << " = ";binaus(a*b);
                break;
    case  '/' : binaus(a);
                if (b)
                { cout << " / ";binaus(b);
                  cout << " = \n";binaus(a/b);
                  cout << " R "; binaus(a%b);
                }
                else cout << "Nenner darf nicht Null sein!";
                break;
    default   : cout << op << " ist kein gültiger Operand!"  ;
  }
  getch();
  return 0;
}
int binein()     // Duale Eingabe abfordern und als int-Wert zurückgeben
{ char x;
  int i,k=0,z;
  cout << "Maximal 16 Dualziffern eingeben: ";
  for( i=0; i<16; i++ )
  { x=getch();
    if ((x>='0') && (x<='1')) z=x-'0';
    else break;
    cout<<x;
    k=2*k+z;
  }
  if(i>16) while(x=='0'||x=='1')x=getch();
  return k;
}
void binaus(int x) // Parameter x als 16stelligen Dualwert ausgeben
{ int k=0x8000;
  while(k)
  { if(x&k) cout <<"1";
    else cout <<"0";
    k=k>>1;
  }
}

