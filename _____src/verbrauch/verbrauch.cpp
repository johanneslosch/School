// Thomas Cassebaum 2011, all rights reserved
#include <iostream>
using namespace std;
int main()   
{ 
  float zaeler_old, zaeler_new;
  const float preis = 0.20;
  cout << "Energieverbrauch und Kosten\n"; 
  cout<< "alter Z\204hlerstand\n";
  cin>> zaeler_old;
  cout<< "neuer Z\204hlerstand\n";
  cin>> zaeler_new;
  if(zaeler_old < zaeler_new){
    cout << "Z\204lerstand Unterschied betr\204gt: " << zaeler_new - zaeler_old << endl;
    cout << "Preis ist: " << preis * (zaeler_new - zaeler_old) <<endl;
  }else{
  return 1;
  }nn
  getchar();
  return 0; 
}