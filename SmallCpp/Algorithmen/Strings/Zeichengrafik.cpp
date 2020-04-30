// Thomas Cassebaum, 31.1.2009, all rights reserved
#include <iostream>
using namespace std;
string ms(string,unsigned short);
string gset(string&);
int main()
{ string kasten="7---8---9cr|   |   |cr4---5---6cr|   |   |cr1---2---3cr";
  cout << ms(gset(kasten),4);
  // cout << ms(kasten,2);
  getchar();
  return 0;
}
string gset(string &s)
{ for(int i=0;i<s.length();i++)
    switch(s[i])
    { case '7': s[i]=218; break;
      case '8': s[i]=194; break;
      case '9': s[i]=191; break;
      case '4': s[i]=195; break;
      case '5': s[i]=197; break;
      case '6': s[i]=180; break;
      case '1': s[i]=192; break;
      case '2': s[i]=193; break;
      case '3': s[i]=217; break;
      case '-': s[i]=196; break;
      case '|': s[i]=179; break;
      case 'c': s[i]=13; break;
      case 'r': s[i]=10; break;
    }
  return s; 
}
string ms(string s,unsigned short l)
{ if(--l) s+=ms(s,l);
  return s;
}

