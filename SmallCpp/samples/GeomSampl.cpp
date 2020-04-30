// Thomas Cassebaum, 18.9.2008, all rights reserved
#define SPEED 2.f  // lower or higher set controls movement-speed
#include <iostream.h>
#include <algeo.h>
void main(int argc, char **argv)
{ glutInit(&argc, argv);              // init GLUT       
  A_Init("3D Grafik",A_PERSP,8);	  // init ALGEO
}
void justify(void)
{ A_xPlane=A_yPlane=A_zPlane=true;    // show x-/y-/z-planes
  A_Positiv=true;                     // only positive quadrant
  A_phi-=0.6f;                        // turn to the left
  A_theta-=.2f;                       // turn down 
  A_distance-=2.f;                    // move away from Scene
  A_sy+=.6f;                          // move down
  A_sx+=1.f;                          // move up
  // M_Foggy=false;
}
void display(void)
{ A_Model(A_NIGHT);                   // set type of Model
  A_Turn(A_turn);                     // turn the direction of the axis  
  glPushMatrix();        			  // save matrix
    C_Vector v1(vect(0.f,0.f,0.f),vect(6.f,6.f,6.f),C_RED,4.f);
    A_Coord(6,false);         // Koordinatensystem 6 Grids nicht negativ
    C_Triangle H(vect(0.f,0.f,4.f),vect(2.f,0.f,0.f),vect(0.f,1.5f,0.5f),C_DARKMAGENTA,C_T_RED,6.f);
    C_Triangle E1(vect(0.f,0.f,6.f),vect(0.f,6.f,-6.f),vect(6.f,0.f,-6.f),C_DARKGREEN,C_T_GREEN,6.f);
    C_Rhombus E2(vect(0.f,0.f,4.f),vect(6.f,0.f,0.f),vect(0.f,6.f,2.f),C_DARKMAGENTA,C_T_MAGENTA,4.f);
  glPopMatrix();        			  // load old matrix 
}
