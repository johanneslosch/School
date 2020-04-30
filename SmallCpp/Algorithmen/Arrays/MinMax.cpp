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
  int ma,mi,su;           // Variablen für Maximum, Minimum, Summe definieren
  ma=mi=su=a[0];          // ... und auf den Wert des ersten Arrayelementes setzen
  for(i=1;i<10;i++)       // Zählschleife für i=1...9 starten (ohne 0!!!)
  { if(a[i]>ma) ma=a[i];  // wenn i.Element > ma, dann wird es neues ma  
    if(a[i]<mi) mi=a[i];  // wenn i.Element < mi, dann wird es neues mi
    su+=a[i];             // aufsummieren des i.Elementes auf s
  }
  // Ausgabe der Ergebnisse
  cout << "\n\nMaximum: " << ma << "\tMinimum: " << mi 
       << "\tMittelwert: " << (float)su/i;
  getchar();     
  return 0;
}
