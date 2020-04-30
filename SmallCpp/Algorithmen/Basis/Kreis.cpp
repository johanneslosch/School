/* Klasse für geometrische Kreis-Objekte mit grafischer Realisierung (ALGEO)
   Thomas Cassebaum 2010, all rights reserved
*/
#include <iostream>
using namespace std;
#include <algeo.h>                 
class kreis                          // Klassendefinition
{ public:  void Zeichnen();          // Methode (Objekt zeichnet sich selbst auf den Bildschirm)
           kreis();                  // Konstruktor (startet automatisch bei jeder Objektbildung)
           kreis(float x,float y,float r,float* col);
           kreis(vect v,float r,float* col);
  private: float x,y,r,col[4];       // Höhe,Breite,links,oben,Farbe
} ;                                        

void justify(void)                   // ALGEO Predefinition-Funktion
{A_sy+=.4;
}
void display(void)                   // ALGEO Renderfunktion
{ A_Model(A_BOOK);     
  glPushMatrix();
   GLfloat rot[4]=A_RED,blau[4]=A_BLUE; // Farbdefinition
   kreis R1;                          // Objektbildung ohne Parameter
   kreis R2(1,1,3,rot);               // Objektbildung mit Parametern
   vect  r3(-2,-1); 
   kreis R3(r3,3,blau);
   C_Point P3(r3,vect(BLAU));
   A_Coord(5);          
   char r3s[20];
   strcpy(r3s,"M"); strcat(r3s,r3.vecstr(2));
   A_TextOut(-3.6,-1.1,0.,r3s,blau);
  glPopMatrix();        			    // load old matrix  
}

int main(int argc, char **argv)      
{ glutInit(&argc, argv);                  
  A_Init("2D Kreis",A_PERSP,5);                    
  return 0; 
}
// Methode (Das Objekt zeichnet sich selbst)
void kreis::Zeichnen()         
{ float M[]={x,y,0.}, R[]={0,0,1};
  A_Circle(M,R,col,r,.05);
}
// Funktionsdefinition des parameterlosen Konstruktors
kreis::kreis()               
{ x= 0.0f; y= 0.0f; r= 1.0f; col[3]= 1.0f; 
  for(int i=0;i<3;i++) col[i]=0.0f; 
  this->Zeichnen();
}
// Funktionsdefinition des parameterbehafteten Konstruktors (reelle Koordinaten)
kreis::kreis(float x,float y,float r,float *col)
{ this->x=x; this->y=y; this->r=r;
  for(int i=0;i<4;i++) this->col[i] =col[i]; 
  this->Zeichnen();
}
// Funktionsdefinition des parameterbehafteten Konstruktors (Ortsvektor des Mittelpunktes)
kreis::kreis(vect v,float r,float *col)
{ this->x=v.x(); this->y=v.y(); this->r=r;
  for(int i=0;i<4;i++) this->col[i] =col[i]; 
  this->Zeichnen();
} 