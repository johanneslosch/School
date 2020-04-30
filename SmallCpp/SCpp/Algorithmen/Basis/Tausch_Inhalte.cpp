// programmiert von Th.Cassebaum am 27.4.2002 gegen 20:27 Uhr 
// all rights reserved 
#include <iostream> 
#include <conio>
#include <time> 
using namespace std;
short a=65, b=-22;
void swap1()
{  a^=b;
   b^=a;
   a^=b;
}
void swap2()
{  register short h;
   h=a;
   a=b;
   b=h;
}
void swap3()
{  register short h;
   b=b+a;
   a=b-a;
   b=b-a;
}
int main(void)
{  long i,z1,z2;
   cout<<"\na = "<<a<<"  b = "<<b; swap1();
   cout<<"\na = "<<a<<"  b = "<<b; swap2();
   cout<<"\na = "<<a<<"  b = "<<b; swap3();
   cout<<"\na = "<<a<<"  b = "<<b;
   z1=clock();
   for(i=0; i<=3000000; i++) swap1();
   z2=clock();
   cout << "\nMethode exklusives ODER  : " << difftime(z2,z1) << " ms";
   z1=clock();
   for(i=0; i<=3000000; i++) swap2();
   z2=clock();
   cout << "\nMethode mit Hilfsvariable: " << difftime(z2,z1) << " ms";
   z1=clock();
   for(i=0; i<=3000000; i++) swap3();
   z2=clock();
   cout << "\nMethode plus und minus   : " << difftime(z2,z1) << " ms";
   getch();
   return 0;
}
