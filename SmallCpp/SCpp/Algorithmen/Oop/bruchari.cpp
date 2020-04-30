// Nichtobjektorientierte Lösung der Bruchrechnung
// programmiert von Th.Cassebaum am 15.2.2004 gegen 22:26 Uhr
// all rights reserved
#include <iostream.h>
void mul(int &az, int &an, int bz, int bn)
{ az*=bz; an*=bn;
}
void add(int &az, int &an, int bz, int bn)
{ az=az*bn+bz*an; an*=bn;
}
int main()
{ int b1z=3,b1n=4,b2z=2,b2n=5;

  cout<<b1z<<"/"<<b1n<<" * "<<b2z<<"/"<<b2n;
  mul(b1z,b1n,b2z,b2n);
  cout<<" = "<<b1z<<"/"<<b1n<<"\n";

  cout<<b1z<<"/"<<b1n<<" + "<<b2z<<"/"<<b2n;
  add(b1z,b1n,b2z,b2n);
  cout<<" = "<<b1z<<"/"<<b1n;

  getchar();
  return 0;
}

