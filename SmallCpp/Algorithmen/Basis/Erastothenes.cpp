// C++ Trainer, 10.5.2004, all rights reserved
#include <iostream.h>
using namespace std;
#define N 1000
int main()
   {
   int i,j,a[10];
   for (a[1]=0,i=2;i<10;i++)
      {
      a[i]=1;
      }
   for (i=2;i<5;i++)
      {
      for (j=2;j<10/i;j++)
         {
         a[i*j]=0;
         }
      }
   for (i=1;i<10;i++)
      {
      if (a[i])
         {
         cout<<i;
         }
      }
   getchar();
   return 0;
   }