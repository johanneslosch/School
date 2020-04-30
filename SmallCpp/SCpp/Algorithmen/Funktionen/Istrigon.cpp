/* programmiert von Th.Cassebaum am 15.2.2004 all rights reserved
   Die logische Funktion Istrigon(a,b,c) liefert einen Wahrheitswert, 
   ob die Seiten a,b und c ein Dreieck bilden können(true) oder nicht
   (false).
*/
#include <iostream>
using namespace std;
bool IsTrigon(double a,double b,double c)
{ if ((a<b+c)&&(b<a+c)&&(c<a+b)) return true; // Dreiecksungleichungen   
  else return false;
}
void main(void)
{  double a,b,c;
   cout << "a: "; cin >> a;                   // Seiteneingaben
   cout << "b: "; cin >> b;
   cout << "c: "; cin >> c;
   if(IsTrigon(a,b,c)) cout << "\n\nDreieck!";
   else cout << "\n\nKein Dreieck!";
   getchar();
}
