// Th. Cassebaum, 25.3.2004, all rights reserved
// a) Fordern Sie nacheinender vom Bediener die Eingabe 
// seines Namens, Vornamens, Geschlechts und Geburts-
// datums ab und speichern Sie die Größen einzeln in 
// Variablen ab! Bilden Sie eine Stringvariable "Angaben" 
// und speichern Sie in dieser Größe einen passenden Satz, 
// der alle eingegeben Angaben zur Bedienerperson erklärt.
#include <iostream.h>
#include <conio.h>
bool Istzahl(string wert);
int DatumStrToInt(string Datum);
string DatumIntToStr(int Datum);
int ReadDatum();
void Auslisten(int i);
bool ReadGeschlecht();
char *name[50],*vorname[50]; int geb[50]; bool frau[50];   
int main()
{ char nam[50],angaben[100]; int h,ant,i=0,j; bool hb,sort;   
  while((i<50)&&(nam[0]!='#'))
  { cout << "Geben Sie Angaben zur Person Nr."<<i+1<<" ein!\n"
         << "Zum Eingabeabschluß geben Sie als Familiennname # ein!\n";
    cout << "\nFamilienname    : "; cin>>nam;
    if(nam[0]=='#') break;
    name[i]=new char[50];
    name[i]=nam;
    cout << "Vorname         : "; cin>>vorname[i];
    geb[i]=ReadDatum();
    frau[i]=ReadGeschlecht();  
    i++;
  }    
  clrscr();
  while(true)    
  { cout << "\n\nSie können die Angaben zur Person jetzt sortiert ausgeben.\n"
         << "Wählen Sie eine Sortierreihenfolge aus!\n\n"
         << "       1 alphabetisch nach dem Familiennamen\n"
         << "       2 nach dem Alter\n"
         << "       0 ohne weitere Liste beenden\n"
         << "\nAuswahlziffer : "; 
    ant=getch();
    switch(ant)
    { case '1': if(i>0) do
              { sort=false;
                { for(j=0;j+1<i;j++)
                  { if(strcmp(name[j],name[j+1])>0)
                    { strcpy(nam,name[j]);strcpy(name[j],name[j+1]);strcpy(name[j+1],nam);
                      strcpy(nam,vorname[j]);strcpy(vorname[j],vorname[j+1]);strcpy(vorname[j+1],nam);
                      h=geb[j];geb[j]=geb[j+1];geb[j+1]=h;
                      hb=frau[j];frau[j]=frau[j+1];frau[j+1]=hb;
                      sort=true;                    
                    }
                  }    
                }
              } while(sort);
              cout<<endl; Auslisten(i);
              break;
      case '2': if(i>0) do
              { sort=false;
                { for(j=0;j+1<i;j++)
                  { if(geb[j]>geb[j+1])
                    { strcpy(nam,name[j]);strcpy(name[j],name[j+1]);strcpy(name[j+1],nam);
                      strcpy(nam,vorname[j]);strcpy(vorname[j],vorname[j+1]);strcpy(vorname[j+1],nam);
                      h=geb[j];geb[j]=geb[j+1];geb[j+1]=h;
                      hb=frau[j];frau[j]=frau[j+1];frau[j+1]=hb;
                      sort=true;                    
                    }
                  }    
                }
              } while(sort);
              cout<<endl; Auslisten(i); 
              break;
      default:return 0;                       
    }
  }     
}
void Auslisten(int i)
{ for(int j=0;j<i;j++)
  { if(frau[i]) cout << "\nFrau ";
    else cout << "\nHerr ";
    cout << vorname[j] << " " << name[j] << " wurde am "
         << DatumIntToStr(geb[j])<< " geboren.";
  }
}
int ReadDatum()
{ int geb; string gebam;
  do
  { cout << "geb.[tt.mm.jjjj]: "; cin>>gebam;
    switch(geb=DatumStrToInt(gebam))
    { case -1: 
        cout << "\n*** Sie haben einen Eingabefehler beim Geburtstag gemacht!"
             << "\n*** Wiederholen Sie diese Eingabe im genauen Muster tt.mm.jj!\n";
      break;
      case -2: 
        cout << "\n*** Sie haben einen Eingabefehler beim Geburtsmonat gemacht!"
             << "\n*** Wiederholen Sie diese Eingabe im genauen Muster tt.mm.jj!\n";
        break;
      case -3: 
        cout << "\n*** Sie haben einen Eingabefehler beim Geburtsjahr gemacht!"
             << "\n*** Wiederholen Sie diese Eingabe im genauen Muster tt.mm.jj!\n";
        break;
     }   
  } while(geb<0);
  return geb;
}
bool ReadGeschlecht()
{ char w;
  do
  { cout << "weiblich?  [j/n]: "; cin>>w;
  } while(w!='j'&&w!='J'&&w!='n'&&w!='N');
  if(w=='j'||w=='J') return true;
  else return false;
}
string DatumIntToStr(int Datum)
{ string rt="00.00.0000";
  rt[1]=Datum%10+0x30; Datum=Datum/10;
  rt[0]=Datum%10+0x30; Datum=Datum/10;
  rt[4]=Datum%10+0x30; Datum=Datum/10;
  rt[3]=Datum%10+0x30; Datum=Datum/10;
  rt[9]=Datum%10+0x30; Datum=Datum/10;
  rt[8]=Datum%10+0x30; Datum=Datum/10;
  rt[7]=Datum%10+0x30; Datum=Datum/10;
  rt[6]=Datum%10+0x30;   
  return rt;
}
int DatumStrToInt(string Datum)
{ int h,geb=0;
  if (Istzahl(Datum.substr(0,2)))
  { geb=(Datum[0]-'0')*10+(Datum[1]-'0');
    if(geb>31) return -1;
  }
  else 
    return -1;
  if (Istzahl(Datum.substr(3,2)))
   { h=((Datum[3]-'0')*10+(Datum[4]-'0'));
     if(h>12) return -2;
     geb=geb+100*h;
   }
  else return -2;
  if (Istzahl(Datum.substr(6,4)))
  { h=((Datum[6]-'0')*1000+(Datum[7]-'0')*100
      +(Datum[8]-'0')*10+(Datum[9]-'0'));
    if(h<1888||h>2020) return -3;
    geb=geb+10000*h;
  }
  else return -3;
  return geb;
}
bool Istzahl(string wert)
{ for(int i=0;i<wert.length();i++)
    if((wert[i]<'0')||(wert[i]>'9'))
      return false;
  return true;
}

