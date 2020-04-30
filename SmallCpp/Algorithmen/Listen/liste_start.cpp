// Th.Cassebaum, 24.6.2004, all rights reserved
#include <iostream.h>
using namespace std;
struct elem
{ char name[20];
  float gross;
  elem *next;
};
elem *anker, *aktuell;
void erfasse(elem *p);
void zeige(elem *p);
void fuegeeinnach()
{ elem *neu;
  neu = new elem;
  erfasse(neu);
  if(aktuell->next==NULL)           // Element das letzte?
  { aktuell->next=neu;
    neu->next=NULL; 
  }
  else
  { neu->next=aktuell->next;
    aktuell->next=neu;
  }
}
int main()
{ anker = new elem;
  aktuell = anker;
  anker->next = NULL;
  erfasse(anker);
  zeige(anker);
  getchar();
  return 0;
}
void erfasse(elem *p)
{ cout << "\nName: "; cin >> p->name;
  cout << "Größe:"; cin >> p->gross;
}
void zeige(elem *p)
{ cout << "\nName: " << p->name;
  cout << "\nGröße:" << p->gross;
}

