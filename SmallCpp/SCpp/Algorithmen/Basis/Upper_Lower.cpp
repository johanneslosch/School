// Th.Cassebaum, 13.10.2004, all rights reserved
#include <iostream>
using namespace std;
string upper(string s);
string lower(string s);
int main()
{ string a;
  cout << "String: "; cin >> a;
  cout << upper(a) << endl << lower(a);
  getchar();
  return 0;
}
string upper(string s)
{ string ns="";
  for(int i=0; i<s.length(); i++)
  { switch(s[i])
    { case '�': ns+='�'; break;
      case '�': ns+='�'; break;
      case '�': ns+='�'; break;
      default: if(s[i]>='a'&&s[i]<='z') ns+=s[i]-32;
               else ns+=s[i];
    }
  }
  return ns;
}
string lower(string s)
{ string ns="";
  for(int i=0; i<s.length(); i++)
  { switch(s[i])
    { case '�': ns+='�'; break;
      case '�': ns+='�'; break;
      case '�': ns+='�'; break;
      default: if(s[i]>='A'&&s[i]<='Z') ns+=s[i]+32;
               else ns+=s[i];
    }
  }
  return ns;
}

