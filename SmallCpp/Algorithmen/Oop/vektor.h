// programmiert von Th.Cassebaum am 1.9.2007 gegen 11:57 Uhr
// all rights reserved
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

