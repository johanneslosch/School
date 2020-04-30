// programmiert von Thomas Cassebaum am 17.9.2002 gegen 17:34 Uhr
// all rights reserved
// Einfacher Aufbau einer einfach verketteten Liste zum Test des
// nicht-objektorientierten Headers d_liste.h
#include <iostream.h>
#include <conio.h>
#include "e_liste.h"
void out(void)
{ lies();
  cout<<"\nName: "<<satz.name<<", Nummer: "<<satz.nummer;
}
int main()
{ unsigned char z;
  init();
  cout<<"Bitte nach dem letzten Satz auf die Namensfrage # eingeben!";
  do
  { cout<<"\nName   : "; cin>>satz.name;
    if(satz.name[0]=='#') break;
    cout<<"Nummer : "; cin>>satz.nummer;
    if(fuegeeinnach())
    { lies();
      cout<<"\t\tgespeichert: "<<satz.name<<", "<<satz.nummer;
    }
    else cout<<"Schreibfehler!";
  } while(satz.name.length());
  cout<<"\n\nEs wurden "<<anzahl()<<" Datensätze eingegeben!";
  cout<<"\nEs werden ab sofort folgende Zeichen als Kommandos anerkannt:";
  cout<<"\na: aktuellen Satz zeigen    f: folgenden Satz zeigen    ";
  cout<<"\nc: aktuellen Satz ändern    n: neuen Satz einfügen      z: Satzanzahl zeigen";
  cout<<"\nh: ersten Satz zeigen       t: letzten Satz zeigen      x: Programm beenden\n";
  do
  { z=getch();
    switch(z)
    { case 'a': lies();out(); break;
      case 'f': if(next())
                { lies();out();
                }
                else cout<<"\7 >>Tail erreicht<<";
                break;
      case 'h': head();lies();out(); break;
      case 't': tail();lies();out(); break;
      case 'z': cout<<"\n\nDie Liste enthält "<<anzahl()<<" Datensätze!";break;
      case 'n':  cout<<"\nName   : "; cin>>satz.name;
                 cout<<"Nummer : ";   cin>>satz.nummer;
                 if(fuegeeinnach())
                 { lies();cout<<"\t\teingefügt: "<<satz.name<<", "<<satz.nummer;
                 }
                 else cout<<"Schreibfehler!"; break;
      case 'c':  lies(); cout<<"\n"<<satz.name<<" wird geändert:";
                 cout<<"\nName   : "; cin>>satz.name;
                 cout<<"Nummer : ";   cin>>satz.nummer;
                 aendern();lies();
                 cout<<"\t\taktualisiert: "<<satz.name<<", "<<satz.nummer;
    }
  } while(z!='x');
  return 0;
}
