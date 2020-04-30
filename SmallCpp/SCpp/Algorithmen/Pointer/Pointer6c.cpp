// Th. Cassebaum, 29.4.2004, all rights reserved
// Erstellen Sie ein Array „good“ von 10 guten und 
// ein Array „bad“ von 10 schlechten menschlichen 
// Eigenschaften ihrer Wahl! Legen Sie weiter ein 
// Zeigerarray mit 2 Elementen an, die die Adressen 
// von good und bad enthalten! Fragen Sie den Bedie-
// ner nach seinem Namen und antworten Sie mit einem 
// Satz der eine beliebige gute und eine beliebige 
// schlechte Eigenschaft aus den Listen anzeigt! Sor-
// gen Sie dafür, dass bei einer späteren erneuten 
// gleichen Namenseingabe wieder der gleiche Satz an-
// gezeigt wird! ( z.B.: Traudi, Du bist wirklich 
// schön, aber hinterlistig!) 
#include <iostream.h>
int main()
{ int sum=0;
  string bad[10]={"doof","gemein","gehässig","gerissen","hinterlistig","blöd","böse","verlogen","schmutzig","unordentlich"},
         good[10]={"gut","brav","fein","prima","oho","toll","lieb","klug","hübsch","schön"};
  char name[30], *z;
  z=name;         
  cout << "Wie heißt Du? "; cin >> name;
  while(z<=&name[strlen(name)/2]) sum+=(int)*z++;
  sum=sum%10;
  cout << name << ", Du bist " << good[sum]; 
  sum=0;
  while(z<=&name[strlen(name)]) sum+=(int)*z++;
  sum=sum%10;
  cout << ", aber " << bad[sum] << "!";
  getchar();
  return 0;
}
