// Th. Cassebaum, 27.4.2004, all rights reserved
// Speichern Sie 56 Punkte und 8 mal den Buchstaben x 
// in einem 8*8-Feld! Die x‘e sollen zufällig mit den 
// Punkten gemischt sein. Geben Sie das gesamte Feld 
// zweimal nebeneinander so aus, dass genau eines der 
// x‘e um eine Position versetzt erscheint (Richtung 
// zufällig). Benutzen Sie Zeigerzugriffe und -arith-
// metik bei Änderungen und Ausgaben!
// Th. Cassebaum, 23.4.2004, all rights reserved
#include <iostream.h>
void aus(char *z)
{ for(int i=0;i<64;i++) 
  { cout << *z++; 
    if(!((i+1)%8)) cout << endl;
  }
}
int main()
{ char a[64],*z=a; short i,x,y,xs,ys;
  randomize();  
  for(i=0;i<64;i++) *z++='.';
  for(i=0;i<8 ;i++)
  { do { x=random(8); y=random(8);
       } while(a[x*8+y]=='x');
    a[x*8+y]='x';
  }
  do { xs=x+random(3)-1; ys=y+random(3)-1;
     } while(xs<0||ys<0||xs>7||ys>7||a[xs*8+ys]=='x');
  aus(a); cout << endl;
  a[x*8+y]='.'; a[xs*8+ys]='x';
  aus(a);
  getchar();
  return 0;
}
