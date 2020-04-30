// programmiert von Thomas Cassebaum am 17.9.2002 gegen 17:32 Uhr
// all rights reserved
// Typdefinitionen und Methoden zur Nutzung einer einfach verketteten Liste
// *** nicht-objektorientierte Lösung *************************************
/*
void init();            Zeiger kopf,ende,aktuell auf NULL setzen (Neue Liste beinnen)
bool fuegeeinvor();     Inhalt von satz vor dem aktuellen Element einfügen  (false:Speicherfehler)
bool fuegeeinnach();    Inhalt von satz nach dem aktuellen Element einfügen (false:Speicherfehler)
void lies();            satz mit dem aktuellen Element füllen (z.B. nach next(); )
void aendern();         aktuelles Element mit satz überschreiben
void head();            erstes Element als aktuelles einstellen
void tail();            letztes Element als aktuelles einstellen
bool next();            folgendes Element als aktuelles einstellen  (false:Tail)
bool prev();            vorheriges Element als aktuelles einstellen (false:Head)
bool listeleer();       Ist die Liste leer? (false:nein, true:ja)
bool letzteselement();  Ist das aktuelle auch das letzte Element? (false:nein, true:ja)
int  anzahl();          Rückgabe der Elementanzahl in der Liste
*/
struct t_inhalt{ string name;
                 string nummer;
               };
struct t_liste { t_inhalt inhalt;
                 t_liste* next;
               };
typedef t_liste* t_zeiger ;
t_zeiger kopf,ende,aktuell; t_inhalt satz;
FILE *datei;

void init()
{ kopf    = NULL; ende    = NULL;
  aktuell = NULL;
}
bool fuegeeinvor()
{ t_zeiger akt=new t_liste;
  if(akt==NULL)
  { cout<<"\nSpeicherfehler! Satz nicht eingefuegt!";
    return false;
  }
  if(kopf==NULL)        // Sonderfall: leere Liste
  { kopf      = akt; ende      = akt;
    akt->next = NULL;
  }
  else
  { if (kopf==aktuell)  // Sonderfall: Element wird Kopfelement
    { kopf      = akt;
      akt->next = aktuell;
    }
    else                // allgemeiner Fall
    { akt->next = aktuell;       //  Vorwaertsverkettung
    }
  }
  akt->inhalt = satz;    // Inhalt übertragen
  aktuell     = akt;     // das aktuelle Element ist das neue
  return true;
}
bool fuegeeinnach()
{ t_zeiger akt=new t_liste[1];
  if(akt==NULL)
  { cout<<"\nSpeicherfehler! Satz nicht eingefuegt!";
    return false;
  }
  if(kopf==NULL)        // Sonderfall: leere Liste
  { kopf      = akt; ende      = akt;
    aktuell   = akt; akt->next = NULL;
  }
  else
  { akt->next     = aktuell->next; //  Vorwaertsverkettung
    aktuell->next = akt;
  }
  akt->inhalt = satz;      // Inhalt übertragen
  if(aktuell==ende)        // ggf. Ende aktualisieren
    ende = akt;
  aktuell = akt;           // das aktuelle Element ist das neue
  return true;
}
void lies()
{ if(aktuell!=NULL) satz = aktuell->inhalt;
}
void aendern()
{ if(aktuell!=NULL) aktuell->inhalt = satz;  // Uebertragen des Inhaltes
  else fuegeeinnach(); // Wenn Liste Leer, Element einfügen
}
void head() { aktuell = kopf; }
void tail() { aktuell = ende; }
bool next()
{ if(aktuell->next!=NULL)
  { aktuell = aktuell->next;
    return true;
  }
  else return false;
}
bool listeleer()
{ if(kopf==NULL) return true;
  else return false;
}
bool letzteselement()
{ if(aktuell==ende) return true;
  else return false;
}
int anzahl()
{ t_zeiger akt=kopf;
  int counter=0;
  while(akt!=NULL)
  { counter++; akt=akt->next;
  }
  return counter;
}
