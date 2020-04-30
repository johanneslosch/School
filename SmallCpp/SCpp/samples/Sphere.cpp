// Thomas Cassebaum, 18.9.2008, all rights reserved
#include <iostream.h>
#include <algeo.h>
void main(int argc, char **argv) // Get commandline arguments from user
{ glutInit(&argc, argv);         // GLUT init (first!)       
  // A_Init(Title,(A_ORTHO/A_PERSP)[,UnitsNumber[,AxSize[,AxLen[,Width,Height]]]]);
  A_Init("2D axis of abscissas",A_PERSP,3,6.);                      
}
void justify()                   // Pre-Justify of ALGEO-variables (such as A_sy, A_sx, ...)
{  A_sy+=1; A_phi-=.5; A_theta-=.18; A_yPlane=true; A_distance-=1.5;}       
void display()                   // Rendering-Function
{ A_Model(A_NIGHT);              // Manifest modeltype (A_BOOK, A_DARK)
  GLfloat MP[3]={0,0,0},     Gelb[4]={1,1,0,.8},
  Norm[3]={-1,2.5,-1},   Schleier[4]={.3,.3,.4,.8};
  A_Coord(3);                    // drawing axis of abscissas (Axunits, Negativ, Scaling, xyz)
  A_Disk(MP,Norm,Schleier,3.5,2.7);
  A_Sphere(MP,Gelb,2.f);
}
