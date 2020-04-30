// Th.Cassebaum, 29.6.2003, all rights reserved
#include <iostream.h>
class Recht 
{ public:    float Flaeche();
  protected: float b, h;
};
class Quader:public Recht
{ public:
    Quader(float bk,float hk,float lk)
    { b=bk; h=hk; l=lk; }
    float Volumen();
  protected: float l;
};
int main()
{ Quader Q(1,2,3);
  cout <<"Grundfläche: "<< Q.Flaeche();
  cout <<"\nVolumen    : "<< Q.Volumen();
  getchar();
  return 0;
}
float Recht:: Flaeche()
{ return b*h;}
float Quader:: Volumen()
{ return Flaeche()*l; }

