#include <iostream.h>
#include <conio.h>
class vector
{ public:
    vector(float,float,float);// Eingabe-Konstruktor
    vector();                 // par.loser Konstruktor
    void VectStr(void);       // Ausgabemethode
    vector plus(vector);      // Vektoraddition
    float skalar(vector);    // Skalarprodukt
  private:
    float k[3];               // private Vektorkomponenten
};
int main()
{ vector r(3,4,5),h(1,1,1);
  cout<<"Vektor        r: "; r.VectStr();
  cout<<"\nVektor        h: "; h.VectStr();
  cout<<"\nVektor      r+h: "; r.plus(h).VectStr();
  cout<<"\nSkalarprod. r*h: " << r.skalar(h);
  getch();
  return 0;
}
void vector::VectStr(void)
{ cout<<"("<<k[0]<<";"<<k[1]<<";"<<k[2]<<")";
}
vector::vector()              // par.loser Konstruktor
{ for(int i=0;i<3;i++) k[i]=0.;}
vector::vector(float k0,float k1,float k2) // Eing.-Konstruktor
{ k[0]=k1; k[1]=k1; k[2]=k2; }
vector vector::plus(vector v)       // Vektoradddition
{ static vector h;
  for(int i=0;i<3;i++) h.k[i]=v.k[i]+k[i];
  return h;
}
float vector::skalar(vector v)      // Skalarprodukt
{ static float h=0.;
  for(int i=0;i<3;i++) h+=v.k[i]*k[i];
  return h;
}


