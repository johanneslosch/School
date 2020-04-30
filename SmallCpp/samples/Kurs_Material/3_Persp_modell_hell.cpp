// Persp_Modell_hell BOOK
#include <iostream.h>
#define A_SPEED .5f                     // Bewegungsgeschwindigkeit der ALGEO-Basisfunktionalität
#include <algeo.h>
void display()							// Renderfunktion 
{ A_Model(A_BOOK);
  A_Coord();
  float zNear=.2f,zFar=.6f,zBack=-.1f,zWidth=8.0f,zHeight=4.5f,zDeep=-10.0f;
  vect ru(zDeep,-zHeight,zWidth),ro(zDeep,zHeight,zWidth),lu(zDeep,-zHeight,-zWidth),lo(zDeep,zHeight,-zWidth),s(0,0,0);
  glPushMatrix();
  TextAus(vect(-5,5,4),"Perspektivisches Modell",vect(SCHWARZ));
  TextAus(vect(-5,4.6,4),"Taste ' 1 ' mehrmals geben.",vect(SCHWARZ));
  TextAus(vect(3,3,4),"1. Der Winkel ' fovy ' (in Grad)",vect(BLAU));
  if(!(A_1%5)) A_1=1;
  if(A_1%5>1) TextAus(vect(3,2.8,4),"2. Aspektratio width / height",vect(ROT));
  if(A_1%5>2) TextAus(vect(3,2.6,4),"3. Entfernung zur clipping plane ' zFar '  ",vect(DUNKELGRUEN));
  if(A_1%5>3) TextAus(vect(3,2.4,4),"4. Entfernung zur clipping plane ' zNear '  ",vect(SCHWARZ));
  glPopMatrix();  
  // StreckeV(vect Start,vect Ziel,vect Farbe,vect Farbe2,float Dicke=2.f,Strichel=0.)  
  StreckeV(s,ro-s,vect(SCHWARZ),1.5);
  StreckeV(s,lu-s,vect(SCHWARZ),1.5);
  if(A_1%5>1)
  { StreckeV(s,lo-s,vect(SCHWARZ),1.5); StreckeV(s,ru-s,vect(SCHWARZ),1.5);
    StreckeV(s,(ro-s)*zBack,vect(SCHWARZ),1.5); StreckeV(s,(lu-s)*zBack,vect(SCHWARZ),1.5);
    StreckeV(s,(lo-s)*zBack,vect(SCHWARZ),1.5); StreckeV(s,(ru-s)*zBack,vect(SCHWARZ),1.5);
    // Parallelogramm::Parallelogramm(vect S, D, D2, CB, CF, float Width=1.f, bool fill=true, border=true,  ad=true)
    Parallelogramm(lu*zBack,(ru-lu)*zBack,(lo-lu)*zBack,vect(DUNKELBLAU),vect(T_GRAU),1.);
    if(A_1%5>2) 
    { Parallelogramm(lu*zFar,(ru-lu)*zFar,(lo-lu)*zFar,vect(ROT),vect(T_GRAU),3.);
      if(A_1%5==3) Ortsvektor(vect(zDeep,0,0)*zFar,vect(ROT),8.f);
    }
    if(A_1%5>3) 
    { Parallelogramm(lu*zNear,(ru-lu)*zNear,(lo-lu)*zNear,vect(DUNKELGRUEN),vect(T_GRAU),2.);   
      if(A_1%5==4) Ortsvektor(vect(zDeep,0,0)*zNear,vect(DUNKELGRUEN),7.f);
    }
  }
}  
void justify()							// Initialisierungsfunktion
{A_sy-=1.0f;A_sx-=2.0f;A_theta-=.1f;A_phi-=.5f; A_distance+=0.f;A_Positiv=true;A_Csyst=false;
}
int main(int argc, char** argv) 		// Hauptfunktion mit Kommandozeilenparametern
{	glutInit(&argc, argv);				// Initialsierung der GLUT-Bibliothek
	A_Init("Perspektivisches Frustum",A_PERSP,5);
	return 0;							// Beenden des C++-Programmes, RC = 0
}