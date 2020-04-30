// Wuerfel Persp Modell NIGHT
#include <iostream.h>
#define A_SPEED .5f                     // Bewegungsgeschwindigkeit der ALGEO-Basisfunktionalität
#include <algeo.h>
void display()							// Renderfunktion 
{ A_Model(A_NIGHT);
  A_Coord();
  //glLoadIdentity();
  float zNear=.2f,zFar=.6f,zBack=-.1f,zWidth=8.0f,zHeight=4.5f,zDeep=-10.0f;
  vect ru(zDeep,-zHeight,zWidth),ro(zDeep,zHeight,zWidth),lu(zDeep,-zHeight,-zWidth),lo(zDeep,zHeight,-zWidth),s(0,0,0);
  glPushMatrix();
  TextAus(vect(-5,5,4),"Perspektivisches Modell",vect(WEISS));
  TextAus(vect(3,3,4),"1. Der Winkel fovy (in Grad)",vect(HELLGELB));
  if(!(A_1%5)) A_1=1;
  if(A_1>1) TextAus(vect(3,2.8,4),"2. Aspektratio width / height",vect(HELLROT));
  if(A_1>2) TextAus(vect(3,2.6,4),"3. Entfernung clipping plane ' zFar '  ",vect(HELLGRUEN));
  if(A_1>3) TextAus(vect(3,2.4,4),"4. Entfernung clipping plane ' zFar '  ",vect(WEISS));
  glPopMatrix();  
  // StreckeV(vect Start,vect Ziel,vect Farbe,vect Farbe2,float Dicke=2.f,Strichel=0.)  
  StreckeV(s,ro-s,vect(WEISS),1.5);
  StreckeV(s,lu-s,vect(WEISS),1.5);
  if(A_1>1)
  { StreckeV(s,lo-s,vect(WEISS),1.5); StreckeV(s,ru-s,vect(WEISS),1.5);
    StreckeV(s,(ro-s)*zBack,vect(WEISS),1.5); StreckeV(s,(lu-s)*zBack,vect(WEISS),1.5);
    StreckeV(s,(lo-s)*zBack,vect(WEISS),1.5); StreckeV(s,(ru-s)*zBack,vect(WEISS),1.5);
      // Parallelogramm::Parallelogramm(vect S, D, D2, CB, CF, float Width=1.f, bool fill=true, border=true,  ad=true)
    Parallelogramm(lu*zBack,(ru-lu)*zBack,(lo-lu)*zBack,vect(HELLGELB),vect(T_WEISS),1.);
    if(A_1%5>2) 
    { Parallelogramm(lu*zFar,(ru-lu)*zFar,(lo-lu)*zFar,vect(HELLROT),vect(T_WEISS),3.);
      if(A_1%5==3) Ortsvektor(vect(zDeep,0,0)*zFar,vect(HELLROT),8.f);
    }
    if(A_1%5>3) 
    { Parallelogramm(lu*zNear,(ru-lu)*zNear,(lo-lu)*zNear,vect(HELLGRUEN),vect(T_WEISS),2.);   
      if(A_1%5==4) Ortsvektor(vect(zDeep,0,0)*zNear,vect(HELLGRUEN),7.f);
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