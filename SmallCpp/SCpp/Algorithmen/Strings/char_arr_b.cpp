// C++ Trainer 2.0, 24.3.2004, all rights reserved
// Zeichen array mit maximal 50 Zeilen und 80 Zeichen eingeben 
// und anschließend ausgeben.
// Suchen einer Zeichenkette und 1.Zeile des Auftretens ausgeben
#include <iostream.h>
#include <conio.h>
int main()
{ char zk[80][50], ez, su[80]; 
  int z,z1,s,s1,i;
  cout << "Geben Sie Zeichen ein.\nZeilenwechsel mit Eingabetaste, \nEnde mit Funktionstaste!\n";
  
  z=0; s=0;
  do
  { zk[s][z]=ez=getch(); 
    if (ez==13) 
    { s=0; z++; cout << endl;}
    else { s++; cout << ez; }
    if(s>=80) {z++;s=0;}
  } while(ez&&(z<50));
  ez=getch();
  cout << endl << "\nGeben Sie eine Suchzeichenfolge: ";
  ez=0; i=0;
  while((ez!=13)&&(i<80))          // Eingabezyklus
  { su[i++]=ez=getch();
    cout<<ez;
  }  
  if(--i<80) su[i]=0;
  cout << "\nSuchtext '"<< su << " wird gesucht...";
  z=0;s=0;
  while(zk[s][z]&&(z<50)) // Suchzyklus
  { if(zk[s][z]==13)      // Zeile zu Ende
    { z++; s=0;
      continue;
    }  
    i=0;
    if(zk[s][z]==su[i])   // evtl. Beginn der Suchfolge?
    { s1=s; z1=z; 
      do
      { i++;s1++;
        if((!su[i])||(i>=80))
        { cout << "\ngefunden in Zeile " << z1+1 <<":\n";
          s1=0;
          do
          { cout<<zk[s1++][z1];
          } while(zk[s1][z1]&&(s1<80)); 
          getchar(); exit(1);
        }
      } while((zk[s1][z1]==su[i])&&(i<80)&&(s1<80));
    }
    s++;
  }
  cout << "\n\nnicht gefunden!";
  getchar();
  return 0;
}
