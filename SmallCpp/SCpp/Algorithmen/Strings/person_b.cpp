// Th. Cassebaum, 25.3.2004, all rights reserved
// a) Fordern Sie nacheinender vom Bediener die Eingabe 
// seines Namens, Vornamens, Geschlechts und Geburts-
// datums ab und speichern Sie die Größen einzeln in 
// Variablen ab! Bilden Sie eine Stringvariable "Angaben" 
// und speichern Sie in dieser Größe einen passenden Satz, 
// der alle eingegeben Angaben zur Bedienerperson erklärt.
// b) Fordern Sie vom Bediener die Eingabe eines weiteren 
// Namens und eines Geburtsdatums und bilden Sie einen 
// zweiten Satz "Angaben2", der die zuerst gespeicherte 
// Person mit der 2. Person vergleicht.

#include <iostream.h>
bool Istzahl(string wert);
int DatumStrToInt(string Datum);
string DatumIntToStr(int Datum);
int ReadDatum();
bool ReadGeschlecht();

int main()
{ string name,vorname,angaben="",name2,vorname2,angaben2=""; 
  int geb,geb2; bool frau,frau2; 
  cout << "Geben Sie Angaben zu Ihrer Person ein!\n\n";
  cout << "Familienname    : "; cin>>name;
  cout << "Vorname         : "; cin>>vorname;
  geb=ReadDatum();
  frau=ReadGeschlecht();  
  if(frau) angaben="Frau ";
  else angaben="Herr ";
  angaben+=vorname+" "+name+" wurde am "+DatumIntToStr(geb)+" geboren.";
  cout << endl << angaben<<endl;
  cout << "\n\nGeben Sie Angaben zu einer 2.Person ein!\n\n";
  cout << "Familienname    : "; cin>>name2;
  cout << "Vorname         : "; cin>>vorname2;
  geb2=ReadDatum();
  frau2=ReadGeschlecht();  
  if(name==name2||vorname==vorname2)
  { if(frau2) angaben2="Frau ";
    else angaben2="Herr ";
    angaben2+=vorname2+" "+name2+" hat ";
    if(name==name2) 
    { angaben2+="den gleichen Familiennamen "; 
      if(vorname==vorname2) angaben2+="und den gleichen Vornamen, "; 
    }
    else if(vorname==vorname2) angaben2+="den gleichen Vornamen, ";
    angaben2+="wie ";
    if(frau) angaben2+="Frau "; else angaben2+="Herr ";
    angaben2+=name+"! ";
  }
  if(frau2) angaben2+="Frau ";
  else angaben2+="Herr ";
  angaben2+=vorname2+" "+name2+" ist ";
  if(geb2>geb)
    angaben2+="jünger als ";
  else
  { if(geb2<geb)  
      angaben2+="älter als ";
    else
      angaben2+="genau so alt wie ";
  }  
  if(frau2) angaben2+="Frau ";
  else angaben2+="Herr ";
  angaben2+=vorname+" "+name+"!";
  cout << endl << angaben2<<endl;
  getchar();
  return 0;
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

