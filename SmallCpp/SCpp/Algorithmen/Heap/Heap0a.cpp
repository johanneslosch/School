/* Th.Cassebaum, 6.5.2004, all rights reserved
   Bilden Sie im Heap n natürliche Zufallszahlen (5...1000)
   und geben Sie diese sortiert aus!
*/
#include <iostream>
using namespace std;
int main()
{ int *p,z,i,h; bool swp=true;
  do
  { cout << "Wieviel Zahlen [>2]: "; cin >> z;
  } while(z<3);
  p = new int[z];  // Heap-Zuweisung
  if(!p) exit(1);  // Abbruch wegen alloc-Fehler
  randomize();
  for(i=0;i<z;i++) p[i]=random(996)+5;  // Füllen
  while(swp)
  { swp=false;
    for(i=0;i<(z-1);i++)
      if (p[i]>p[i+1])
      { h=p[i];p[i]=p[i+1];p[i+1]=h;swp=true; }
  }
  for(i=0;i<z;i++) cout << p[i] << " "; // Ausgeben
  delete p;
  getchar();
  return 0;
}
