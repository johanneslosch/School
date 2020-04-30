// SmallC++ 2010, all rights reserved
#include <iostream>
using namespace std;
struct person
{ string name;    // Familienname
  int alter;      // Alter in Jahren
  float Groesse;  // in Meter
  float fingerlang[10];  // in cm
} ;
void In(person*);
void Out(person*);
int main()   
{ person Lilo, *Fiktiv, *point = &Lilo;
  // Lilo.name = "Unger"; Lilo.alter = 18; Lilo.Groesse = 1.67; Lilo.fingerlang[0] = 9.7;
  Fiktiv = new person; 
  // Fiktiv->name = "Lottemann"; Fiktiv->alter = 72; Fiktiv->Groesse = 1.71; Fiktiv->fingerlang[0] = 8.8;
  In(point); In(Fiktiv);
  Out(point); Out(Fiktiv);
  getchar();
  return 0; 
}
void In(person *p)
{ cout << "Name   : "; cin >> p->name; 
  cout << "Alter  : "; cin >> p->alter; 
  cout << "Groesse: "; cin >> p->Groesse; 
  for(int i=0;i<10; i++)
  { cout << "Laenge Finger " << i+1 << " = ";
    cin >> p->fingerlang[i];
  }  
}
void Out(person *p)
{ cout << "\n\nDie Person heisst " << p->name << ", sie ist " << p->alter << " Jahre alt und " << p->Groesse << " m gross."
       << "\nDie Finger der linken Hand sind ";
  for(int i=0;i<5;i++) cout << p->fingerlang[i] << ", "; cout << " cm lang."; 
  cout << "\nDie Finger der rechten Hand sind ";
  for(int i=5;i<10;i++) cout << p->fingerlang[i] << ", "; cout << " cm lang."; 
}