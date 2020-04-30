// Johannes Losch
#include <iostream>
using namespace std;
int main()   
{
int input; 
float pi = M_PI;
cout << "Waelen Sie was Sie berechnen wollen.\n 1: Zylinder\n 2: Wuefel\n 3: Quadrat\n 4: Kreisgegel\n";
cin >> input;
switch(input){
	
	//Zylinder
	case 1 : {
	float r, h;
		cout << "Geben Sie den Radius (cm) ein: ";
		cin >> r;
		cout << "Geben Sie die Hoehe (cm) ein: ";
		cin >> h;
		
		cout << "Volumina: " << pi*r*r*h << " cm^3.\n";
		cout << "Oberflaeche: " << 2*pi*r*(r+h) << " cm^2.\n";
		break;
	}
	
	//Würfel
	case 2: {
		float s;
		cout << "Geben Sie die Seitenlaenge (cm) ein: ";
		cin >> s;
		
		cout << "Volumina: " << s*s*s << " cm^3.\n";
		cout << "Oberflaeche: " << 6*s << " cm^2\n";
		break;
	}
	
	//Quadrat
	case 3 : {
		float a, b, c;
		cout << "Geben Sie die Seitenlaenge 1 (cm) ein: ";
		cin >> a;
		cout << "Geben Sie die Seitenlaenge 2 (cm) ein: ";
		cin >> b;
		cout << "Geben Sie die Seitenlaenge 3 (cm) ein: ";
		cin >> c;
		
		cout << "Volumina: " << a*b*c << " cm^3.\n";
		cout << "Oberflaeche: " << 2*(a*b+a*c+b*c) << " cm^2\n";
		break;
	}
	
	//Kreiskegel
	case 4 : {
		float r, s, h;
		cout << "Geben Sie den Radius (cm) ein: ";
		cin >> r;
		cout << "Geben Sie die Seitenlaenge (cm) ein: ";
		cin >> s;
		cout << "Geben Sie die Hoehe (cm) ein: ";
		cin >> h;
		
		cout << "Volumina: " << pi/3*pi*pi*h << " cm^3.\n";
		cout << "Oberflaeche: " << 2*pi*r*(r+s) << " cm^2\n";
		break;
	}
	default: {
		cout << "Ungueltige Eingabe!\n";
		return 1;
	}
}
  getchar();
  return 0; 
}