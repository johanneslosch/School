// Thomas Cassebaum 2011, all rights reserved
#include <iostream>
using namespace std;
int main() { 
	int umsatz;
	cout << "Provisionsrechner\n";
	cout << "Geben Sie den Umsatz in EUR ein!\n";
	cin >> umsatz;
	if(umsatz >= 100000){
		cout << "Die Provision betr\204gt: " << umsatz*0.075 << " EUR.\n";
	}else if (umsatz <= 100000){
		cout << "Die Provision betr\204gt: " << umsatz*0.05 << " EUR.\n";
	}else {
		cout << "Unbekannter Fehler!\n";
	}
  getchar();
  return 0; 
}