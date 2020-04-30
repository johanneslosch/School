#include <iostream>
using namespace std;
int main()   
{ 
float kapital, tage, zinssatz; 
  cout << "Zinsberechnung \n";
  cout << "Geben Sie ihr Kapital an!" << endl;
  cin >> kapital;
  cout << "Geben Sie nun den Zinssatz an" << endl;
  cin >> zinssatz / 100;
  cout << "Geben Sie nun die Laufzeit in Tagen an" << endl;
  cin >> tage;
  cout << "Die Zinsen betragen: " << (kapital * zinssatz * tage) / 360 << "€" << endl;
  getchar();
  return 0; 
}