/* Th.Cassebaum 2004, all rights reserved
   E-V-A Eingabe-Verarbeitung-Ausgabe (C) Geschwindigkeitsberechnung
*/
#include <stdio.h>             // Header für printf,scanf
int main()                     // Hauptfunktion nach ANSI-Standard
  { float s=0.,t=0.,v;         // Variablendefinition für reelle s,t,v
    // *** Eingabe **************
    printf("Weg [m]: ");       // Ausgabe der Eingabeaufforderung für den Weg
    scanf("%f",&s);               // Eingabe als reelle Zahl
    printf("Zeit[s]: ");       // Ausgabe der Eingabeaufforderung für den Weg
    scanf("%f",&t);               // Eingabe als reelle Zahl
    // *** Verarbeitung *********
    v = s/t;                   // Ergebniserrechnung
    // *** Ausgabe **************
    printf("\n\nGeschwindigkeit : %f m/s\n\t   oder : %f km/h",v,v*3.6);
    getchar();getchar();       // Warten auf Tasteneingabe
    return 0;                  // Rückgabewert für Erfolg
  }
