// Th.Cassebaum, 19.5.2004, all rights reserved
#include <iostream.h>
struct dat
{ unsigned short day,mon,year;
};
struct person
{ char tel[12];
  string name;
  dat gebdat;
};
bool Datein(person &x);
void Dataus(person x);
int main()
{ person *gebkind; int i,j,zahl;
  cout << "Zahl der Personen : ";
  cin >> zahl;
  gebkind=new person[zahl];
  if(!gebkind){ cout << "\Speicherfehler!"; return 1; }
  for(i=0;i<zahl;i++) 
  { Datein(gebkind[i]);
    if(gebkind[i].name=="#") break;
  }
  for(j=0;j<i;j++) Dataus(gebkind[j]);
  getchar();
  return 0;
}
bool Datein(person &x)
{ char a;
  cout << "Name : "; cin >> x.name;
  if(x.name=="#") return false;
  cout << "Telefon-Nr.: "; cin >> x.tel;
  cout << "Geburtsdatum, \nTag [2-stlg.]    : "; cin >> x.gebdat.day;
  cout << "Monat [2-stlg.] : "; cin >> x.gebdat.mon;
  cout << "Jahr  [4-stlg.] : "; cin >> x.gebdat.year;
  return true;  
}
void Dataus(person x)
{ cout << "Name : " << x.name
       << ", Tel.-Nr.: " << x.tel 
       << ", geb.am " << x.gebdat.day << "."
       << x.gebdat.mon << "." << x.gebdat.year; 
}

