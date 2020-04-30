// Th.Cassebaum, 18.5.2004, all rights reserved
// Erstellen Sie eine Struktur Fach zur Speicherung von bis zu 10 mündlichen 
// und bis zu 10 schriftlichen Zensuren oder Notenpunkten (00...15) für ein 
// Unterrichtsfach. Weiter werden die Bezeichnung des Unterrichtsfaches und 
// der(die) Name(n) der bis zu 5 unterrichtenden Lehrer(innen) in die Struktur 
// aufgenommen. Bilden Sie eine Funktion Fach_ein() zur Eingabe der Fachbezeich-
// nung, der Lehrernamen und der Noten (gesondert nach mündlichen und schrift-
// lichen Noten). Erstellen Sie eine Funktion Fach_aus() zur Ausgabe aller 
// Daten dieser Struktur, ergänzt durch den Mittelwert der mündlichen und 
// schriftlichen Noten.
#include <iostream.h>
struct Fach
{ short mdl[10];
  short sch[10];
  string fachbez;
  string lehrer[5];
};
Fach Fach_ein();
void Fach_aus(Fach f);
int main()
{ Fach f;
  f=Fach_ein();
  Fach_aus(f);
  getchar();
  return 0;
}
Fach Fach_ein()
{ Fach f; int i;
  cout << "\nFachbez. : "; cin >> f.fachbez;
  cout << "Nach dem letzten Lehrer # eingeben!\n";
  for(i=0;i<5;i++)
  { cout << i+1 << ". Lehrer   : "; cin >> f.lehrer[i];
    if(f.lehrer[i]=="#")
    { f.lehrer[i]=""; break; }
  }
  cout << "Nach der letzten mdl.Note -1 eingeben!\n";
  for(i=0;i<10;i++)
  { cout << i+1 << ". mündl.Note : "; cin >> f.mdl[i];
    if(f.mdl[i]<0||f.mdl[i]>15)
    { f.mdl[i]=-1; break; }
  }
  cout << "Nach der letzten schrft.Note -1 eingeben!\n";
  for(i=0;i<10;i++)
  { cout << i+1 << ". schrf.Note : "; cin >> f.sch[i];
    if(f.sch[i]<0||f.sch[i]>15)
    { f.sch[i]=-1; break; }
  }
  return f;
}
void Fach_aus(Fach f)
{ int sm=0,ss=0,i;
  cout << "\nFachbezeichnung: " << f.fachbez<<endl;
  for(i=0;i<5;i++)
  { if(f.lehrer[i]!="")
      cout << i+1 << ". Lehrer : "<< f.lehrer[i] << endl;
    else break;
  }
  for(i=0;i<10;i++)
  { if(f.mdl[i]<0) break;
    cout << i+1 << ". mündl. Note : "<< f.mdl[i] << endl;    
    sm+=f.mdl[i];
  }
  cout << "Mittelwert mündlich: " << (float)sm/i<<endl;
  for(i=0;i<10;i++)
  { if(f.sch[i]<0) break;
    cout << i+1 << ". schrf. Note : "<< f.sch[i] << endl;
    ss+=f.sch[i];
  }
  cout << "Mittelwert schrftl.: " << (float)ss/i<<endl;
}
