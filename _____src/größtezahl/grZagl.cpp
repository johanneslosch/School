// Thomas Cassebaum 2011, all rights reserved
#include <iostream>
using namespace std;
int main()   
{ 
int z1, z2, z3, grZ = 0;
cout<<"Enter Zahlen\n";
cin>>z1;
cin>>z2;
cin>>z3;

if((z1 == z2) || (z1 == z3)){
	if(z2 != z3){
		if(z2 < z3) {
			grZ = z3;
		}else{
			grZ = z2;
		}
	}
}else if(z1 < z2){
	if(z3 < z2){
		grZ = z2;
	}else if(z3 > z1){
		grZ = z3;
	}else {
		grZ = z1;
	}
}
cout<<"Gr\224\341te Zahl: " << grZ << endl;
  getchar();
  return 0; 
}