// SmallC++ 2009, all rights reserved
#define SPEED 2 	           		// set movement-speed (default value: 2)
#include <iostream.h>
#include <algeo.h>
void main(int argc, char **argv)    // get commandline arguments from user
{ glutInit(&argc, argv);            // GLUT init (first!)       
  A_Init("Algeo",A_PERSP,4,6);   	// A_Init(title,(A_ORTHO/A_PERSP)[,units[,axSize[,axLen[,width,height]]]]);                   
}
void justify()                      // pre-justify of ALGEO-variables (such as A_sy, A_sx, ...)
{ A_zPlane=true;                    // show z-Plane with axes-grid, other example: A_sy+=.025f;    
  A_phi-=.5; A_theta-=.2;
}       
void display()                      // rendering-function
{ A_Model(A_NIGHT);                 // manifest modeltype, other values: A_BOOK, A_DARK
  vect s(1,2,3),r(0,-.5,-2);		// include here your render-code ...
  C_Vect0 a(s,C_RED,4);   
  C_Vector v(s,r,C_GREEN,4);
  C_Line g(s,r,C_T_GREEN,2,10,10,1);
  A_Coord(4);                       // drawing coordinate-axes
}