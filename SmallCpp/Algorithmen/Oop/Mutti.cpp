// Th.Cassebaum, 29.6.2003, all rights reserved
#include <iostream.h>
class Mutti
{ public:    float Summe();
             float a, b;
};
class Embryo
{ public: Mutti M;
          Embryo(float ak,float bk,float ck)
          { M.b=bk; M.a=ak; c=ck; }
          float Summe();
  protected: float c;
};

int main()
{ Embryo E(1,2,3);
  cout <<"Muttis  Summe : "<< E.Summe();
  cout <<"\nEmbryos Summe : "<< E.M.Summe();
  getchar();
  return 0;
}
float Mutti:: Summe()
{ return a + b; }
float Embryo:: Summe()
{ return M.Summe()+c; }

