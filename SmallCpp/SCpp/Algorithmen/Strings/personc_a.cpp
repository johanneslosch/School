// Th. Cassebaum, 25.3.2004, all rights reserved
// a) Fordern Sie nacheinender vom Bediener die Eingabe 
// seines Namens, Vornamens, Geschlechts und Geburts-
// datums ab und speichern Sie die Größen einzeln in 
// Variablen ab! Bilden Sie eine Stringvariable "Angaben" 
// und speichern Sie in dieser Größe einen passenden Satz, 
// der alle eingegeben Angaben zur Bedienerperson erklärt.
#include <iostream.h>
bool IstZiffer(char wert);
int DatumStrToInt(char* Datum);
char* DatumIntToStr(int Datum);
int ReadDatum();
bool ReadGeschlecht();

int main()
{ char name[30],vorname[30],angaben[100]; 
  int geb; bool frau; 
  cout << "Geben Sie Angaben zu Ihrer Person ein!\n\n";
  cout << "Familienname    : "; cin>>name;
  cout << "Vorname         : "; cin>>vorname;
  geb=ReadDatum();
  frau=ReadGeschlecht();  
  if(frau) strcpy(angaben,"Frau ");
  else strcpy(angaben,"Herr ");
  strcat(angaben,vorname);
  strcat(angaben," ");
  strcat(angaben,name);
  strcat(angaben," wurde am ");
  strcat(angaben,DatumIntToStr(geb));
  strcat(angaben," geboren.");
  cout << endl << angaben;
  getchar();
  return 0;
}
int ReadDatum()
{ int geb; char gebam[10];
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
char* DatumIntToStr(int Datum)
{ char* rt="00.00.0000";
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
int DatumStrToInt(char* Datum)
{ int h,geb;
  if(IstZiffer(Datum[0])&&IstZiffer(Datum[1]))
  { geb=(Datum[0]-'0')*10+(Datum[1]-'1');
    if(geb>31) return -1;
  }
  else 
    return -1;
  if(IstZiffer(Datum[3])&&IstZiffer(Datum[4]))
  { h=((Datum[3]-'0')*10+(Datum[4]-'0'));
    if(h>12) return -2;
    geb=geb+100*h;
  }
  else return -2;
  if(IstZiffer(Datum[6])&&IstZiffer(Datum[7])&&IstZiffer(Datum[8])&&IstZiffer(Datum[9]))
  { h=((Datum[6]-'0')*1000+(Datum[7]-'0')*100
      +(Datum[8]-'0')*10+(Datum[9]-'0'));
    if(h<1888||h>2020) return -3;
    geb=geb+10000*h;
  }
  else return -3;
  return geb;
}
bool IstZiffer(char wert)
{ if((wert<'0')||(wert>'9')) return false;
  else return true;
}

