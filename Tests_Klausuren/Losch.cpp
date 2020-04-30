// Johannes Losch 2019, all rights reserved
#include <iostream>
using namespace std;
int main()   
{ 
  float _alter, _betriebsjahre;
  int __tage = 0;
  cout << "Geben Sie ihr Alter ein!\n";
  
  //Eingaben
  cin >> _alter;
  cout << "Geben Sie die Dauer Ihrer Betriebszugeh\231rigkeit ein!\n";//231 - großes Ö - finde das kleine ö nicht
  cin >> _betriebsjahre;
  
  if(_alter < 18){
  	__tage += 30;
  }else{
  	if(_alter <= 40){
  		__tage += 28;
  	}else if(_alter > 40){
  		__tage += 31;
    	}else {
  		cout << "ERROR: unbekannter Fehler";
  	}
  }
  if (_betriebsjahre >=10){
  	if(_betriebsjahre >=25){
  		__tage += 2;
  	}else{
  		__tage += 1;
  	}
  }
  
  cout << "Sie haben einen Anspruch auf " << __tage << " Urlaubstage\n";
  
  getchar();
  return 0; 
}