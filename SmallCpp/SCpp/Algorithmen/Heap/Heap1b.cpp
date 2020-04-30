/* Th.Cassebaum , 5.5.2004, all rights reserved
   Speichern Sie in einem aufzubauenden dynamischen Speicherbereich eine 
   zufällige Anzahl (5…5000) reeller Zahlen. Die per Zufallszahlen zu be-
   stimmenden reellen Zahlen besitzen maximal zwei Nachkommastellen und 
   sind aus dem Bereich -2000.00,…,+1999.99 . Errechnen Sie die Summe und 
   den Mittelwert aller reeller Zahlen im dynamischen Array und geben Sie 
   das Ergebnis über Bildschirm aus!
*/
#include <iostream>
using namespace std;
int main()
{ float *z,s=0.; int anz,i;     
  randomize();
  anz=random(4996)+5;
  z=new float[anz];
  for(i=0;i<anz;i++)
  { z[i]=(random(400000)-200000)/100.;
    s+=z[i];
  }
  cout << "Summe der " << anz << " Zahlen = " 
       << s << ", Mittelwert = " << s/anz;
  getchar();
  return 0;
}
