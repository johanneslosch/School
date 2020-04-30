// Thomas Cassebaum 2011, all rights reserved
#include <iostream>
using namespace std;
int main(){
	float workHours, workovertime, payPerHour;
	float iststunden, sollStunden;
	const float upToTen = 0.25, overTen = 0.3;
	
	cout << "BruttoArbeitsrechnerdings\n";
	cout << "Geben Sie den Stundensatz an!\n";
	cin >> payPerHour;
	cout << "Geben Sie die festgelegte Arbeitszeit ein!\n";
	cin >> sollStunden;
	cout << "Geben Sie die tats\204chliche Arbeitszeit ein!\n";
	cin >> iststunden;
	
	workovertime = iststunden-sollStunden ;
	workHours = sollStunden;
	
	if(workovertime >= workHours*0.1){
		cout << "Zahlung betr\204gt: " << (workHours * payPerHour)/0.25 + workovertime * payPerHour << " EUR.\n";
	}else {
		cout << "Zahlung betr\204gt: " << (workHours * payPerHour)/0.3 + workovertime * payPerHour << " EUR.\n";
	}
	
  getchar();
  return 0; 
}