// Fünf Sortierverfahren für zufällige dynamische Arrayinhalte
// beliebiger Größe mit Zeitmessung.
// programmiert von Th.Cassebaum am 27.2.2002 gegen 22:33 Uhr
// all rights reserved 
#include <iostream> 
#include <conio> 
#include <iomanip> 
#include <time> 
using namespace std;
#define s 5                 // Anzahl der Sortierverfahren
// Sortieralgorithmen 
int bits(unsigned int w,int b);
void quicksort(int l,int r);
int intcmp(const void *, const void *);
char ant; unsigned int *T[s];
int main() 
{  unsigned int i, j, h, m, mi, gr;
   long Zeit;
   randomize();
   do
   {  cout << "Wieviel Zahlen sollen sortiert werden? (z.B. 10000): ";
      cin >> gr;
      for(i=0;i<s;i++) T[i] = new unsigned int[gr]; // Heap bereitstellen
      for(i=0; i<gr; i++) // Füllen der Heaparrays mit Zufallswerten 
      {  T[0][i]=rand();
         for(j=1;j<s;j++) T[j][i]=T[0][i];
      }
      cout << "\nZeitdauer zur Sortierung von "<<gr<<" Integerzahlen\n\n";
      // 1. Quick Sort 
      Zeit=clock();
      qsort(T[0],gr,sizeof(int),intcmp);
      cout << "\nQuick Sort     : " << difftime(clock(),Zeit) << " ms";
      // 2. Selection Sort 
      Zeit=clock();
      for( i=0; i<gr-1; i++ ) 
      {  mi=32767;
         for( j=i; j<gr; j++ ) // Minimumsuche 
         if(T[1][j]<mi) 
         {  m=j;
            mi=T[1][j];
         }
         h=T[1][m];
         T[1][m]=T[1][i];
         T[1][i]=h; // Tausch 
      }
      cout << "\nSelection Sort : " << difftime(clock(),Zeit) << " ms";

      // 3. Insertion Sort
      Zeit=clock();
      for( i=2; i<=gr; i++ )
      {  mi=T[2][i];              // Annahme Minimum
         j=i;
         while((T[2][j-1]>mi) && (j>1))
         { T[2][j]=T[2][j-1];
           j=j-1;
         }
         T[2][j]=mi;
      }
      cout << "\nInsertion Sort : " << difftime(clock(),Zeit) << " ms";

      // 4. Bubble Sort
      Zeit=clock();
      do 
      {  m=0;
         for( j=0; j<gr-1; j++ ) if(T[3][j+1]<T[3][j])
         {  h=T[3][j];
            T[3][j]=T[3][j+1];
            T[3][j+1]=h;
            m=1;
         }
         // Tausch 
      } while(m);
      cout << "\nBubble Sort    : " << difftime(clock(),Zeit) << " ms";

      // 5. Quick Sort zu Fuss
      Zeit=clock();
      quicksort(0,gr-1);
      cout << "\nQuick Sort 3m  : " << difftime(clock(),Zeit) << " ms";

      // Anzeige der Ergebnisse?
      cout << "\n\nWenn Sie es nicht glauben, sehen Sie sich die Zahlenfolgen\n\n\t1 Quicksort,"
      << "\n\t2 Selection Sort, \n\t3 Insertion Sort oder \n\t4 Bubble Sort\n"
      << "\t0 Nochmal\n\n\tStrg/C für Beenden\nan! \n\n";
      do 
      {  cout << "Ich will sehen: Zahlenfolge Nr. ";
         cin >> h;
      } while (h<0||h>s);
      if(h) 
      {  for(i=0;i<gr;i++) cout << T[h-1][i] << " ";
         getch();
      }
      for(i=0;i<s;i++) delete[] T[i];
   } while ( true);
   return 0;
}
int intcmp(const void *A, const void *B) 
{  if(*(int *)A > *(int *)B) return(1);
   else return(-1);
}
void quicksort(int l,int r)
{ int wert,t,i=l,j=r;
  wert=T[4][(l+r)/2];
  do
  { while(T[4][i]<wert) i++;
    while(wert<T[4][j]) j--;
    if(i<=j)
    { t=T[4][i]; T[4][i++]=T[4][j]; T[4][j--]=t;         // Tausch
    }
  } while(i<=j);
  if(l<j) quicksort(l,j);
  if(i<r) quicksort(i,r);
}

