// Th. Cassebaum, 4.9.2007, all rights reserved
#include <iostream>
#include <conio>
using namespace std;
char ein[35];
union area
{ float f;
  int i;
  unsigned int u;  
  unsigned short w[2];
  unsigned char b[4];
} a;
void Aus(unsigned int u,char *s,int l,int typ)
{ int i;
  itoa(u,ein,typ); cout << s;
  for(i=0;i<l-strlen(ein);i++)cout << '0';
  cout << ein;
}
int IsNum(char *z)    // 0-ungültig, 1-ganz, 2-reell
{ int pkt=0, erg=1; 
  while(((*z)==' ')||((*z)==9))z++;    // Leerzeichen, Tabulatoren
  if(((*z)=='+')||((*z)=='-'))z++;     // +,- akzeptieren
  while(((*z)==' ')||((*z)==9))z++;    // Leerzeichen, Tabulatoren
  while(*z)                            // solange nicht Terminator
  { if((*z)==',') (*z)='.';            // Komma wird Punkt
    if((*z)=='.') 
    { pkt++; erg=2; z++;               // float wählen
    }
    if(pkt>1) return 0;                // mehr als ein Punkt -> falsch
    if(*z)
    { if(((*z)<'0')||((*z)>'9')) return 0;   // keine Ziffer -> falsch 
      z++;
    }  
  }
  return erg;
}
int main()
{ char text[35]; int flint=1,i;
do
{
  do
  { clrscr();
    cout << "\n  Programm zur Ermittlung interner Zahlencodes"
         << "\n  --------------------------------------------"
         << "\n  Geben Sie Zahlen mit oder ohne Vorzeichen (+/-) mit oder ohne "
         << "\n  Komma/ Dezimalpunkt ein! Strg/C beendet das Programm.\n";    
    if(!flint) cout << "\n  Eingabefehler -> " << ein << endl;
    cout << "\n\n  Zahl:\t"; cin >> ein;
    flint=IsNum(ein);            // Gültige Zahl?
  } while(!flint);               // solange ungültig
  if(flint==1)                   // ganze Zahl (int)
  { cout << "\n  ganze Zahl!\n"; a.i=atoi(ein);
  }
  else                           // relle Zahl (float)
  { cout << "\n  reelle Zahl!\n"; a.f=atof(ein);
  }
  cout << "\n\n  dual:\n";
  Aus(a.u,"\n  Doppelwort: ",32,2);
  Aus(a.w[0],"\n  Zwei Worte: ",16,2);
  Aus(a.w[1]," ",16,2);
  Aus(a.b[0],"\n  Vier Bytes: ",8,2);
  Aus(a.b[1]," ",8,2);
  Aus(a.b[2]," ",8,2);
  Aus(a.b[3]," ",8,2);
  cout << "\n\n  hexadezimal:\n";
  Aus(a.u,"\n  Doppelwort: ",8,16);
  Aus(a.w[0],"\n  Zwei Worte: ",4,16);
  Aus(a.w[1]," ",4,16);
  Aus(a.b[0],"\n  Vier Bytes: ",2,16);
  Aus(a.b[1]," ",2,16);
  Aus(a.b[2]," ",2,16);
  Aus(a.b[3]," ",2,16);
  getchar();
} while(true);
  return 0;
}
