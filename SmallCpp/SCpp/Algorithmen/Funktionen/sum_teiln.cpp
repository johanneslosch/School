/* C++ Trainer, 23.2.2005, all rights reserved
   rekursiv: Summe aller durch n teilbaren Zahlen, 
   die kleiner oder gleich x sind
*/
#include <iostream>
using namespace std;
int sum_n(int x,int n)
{ x-=x%n;
  if(x>0) return sum_n(x-n,n)+x;
  else return 0;
}
int main()
{ cout<<sum_n(12,3);
  getchar();
  return 0;
}
