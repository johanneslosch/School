// Th.Cassebaum, 29.6.2003, all rights reserved
#include <iostream.h>
class Vati
{ public: Vati(){}
          Vati(float ak,float bk)
          { a=ak; b=bk; }
          float Summe();
  protected: float a, b;
};
class Kind:public Vati
{ public: Kind(float ak,float bk,float ck)
          { a=ak; b=bk; c=ck; }
          float Summe();
  protected: float c;
};

int main()
{ Kind K(1,2,3); Vati V(1,2);
  cout <<"Vatis Summe : "<< V.Summe();
  cout <<"\nKinds Summe : "<< K.Summe();
  getchar();
  return 0;
}
float Vati:: Summe()
{ return a + b; }
float Kind:: Summe()
{ return Vati::Summe()+c; }


