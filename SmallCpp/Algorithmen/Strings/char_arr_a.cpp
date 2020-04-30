// C++ Trainer 2.0, 24.3.2004, all rights reserved
// Zeichen array mit maximal 50 Zeilen und 80 Zeichen eingeben 
// und anschließend ausgeben.
#include <iostream.h>
#include <conio.h>
int main()
{ char zk[80][50], ez; int z,s;
  cout << "Geben Sie Zeichen ein.\nZeilenwechsel mit Eingabetaste, \nEnde mit Funktionstaste!\n";
  
  z=0; s=0;
  do
  { zk[s][z]=ez=getch(); 
    if (ez==13) 
    { s=0; z++; cout << endl;}
    else { s++; cout << ez; }
    if(s>=80) {z++;s=0;}
  } while(ez&&(z<50));
  cout << endl << "\nSie haben eingegeben: \n\n";
  z=0;s=0;
  cout << z+1 << " "; 
  while(zk[s][z]&&(z<50))
  { if(zk[s][z]==13) 
    { cout<<endl<<++z+1<<" "; s=0; }
    else {cout<<zk[s][z]; s++;}
    if(s>=80) {z++;s=0;}
  }
  ez=getch();
  getchar();
  return 0;
}
