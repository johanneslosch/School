/* Th.Cassebaum , 5.5.2004, all rights reserved
   Geben Sie auf dem Bildschirm ein im Heap erzeugtes rechteckiges 
   Zahlenfeld zufälliger natürlicher Zahlen (0,…,99) aus! Das Zahlen-
   feld besitzt die Länge x und die Höhe von y Werten. x und y sind 
   zufällig aus dem Wertebereich (3,…,8) zu bestimmen. Geben Sie danach 
   das im Heap gespeicherte zugehörige Zahlenfeld aufsteigend sortiert 
   auf dem Bildschirm aus!
*/  
#include <iostream>
using namespace std;
int main()
{ unsigned int x,y,g,i,j,*z; bool h;
  randomize();
  x=random(6)+3; y=random(6)+3; g=x*y;
  z=new unsigned int[x*y];
  cout << "Breite: " << x << ", Höhe: " 
       << y << endl << endl;
  for(i=0;i<y;i++) 
  { for(j=0;j<x;j++) 
    { z[i*x+j]=random(100);
      if(z[i*x+j]<10) cout << "0";
      cout << z[i*x+j] << " ";
    }
    cout << endl;      
  }
  do
  { h=false;
    for(i=0;i<(g-1);i++)
    { if(z[i]>z[i+1])
      {j=z[i];z[i]=z[i+1];z[i+1]=j;h=true;}
    }
  } while(h);
  cout << endl;
  for(i=0;i<y;i++) 
  { for(j=0;j<x;j++) 
    { if(z[i*x+j]<10) cout << "0";
      cout << z[i*x+j] << " ";
    }
    cout << endl;      
  }
  getchar();
  return 0;
}
