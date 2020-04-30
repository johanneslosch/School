// Th.Cassebaum, 19.5.2004, all rights reserved
#include <iostream.h>
struct person
{ float Gross;
  string Name;
  bool Frau;
};
void Datein(person &x);
void Dataus(person x);
int main()
{ person *Soldat; int i,j,zahl;
  cout << "Zahl der Soldaten : ";
  cin >> zahl;
  Soldat=new person[zahl];
  if(!Soldat)
  { cout << "\Speicherfehler!"; 
    return 1;
  }
  for(i=0;i<zahl;i++) 
  { Datein(Soldat[i]);
    if(Soldat[i].Name=="#") break;
  }
  for(j=0;j<i;j++) Dataus(Soldat[j]);
  getchar();
  return 0;
}
void Datein(person &x)
{ char a;
  cout << "Name : "; cin >> x.Name;
  if(x.Name=="#") return;
  cout << "Größe: "; cin >> x.Gross;
  cout << "Geschl.[m/w]: "; cin >> a;
  if(a=='w'||a=='W') x.Frau=true;
  else x.Frau=false;  
}
void Dataus(person x)
{ cout << "\nName : " ;
  if(x.Frau) cout << "Frau ";
  else cout << "Herr ";
  cout << x.Name;
  cout << "\nGröße: " << x.Gross << "m";
}

