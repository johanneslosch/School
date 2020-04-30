// Thomas Cassebaum 2011, all rights reserved
#include <iostream>
using namespace std;
int main()   
{ 
  int benzin_getankt, distanz; 
  cout << "Distanz:\n";
  cin >> distanz;
  cout << "Benzin getankt:\n";
  cin >> benzin_getankt;
  cout << "Verbrauch: " << benzin_getankt * 100 / distanz << endl;
  getchar();
  return 0; 
}