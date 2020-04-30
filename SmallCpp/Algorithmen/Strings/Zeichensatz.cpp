// Thomas Cassebaum, 31.1.2009, all rights reserved
#include <iostream.h>
int main()
{ for(short x=1; x<256; x++) 
  if(x<7||x>13)
  { if(x<100) cout << " ";
    if(x<10) cout << " ";
    cout << x << " " <<(char)x << "\t";
  }
  getchar();
  return 0;
}
