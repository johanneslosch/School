// Aufbau eines 2-dimensionalen, quadratischen Arrays mit Zufallswerten,
// die Seitenlänge (<2) des Zahlenquadrats wird mit #define bereitgestellt,
// Anzeige des gesamten Quadrats mit vernünftigen Spaltenbreiten, 
// Tausch der ersten und letzten Zeile im Zahlenquadrat,
// Aufsteigende Sortierung aller Werte im Zahlenquadrat. 

// Th. Cassebaum, 26.3.2008, all rights reserved

#define g 3                // Seitenlänge des Zahlenquadrats
#include <iostream>
#include <iomanip>       // Header für Spaltenbreiten (setw,...)
using namespace std;

void Fill(int*);           // * Prototypen mit Pointerparameter 
void Out(int*);            // * für die Übergabe der Arrayadresse
void Swap1l(int*);         // *
void Bubble(int*);         // *

int main()                 // Hauptprogramm
{ if(g<2) return 1;        // Abbruch für g<2, (RC:1)
  int a[g][g],*p=a[0];     // Array und Zeigerdefinition
  Fill(p); Out(p);         // Füllen, Anzeigen
  cout << "1. mit letzter Zeile getauscht:" << endl;
  Swap1l(p); Out(p);       // Tauschen, Anzeigen
  cout << "alle Zahlen sortiert :" << endl;
  Bubble(p); Out(p);       // Sortieren, Anzeigen
  getchar();               // Warten zum Betrachten der BS-Anzeige
  return 0;                // normales Programmende (RC:0)
}

void Fill(int *a)          // Fill: Füllen des Arrays mit Zufallswerten
{ randomize();             // Zufallsgenerator initialisieren
  for(int i=0;i<g*g;i++)   // Schleife über alle Elemente
    *(a++)=random(g*g+1);  // Zufallswerte setzen (max.: g*g)
}
void Out(int *a)           // Out: Anzeige des kompletten Arrays
{ int b=log10(g*g)+2;      // Spaltenbreite logarithmisch bestimmen
  for(int i=0;i<g;i++)           // Zeilenschleife
  { for(int j=0;j<g;j++)         // Spaltenschleife
      cout << setw(b) << *(a++); // Elementausgabe mit Spaltenbreite
    cout << endl;                // neue Zeile anzeigen
  }    
}
void Swap1l(int *a)        // Swap1l: Tausch der ersten und letzten zeile
{ int *s=a, *e=&a[g*(g-1)];// Adressen der Startelemente s und e
  while(s<&a[g])           // Schleife bis zum letzten Element der Zeile
  { *s^=*e;*e^=*s;*s++^=*e++;    // Tausch ohne Hilfsvariable
  }
}
void Bubble(int *a)        // Bubble: Sortierung mit Bubble-Sort
{ bool tausch=true; int h; // 
  while(tausch)            // Außenschleife (solange "getauscht" wurde)
  { int *p=a;              // Zeiger auf Arraybeginn setzen
    tausch=false;          // Merker auf "nicht getauscht" setzen
    while(p<&a[g*g-1])     // Innenschleife (bis zum Ende)
    { if(*(p+1)<*p)              // Reihenfolge falsch? -> dann:
      { h=*(p+1);*(p+1)=*p;*p=h; // Tausch mit Hilfsvariable 
        tausch=true;             // Setzen des Merkers auf "getauscht" setzen
      }
      p++;                       // nächstes Vergleichspaar
    }
  }
}

