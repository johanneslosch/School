// Th.Cassebaum, C++ Trainer, 9.7.2008, all rights reserved
// Vektorklasse für n-dimensionale Vektoren

// vector v(3,-1,1,2)      3-dim. Vektorobjekt mit den Komponenten (-1,1,2)
// vector u;               4-dim. Nullvektor
// vector w(2);            2-dim. Nullvektor
// v.cp[0]                 x-Komponente des Vektors v
// v.cp[1]                 y-Komponente des Vektors v
// v.Str()                 Gibt nullterminierten String zum Vektor v zurück z.B.(-1,1,2)
// u+v, u-v                Gibt Summmen-(Differenzen-)vector der vektoraddierten u+v(u-v) zurück
// u*v                     Gibt das Skalarprodukt u*v als double-Wert zurück 
// u%v                     Gibt das Vektorprodukt als vector zurück (nur 3-dim.)
// v.Length()              Gibt die Länge des Vektors v als unsigned-Wert zurück

class vector
{ public:
    vector(unsigned short dm,double,double,double,double); // Konstruktor für max. 4-dim-Vektoren
    vector(unsigned short dm);    // Konstruktor für Nullvektoren 
    vector();                     // Konstruktor für 4-dim. Nullvektoren
    char* Str();
    double Length();
    vector operator+(vector &x);        // Operatorüberladung ADD für Klasse vector
    vector operator-(vector &x);        // Operatorüberladung SUB für Klasse vector
    double operator*(vector &x);        // Operatorüberladung Skalarprodukt
    vector vector::operator%(vector &x);// Operatorüberladung Vektorprodukt
    double* cp;
  private:
    unsigned short dim;        // private Werte
};
double vector::Length()
{ double y=0;
  if(dim>0)
  { for(int i=0;i<dim;i++)
    { y+=(double)cp[i]*(double)cp[i];}
  }
  return sqrt(y);
}
vector vector::operator%(vector &x)
{ short mi=min(dim,x.dim);
  static vector y(mi);
  if(mi==3)
  { y.cp[0]=cp[1]*x.cp[2]-cp[2]*x.cp[1];
    y.cp[1]=-cp[0]*x.cp[2]+cp[2]*x.cp[0];
    y.cp[2]=cp[0]*x.cp[1]-cp[1]*x.cp[0];
  }
  return y;
}
double vector::operator*(vector &x)
{ double y=0.;
  if((dim>0)&&(x.dim>0))
  { short mi=min(dim,x.dim);
    for(short i=0;i<mi;i++)
    { y+=(double)cp[i]*(double)x.cp[i];}
  }
  return y;
}
vector vector::operator+(vector &x)
{ static vector y(min(dim,x.dim));
  if(dim>0) for(int i=0;i<min(dim,x.dim);i++) y.cp[i]=cp[i]+x.cp[i];
  return y;
}
vector vector::operator-(vector &x)
{ static vector y(min(dim,x.dim));
  if(dim>0) for(int i=0;i<min(dim,x.dim);i++) y.cp[i]=cp[i]-x.cp[i];
  return y;
}
char* vector::Str()
{ static char s[12],v[50];v[0]=0;
  if(dim)
  { strcpy(v,"(");
    for(int i=0;i<dim;i++)
    { gcvt(cp[i],6,s);
      strcat(v,s);
      if(i<dim-1)strcat(v,"|");
    }
    strcat(v,")");
  }
  return v;
}
vector::vector(unsigned short dm,double x,double y=0,double z=0,double t=0)
{ if(dm)
  { cp = new double[dm]; dim=dm;
    cp[0]=x; if(dim>1){cp[1]=y; if(dim>2){cp[2]=z; if(dim>3)cp[3]=t;}}
  }
  else exit(1);
}
vector::vector(unsigned short dm)    // Konstruktor für n-dim.Nullvektoren 
{ if(dm)
  { cp = new double[dm]; dim=dm;
    while(dm--) cp[dm]=0;
  }
  else exit(1);
}
vector::vector()    // Konstruktor für 4-dim.Nullvektoren 
{ cp = new double[4]; dim=4;
  cp[0]=cp[1]=cp[2]=cp[3]=0;
}

