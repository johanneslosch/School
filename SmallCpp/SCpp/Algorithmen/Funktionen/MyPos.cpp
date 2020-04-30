/* programmiert von Th.Cassebaum am 15.2.2002 all rights reserved
   MyPos(x,y) untersucht, ob der nullterminierte String y im nullterminierten String x
   enthalten ist. Es wird die Position des 1.Zeichens von y in x zurückgegeben. Sollte
   y nicht in x enthalten sein, wird 0 zurückgegeben.
*/
#include <iostream>
#include <conio>
using namespace std;
unsigned int MyPos(char *a,char *b)
{ unsigned int pos=1,al,bl,i;bool suc;
  al=strlen(a);bl=strlen(b);
  if(al<bl)return 0;
  while(al>=bl)
  { suc=true;
    for(i=0;i<bl;i++)
    { if((a[i])!=(b[i]))
      { suc=false; break;
      }
    }
    if(suc)return pos;
    pos++; a++; al=strlen(a);
  }
  return 0;
}
unsigned int MyPos(string a,string b)
{ unsigned int pos=1,al,bl,i; bool suc=false;
  string h=a;
  al=h.length();bl=b.length(); 
  if(al<bl)return 0;
  while(al>=bl)
  { if(h.substr(0,bl)==b) 
    { suc=true; break; }
    pos++; 
    h=h.substr(1,al-1);
    al=h.length();
  }
  if(suc) return pos; else return 0;
}
int main()
{ int ps;
  char *x="Dr.Nudelmilch",*y="elmi";
  string s="Dr.Nudelmilch",t="elmi";
  cout <<"\n '"<<y<<"' ist ab "
       <<MyPos(x,y)<<". Pos. in '";
  cout<<x;
  if(MyPos(x,y)>0) cout<<"' enthalten!";
  else cout << "' nicht enthalten!";
  cout << "\n\n";

  cout <<"\n '"<<t<<"' ist ab "
       <<MyPos(s,t)<<". Pos. in '";
  cout<<s;
  if(MyPos(s,t)>0) cout<<"' enthalten!";
  else cout << "' nicht enthalten!";
  getch();
  return 0;
}
