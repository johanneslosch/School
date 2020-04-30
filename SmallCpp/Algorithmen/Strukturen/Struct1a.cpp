// Th.Cassebaum, 18.5.2004, all rights reserved
// Für eine Berufsschule werden gedruckte Schülerlisten benötigt, 
// die alphabetisch nach dem Namen, dem Alter und nach dem Ge-
// schlecht geordnet ausgegeben werden können. Erstellen Sie eine 
// C++ Struktur Schueler, die als Attribute ein Textfeld "Name", 
// ein logisches Feld zur Speicherung des Geschlechts und ein Ganz-
// zahlenfeld "Alter" integriert. Bilden Sie Funktionen zur Daten-
// eingabe Create() und zur nach dem Sortierattribut sortierten 
// Druckausgabe List(Sortierattribut). Testen Sie die Funktionen 
// Create und List in der Hauptfunktion durch passende Aufrufe!
#include <iostream.h>
#include <iomanip.h>
struct schueler
{ string Name;
  bool Frau;
  unsigned short Alter;
};
schueler Create();
void List(int sa);
schueler *p;
int main()
{ unsigned int anz,i,j;
  cout << "Maximale Schülerzahl: "; cin >> anz;
  p = new schueler[anz];
  cout << "Zum Beenden # als Namen eingeben!" << endl;
  for(i=0;i<anz;i++) 
  { p[i]=Create();
    if(p[i].Name=="") break;  
  }
  List(0); List(1); List(2);
  getchar();
  return 0;
}
schueler Create()
{ schueler sch; char a,n[50];
  cout << "Name           : "; cin >>sch.Name;
  if(sch.Name.substr(0,1)=="#") 
  { sch.Name=""; return sch;}
  do { cout << "Alter          : "; 
       while((cin.peek())>'9'||cin. peek()<'0')cin.ignore();
       cin >> sch.Alter; 
     } while(sch.Alter<0||sch.Alter>120);
  do
  { cout << "Geschlecht(m/w): "; cin >> a;
  } while(a!='m'&&a!='M'&&a!='w'&&a!='W');
  if(a=='m'||a=='M') sch.Frau=false; else sch.Frau=true;
  return sch;
}
void List(int sa)
{ schueler *u,h; bool swap=true;
  switch(sa)
  { case 0: 
    { while(swap)
      { swap=false;
        for(u=p+1;u->Name!="";u++)
        { if(u->Name<(u-1)->Name)
          { h.Name=u->Name; u->Name=(u-1)->Name; (u-1)->Name=h.Name; 
            h.Alter=u->Alter; u->Alter=(u-1)->Alter; (u-1)->Alter=h.Alter; 
            h.Frau=u->Frau; u->Frau=(u-1)->Frau; (u-1)->Frau=h.Frau; 
            swap=true;
          }
        }
      }
      cout << "\nsortiert nach dem Namen:\n";
    } break; 
    case 1: 
    { while(swap)
      { swap=false;
        for(u=p+1;u->Name!="";u++)
        { if(u->Alter<(u-1)->Alter)
          { h.Name=u->Name; u->Name=(u-1)->Name; (u-1)->Name=h.Name; 
            h.Alter=u->Alter; u->Alter=(u-1)->Alter; (u-1)->Alter=h.Alter; 
            h.Frau=u->Frau; u->Frau=(u-1)->Frau; (u-1)->Frau=h.Frau; 
            swap=true;
          }
        }
      }
      cout << "\nsortiert nach dem Alter:\n";
    } break; 
    case 2: 
    { while(swap)
      { swap=false;
        for(u=p+1;u->Name!="";u++)
        { if(u->Frau<(u-1)->Frau)
          { h.Name=u->Name; u->Name=(u-1)->Name; (u-1)->Name=h.Name; 
            h.Alter=u->Alter; u->Alter=(u-1)->Alter; (u-1)->Alter=h.Alter; 
            h.Frau=u->Frau; u->Frau=(u-1)->Frau; (u-1)->Frau=h.Frau; 
            swap=true;
          }
        }
      }
      cout << "\ngeordnet nach dem Geschlecht:";
    } break; 
  }
  for(u=p;u->Name!="";u++)
  { cout <<endl <<setw(5);
    if(u->Frau) cout << "Frau "; else cout << "Herr ";
    cout <<setw(30)<<u->Name <<setw(8) <<u->Alter
         <<" Jahre";
  }      
          
}

