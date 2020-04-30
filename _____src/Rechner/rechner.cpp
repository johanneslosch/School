// Thomas Cassebaum 2011, all rights reserved
#include <iostream>
using namespace std;
int main()   
{ 
float z1 = 0.0, z2 = 0.0;
int menue = 0;
	cout << "Rechner\n";
	cout << "Geben Sie was ein!\n";
	cout << "\n";
	cout << "\n";
	cout << "+ : 1\n"<<
		  "- : 2 \n"<< 
		  "* : 3 \n"<< 
		  "/ : 4\n";
	cout << "\n";
	cin >> menue;
	
	if(menue > 4 && menue >= 1){
		return 1;
	}
	cout << "\n";
	cout << "Geben Sie die beiden Zahlen nacheinander ein!\n";
	
	cin >> z1;
	cin >> z2;
	
	switch(menue){
		case 1: {
			cout << "Ergebnis: " << z1 + z2<<endl;
			break;
		}
		case 2: {
			cout << "Ergebnis: " << z1 - z2<<endl;
			break;
		}
		case 3: {
			cout << "Ergebnis: " << z1 * z2<<endl;
			break;
		}
		case 4: {
			if(z2 > 0){
			cout << "Ergebnis: " << z1 / z2<<endl;
			break;
			}else
				return 1;
		}
		default: {
			cout << "Fehlerhafte Eingabe!\n";
			break;
		}
	}
	
	getchar();
	return 0; 
}