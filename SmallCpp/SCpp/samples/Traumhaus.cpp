// Thomas Cassebaum, 18.9.2008, all rights reserved
#include <iostream.h>
#include <algeo.h>
void rect(GLfloat**,GLfloat*);
void triangle(GLfloat **w,GLfloat *c);
void main(int argc, char **argv)
{ glutInit(&argc, argv);            // GLUT initialisieren       
  A_Init("Traumhaus",A_PERSP,5);      // ALGEO initialisieren                  
}
void justify(void){ A_sy+=1.5f; A_theta-=0.2; A_phi-=0.4; A_distance-=4.; }   // Justieren des Fensters
void display(void)
{ A_Model(A_NIGHT);                 // Modelltyp festlegen (auch: A_BOOK, A_DARK)
  GLfloat Rot[4] ={.3f,0.f,0.f,1.f};// Farbe Rot, undurchsichtig (RGBA-Darstellung)
  GLfloat Gelb[4]=A_LIGHTYELLOW;         // Farbe Gelb, undurchsichtig (vordefiniert)
  GLfloat a=2.f; GLfloat LT[]={-a,a,a},RT[]={a,a,a},RB[]={a,-a,a},LB[]={-a,-a,a}; GLfloat *W[4]={LT,RT,RB,LB}; 
  rect(W,Gelb); for(int i=0;i<4;i++) W[i][2]=-a; rect(W,Gelb);
  for(int i=0;i<3;i++) {W[1][i]=W[0][i]; W[2][i]=W[3][i];} W[1][2]=-W[1][2]; W[2][2]=-W[2][2];
  rect(W,Gelb); for(int i=0;i<4;i++) W[i][0]=a; rect(W,Gelb);
  W[2][0]=0.f;W[2][1]=a*2.f;W[2][2]=0.f; triangle(W,Rot);
  for(int i=0;i<2;i++) W[i][0]=-a; triangle(W,Rot);
  W[0][0]=-W[0][0];W[0][2]=-W[0][2]; triangle(W,Rot);
  W[0][0]=-W[0][0];W[0][2]=-W[0][2];W[1][0]=-W[1][0];W[1][2]=-W[1][2]; triangle(W,Rot);
 // A_Coord(3);                       // Koordinatensystem (Axunits, Negativ, Scaling, xyz)
}
void rect(GLfloat **w,GLfloat *c)
{ A_MatColor(c);                  // Materialfarbe setzen
  glBegin(GL_QUADS);           
    glVertex3f (w[0][0],w[0][1],w[0][2]); glVertex3f (w[1][0],w[1][1],w[1][2]);  // 1.u.2.Eckpunkt
    glVertex3f (w[2][0],w[2][1],w[2][2]); glVertex3f (w[3][0],w[3][1],w[3][2]);  // 3.u.4.Eckpunkt
  glEnd ();
} 
void triangle(GLfloat **w,GLfloat *c)
{ A_MatColor(c);                  // Materialfarbe setzen
  glBegin(GL_POLYGON);           
    glVertex3f (w[0][0],w[0][1],w[0][2]); glVertex3f (w[1][0],w[1][1],w[1][2]);  // 1.u.2.Eckpunkt
    glVertex3f (w[2][0],w[2][1],w[2][2]);  // Eckpunkt
  glEnd ();
} 
