// Th. Cassebaum, 19.3.2003, all rights reserved
#include <iostream.h>

// gibt Adresse und Inhalt von *p zurück
string PntToStr(int *p); 

int main()
{ int a=10,b=24;    // int belegt 4 Bytes

  // int* belegt 4 Bytes (32 Bit-Adresse)
  int *p1,*p2;      // Zeiger-(Pointer-) Variablen

  p1=&a; p2=&b;     // Setze Zeiger auf Adresse

  cout << "p1" << PntToStr(p1);
  cout << "\np2" << PntToStr(p2);

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
