#include <iostream.h>
#include <conio.h>
class vector
{ public:
    vector(unsigned short dm);   // Konstruktor
    void VectStr(void);
    double VectNorm(void);
    vector operator+(vector &x);   // Operatorüberladung ADD für Klasse vector
    vector operator-(vector &x);   // Operatorüberladung SUB für Klasse vector
    double operator*(vector &x);   // Operatorüberladung Skalarprodukt
    double*pt;
  private:
    unsigned short dim;        // private Werte
};
double vector::VectNorm(void)
{ double y=0;
  if(dim>0)
  { for(int i=0;i<dim;i++)
    { y+=(double)pt[i]*(double)pt[i];}
  }
  return sqrt(y);
}
double vector::operator*(vector &x)
{ double y=0;
  if((dim>0)&&(dim==x.dim))
  { for(int i=0;i<dim;i++)
    { y+=(double)pt[i]*(double)x.pt[i];}
  }
  return y;
}
vector vector::operator+(vector &x)
{ static vector y(dim);
  if((dim>0)&&(dim==x.dim))
  { for(int i=0;i<dim;i++)
    { y.pt[i]=pt[i]+x.pt[i];}
  }
  else {y.dim=0; }
  return y;
}
vector vector::operator-(vector &x)
{ static vector y(dim);
  if((dim>0)&&(dim==x.dim))
  { for(int i=0;i<dim;i++)
    { y.pt[i]=pt[i]-x.pt[i];}
  }
  else {y.dim=0; }
  return y;
}
void vector::VectStr(void)
{ if(dim)
  { cout<<"(";
    for(int i=0;i<dim;i++)
    { cout<<pt[i];
      if(i<dim-1)cout<<",";
    }
    cout<<")";
  }
  else cout<<"#Nullvektor#";
}
vector::vector(unsigned short dm)   // Konstruktor
{ if(dm)
  { pt = new double[dm];
    dim=dm;
  }
  else exit(1);
}
int main()
{ vector r(5),s(5);
  r.pt[0]=3;r.pt[1]=5;r.pt[2]=4;r.pt[3]=7;r.pt[4]=6;
  s.pt[0]=2;s.pt[1]=1;s.pt[2]=8;s.pt[3]=0;s.pt[4]=9;
  cout<<"Vektor      r: ";r.VectStr();
  cout<<"\nVektor      s: ";s.VectStr();
  cout<<"\nVektor    r+s: ";(r+s).VectStr();
  cout<<"\nVektor    r-s: ";(r-s).VectStr();
  cout<<"\nProdukt   r*s: "<<r*s<<" (Skalarprodukt)";
  cout<<"\nVektornorm(r): "<<r.VectNorm();
  getch();
  return 0;
}

