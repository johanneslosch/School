// Thomas Cassebaum, 18.9.2008, all rights reserved
 #define SPEED 1.f                               // set movement-speed (default value: 2.0)
#include <iostream.h>
#include <algeo.h>
void main(int argc, char **argv)                   // Get commandline arguments from user
{ glutInit(&argc, argv);                           // GLUT init (first!)       
  A_Init("2D axis of abscissas",A_ORTHO,6,6.f);    // A_Init(Title,(A_ORTHO/A_PERSP)[,UnitsNumber[,AxSize[,AxLen[,Width,Height]]]]);                   
}
void justify()                                     // Pre-Justify of ALGEO-variables (such as A_sy, A_sx, ...)
{ A_zPlane=true;                                   // show z-Plane with axes-grid, other example: A_sy+=.025f;    
}       
void display()                                     // Rendering-Function
{ A_Model(A_NIGHT);                                // Manifest modeltype, other values: A_BOOK, A_DARK
  // include here your render-code ...
  A_Coord();                                       // drawing coordinate-axes, Parameters: (int axunits, bool negativ, bool scalenumbers, bool xyz)
}
