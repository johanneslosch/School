// Thomas Cassebaum 2011, all rights reserved
#include <iostream>
using namespace std;
int main()   
{ 
  float bjahre, evorjahr;
  
  cout << "Geben Sie Ihre Betriebsgeh\224rigkeit an! (Jahre)\n";
  cin >> bjahre;
  cout << "Geben Sie ihr Einkommen vom letzten Jahr an!\n";
  cin >> evorjahr;
  
  if(bjahre <= 2){
  	cout << "Sie erhalten eine Pr\204mie von " << evorjahr * 0.05 << " EUR.\n";
  }else if(bjahre >2 && bjahre <= 5){
  	cout << "Sie erhalten eine Pr\204mie von " << evorjahr * 0.10 << " EUR.\n";
  }else if(bjahre >5 && bjahre <= 15){
  	cout << "Sie erhalten eine Pr\204mie von " << evorjahr * 0.15 << " EUR.\n";
  }else if(bjahre > 15){
  	cout << "Sie erhalten eine Pr\204mie von " << evorjahr * 0.20 << " EUR.\n";
  }else {
  	cout << "ung\201ltige Eingabe!\n";
  }
  
  getchar();
  return 0; 
}