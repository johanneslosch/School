/* Th.Cassebaum, 9.7.2003, all rights reserved
   Dynamisches Array zum Zeichnen eines zufälligen Sternenmusters
*/
#include <iostream>
using namespace std;
int main()
{ char *ps,*s;         // s: Zeiger auf dynamisches Zeilen-Spalten-Array, ps: Wanderzeiger
  int *ph,*pt,*t,i,j;  // t: Zeiger auf Stern-Feldnummern-Array, ph, pt: Wanderzeiger
  int zz,sz,rz,gz;     // zz: Zeilenzahl, sz:Spaltenzahl, rz: Sternzahl, gz: Feldanzahl
  bool gut;            // gut: logisches Feld zur Prüfung von evtl. doppelt auftretenden Sternzahlen
  randomize();
  do 
  { cout<<"Zeilen : "; cin>>zz;
  } while(zz<=1);                  // zz muß größer 1 sein
  do 
  { cout<<"Spalten: "; cin>>sz;
  } while(sz<=1);                  // sz muß größer 1 sein
  gz=zz*sz;                        // Feldanzahl bestimmen: Zeilenzahl * Spaltenzahl
  s=new char[gz];                  // dynamische Feld-Array dynamisch bilden
  do
  { cout<<"Sterne : "; cin>>rz;
  } while( (rz<=1) || (rz>=gz) );  // rz muß größer 1 sein, außerdem kleiner als die Feldanzahl
  t=new int[rz];                   // Stern-Feldnummern-Array dynamisch bilden
  for(pt=t;pt<=&t[rz-1];pt++)
  { do
    { *pt=random(gz); gut=true;         // Zufallszahl zwischen 0 und Feldanzahl-1 bilden
      for(ph=t;ph<pt;ph++)              // Vergleich mit allen bereits bestimmten Sternpositionen
        if(*ph==*pt) {gut=false;break;} // doppeltes Auftreten?
    } while(!gut);                      // Wiederholen, solange doppelte Sternpositionen auftreten
  }
  for(ps=s;ps<=&s[gz-1];ps++) *ps='.';     // Feld-Array mit Punkten füllen
  for(i=0;i<rz;i++) s[t[i]]='*';        // Sternfelder mit einem Stern besetzen
  for(i=0;i<zz;i++)                   // Schleife zur Ausgabe aller Zeilen
  { for(j=0;j<sz;j++) cout<<s[i*sz+j];  // Schleife zur Ausgabe aller Zeichen einer Zeile 
    cout<<endl;                         // Vorschub am Zeilenende
  }
  getchar();
  return 0;
}
