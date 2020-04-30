/* Th.Cassebaum , 1998, all rights reserved
   Es sollen n Lottotipps entworfen und auf dem Bildschirm angezeigt werden. 
   - Keine Zahl darf im Tipp doppelt vorkommen.
   - mindestens drei der Zahlen sollen aufeinander folgen 
     und größer als 31 sein.
*/
#include <iostream>             // Standard I/O-Klassen
#include <conio>                // fuer getch(), window() und clrscr()
using namespace std;
int main()                      // Hauptfunktion
{ int *p,s,i,j,k,h,doppel,ueb31,drei;
  randomize();
  cout << "\n\t Programm zur Ermittlung zuf„lliger Lottotips";
  cout << "\n\t Bitte die Anzahl der gewnschten Tips eingeben!\n";
  do { cout << "\nAnzahl = "; cin >> s; } while (s<=0);
  p=new int[s*6];                            // Dynamischen Speicher bereitstellen.
  for(i=0;i<s;i++)
  { do
    { drei=0; ueb31=0; p[i*6]=random(49)+1;	 // 1. Lottozahl
      if(p[i*6]>31) ueb31++;				 // über 31?
      for(j=1;j<=5;j++)						 // Schleife 2. ... 6. Lottozahl
      { do { doppel=0; p[i*6+j]=random(49)+1;
	         for(k=0;k<j;k++) if(p[i*6+k]==p[i*6+j]) doppel++; // doppelte Zahl?
	       } while(doppel);
	    if(p[i*6+j]>31) ueb31++;             // über 31?
      }
      if(ueb31==3)
      { for(j=1;j<=5;j++)
        { for(k=0;k<j;k++)
            if(p[i*6+k]>p[i*6+j])              // Reihenfolge falsch?
            { h=p[i*6+k]; p[i*6+k]=p[i*6+j]; p[i*6+j]=h;  // Tauschen
            }
        }
	    for(k=0;k<4;k++)                       // Folgen drei Zahlen aufeinander?
	      if((p[i*6+k]+1==p[i*6+k+1]) && (p[i*6+k]+2==p[i*6+k+2])) { drei++; break; }
      }
    } while((ueb31!=3)||(!drei));
  }
  for(i=0;i<s;i++)							   // Ausgabeschleife
  { for(j=0;j<=5;j++) 
      cout << "\t" << p[i*6+j]; 
    cout << endl;  
  }
  delete p;                                  // Dynamischen Speicher freigeben.
  getchar();
  return 0;
}
