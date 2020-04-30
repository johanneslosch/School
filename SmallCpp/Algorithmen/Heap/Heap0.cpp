// Th. Cassebaum, 29.4.2004, all rights reserved
#include <iostream>
using namespace std;
int main()
{ int *p;           // Zeiger für den Heapbeginn
  p = new int[10];  // Heap-Array für 10 int-Elemente
  p[0]=1; ++p[0];   // Manipulation des 1.Elementes
  cout << p[0];     // Ausgabe des 1.Elementes
  delete p;         // Freigabe des Heaps

  getchar();
  return 0;
}
