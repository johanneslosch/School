// Johannes Losch 2019, all rights reserved
#include <iostream>
using namespace std;
int main()   
{ 
  int _cooperateYears;
  float __costs, __reduce, _units, ___costs;
  
  //cooperate Years
  cout << "Enter cooperate Years\n";
  cin >> _cooperateYears;
  
  //units
    cout << "Enter count of Units\n";
  cin >> _units;
  
  //costs
  cout << "Enter pricing from the item\n";
  cin >> __costs;
  
  ___costs = __costs * _units;
  if(_cooperateYears <= 10){
  	if(_units <= 500){
  		__reduce = 0.02;
  		cout << "price is " <<___costs - (___costs * __reduce)<< " EUR."<<endl; 
  	}else if(_units > 500 && _units <= 1000){
  		__reduce = 0.05;
  		cout << "price is " <<___costs - (___costs * __reduce)<< " EUR."<<endl; 
  	}else if (_units >= 1001){
  		__reduce = 0.10;
  		cout << "price is " <<___costs - (___costs * __reduce)<< " EUR."<<endl; 
  	}else{
  		cout << "Error at unit count\n";
  		return 1;
  	}
  }else
  	cout << "price is " <<___costs<< " EUR."<<endl; 
  
  getchar();
  return 0; 
}