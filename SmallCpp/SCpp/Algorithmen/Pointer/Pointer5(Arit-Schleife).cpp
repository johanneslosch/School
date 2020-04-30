// Th. Cassebaum, 22.4.2004, all rights reserved
#include <iostream.h>
int main()
{ double *pd, d[11];  
  int *pi, i[11];
  pd = d; pi = i;
  randomize();
  do
  { *pd = random(10000)/100.;
    *pi = random(201)-100;
    pd++; pi++;
  }while(pd <= &d[10]) ;  

  getchar();
  return 0;
}
