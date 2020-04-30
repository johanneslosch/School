/* Th. Cassebaum, 3.3.2008, all rights reserved
   Speicherung von Brüchen in einer verketteten Liste
   zu einer Struktur, deren Instanzen Brüche mit den
   ganzzahligen Attributen Zähler und Nenner speichern.
   Sie enthalten weiter ein Zeigerattribut, das die 
   Adresse des Folgeelementes in der Liste enthält.
*/
#include <iostream>
using namespace std;
struct Belem            // Klasse, deren Objekte die Listenelemente sind
{ int z,n;              // Zähler z und Nenner n (Bruchwerte)
  Belem *next;          // Zeiger *next auf das Folgeelement
} *anker, *aktu;        // Standard-Listenzeiger
// Initialisieren der leeren Liste
void Init()       
{ anker=aktu=NULL;      // Die Standard-Listenzeiger werden initialisiert
}
// Ausgabe eines Bruchelementes
void Bout(Belem b)
{ cout << b.z << "/" << b.n;  
}
// Ausgabe aller Bruchelemente der Liste
void List()
{ Belem *hilf=anker;
  while(hilf) 
  { Bout(*hilf); cout << " "; hilf=hilf->next; }  
}
// Anzahl der Listeelemente bestimmen
int Anzahl()
{ Belem *hilf=anker; int anz=0;
  while(hilf) 
  { anz++; hilf=hilf->next; }
  return anz;  
}
// Einfügen eines neuen Elementes nach dem aktuellen Element
void Inc(int zi,int ni) 
{ Belem *hilf=new Belem;
  hilf->z=zi; hilf->n=ni; // Initialisieren mit zi und ni 
  if(!aktu)  
  { if(!anker)  // erstes Element
    { anker=aktu=hilf; 
      aktu->next=NULL;
    }
    else        // neues erstes Element
    { hilf->next=anker;
      anker=aktu=hilf;      
    }
  }
  else          // neues, nicht erstes Element
  { hilf->next=aktu->next;
    aktu->next=hilf;
    aktu=aktu->next;      
  }
}
int main()
{ Init();                   // Leere Liste aufbauen
  Inc(1,4); Inc(2,3);       // Zwei Listenelemente einfügen 
  aktu=anker;
  Inc(1,2);                 // Ein weiteres Element zwische 1/4 und 2/3 einfügen
  aktu=NULL;
  Inc(1,8);                 // Ein neues Ankerelement voran stellen
  cout << "Listenelemente: ";
  List();                   // Die gesamte Liste ausgeben
  cout << "\nEs sind "
       << Anzahl()          // Die Elementeanzahl der Liste ausgeben
       << " Elemente in der Liste gespeichert.";
  getchar();
  return 0;
}
