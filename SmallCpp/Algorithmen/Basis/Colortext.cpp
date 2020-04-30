// Th.Cassebaum, 29.3.2009, all rights reserved
#include <iostream>
#include <conio>
using namespace std;
int main()
{ cout << "Bildung jeder Farbkombination" << endl;
  for(int i=0;i<8;i++)
  { for(int j=0;j<16;j++)
    { textcolor (j);	        // Legt Textfarbe W fest
      textbackground (i);		  // Legt Texthintergrundfarbe W fest
      cprintf("X");
    }
    cout << endl;
  }
  getchar();
  return 0;
}
