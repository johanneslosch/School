// Thomas Cassebaum, 18.9.2008, all rights reserved
#include <iostream.h>
#include <algeo.h>
void main(int argc, char **argv) // Get commandline arguments from user
{ glutInit(&argc, argv);         // GLUT init (first!)       
  // A_Init(Title,(A_ORTHO/A_PERSP)[,UnitsNumber[,AxSize[,AxLen[,Width,Height]]]]);
  A_Init("2D axis of abscissas",A_PERSP,6,5);                      
}
void justify()                   // Pre-Justify of ALGEO-variables (such as A_sy, A_sx, ...)
{ A_sy+=.18f; A_sx+=.05f;A_phi-=.5f;A_theta-=.2f; A_distance-=.35f; A_xPlane=A_yPlane=A_zPlane=A_Positiv=true;}       
void display()                   // Rendering-Function
{ A_Model(A_NIGHT);              // Manifest modeltype (A_BOOK, A_DARK)
  // include here your render-code ...
  A_Coord(5,false);                    // drawing axis of abscissas (Axunits, Negativ, Scaling, xyz)
}
