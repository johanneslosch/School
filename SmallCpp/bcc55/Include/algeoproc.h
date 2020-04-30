// Thomas Cassebaum, 24.8.2012, all rights reserved
// algeo.h  (kernel of ALGEO_V0.3)
//--------------------------------------------------
#include <t3d.h>
#include <t3d.cpp>
#include <windows.h>
#include <math.h>
#define A_speedfactor  0.05f // speed of objects-motion related to manual actions
#define A_NIGHT         'N'  // night-mode
#define A_BOOK          'B'  // book-mode
#define A_DARK          'D'  // dark-blue-mode
#define A_SKY           'S'  // light-blue-mode

#define A_ORTHO false        // orthogonal mode  use it for 2D
#define A_PERSP true         // perspective mode use it for 3D

#ifndef A_SPEED 
  #define A_SPEED 2.f // lower or higher set controls movement-speed
#endif
#define ROTATE 2             // mouse mode ROTATE
#define MOVE 1               // mouse mode MOVE

// Color and Light ***************************************************************************

#define LightPos0  {1.0f, 1.0f, 1.0f, 1.0f}  // default Light position

// use ready-defined Colors
#define A_WHITE         {1.f, 1.f, 1.f, 1.f}
#define A_BLUE          {0.f, 0.f, 1.f, 1.f}
#define A_RED           {1.f, 0.f, 0.f, 1.f}
#define A_GREEN         {0.f, 1.f, 0.f, 1.f}
#define A_YELLOW        {1.f, 1.f, 0.f, 1.f}
#define A_CYAN          {0.f, 1.f, 1.f, 1.f}
#define A_MAGENTA       {1.f, 0.f, 1.f, 1.f}
#define A_BLACK         {0.f, 0.f, 0.f, 1.f}
#define A_GRAY          {.5f, .5f, .5f, 1.f}

#define A_TRANSPARENT   {0.f, 0.f, 0.f, .0f}
#define A_T_GLASS       {1.f, 1.f, 1.f, .2f}
#define A_T_WHITE       {1.f, 1.f, 1.f, .5f}
#define A_T_BLUE        {0.f, 0.f, 1.f, .5f}
#define A_T_RED         {1.f, 0.f, 0.f, .5f}
#define A_T_GREEN       {0.f, 1.f, 0.f, .5f}
#define A_T_YELLOW      {1.f, 1.f, 0.f, .5f}
#define A_T_CYAN        {0.f, 1.f, 1.f, .5f}
#define A_T_MAGENTA     {1.f, 0.f, 1.f, .5f}
#define A_T_BLACK       {0.f, 0.f, 0.f, .5f}
#define A_T_GRAY        {.5f, .5f, .5f, .5f}
#define A_T_DARKGRAY    {.3f, .3f, .3f, 1.f}
#define A_T_DARKBLUE    {0.f, 0.f, .5f, 1.f}
#define A_T_DARKRED     {.5f, 0.f, 0.f, 1.f}
#define A_T_DARKGREEN   {0.f, .5f, 0.f, 1.f}
#define A_T_DARKYELLOW  {.5f, .5f, 0.f, 1.f}
#define A_T_DARKCYAN    {0.f, .5f, .5f, 1.f}
#define A_T_DARKMAGENTA {.5f, 0.f, .5f, 1.f}

#define A_T_LIGHTGRAY   {.6f, .6f, .6f, .5f}
#define A_T_LIGHTBLUE   {.3f, .3f, 1.f, .5f}
#define A_T_LIGHTRED    {1.f, .3f, .3f, .5f}
#define A_T_LIGHTGREEN  {.3f, 1.0f,.3f, .5f}
#define A_T_LIGHTYELLOW {1.f, 1.f, .3f, .5f}
#define A_T_LIGHTCYAN   {.3f, 1.f, 1.f, .5f}
#define A_T_LIGHTMAGENTA {1.f, .3f, 1.f, .5f}

#define A_LIGHTGRAY     {.6f, .6f, .6f, 1.f}
#define A_LIGHTBLUE     {.3f, .3f, 1.f, 1.f}
#define A_LIGHTRED      {1.f, .3f, .3f, 1.f}
#define A_LIGHTGREEN    {.3f, 1.0f,.3f, 1.f}
#define A_LIGHTYELLOW   {1.f, 1.f, .3f, 1.f}
#define A_LIGHTCYAN     {.3f, 1.f, 1.f, 1.f}
#define A_LIGHTMAGENTA  {1.f, .3f, 1.f, 1.f}

#define A_DARKGRAY      {.3f, .3f, .3f, 1.f}
#define A_DARKBLUE      {0.f, 0.f, .5f, 1.f}
#define A_DARKRED       {.5f, 0.f, 0.f, 1.f}
#define A_DARKGREEN     {0.f, .5f, 0.f, 1.f}
#define A_DARKYELLOW    {.5f, .5f, 0.f, 1.f}
#define A_DARKCYAN      {0.f, .5f, .5f, 1.f}
#define A_DARKMAGENTA   {.5f, 0.f, .5f, 1.f}

#define A_KOORDGRAY     {.7f, .7f, .7f, 1.f}
#define A_KOORDBLUE     {.5f, 1.0f, 1.0f, 1.f}
#define A_KOORDWHITE    {1.f, .8f, .8f, .9f}

bool A_Csyst=true;
// light-positions
GLfloat lightPos0[4]       = LightPos0;
// colors of the coordinates

GLfloat A_CoordColor[4]    = A_KOORDWHITE;
GLfloat A_CoordColor1[4]   = A_KOORDBLUE;
GLfloat A_CoordColor2[4]   = A_KOORDGRAY;
GLfloat Dunst[4]           = A_KOORDWHITE;
GLfloat A_DunstGrid[4]     = {.5f, .5f, .5f, .05f};
GLfloat A_Transparent[4]   ={0.f,0.f,0.f,0.f};     
GLfloat *A_GridColor;
GLfloat A_GridNIGHT[4]     = A_T_WHITE;     
GLfloat A_GridDARK[4]      = A_T_WHITE;     
GLfloat A_GridBOOK[4]      = A_T_GRAY;     
GLfloat A_GridSKY[4]       = A_T_BLACK;     

GLfloat CharColor_night[4] = A_WHITE;
GLfloat CharColor_book[4]  = A_BLACK;
GLfloat CharColor_sky[4]  = A_BLACK;
GLfloat CharColor_coord[4] = A_YELLOW;
GLfloat CharColor_book_blue[4] = A_DARKBLUE;
GLfloat CharColor_sky_blue[4] = A_BLACK;
GLfloat *A_CharCoord;
GLfloat *A_CharColor;

GLfloat feedcolor_dark[4] = {0.f,0.f,0.f,.7f};
GLfloat feedcolor_night[4] = {.3f,.3f,1.f,.4f};
GLfloat feedcolor_book[4]  = A_WHITE;
GLfloat feedcolor_sky[4]  = {.9f,.9f,1.f,.4f};
GLfloat *feedcolor;
GLfloat FuncColor[4]       = A_LIGHTRED;     

// state variables ************************************************************************************
//bool A_aend=true;
int A_0=1,A_1=1,A_2=1,A_3=1,A_4=1,A_5=1,A_6=1,A_7=1,A_8=1,A_9=1;
int      A_AxLine=0;                // linewidth axes
int      A_AxUnits=0;               // number of axunits in xyz-direction
unsigned A_CoordAnz=0;              // units counter
float    A_CoordLine=0.f;           // linewidth of axes
float    A_distance = 1.f;          // distance of object to camera
bool	 A_extmode = false;			// extended mode of your application (turn on/off with Button "E")
bool     A_Fnt=true;                //
bool     A_Foggy=true;              // fog-switch
bool     A_Gatt=true;               // coord-plane- and grid-lines
int      A_height=0, A_width=0;     // GLUT-windows-size
bool     A_HelpLines=false;         // helpline-switch (only vectors)
float    A_sx=0.f,A_sy=0.f,A_sz=0.f;// camera shifts in xyz-direction
float    A_ox=0.f, A_oy=0.f;		// ORTHO: picture shifts x:left-right  y:top-down
float    A_oz=1.f;					// ORTHO: picture distance
float    A_phi=0.f;                 // camera rotates around y-axis at an angel of ... degrees (s.a. 2° = 2./180.*M_PI)
float    A_theta=0.f;               // camera rotates around x-axis at an angel of ... degrees (s.a. 2° = 2./180.*M_PI)
bool     A_Positiv=false;           // coord-plane-lines only positiv quadrant
bool     A_Numbers=true;			// Show/Hide Numbers of axis
bool	 A_Quest=true;				// Quests un/-visible;
float    A_turn[3]={0.f,1.f,0.f};   // change axes in clock direction
float    A_x=1.f;                   // control with Keys 'g' and 'k'
char     A_theme=0;                 // Farbthema
bool     A_tc3d = false;            // true -> 3D, false -> 2D 
unsigned A_Top=0;                   // x-Axis right-direction (y=1, z=2);
bool     A_xPlane=false,
         A_yPlane=false,
         A_zPlane=false;            // axis-planes of the coordinates
bool     A_Transp=true;             // transparent on-off
bool     A_full=false;              // fullscreen on-off
int      motionState;               // Mouse-motion-state
float    pl=A_CoordAnz;             // coord-planes-area, gridcounter 
float    oldX, oldY;                // save-variables of last x,y
bool	 richtung=true;	 

// pointer of quadric-object
GLUquadricObj *quadric=gluNewQuadric();	
// prototypes
void display(void);	                // render-function
void idle(void);                    // idle (nothing to do)
void justify();                     // user-justify at start time
// A_prototypes ************************************************************************************
float* A_AngToCart(float,float);                    // calculate spherical- to cartesian coordinates
void A_Basics();                                    // set basic values of important state-variables
void A_Circle(float*, float*, float*, float, float);// render circle
void A_Cube(float*, float*, float*, float*, float, float);  // render cube
void A_Coord(int,bool,bool,bool);                   // render a cartesian co-ordinate system
void A_Cyln(float*, float*, float*, float, float);  // render cyln
void A_CylnConeRow(int);                            // render co-ordinate axes with n units 
void A_Disk(float*, float*, float*, float, float);  // render disk with outer and inner-radius
float A_f1(float);                                  // define user-function 1
float A_f2(float);                                  // define user-function 2
void A_Func2D1(float,float,float*,float,float);     // 2D-user-function 1
void A_Func2D2(float,float,float*,float,float);     // 2D-user-function 2
void A_Fog(float*,float);                           // configure and activate linear Fog
void A_Grid(float*, float*, float*);                // render co-ordinate-grid
void A_Init(char*,bool,int,int,int,int);            // init ALGEO-environment
void A_Keys(unsigned char,int,int);                 // callback-function keys
void A_Line(GLfloat*, GLfloat*, GLfloat*,           // * render line with extension (plus- or/and minus- 
            GLfloat,  GLfloat,  GLfloat,            // * direction) in vector-direction at position-vector
            GLfloat, GLfloat);           
void A_LineS(float*,float*,float*,float,int);       // render small line from S to D in color C,Thickness T and stippled ST 
void A_MatColor(GLfloat*);                          // choose material color
void A_Model(char);                                 // choose model (A_PERSP or A_ORTHO)
void A_Mouse(int,int,int,int);                      // callback-function mouse-detection
void A_MouseMotion(int,int);                        // callback-function mouse-movement
void A_Pixel(float*,float*,float);                  // set pixel with color and size
void A_Plane(float*,float*,float*,float*);          // render a rectangle plane without border
void A_PlaneRound(float*,float*,float*,float*);     // render a round plane without border
void A_Quader(float*,float*,float*,float*,float*,float*,float,bool,bool);
void A_Rectangle(float*,float*,float*,float*,float*,float,bool,bool);
void A_Rhombus(float*,float*,float*,float*,float*,float,bool,bool); // render a rectangle with plane and border
void A_Triangle(float*,float*,float*,float*,float*,float,bool,bool);  // render a triangle with plane and border
void A_SpecKeys(int,int,int);                       // callback-functions special-keys
void A_Sphere(float*, float*, float);               // render sphere
void A_TextOut(float*,string,float*,float);                
void A_TextOut(float*,char*,float*);                
void A_TextOut(float,float,float,char*,float*);
void A_SetTop(unsigned);
void A_Turn(GLfloat*);                              // rotate in 3D-vector-direction
void A_TurnAxes();									// rotate axes in clock-direction
void A_Vect(GLfloat*,GLfloat*,GLfloat*,GLfloat);    // render vector in direction at position vector
float* A_VectAdd(float*,float*);                    // return vector addition
float A_VectLength(GLfloat*);                       // return vector-length
GLfloat* A_VectProd(GLfloat*,GLfloat*);             // return vector product
float* A_VectMulv(float*,float);                    // return vector multiplication with a value
float* A_VectSub(float*,float*);                    // return vector subtraktion
void A_VectZero(GLfloat*,GLfloat*,GLfloat);         // render vektor in direction at origin of ordinates
void A_ScaleOut(int step);
/*void A__x(float*, float*, float);
void A__y(float*, float*, float);
void A__z(float*, float*, float);
*/

// declarations of functions  *************************************************************************

// Output of Scalenumbers
void A_ScaleOut(int step)
{   int max=A_AxUnits-1;
    GLfloat grau[] = A_GRAY , gelb[] = A_YELLOW, blau[] = A_BLUE;
    A_MatColor(grau);
    float scale=.25f;
	glPushMatrix();
	  //glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
	  //glMatrixMode(GL_MODELVIEW);
	  glScalef(scale,scale,scale);
	  glTranslatef(-.2f - 16.f*max*scale, -5.6f*scale, +0.0f*scale);  // näher/ferner
	  string s; int i; char sch[20];
	  itoa(-1*(max+1),sch,10);
	  s=(string)sch;
	  for(i=-max;i<=max;i+=step)
	  { if(i){ if(i>0||!A_Positiv)
	           { itoa(i,sch,10); s=(string)sch; 
  	             glPushMatrix();
  	               if(A_Top) { glRotatef(90.f,1.0f,0.0f,0.0f);
  	                           glRotatef(90.f,0.0f,1.0f,0.0f);
  	                           glTranslatef(5.2f*scale, -5.9f*scale, 0.0f*scale);
  	                         }
  	               t3dDraw3D(s, 0.f, 0.f, scale*.6f);  // Tiefe
  	             glPopMatrix();  
  	           }
  	           A_MatColor(grau);
	         }
	    glTranslatef(scale*16.0f*step, 0.0f, 0.0f);
	  }
	  
      s="x";
	  glPushMatrix();
	    glScalef(scale*8.f,scale*8.f,scale*8.f);
	    if(!A_Top) glTranslatef(scale*2.0f*step, 0.0f, 0.0f);
        if((A_theme==A_SKY)||(A_theme==A_BOOK)) A_MatColor(blau); else A_MatColor(gelb);
	    if(A_Top) { glRotatef(90.f,1.0f,0.0f,0.0f);
  	                glRotatef(90.f,0.0f,1.0f,0.0f);
  	                glTranslatef(step*2.6f*scale, -3.0f*scale, 0.0f*scale);
                  }
        t3dDraw3D(s, 0.f, 0.f, scale*.4f);
	  glPopMatrix();
	  A_MatColor(grau);
	  
	  glTranslatef((-16.0f*max-16.0f*step+5.5f)*scale, (6.2f -16.f*max)*scale, 0.0f);  // näher/ferner
	  s=(string)sch;
	  for(i=-max;i<=max;i+=step)
	  { if(i) { if(i>0||!A_Positiv)
	            { itoa(i,sch,10); s=(string)sch; 
  	             glPushMatrix();
  	               if(A_Top) { glRotatef(90.f,1.0f,0.0f,0.0f);
  	                           glRotatef(90.f,0.0f,1.0f,0.0f);
  	                           glTranslatef(-1.f*scale, -5.9f*scale, -4.5f*scale);
  	                         }
  	               t3dDraw3D(s, 0.f, 0.f, scale*.6f);  // Tiefe
  	             glPopMatrix();  
  	            }
  	          }  
	    glTranslatef(0.0f,scale*16.0f*step, 0.0f);
	  }
      s="y";
	  glPushMatrix();
	    glScalef(scale*8.f,scale*8.f,scale*8.f);
	    glTranslatef(2.f*scale, scale*(16.f*step-12.f), 0.f);
        if((A_theme==A_SKY)||(A_theme==A_BOOK)) A_MatColor(blau); else A_MatColor(gelb);
	    if(A_Top) { glRotatef(90.f,1.0f,0.0f,0.0f);
  	                glRotatef(90.f,0.0f,1.0f,0.0f);
  	                glTranslatef(step*-3.f*scale, -3.0f*scale, -4.0f*scale);
                  }
        t3dDraw3D(s, 0.f, 0.f, scale*.4f);
	  glPopMatrix();
	  A_MatColor(grau);


	  if(A_tc3d)
	  { glTranslatef(11.0f*scale-16.f*scale, (-38.f-16.f*max + 16.f*step)*scale, (16.f-16.f*max-16.0f*step)*scale);  // näher/ferner
	    s=(string)sch;
	    for(i=-max;i<=max;i+=step)
	    { if(i) { if(i>0||!A_Positiv)
	              { itoa(i,sch,10); s=(string)sch; 
  	             glPushMatrix();
  	               if(A_Top) { glRotatef(90.f,1.0f,0.0f,0.0f);
  	                           glRotatef(90.f,0.0f,1.0f,0.0f);
  	                           glTranslatef(10.0f*scale, .5f*scale, 0.0f*scale);
  	                         }
  	               t3dDraw3D(s, 0.f, 0.f, scale*.6f);  // Tiefe
  	             glPopMatrix();  
	              }
	            }
	      glTranslatef(0.0f, 0.0f,scale*16.0f*step);
	    }
	  
        s="z";
	    glPushMatrix();
	    //glTranslatef(0.0f, 0.0f,scale*16.0f*step);
	      glScalef(scale*8.f,scale*8.f,scale*8.f);
        if((A_theme==A_SKY)||(A_theme==A_BOOK)) A_MatColor(blau); else A_MatColor(gelb);
	    if(A_Top) { glRotatef(90.f,1.0f,0.0f,0.0f);
  	                glRotatef(90.f,0.0f,1.0f,0.0f);
  	                glTranslatef(step*6.5f*scale, 4.0f*scale, 0.0f*scale);
                  }
          t3dDraw3D(s, 0.f, 0.f, scale*.4f);
	    glPopMatrix();
	    A_MatColor(grau);
      }
  	glPopMatrix();
}

// keyboard functions
void inline A_Keys(unsigned char key, int x, int y)
{  bool tast=true;
   switch(key)
   { case '*':
     case '+':  if(A_tc3d) A_distance-=A_speedfactor*A_SPEED; break;
     case '_':
     case '-':  if(A_tc3d) A_distance+=A_speedfactor*A_SPEED; break;
     case '1':  A_1++; break;
     case '2':  A_2++; break;
     case '3':  A_3++; break;
     case '4':  A_4++; break;
     case '5':  A_5++; break;
     case '6':  A_6++; break;
     case '7':  A_7++; break;
     case '8':  A_8++; break;
     case '9':  A_9++; break;
     case '0':  A_0++; break;
     case '!':  A_1--; break;
     case '"':  A_2--; break;
     case 167:  A_3--; break;
     case '$':  A_4--; break;
     case '%':  A_5--; break;
     case '&':  A_6--; break;
     case '/':  A_7--; break;
     case '(':  A_8--; break;
     case ')':  A_9--; break;
     case '=':  A_0--; break;
     case 'a':
     case 'A':  if(A_tc3d) A_phi+=A_speedfactor*A_SPEED; break;
     case 'b':  
     case 'B':  if(A_Fnt) A_Fnt=0; else A_Fnt=1; break;
     case 'c':
     case 'C':  A_Csyst=!A_Csyst; break;
     case 'd':
     case 'D':  if(A_tc3d) A_phi-=A_speedfactor*A_SPEED; break;
     case 'e':
     case 'E':  A_extmode=!A_extmode; break;
     case  27:  exit(0); break;
     case 'f':
     case 'F':  A_Foggy=!A_Foggy; break;
     case 'g':
     case 'G':  A_x++; break;
     case 'h':
     case 'H':  A_HelpLines=!A_HelpLines; break;
     case 'i':
     case 'I':  break;
     case 'j':
     case 'J':  break;
     case 'k':
     case 'K':  A_x--; break;
     case 'l':
     case 'L':  A_Gatt=!A_Gatt; break; // (Lines at Grid)
     case 'm':
     case 'M':  A_tc3d=!A_tc3d; break;
     case 'n':  
     case 'N':  A_Numbers=!A_Numbers; break;
     case 'o':
     case 'O':  break;
     case 'p':
     case 'P':  A_Positiv=!A_Positiv; break;
     case 'q':
     case 'Q':  A_Quest=!A_Quest; break;
	 case 'r':
	 case 'R':  if(A_Top<1) A_Top++; else A_Top=0; break;
	 case 's':
	 case 'S':	if(A_tc3d) A_theta+=A_speedfactor/3.*A_SPEED; break;
     case 't':
     case 'T':  A_Transp=!A_Transp; break;
     case 'u':
     case 'U':  A_Basics(); 
                justify(); 
  				if(A_tc3d)
  				{ if(A_Positiv)
    			  { A_sy+=2.4f;  A_distance+=A_CoordAnz*2.2f;
    			  }
    			  else 
    			  { A_distance += A_CoordAnz *3.5f; 
    			  }
  				}
                break;
     case 'v':  
     case 'V':  A_full=!A_full;
                if(A_full)
                { glutFullScreen();
                } 
                else 
                { glutReshapeWindow(A_width, A_height);    
                  glutPostRedisplay();
                }
                break;
     case 'w':
     case 'W':  if(A_tc3d) A_theta-=A_speedfactor/3.*A_SPEED; break;
     case 'x':
     case 'X':  A_xPlane=!A_xPlane; break;
     case 'y':
     case 'Y':  A_yPlane=!A_yPlane; break;
     case 'z':
     case 'Z':  A_zPlane=!A_zPlane; break;
     default: tast=false;
   }
   //if(tast)  A_aend=true;
   glutPostRedisplay();
}
void inline A_SpecKeys(int key, int x, int y)
{  switch(key)
   { case GLUT_KEY_LEFT:  A_sx+=A_speedfactor*A_SPEED; break;
     case GLUT_KEY_RIGHT: A_sx-=A_speedfactor*A_SPEED; break;
     case GLUT_KEY_DOWN:  A_sy+=A_speedfactor*A_SPEED; break;
     case GLUT_KEY_UP:    A_sy-=A_speedfactor*A_SPEED; break;
     case GLUT_KEY_F1:    WinExec("cmd /c \"CppKurs.chm\"", SW_SHOW);
   }
   glutPostRedisplay();
}

// choose material color

void A_MatColor(GLfloat *C)
{ 
  glMaterialfv(GL_FRONT,GL_AMBIENT_AND_DIFFUSE,C); 
  glMaterialfv(GL_FRONT,GL_SPECULAR, C);
  glMaterialf(GL_FRONT,GL_SHININESS,20); 
}
// draw graphic of 2D-Function f(x)
void A_Func2D1(float Xstart, float Xend,GLfloat *Color, float Thick, float Xstep=0.1f)
{ bool nocatch=true;
  GLfloat D[3],P[3];       // D: direction, P: point
  D[2]=0.f; P[2]=0.f;      // z-component: zero
  float Xswing=Xstep/16.f; // overlay of the cylns
  for(P[0]=Xstart; P[0]<Xend-.0001f; P[0]+=Xstep)   // loop of cyln-draws
  { try { P[1]=A_f1(P[0]);                          // calculate function-value
          D[0]=Xstep;D[1]=A_f1(P[0]+Xstep)-P[1];    // calculate destination of the cyln
          if(A_VectLength(D)<(1E3))
          if(nocatch) A_Cyln(P,D,Color,A_VectLength(D)+Xswing,Thick/100.f);  // draw cyln
          else nocatch=true;
        }
    catch(...) { nocatch=false; continue; }
  }
}
void A_Func2D2(float Xstart, float Xend,GLfloat *Color, float Thick, float Xstep=0.1f)
{ bool nocatch=true;
  GLfloat D[3],P[3];       // D: direction, P: point
  D[2]=0.f; P[2]=0.f;      // z-component: zero
  float Xswing=Xstep/16.f; // overlay of the cylns
  for(P[0]=Xstart; P[0]<Xend-.0001f; P[0]+=Xstep)   // loop of cyln-draws
  { try { P[1]=A_f2(P[0]);                          // calculate function-value
          D[0]=Xstep;D[1]=A_f2(P[0]+Xstep)-P[1];    // calculate destination of the cyln
          if(A_VectLength(D)<(1E3))
          if(nocatch) A_Cyln(P,D,Color,A_VectLength(D)+Xswing,Thick/100.f); // draw cyln
          else nocatch=true;
        }
    catch(...) { nocatch=false; continue; }
  }
}

// vector addition
float* A_VectAdd(float* A,float* B)
{ static float S[3];
  for(int i=0;i<3;i++) S[i]=A[i]+B[i];
  return S;
}
// vector subtraction
float* A_VectSub(float* A,float* B)
{ static float S[3];
  for(int i=0;i<3;i++) S[i]=A[i]-B[i];
  return S;
}
// vector multiplication with a value
float* A_VectMulv(float* A,float value)
{ static float S[3];
  for(int i=0;i<3;i++) S[i]=A[i]*value;
  return S;
}
// row of cylinders ending by a cone (drawing axis-vector)
void A_CylnConeRow(int n)            
{ // glDisable(GL_DEPTH_TEST);          // depth test
  for(int i=0;i<n;i++)                           // n Zylinder in Richtung mit Kegelspitze zeichnen  
  { if(i%2)A_MatColor(A_CoordColor2);//glMaterialfv(GL_FRONT_AND_BACK, GL_AMBIENT_AND_DIFFUSE, A_CoordColor2);
    else   A_MatColor(A_CoordColor);//glMaterialfv(GL_FRONT_AND_BACK, GL_AMBIENT_AND_DIFFUSE, A_CoordColor);
    gluCylinder(quadric,A_CoordLine,A_CoordLine,1.f,32,1); // Zeichne Zylinder in Länge 0.08 und Strichdicke in Richtung	
    glTranslatef(0.0f,0.0f,1.f); // Schiebe um 0.08 in Richtung
  }
  A_MatColor(A_CoordColor1);
  //glMaterialfv(GL_FRONT_AND_BACK, GL_AMBIENT_AND_DIFFUSE, A_CoordColor1);
  glutSolidCone(A_CoordLine*3.f,A_CoordLine*9.f,32,1);      // Zeichne Kegel in Richtung
  gluDisk(quadric,0.f,A_CoordLine*3.f, 32, 1);
  // glEnable(GL_DEPTH_TEST);          // depth test
  glTranslatef(0.0f,0.0f,-n);              // Ausgangspunkt wieder einstellen
  A_MatColor(A_CoordColor2);
  //glMaterialfv(GL_FRONT_AND_BACK, GL_AMBIENT_AND_DIFFUSE, A_CoordColor2);
}
void A_print_bitmap_string(void* font, char* s)
{ if (s && strlen(s))
  { while (*s) 
    { glutBitmapCharacter(font, *s); 
      s++; 
    }
  }
}
/* Textausgabe an der Position P (P ist ein Pointer der auf das Array P[3] zeigt.)      
   P - Positionsvektor, S - Ausgabetext, Color - Farbvektor, scale - Schriftgröße (Standard 0.25f)
*/
// Ausgabe des 3D-Textes S, der  durch Szenenbewegungen nicht verändert wird
void A_TextStatic(float* P, string S, float *Color=NULL, float scale=0.25f)
{ glPushMatrix();
    if(A_Top==1) { A_Turn(A_turn); A_Turn(A_turn); }
	glTranslatef(A_sx, A_sy, A_sz);
	A_Turn(A_AngToCart(A_theta,A_phi));
	if(Color)A_MatColor(Color);
	glScalef(scale,scale,scale);
    //float hll;
	//if(A_Top==1) { A_TurnAxes(); A_TurnAxes();  
	//hll=P[0]; P[0]=P[1]; P[1]=P[2]; P[2]=hll; }
	glTranslatef(P[0]*scale, P[1]*scale, P[2]*scale);
    t3dDraw3D(S, 0.f, 0.f, scale*.4f);
  glPopMatrix(); 
}
// Ausgabe eines 3D-Textes string S der als Teil der Szene mitbewegt wird
void A_TextOut(float* P, string S, float *Color=NULL, float scale=0.25f)
{   glPushMatrix();
	  if(Color)A_MatColor(Color);
	  glScalef(scale,scale,scale);
	  float hll;
	  if(A_Top==1) { A_TurnAxes(); A_TurnAxes();  
	  hll=P[0]; P[0]=P[1]; P[1]=P[2]; P[2]=hll; }
	  glTranslatef(P[0]*scale, P[1]*scale, P[2]*scale);
      t3dDraw3D(S, 0.f, 0.f, scale*.6f); 
	glPopMatrix();    
}
// Ausgabe eines Bitmap-Textes mit Positionsvektor P[3]
void A_TextOut(float* P, char* S, float *Color=NULL)
{ glColor4f(Color[0],Color[1],Color[2],Color[3]); // Rot
  glRasterPos3f(P[0],P[1],P[2]);             // Einstellung Textposition  
  A_print_bitmap_string(GLUT_BITMAP_TIMES_ROMAN_24 , S);//HELVETICA_18, S);//TIMES_ROMAN_24 , S);
  if(Color) A_MatColor(Color); 
}
// Ausgabe eines Bitmap-Textes mit den Positionskomponenten P0,P1,P2
void A_TextOut(float P0,float P1,float P2, char* S, float *Color=NULL)
{ glColor4f(Color[0],Color[1],Color[2],Color[3]); // Rot
  glRasterPos3f(P0,P1,P2);             // Einstellung Textposition  
  A_print_bitmap_string(GLUT_BITMAP_TIMES_ROMAN_24 , S);//HELVETICA_18, S);//TIMES_ROMAN_24 , S);
  if(Color) A_MatColor(Color); 
}

// drawing axis of abscissas
void A_Coord(int limgrid=5,bool scale=false,bool xyz=true)
{ float KoordTextPos[3];
  //if(A_aend) 
{
  if(limgrid<1) limgrid=1;
  bool neg=!A_Positiv;
  unsigned short Kanz=A_AxUnits;
  if(limgrid) pl=limgrid;
  float DLine=A_CoordLine*(A_AxUnits+2); // distance text of axes
  float lachs[]={4.,6.,9.,3.};           // offsets
  // Szene zeichnen
if(A_Csyst)
{ 
  glPushMatrix(); // 1       
  if(!neg){lachs[0]-=3.f;lachs[1]+=3.f;lachs[3]-=3.; }
  if(A_Numbers) A_ScaleOut(1);      // scalout(Maxwert, Schrittweite [, scale (=.25)] )
  
  if(A_tc3d)
  { 
    if(A_Numbers) A_ScaleOut(1);    // scalout(Maxwert, Schrittweite [, scale (=.25)] )
    glTranslatef(0.,0.,-Kanz*(lachs[2]));       // move in z-direction backwards (start-point for coordline z)
    A_MatColor(A_CoordColor);
    
    //glMaterialfv(GL_FRONT_AND_BACK, GL_AMBIENT_AND_DIFFUSE, A_CoordColor);
    if(neg) gluCylinder(quadric,0.5*A_CoordLine,A_CoordLine,Kanz*lachs[1],32,1); // render cylinder in current direction	
    glTranslatef(0.,0.,Kanz*(lachs[1]));       // move in z-direction (start-point for marked coordlinie z)
    A_CylnConeRow(Kanz*(lachs[0]));            // render cylinders with end-cone (z-axis)
    A_MatColor(A_CoordColor);
    //glMaterialfv(GL_FRONT_AND_BACK, GL_AMBIENT_AND_DIFFUSE, A_CharColor);
    glTranslatef(0.,0.,Kanz*(lachs[3]));       // move back
    //if(xyz) A_TextOut(.0f,.0f,Kanz+1.f, "z",A_CharCoord);
    /*
    float KoordTextPos[3];
    if(xyz) 
    { KoordTextPos[0]=0.f;KoordTextPos[1]=0.f;KoordTextPos[2]=Kanz+1.f;
      A__z(KoordTextPos, A_CharCoord, .16f);
    }
    */
  }
  else 
  { A_Top=0;
    lachs[0]= 2.;lachs[1]=0.;lachs[2]=1.;lachs[3]=1.; 
  }
  glRotatef(-90.f,1.0f,0.0f,0.0f);              
  glTranslatef(0.,0.,-Kanz*lachs[2]);         
  A_MatColor(A_CoordColor);
  //glMaterialfv(GL_FRONT_AND_BACK, GL_AMBIENT_AND_DIFFUSE, A_CoordColor);
  if(neg)gluCylinder(quadric,0.5*A_CoordLine,A_CoordLine,Kanz*lachs[1],32,1); 
  glTranslatef(0.,0.,Kanz*lachs[1]);           
  A_CylnConeRow(Kanz*lachs[0]);               
  A_MatColor(A_CoordColor);
  //glMaterialfv(GL_FRONT_AND_BACK, GL_AMBIENT_AND_DIFFUSE, A_CharColor);
  glTranslatef(0.,0.,Kanz*lachs[3]);          
  glRotatef(-90.f,-1.0f,0.0f,0.0f);           
  // if(xyz) A_TextOut(Kanz+1.,.0f,.0f, "x",A_CharCoord);
  /*
  if(xyz) 
  { KoordTextPos[0]=Kanz+1.f;KoordTextPos[1]=0.f;KoordTextPos[2]=0.f;
    A__x(KoordTextPos, A_CharCoord, .14f);
  }
  */
  glRotatef(-90.f,1.0f,0.0f,0.0f);              // turn direction ...  
  glRotatef(90.f,0.0f,1.0f,0.0f);               // ... in y-direction
  glTranslatef(0.,0.,-Kanz*lachs[2]);       // translate in y-direction back (start of coordline z)
  A_MatColor(A_CoordColor);
  //glMaterialfv(GL_FRONT_AND_BACK, GL_AMBIENT_AND_DIFFUSE, A_CoordColor);
  if(neg) gluCylinder(quadric,0.5*A_CoordLine,A_CoordLine,Kanz*lachs[1],32,1); // render cyln in previous direction	
  glTranslatef(0.,0.,Kanz*lachs[1]);                    // translate in y-direction backwords (start of coordline y)
  A_CylnConeRow(Kanz*lachs[0]);                                     // render the cylns with top (y-Axis)
  A_MatColor(A_CoordColor);
  //glMaterialfv(GL_FRONT_AND_BACK, GL_AMBIENT_AND_DIFFUSE, A_CharColor);
  glTranslatef(0.,0.,Kanz*lachs[3]);                     // Rückverschiebung zum Ursprung
  glRotatef(90.f,1.0f,0.0f,0.0f);               // set in z-direction again (Light of 'y')
  //if(xyz) A_TextOut(-Kanz-1.,.0f,.0f, "y",A_CharCoord);
  /*
  if(xyz) 
  { KoordTextPos[0]=-Kanz-.8f;KoordTextPos[1]=-0.3f;KoordTextPos[2]=0.f;
    A__y(KoordTextPos, A_CharCoord, .16f);
  }
  
  if(scale)
  { if(Kanz>=5) { A_TextOut(-.39f,-DLine,.0f, "5", A_CharColor); 
                A_TextOut(.42f,-DLine,.0f, "-5"); }
    if(Kanz>=10){ A_TextOut(-.79f,-DLine,.0f,"10"); A_TextOut(.83f,-DLine,.0f,"-10"); }
  }
  */
  glPopMatrix();  // 1  
  GLfloat x_T[3]={0.f,-pl,-pl}, x_B[3]={0.f,pl,pl};
  GLfloat y_T[3]={pl,0.f,pl}, y_B[3]={-pl,0.f,-pl};
  GLfloat z_T[3]={-pl,-pl,0.f}, z_B[3]={pl,pl,0.f};
  GLfloat x_pT[3]={0.f,0.f,0.f}, x_pB[3]={0.f,pl,pl};
  GLfloat y_pT[3]={pl,0.f,pl}, y_pB[3]={0.f,0.f,0.f};
  GLfloat z_pT[3]={0.f,0.f,0.f}, z_pB[3]={pl,pl,0.f};
  glPushMatrix;  // 1
  GLfloat pl2=A_Positiv?pl:(pl+pl);
  GLfloat xU[3]={pl2,0,0},yU[3]={0,pl2,0},zU[3]={0,0,pl2},
          xmU[3]={-pl2,0,0},zmU[3]={0,0,-pl2};
  if(A_Positiv)  // only positive quadrant
  { if(A_xPlane) 
      A_Rhombus(x_pT,yU,zU,A_GridColor, A_DunstGrid,3.f, true,true);  // draw yz-plane
    if(A_yPlane)
      A_Rhombus(y_pT,zmU,xmU,A_GridColor, A_DunstGrid,3.f, true,true);// draw xz-plane
    if(A_zPlane) 
      A_Rhombus(z_pT,xU,yU,A_GridColor, A_DunstGrid,3.f, true,true);  // draw xy-plane
    if(A_Gatt)
    { if(A_xPlane) A_Grid(x_pT,x_pB,A_GridColor); // draw yz-gatter
      if(A_yPlane) A_Grid(y_pT,y_pB,A_GridColor); // draw xz-gatter
      if(A_zPlane) A_Grid(z_pT,z_pB,A_GridColor); // draw xy-gatter
    }
  } 
  else // every quadrants
  { if(A_xPlane)  
      A_Rhombus(x_T,yU,zU,A_GridColor, A_DunstGrid,3.f, true,true);  // draw yz-plane
    if(A_yPlane) 
      A_Rhombus(y_T,xmU,zmU,A_GridColor, A_DunstGrid,3.f, true,true);// draw xz-plane
    if(A_zPlane)  
      A_Rhombus(z_T,xU,yU,A_GridColor, A_DunstGrid,3.f, true,true);  // draw xy-plane
    if(A_Gatt)
    { if(A_xPlane) A_Grid(x_T,x_B,A_GridColor); // draw yz-gatter
      if(A_yPlane) A_Grid(y_T,y_B,A_GridColor); // draw xz-gatter
      if(A_zPlane) A_Grid(z_T,z_B,A_GridColor); // draw xy-gatter
    }
  } 
  glPopMatrix();  // 1
}
//A_aend=false;
}
}
void A_Plane(float* T, float* B, float* C ,float* CB)
{ glPushMatrix; // 1
  A_MatColor(C);
  //glMaterialfv(GL_FRONT_AND_BACK, GL_AMBIENT_AND_DIFFUSE, C);
  glBegin(GL_QUADS);     // quad plane       
    glVertex3f( B[0], B[1], B[2]);    
    if(B[1]!=T[1]) glVertex3f( T[0], B[1], T[2]);
    else glVertex3f( T[0], B[1], B[2]);     
    glVertex3f( T[0], T[1], T[2]);     
    if(B[1]!=T[1]) glVertex3f( B[0], T[1], B[2]);
    else glVertex3f( B[0], T[1], T[2]);
  glEnd();
  A_MatColor(CB);
  //glMaterialfv(GL_FRONT_AND_BACK, GL_AMBIENT_AND_DIFFUSE, CB);
  glBegin(GL_LINE_LOOP); // grid lines           
    glVertex3f( B[0], B[1], B[2]);    
    if(B[1]!=T[1]) glVertex3f( T[0], B[1], T[2]);
    else glVertex3f( T[0], B[1], B[2]);     
    glVertex3f( T[0], T[1], T[2]);     
    if(B[1]!=T[1]) glVertex3f( B[0], T[1], B[2]);
    else glVertex3f( B[0], T[1], T[2]);
  glEnd();
  glPopMatrix;  // 1
}

void A_Grid(float* T, float* B, float* C )
{ float Tv[3],Bv[3], diff; float thick=2.f;
  if(T[0]==B[0])
  { for(int i=0;i<3;i++) { Tv[i]=T[i]; Bv[i]=B[i]; }  
    diff = (B[2]-T[2])/(2.f*pl);
    if(A_Positiv) diff+=diff; 
    for(Bv[2]=Tv[2];Bv[2]<(B[2]+.0001);Tv[2]+=diff,Bv[2]+=diff) 
      A_LineS(Tv,Bv,C,thick,0);
    for(int i=0;i<3;i++) { Tv[i]=T[i]; Bv[i]=B[i]; }  
    diff = (B[1]-T[1])/(2.f*pl);
    if(A_Positiv) diff+=diff; 
    for(Bv[1]=Tv[1];Bv[1]<(B[1]+.0001);Tv[1]+=diff,Bv[1]+=diff) 
      A_LineS(Tv,Bv,C,thick,0);
  }   
  else if(T[1]==B[1])
  { for(int i=0;i<3;i++) { Tv[i]=T[i]; Bv[i]=B[i]; }  
    diff = (B[0]-T[0])/(2.f*pl);
    if(A_Positiv) diff+=diff; 
    for(Bv[0]=Tv[0];Bv[0]>(B[0]+.0001);Tv[0]+=diff,Bv[0]+=diff) 
      A_LineS(Tv,Bv,C,thick,0);
    for(int i=0;i<3;i++) { Tv[i]=T[i]; Bv[i]=B[i]; }  
    diff = (B[2]-T[2])/(2.f*pl);
    if(A_Positiv) diff+=diff; 
    for(Bv[2]=Tv[2];Bv[2]>(B[2]+.0001);Tv[2]+=diff,Bv[2]+=diff) 
      A_LineS(Tv,Bv,C,thick,0);
  }   
  else if(T[2]==B[2])
  { for(int i=0;i<3;i++) { Tv[i]=T[i]; Bv[i]=B[i]; }  
    diff = (B[0]-T[0])/(2.f*pl);
    if(A_Positiv) diff+=diff; 
    for(Bv[0]=Tv[0];Bv[0]<(B[0]+.0001);Tv[0]+=diff,Bv[0]+=diff) 
      A_LineS(Tv,Bv,C,thick,0);
    for(int i=0;i<3;i++) { Tv[i]=T[i]; Bv[i]=B[i]; }  
    diff = (B[1]-T[1])/(2.f*pl);
    if(A_Positiv) diff+=diff; 
    for(Bv[1]=Tv[1];Bv[1]<(B[1]+.0001);Tv[1]+=diff,Bv[1]+=diff) 
      A_LineS(Tv,Bv,C,thick,0);
  }   
}
void A_Rhombus( float *S, float *R1, float *R2,  float* BorderColor, 
                float* FillColor,float T=1.f, bool Fill = false, bool Border=true)
{ glPushMatrix();  // 1
  glTranslatef(S[0],S[1],S[2]); 
  float *ZW; ZW=A_VectAdd(R1,R2);
  if(Fill)  
  { A_MatColor(FillColor);
    //glMaterialfv(GL_FRONT_AND_BACK, GL_AMBIENT_AND_DIFFUSE, FillColor);
    glBegin(GL_QUADS);            
      glVertex3f(0.f,0.f,0.f);
      glVertex3f(R1[0],R1[1],R1[2]);
      glVertex3f(ZW[0],ZW[1],ZW[2]);
      glVertex3f(R2[0],R2[1],R2[2]);
    glEnd();
  }
  glPopMatrix();    // 1
  if(Border)
  { glPushMatrix();  // 1
    glMaterialfv(GL_FRONT_AND_BACK, GL_AMBIENT_AND_DIFFUSE, BorderColor);
    A_Line(A_VectAdd(S,R1),R2,BorderColor,T,0,0,0,0);
    A_Line(A_VectAdd(S,R2),R1,BorderColor,T,0,0,0,0);
    A_Line(S,R1,BorderColor,T,0,0,0,0);
    A_Line(S,R2,BorderColor,T,0,0,0,0);
    A_Sphere(S,BorderColor,T);    
    A_Sphere(A_VectAdd(S,R1),BorderColor,T);    
    A_Sphere(A_VectAdd(S,R2),BorderColor,T);    
    A_Sphere(A_VectAdd(R2,A_VectAdd(S,R1)),BorderColor,T);    
    glPopMatrix();  // 1
  }  
  
}
void A_Rectangle( float *S, float *R1, float *R2,  float* BorderColor, 
                float* FillColor,float T=1.f, bool Fill = false, bool Border=true)
{ glPushMatrix();  // 1
  glTranslatef(S[0],S[1],S[2]); 
  float *ZW; ZW=A_VectAdd(R1,R2);
  if(Fill)  
  { A_MatColor(FillColor);
    //glMaterialfv(GL_FRONT_AND_BACK, GL_AMBIENT_AND_DIFFUSE, FillColor);
    glBegin(GL_QUADS);            
      glVertex3f(0.f,0.f,0.f);
      glVertex3f(R1[0],R1[1],R1[2]);
      glVertex3f(ZW[0],ZW[1],ZW[2]);
      glVertex3f(R2[0],R2[1],R2[2]);
    glEnd();
  }
  glPopMatrix();    // 1
  if(Border)
  { glPushMatrix();  // 1
    A_MatColor(BorderColor);
    //glMaterialfv(GL_FRONT_AND_BACK, GL_AMBIENT_AND_DIFFUSE, BorderColor);
    A_Line(A_VectAdd(S,R1),R2,BorderColor,T,0,0,0,0);
    A_Line(A_VectAdd(S,R2),R1,BorderColor,T,0,0,0,0);
    A_Line(S,R1,BorderColor,T,0,0,0,0);
    A_Line(S,R2,BorderColor,T,0,0,0,0);
    A_Sphere(S,BorderColor,T);    
    A_Sphere(A_VectAdd(S,R1),BorderColor,T);    
    A_Sphere(A_VectAdd(S,R2),BorderColor,T);    
    A_Sphere(A_VectAdd(R2,A_VectAdd(S,R1)),BorderColor,T);    
    glPopMatrix();  // 1
  }  
  
}
void A_Quader( float *S, float *R1, float *R2, float* R3, float* BorderColor, 
                float* FillColor,float T=1.f, bool Fill = false, bool Border=true)
{ A_Rectangle(S,R1,R2,BorderColor,FillColor,T,Fill,Border);
  A_Rectangle(S,R1,R3,BorderColor,FillColor,T,Fill,Border);
  A_Rectangle(S,R2,R3,BorderColor,FillColor,T,Fill,Border);
  for(int i=0;i<3;i++) S[i]=S[i]+R1[i]+R2[i]+R3[i];
  for(int i=0;i<3;i++) { R1[i]=-R1[i]; R2[i]=-R2[i]; R3[i]=-R3[i]; }
  A_Rectangle(S,R1,R2,BorderColor,FillColor,T,Fill,Border);
  A_Rectangle(S,R1,R3,BorderColor,FillColor,T,Fill,Border);
  A_Rectangle(S,R2,R3,BorderColor,FillColor,T,Fill,Border);
} 
void A_Triangle(float *S, float *R1, float *R2,  float* BorderColor, 
                 float* FillColor,float T, bool Fill = false, bool Border=true)
{ glPushMatrix(); // 1
  glTranslatef(S[0],S[1],S[2]); 
  if(Fill)  
  { A_MatColor(FillColor);
    //glMaterialfv(GL_FRONT_AND_BACK, GL_AMBIENT_AND_DIFFUSE, FillColor);
    glBegin(GL_POLYGON);            
      glVertex3f(0.f,0.f,0.f);
      glVertex3f(R1[0],R1[1],R1[2]);
      glVertex3f(R2[0],R2[1],R2[2]);
    glEnd();
  }
  glPopMatrix();  // 1
  
  if(Border)
  { glPushMatrix(); // 1
    A_MatColor(BorderColor);
    //glMaterialfv(GL_FRONT_AND_BACK, GL_AMBIENT_AND_DIFFUSE, BorderColor);
    A_Line(S,R1,BorderColor,T,0,0,0,0);
    A_Line(A_VectAdd(S,R1),A_VectSub(R2,R1),BorderColor,T,0,0,0,0);
    A_Line(S,R2,BorderColor,T,0,0,0,0);
    A_Sphere(A_VectAdd(S,R1),BorderColor,T);    
    A_Sphere(A_VectAdd(S,R2),BorderColor,T);    
    A_Sphere(S,BorderColor,T);    
    glPopMatrix();  // 1
  }
  
}
// render a line from Start to Desti in Color and Width,
// elongation forwards with lplus and backwards with lminus.
// kplus and kminus gets the line between limit-points
void A_Line(GLfloat* Start,GLfloat* Desti,GLfloat* Color,         
            GLfloat Width, GLfloat lplus=0.f, GLfloat lminus=0.f,
            GLfloat kplus=0.f, GLfloat kminus=0.f) 
{ glPushMatrix();  // 1
    Width/=100.f;
    glTranslatef(Start[0],Start[1],Start[2]); 
    A_Turn(Desti); 
    A_MatColor(Color);
    //glMaterialfv(GL_FRONT_AND_BACK, GL_AMBIENT_AND_DIFFUSE, Color);  // choose color
    if(lminus)
    { glTranslatef(0.0f,0.0f,-lminus);
      gluCylinder(quadric,Width,Width,lminus,32,1); 	
      glTranslatef(0.0f,0.0f,lminus);
    }
    if(kminus)glTranslatef(0.0f,0.0f,kminus);
    // draw cyln with width 
    gluCylinder(quadric,Width,Width,(A_VectLength(Desti)-kminus-kplus),32,1);        
    if(lplus)
    { glTranslatef(0.0f,0.0f,(A_VectLength(Desti)-kminus));
      gluCylinder(quadric,Width,Width,lplus,32,1); 	
      glTranslatef(0.0f,0.0f,-(A_VectLength(Desti)-kminus));
    }
  glPopMatrix();  // 1
}
void A_LineS(float *S,float *D,float *C,float T=.5f,int stip=0)   // small line from S to D in color C and linewidth T
{ glPushMatrix(); // 1
  A_MatColor(C);
  //glMaterialfv(GL_FRONT_AND_BACK, GL_AMBIENT_AND_DIFFUSE, C);
  glLineWidth(T);
  if(stip)
  { glEnable (GL_LINE_STIPPLE);
    glLineStipple( stip, 0x0F0F );  
  }
  glBegin(GL_LINES);
    glVertex3f( S[0], S[1], S[2]);
    glVertex3f( D[0], D[1], D[2]);
  glEnd(); 
  if(stip) glDisable (GL_LINE_STIPPLE);
  glPopMatrix(); // 1
}
void A_Pixel(float* MiddlePt, float* Color, float Size )
{ glPushMatrix();  // 1       
  glPointSize(Size);
  A_MatColor(Color);
  //glMaterialfv(GL_FRONT_AND_BACK, GL_AMBIENT_AND_DIFFUSE, Color);
  glBegin(GL_POINTS);            
    glVertex3f(MiddlePt[0],MiddlePt[1],MiddlePt[2]);
  glEnd();
  glPopMatrix();   // 1      
} 

void A_Sphere(float* MiddlePt, float* Color, float Radius )
{ glPushMatrix();   // 1      
  glTranslatef(MiddlePt[0],MiddlePt[1],MiddlePt[2]); 
  A_Turn(MiddlePt);
  A_MatColor(Color);
  //glMaterialfv(GL_FRONT_AND_BACK, GL_AMBIENT_AND_DIFFUSE, Color);
  glutSolidSphere(Radius/100.f,128,128);
  A_MatColor(Color);
  glPopMatrix();    // 1    
} 
void A_Cube(float* MiddlePt, float* Direction, float* FillColor,float* BorderColor, float Border, float Thickness)  // render Cube
{ glPushMatrix();    // 1     
  glTranslatef(MiddlePt[0],MiddlePt[1],MiddlePt[2]); 
  A_Turn(Direction);
  A_MatColor(BorderColor);
  //glMaterialfv(GL_FRONT_AND_BACK, GL_AMBIENT_AND_DIFFUSE, BorderColor);
  glLineWidth(Thickness);
  if(Border) glutWireCube((GLdouble)Border);
  if(FillColor[3])
  { A_MatColor(FillColor);
    //glMaterialfv(GL_FRONT_AND_BACK, GL_AMBIENT_AND_DIFFUSE, FillColor);
    glutSolidCube((GLdouble)Border);
  }
  glPopMatrix();      // 1
  glFlush();   
} 
void A_Disk(float* MiddlePt, float* Direction, float* Color, float oRadius, float iRadius=0.)
{ glPushMatrix();   // 1      
  glTranslatef(MiddlePt[0],MiddlePt[1],MiddlePt[2]); 
  A_Turn(Direction);
  A_MatColor(Color);
  //glMaterialfv(GL_FRONT_AND_BACK, GL_AMBIENT_AND_DIFFUSE, Color);
  gluDisk(quadric,iRadius,oRadius, 64, 1);
  glPopMatrix();    // 1    
} 
void A_Circle(float* MiddlePt, float* Direction, float* Color, float Radius, float Thickness)
{ glPushMatrix();    // 1     
  glTranslatef(MiddlePt[0],MiddlePt[1],MiddlePt[2]); 
  A_Turn(Direction);
  A_MatColor(Color);
  //glMaterialfv(GL_FRONT_AND_BACK, GL_AMBIENT_AND_DIFFUSE, Color);
  gluDisk(quadric,(Radius-Thickness),Radius, 64, 1);
  glPopMatrix();     // 1    
} 

GLfloat* A_VectProd(GLfloat* A,GLfloat* B)
{ static GLfloat V[3];
  V[0]=A[1]*B[2]-A[2]*B[1]; 
  V[1]=A[2]*B[0]-A[0]*B[2]; 
  V[2]=A[0]*B[1]-A[1]*B[0];
  return V; 
}
void A_PlaneRound(float* S,float* R1,float* R2,float* C)
{ GLfloat T[3],V[3],R[3],E[3],*H,N[3];
  H=A_VectProd(R1,R2); for(int i=0;i<3;i++) N[i]=H[i];                    // N is orthogonal to R1 and to R2 Normale
  A_Disk(S,N,C,100.,0.f);
  //glFlush();
  GLfloat G[3],
  *Res=A_VectAdd(R1,R2);                                                  // Res is the result-vector of R1+R2
  H=A_VectMulv(Res,1/A_VectLength(Res)); for(int i=0;i<3;i++) G[i]=H[i];  // G is the unit-normed Res
  H=A_VectMulv(G,50.f);                  for(int i=0;i<3;i++) E[i]=H[i];  // E is 50 * unit-normed Res
  H=A_VectProd(N,G);                     for(int i=0;i<3;i++) V[i]=H[i];  // V is orthogonal to Res and to N (Normale)
  H=A_VectMulv(V,1/A_VectLength(V));     for(int i=0;i<3;i++) R[i]=H[i];  // R is the unit-normed V
  H=A_VectMulv(R,50.f);                  for(int i=0;i<3;i++) T[i]=H[i];  // T is 50 * unit-normed V 
  glPushMatrix; // 1
   A_MatColor(C);
   //glMaterialfv(GL_FRONT_AND_BACK, GL_AMBIENT_AND_DIFFUSE, C);
   for(float i=-40.;i<40.;i+=2.f)          
   { glBegin(GL_LINES); // grid lines
       glVertex3f( S[0]+E[0]+R[0]*i, S[1]+E[1]+R[1]*i, S[2]+E[2]+R[2]*i);    
       glVertex3f( S[0]-E[0]+R[0]*i, S[1]-E[1]+R[1]*i, S[2]-E[2]+R[2]*i);
       glVertex3f( S[0]+T[0]+G[0]*i, S[1]+T[1]+G[1]*i, S[2]+T[2]+G[2]*i);    
       glVertex3f( S[0]-T[0]+G[0]*i, S[1]-T[1]+G[1]*i, S[2]-T[2]+G[2]*i);
     glEnd();
   }
  glPopMatrix;    
}

void A_VectZero(GLfloat* Desti,GLfloat* Color, GLfloat Width)
{ Width/=100.f;
  glPushMatrix();  // 1  
  A_Turn(Desti); 
  A_MatColor(Color);
  //glMaterialfv(GL_FRONT_AND_BACK, GL_AMBIENT_AND_DIFFUSE, Color);
  gluCylinder(quadric,Width,Width,A_VectLength(Desti)-9*Width,32,1); // render cylinder, length, width, direction	
  glTranslatef(.0f,.0f,A_VectLength(Desti)-9*Width);                 // move in direction
  A_MatColor(Color);
  //glMaterialfv(GL_FRONT_AND_BACK, GL_AMBIENT_AND_DIFFUSE, Color);
  glutSolidCone(3.f*Width,9.f*Width,32,1);                           // render a Cone in direction
  gluDisk(quadric,0.f,3.f*Width, 32, 1);
  glPopMatrix();    // 1
  if(A_HelpLines) // HelpLines
  { glPushMatrix();  // 1
    A_MatColor(Color);
    //glMaterialfv(GL_FRONT_AND_BACK, GL_AMBIENT_AND_DIFFUSE, Color);
    glLineWidth(2);
    glLineStipple(1,0xFF);  
    glEnable(GL_LINE_STIPPLE);
    glBegin(GL_LINE_STRIP);            
      glVertex3f( Desti[0], Desti[1], Desti[2]);
      glVertex3f( 0.f, Desti[1], Desti[2]);
      glVertex3f( 0.f, 0.f, Desti[2]);
      glVertex3f( Desti[0],0.f, Desti[2]);
      glVertex3f( Desti[0], Desti[1], Desti[2]);
      glVertex3f( Desti[0], Desti[1], 0.f);
      glVertex3f( Desti[0], 0.f, 0.f);
      glVertex3f( 0.f, 0.f, 0.f);
      glVertex3f( 0.f,Desti[1], 0.f);
      glVertex3f( Desti[0], Desti[1], 0.f);
    glEnd();
    glBegin(GL_LINES);            
      glVertex3f( Desti[0], 0.f, 0.f);
      glVertex3f( Desti[0], 0.f, Desti[2]);
    glEnd();
    glBegin(GL_LINES);            
      glVertex3f( 0.f, 0.f, Desti[2]);
      glVertex3f( 0.f, 0.f, 0.f);
    glEnd();
    glBegin(GL_LINES);            
      glVertex3f( 0.f, Desti[1], Desti[2]);
      glVertex3f( 0.f, Desti[1],0.f );
    glEnd();
    glDisable(GL_LINE_STIPPLE);
    glPopMatrix();
  }  
}

void A_Vect(GLfloat* Start,GLfloat* Desti,GLfloat* Color, GLfloat Width)
{ glPushMatrix();
    glTranslatef(Start[0],Start[1],Start[2]); 
    A_VectZero(Desti,Color,Width);       // render a vector from zero-point
  glPopMatrix();
}

void A_Cyln(float* Start, float* Desti,float* Color, float Length, float Thick )
{ glPushMatrix();        
  glTranslatef(Start[0],Start[1],Start[2]); 
  A_Turn(Desti);
  A_MatColor(Color);
  //glMaterialfv(GL_FRONT_AND_BACK, GL_AMBIENT_AND_DIFFUSE, Color);
  gluCylinder(quadric,Thick,Thick,Length,32,1); // render a cylinder, length, linewidth, direction
  glPopMatrix();        
} 
void idle(void) 
{ glutPostRedisplay(); }

float A_VectLength(GLfloat* Vect)  // length of 3D-vector Vect
{ return sqrt(Vect[0]*Vect[0]+Vect[1]*Vect[1]+Vect[2]*Vect[2]);
}
void A_SetTop(unsigned ax)
{ A_Top=ax;
}
void A_Turn(GLfloat* v)
{ if(!v[2]) glRotatef(v[0]>0.f?90.f:-90.f,0.f,1.f,0.f);   
  else glRotatef(v[2]>0.f?atan(v[0]/v[2])*180.f/M_PI:(-M_PI+atan(v[0]/v[2]))*180.f/M_PI,0.f,1.f,0.f);
  if(v[2]||v[0]) glRotatef(-atan(v[1]/sqrt(v[2]*v[2]+v[0]*v[0]))*180./M_PI,1.f,0.f,0.f);
  else glRotatef(v[1]>0?-90.f:90.f,1.f,0.f,0.f);
}

void A_TurnAxes(){ A_Turn(A_turn); }

// mouse functions
void A_MouseMotion(int x, int y)
{ float deltaX = x - oldX, deltaY = y - oldY;
  if(A_tc3d)
  { if (motionState == ROTATE) 
    {  A_theta-=deltaY*A_SPEED*.002f; A_phi+=.002f*A_SPEED*deltaX; 
	}
	else /*if (motionState == MOVE)*/ A_distance += A_speedfactor*.5f * deltaY*A_SPEED;
	oldX = x; oldY = y;
	glutPostRedisplay();
  }
  else
  { if (motionState == ROTATE) 
    {  A_sy+=.001*deltaY; A_sx-=.001*deltaX; 
	}
  }	
}
void A_Mouse(int button, int state, int x, int y)
{ oldX = x; oldY = y;
  if (button==GLUT_LEFT_BUTTON)      {if(state == GLUT_DOWN) motionState = ROTATE;}
  else if (button==GLUT_RIGHT_BUTTON){if(state == GLUT_DOWN) motionState = MOVE;}
}
// calculate cartesic coordinates 
float* A_AngToCart(float theta,float psi)
{ static float Kartes[3]; // *Kartes=new float[3];
  Kartes[0] = sin(theta) * cos(psi); 
  Kartes[1] = cos(theta);              // calculate angels A_theta und A_phi
  Kartes[2] = sin(theta) * sin(psi);   // to cartesic coordinates
  return Kartes;
}
// fog switch on
void A_Fog(float* Color,float Intensity=.9f) // Nebel konfigurieren und aktivieren
{ glFogfv(GL_FOG_COLOR,Color);
  glFogi(GL_FOG_MODE,GL_LINEAR);
  glFogf(GL_FOG_START,A_CoordAnz*3);
  glFogf(GL_FOG_END,A_CoordAnz*5);
  glFogf(GL_FOG_DENSITY,Intensity);          
  glHint(GL_FOG_HINT, GL_NICEST);
}
void A_Model(char Th=A_NIGHT )
{ //if(!A_aend) 
  glutSwapBuffers();
  glLoadIdentity();                   
  A_theme=Th;
  // activate anti-aliasing
  if(A_Transp) 
  { glEnable(GL_BLEND);
    glBlendFunc(GL_SRC_ALPHA,GL_ONE_MINUS_SRC_ALPHA);
  }
  else glDisable(GL_BLEND);

  glEnable(GL_LINE_SMOOTH);
  glHint(GL_LINE_SMOOTH_HINT, GL_NICEST);

  float *Kart = A_AngToCart(A_theta,A_phi); // camera-position angel in cartesic form
  gluLookAt(Kart[0]*A_distance+A_sx,Kart[1]*A_distance+A_sy,Kart[2]*A_distance+A_sz,A_sx,A_sy,A_sz,0.f,1.f,0.f);   // 3D-Kameraposition

  float fogcolor_dark[4] = {0.f,0.f,0.0f,1.f};
  float fogcolor_night[4] = {.0f,.0f,.2f,1.f};
  float fogcolor_book[4] = {1.f,1.f,1.f,1.f};
  float fogcolor_sky[4] = {.9f,.9f,1.f,1.f};
  
  float *fogcolor;
  Dunst[3]=1.f;
  A_CoordColor[3]=.9f;
  A_CoordColor1[3]=.9f;
  A_CoordColor2[3]=.9f;
  switch(A_theme)
  { case A_SKY:    glClearColor(.9f,.9f,1.f,1.f);
                   for(int i=0;i<3;i++)
                   { A_CoordColor[i]=0.f;
                     A_CoordColor1[i]=.0f;
                     A_CoordColor2[i]=.6f;
                     Dunst[i]=1.f;
                   }
                   fogcolor=fogcolor_sky;
                   feedcolor=feedcolor_sky;
                   A_CharColor=CharColor_sky;
                   A_CharCoord=CharColor_sky_blue;
                   A_GridColor=A_GridSKY;
                   break;
    case A_BOOK:   glClearColor(1.f,1.f,1.f,1.f);
                   for(int i=0;i<3;i++)
                   { A_CoordColor[i]=0.f;
                     A_CoordColor1[i]=.0f;
                     A_CoordColor2[i]=.6f;
                     Dunst[i]=1.f;
                   }
                   fogcolor=fogcolor_book;
                   feedcolor=feedcolor_book;
                   A_CharColor=CharColor_book;
                   A_CharCoord=CharColor_book_blue;
                   A_GridColor=A_GridBOOK;
                   break;
    
    case A_DARK:   glClearColor(0.f,0.f,0.0f,1.f);
                   for(int i=0;i<3;i++)
                   { A_CoordColor[i]=1.f;
                     A_CoordColor1[i]=1.f;
                     A_CoordColor2[i]=.0f;
                     Dunst[i]=0.f;
                   }
                   A_CoordColor2[2]=.3f;
                   fogcolor=fogcolor_dark;
                   feedcolor=feedcolor_dark;
                   A_CharCoord=CharColor_coord;
                   A_CharColor=CharColor_night;
                   A_GridColor=A_GridDARK;
                   break;
    case A_NIGHT:
    default:       
                   glClearColor(0.f,0.f,0.2f,1.f);
                   for(int i=0;i<3;i++)
                   { A_CoordColor[i]=1.f;
                     A_CoordColor1[i]=1.f;
                     A_CoordColor2[i]=.0f;
                     Dunst[i]=0.f;
                   }
                   A_CoordColor2[1]=.2f;
                   A_CoordColor2[3]=1.f;
                   fogcolor=fogcolor_night;
                   feedcolor=feedcolor_night;
                   A_CharCoord=CharColor_coord;
                   A_CharColor=CharColor_night;
                   A_GridColor=A_GridNIGHT;
                   break;                   
  }  
  if(A_Foggy) { A_Fog(fogcolor);  glEnable(GL_FOG); } // activat Fog
  else glDisable(GL_FOG);	        
  glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT );        
  glLightfv(GL_LIGHT0, GL_POSITION, lightPos0);// light 0 active
  GLfloat  ambient[4] = A_LIGHTGRAY;
  GLfloat specular[4] = A_WHITE;
  GLfloat  diffuse[4] = A_LIGHTGRAY; 
  glLightfv(GL_LIGHT0, GL_AMBIENT, ambient);   // ambiente light
  glLightfv(GL_LIGHT0, GL_SPECULAR, specular); // spectual light
  glLightfv(GL_LIGHT0, GL_DIFFUSE, diffuse);   // diffuse  light
  for(int i=0; i<A_Top; i++) A_Turn(A_turn);
  glPushMatrix();
  glutPostRedisplay();
} 
void A_Basics()                       
{ A_sx = A_sz = A_sy = 0.f;
  A_xPlane = A_yPlane = A_zPlane = false;
  A_theta=A_phi=M_PI / 2.f;
  A_distance=1.f;
  A_Gatt=true; 
  A_Positiv=false;
  A_x=1.f;
  A_Foggy=true;
  //A_tc3d = true;
}


void A_Init(char* titel,bool tc_3d=true, int AxU=6, int AxL=7, int width=0, int height=0)
{ cout << "\nTastenfunktionen von ALGEO\n"
       << "------------------------------------------------------------------------------\n\n"
       << "F1  - Hilfe                          ESC - Exit (Beenden)\n\n"
       << "A/D - drehen nach links/rechts       S/W - drehen nach oben/unten\n"
       << "C   - Koordinaten ein/aus            P   - nur positive Quadranten ein/aus\n"
       << "F   - Nebel ein/aus                  R   - xyz-Koordinatenrotation\n"
       << "G   - A_x um 1 erh”hen               T   - Transparenz ein/aus\n"
       << "H   - Hilfslinien ein/aus            U   - Ursprungsbild rufen\n"
       << "K   - A_x um 1 vermindern            V   - Vollbild ein/aus\n"
       << "L   - Gitter ein/aus                 XYZ - Planes ein/aus\n"
       << "M   - 2D/3D Darstellung wechseln     +/- - vergr”áern/verkleinern\n\n"
       << "0..9 - A_0..A_9 um 1 erh”hen         Shift/0..9 - A_0..A_9 um 1 vermindern\n"	
       << "Pfeiltasten - verschieben nach links/rechts/oben/unten\n\n";
  cout << "Mit gedrckter linker Maustaste erfolgen Drehungen bei Mausbewegungen.\n"
       << "Mit gedrckter rechter Maustaste wird die Distanz der Kamera ver„ndert.\n\n\n"
       << "\t\tViel Spaá wnscht Thomas Cassebaum 2010";       
  if((A_CoordAnz<=0)||(A_CoordAnz>100)) A_CoordAnz=5;
  A_CoordAnz=A_AxUnits=AxU;  // Number of axunits in xyz-direction
  A_AxLine =AxL;             // Linienstärke der Koordinatenachsen
  A_CoordLine=A_AxLine/100.f;
  A_width=width;A_height=height;
  A_Basics();  
  if(!A_width) A_width=glutGet(GLUT_SCREEN_WIDTH)-16;
  if(!A_height) A_height=glutGet(GLUT_SCREEN_HEIGHT)-36;
  glutInitDisplayMode(GLUT_DOUBLE | GLUT_RGB | GLUT_MULTISAMPLE | GLUT_DEPTH | /*GLUT_STENCIL|*/ GLUT_ALPHA);
  glutInitWindowSize(A_width,A_height);    // set window-size (width, height)
  glutCreateWindow(titel);     // create graphics-window with GLUT (titel: "...")
  glutDisplayFunc(display);    // set name of render-function
  glutIdleFunc(display);
  A_tc3d = tc_3d;              // false -> 2D, true -> 3D 
  if(A_height<A_width)A_Fnt=A_height; else A_Fnt=A_width;
  if(A_Fnt<400) A_Fnt = 0;     // font style depends on picture-width
  else A_Fnt = 1;  
  //A_Basics();
  glutMotionFunc(A_MouseMotion);// name mouse-move-functions
  glutMouseFunc(A_Mouse);           
  glutKeyboardFunc(A_Keys);         // name keyboard-functions
  glutSpecialFunc(A_SpecKeys);      // name special-key-function
  glEnable(GL_LIGHTING);            // aktivate light 
  glEnable(GL_LIGHT0);              // light Nr.0 switch on
  
  glClearDepth(1.0f);				// depth buffer setup        
  glEnable(GL_DEPTH_TEST);          // depth test
  glDepthFunc(GL_LEQUAL);			     // The Type Of Depth Testing To Do
  glHint(GL_PERSPECTIVE_CORRECTION_HINT, GL_NICEST); // Really Nice Perspective Calculations
  //BuildFont();
  glViewport(0,0,A_width,A_height); // view window				
  glMatrixMode(GL_PROJECTION);	    // projection mode			
  glLoadIdentity();          // load unit-matrix
  
  // perspective or orthog. view-model
  t3dInit();
  justify(); 
  if(A_tc3d) 
    gluPerspective(45.0f,(GLfloat)A_width/(GLfloat)A_height,0.1f,10.f+A_CoordAnz*4.f);
  else       
  { // glOrtho(left,right,bottom,top,near,far);
    float opti2=1.1f*A_distance*A_CoordAnz+.4f;
    float opti1=opti2/A_height*A_width;
    glOrtho(-opti1+A_ox,opti1+A_ox,-opti2+A_oy+.5f,opti2+A_oy+.5f, .01f, 6.f+A_distance*4.f);
  }
  //glClear(GL_COLOR_BUFFER_BIT);
  glClearColor(1.f,1.f,1.f,1.f);
  glMatrixMode(GL_MODELVIEW);         
  glLoadIdentity();          // load unit-matrix
  if(A_full) glutFullScreen();
  else { glutReshapeWindow(A_width, A_height);
         glutPositionWindow(10, 30); 
       } 
  if(A_tc3d)
  { if(A_Positiv)
    { A_sy+=2.4f;  A_distance+=A_CoordAnz*2.2f;
    }
    else 
    { A_distance += A_CoordAnz*3.4f; 
    }
  }
  glutMainLoop();                  
}
