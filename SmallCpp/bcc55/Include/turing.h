// programmiert von Th.Cassebaum am 29.4.2002 gegen 8:43 Uhr
// all rights reserved
#include <iostream.h>
#include <conio.h>
#define _ 0
#define L 0
#define N 1
#define R 2
short az[]={0,0,0};    // aktueller Zustand
char band[250],      // Turingband
     *p;             // Positionszeiger im Band
void trimaus(void)
{ int j=0;
  sfolge[j]=0;
  for(int i=0;i<250;i++)
  { if(band[i]!=' ')
    { sfolge[j++]=band[i];
      sfolge[j]='\0';
    }
  }
  cout << "\n(z" << az[0] << ",";
  switch(X[az[1]])
  { case ' ': cout << '*'; break;
    default:  cout << X[az[1]];
  }
  cout<<",";
  switch(az[2])
  { case L: cout << "L";break;
    case R: cout << "R";break;
    case N: cout << "N";break;
  }
  cout << ")  " << sfolge ;

}
void start(void)
{ int i;
  for(i=0;i<100;i++)band[i]=' ';
  for(;i<(100+strlen(sfolge));i++) band[i]=sfolge[i-100];
  for(;i<249;i++)band[i]=' ';
  p=&band[100];
}
