// Th. Cassebaum, 19.3.2003, all rights reserved
#include <iostream.h>

// gibt Adresse und Inhalt von *p zurück
string PntToStr(int *p); 
string PntToStr(double *p); 
int main()
{ int a=10,b=24;             // int    4 Bytes
  double c=23.12, d=-19.621; // double 8 Bytes
  // alle Pointer(*) 4 Bytes (32 Bit-Adresse)
  int *p1,*p2;      // Zeigervariablen für int
  double *p3,*p4;   // für double
  p1=&a; p2=&b;     // Setze Zeiger auf Adresse
  p3=&c; p4=&d;
  cout << "p1" << PntToStr(p1);
  cout << "\np2" << PntToStr(p2);
  cout << "\np3" << PntToStr(p3);
  cout << "\np4" << PntToStr(p4);
  getchar();
  return 0;
}

string PntToStr(int *p) // gibt Adresse und Inhalt zurück
{ int adr;char s[10];string r;
  adr=(int)p;
  itoa(adr,s,16);
  r=" zeigt auf "+string(s);
  itoa(*p,s,10);
  r+=" Inhalt --> "+string(s);
  itoa(*p,s,16);
  r+="\thex:"+string(s);
  itoa(*p,s,2);
  return r+"\tdual:"+string(s);    
}
string PntToStr(double *p) // gibt Adresse und Inhalt zurück
{ int adr;char s[20];string r;
  adr=(int)p;
  itoa(adr,s,16);
  r=" zeigt auf "+string(s);
  gcvt(*p,7,s);
  return r+" Inhalt --> "+string(s);   
}
