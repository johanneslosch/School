// Th. Cassebaum, 22.4.2004, all rights reserved 
#include <iostream.h> 
int main() 
{ double *pd, d[11]; int *pi, i[11];
  pd = d; pi = i;
  *pd = 21.34;  *pi = 5;
  cout << pd <<" " << pi << endl;
  pd++; pi+=3;           // Zeigerarithmetik
  *pd = 33.99; *pi = 6;
  cout << pd <<" " << pi;
  cout <<endl <<d[0] <<" " << d[1];
  cout <<endl <<i[0] <<" " <<i[3];
  getchar();
  return 0;
}
