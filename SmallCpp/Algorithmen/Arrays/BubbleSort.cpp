// Minimum und Maximum von Eingabewerten bis zur Eingabe von Null.
// Th. Cassebaum, 15.2.2004, all rights reserved
#include <iostream>
using namespace std;
int main()                
{ int a[10],i;            // Array a und Laufvariable i definieren
  
  randomize();            // Zufallsgenerator Anfangswert festlegen
  for(i=0;i<10;i++)       // Zählschleife für i=0...9 starten
  { a[i]=random(100);     // Zufallszahl 0...99 bilden
    cout << a[i] << " ";  // Arrayelement i ausgeben
  }   
  
  bool ts;                // Variable für Tausch definieren
  do       
  { ts=false;             // ts auf "nicht getauscht" stellen
    for(i=0;i<10-1;i++)   // Zählschleife für i=1...9 starten (ohne 0!!!)
    { if(a[i]>a[i+1])     // a[i],a[i+1] in falscher Reihenfolge?
      { int h=a[i];a[i]=a[i+1];a[i+1]=h; // ja -> Tausch a[i]<->a[i+1] 
        ts=true;          // ts auf "getauscht" stellen 
      }  
    }
  } while(ts);            // alles nochmal, wenn getauscht wurde
  
  cout << "\n\n";         // Alle Zahlen sortiert ausgeben
  for(i=0;i<10;i++) cout << a[i] << " ";

  getchar();     
  return 0;
}
