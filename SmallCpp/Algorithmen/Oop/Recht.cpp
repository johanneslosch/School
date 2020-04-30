// Ablaufverfolgung der Kon- und Destruktoren
// Th.Cassebaum, 29.6.2003, all rights reserved 

#include <iostream.h> 
class Recht 
{ public: float Flaeche();
          float Umfang();
          Recht(){ cout << " Kon1 läuft!";};
          Recht(float,float);
          ~Recht(){ cout << "\nDestruktor läuft!"; }
  private: float b; float h;
} A(3,4),B(2,3);
void main() 
{ Recht C,D[8],*E;
  E=new Recht(2,3);
  cout << endl << E->Flaeche();
  cout << endl << D[2].Umfang()-E->Umfang();
  delete E;
  cout << endl <<A.Flaeche()+B.Umfang();
  getchar();
}
Recht::Recht(float bk,float hk)
{ b=bk; h=hk; cout << "\nKon2 läuft!";}
float Recht:: Flaeche() { return b*h;}
float Recht:: Umfang() { return 2*b+2*h;}

