// Thomas Cassebaum, 18.9.2008, all rights reserved
// Header der Vectorklasse

void display(void);	                                                   
#include <Gl/glut.h>
#include <algeoproc.h>
/* 
vect a(float x,y,z,a);  4D-vector
   attributes:   SN[4];          start-vector
   methodes:     x(),y(),z(),a() gets SN[0]...SN[4]
                 length(),       gets length of SN
   operators:    +               gets vector sum
                 -               gets vector difference
                 *               gets vector product
   constructors: (),(float x,y,z,a),(float*)
*/
class vect
{ public: float SN[4];
    vect();                       // Konstruktor
    vect(float,float,float,float);// Konstruktor
    vect(float*);                 // Konstruktor
    //void VectStr(void);
    float length(void);
    vect operator+(vect &);    	  // addition operator overload 
    vect operator-(vect &);    	  // subtraction operator overload
    float operator*(vect &);   	  // scalar product operator overload
    vect operator%(vect &);    	  // vector produkt operator overload
    vect operator*(float );    	  // constant multiplication operator overload
    vect operator/(float );    	  // constant divisionv overload
    bool operator!=(const vect &);// get true if equal  else false
    bool operator==(const vect &);// get false if equal else true
    friend ostream& operator<<(ostream &os, const vect &v); // left-shift of the vector-string
    float x(){return SN[0];}
    float y(){return SN[1];}
    float z(){return SN[2];}
    float a(){return SN[3];}
};
ostream& operator<<(ostream &os, const vect &v) // left-shift of the vector-string
{ os << "(" << v.SN[0] << "|" << v.SN[1] << "|" << v.SN[2] << "|" << v.SN[3] << ")";
  return os;
}
bool vect::operator!=(const vect &v)
{ for(int i=0;i<4;i++) 
    if(SN[i]!=v.SN[i]) return true;
  return false;
}
bool vect::operator==(const vect &v)
{ for(int i=0;i<4;i++) 
    if(SN[i]!=v.SN[i]) return false;
  return true;
}
/* 
C_Point(vect SN,CN,float W); Pixel with coordinates, color and width
   attributes:   CN[4];        color-vector
   methodes:     draw()        object drawing
   constructors: (),
                 (bool),
                 (float *SN,*CN,W, bool ad),(float*)
*/
class C_Point : public vect
{ public: C_Point(vect,vect,float,bool);
          C_Point(bool);
          C_Point();
          void draw();
          float CN[4],W;
};
/* 
C_Vect0(vect SN,CN,float W);   position vector with coordinates, color and width
                               draws the vector while object-instantiation
   methodes:     draw()        object drawing
   constructors: (),
                 (bool),
                 (vect SN,CN,float W, bool ad)
                 (C_Point P)
*/
class C_Vect0 : public C_Point
{ public: C_Vect0(vect,vect,float,bool);
          C_Vect0(vect,vect);
          C_Vect0(C_Point);
          C_Vect0(vect);
          C_Vect0(bool);
          C_Vect0();
          void draw();
};
/*
C_Vector(vect SN,DN,CN,float W);  vector with coordinates of start and direction
                                  , color and width
                                  draws the vector while object-instantiation
   methodes:     draw()           object drawing
   constructors: (),
                 (bool),
                 (vect SN,DN,CN,float W, bool ad)
                 (C_Point P)
*/
class C_Vector : public C_Vect0
{ public: C_Vector(vect,vect,vect,float,bool);
          C_Vector(bool);
          C_Vector();
          void draw();
          GLfloat DN[4];
};
/*
C_Line(vect SN,DN,CN,float W,LP,LM,KP,KM);  
  Line with coordinates of start and direction, color and width 
  solution with long cylinders
draws the vector while object-instantiation with rules
   attributes:   LP,LM,KP,KM      outer(L)/inner(K)-length plus(P)/minus(M)-direction
   methodes:     draw()           object drawing
   constructors: (),
                 (bool),
                 (vect SN,DN,CN,float W,LP,LM,KP,KM,bool ad)
*/
class C_Line : public C_Vector
{ public: C_Line(vect,vect,vect,float,float,float,float,float,bool);
          C_Line(bool);
          C_Line();
          void draw();
          GLfloat LP,LM,KP,KM;
};
/*
C_Disk(vect SN(MiddlePnt),DN(NormalDirection),CN(FillColor),
       float LP(outerRadius),LM(innerRadius));  
  Line with coordinates of start and direction, color and width
  solution with Vertex-Lines
  methodes:     draw()    object drawing
  constructors: (),
                (bool),
                (vect SN,DN,CN,float LP,LM)
*/
class C_Disk : public C_Line
{ public: C_Disk(vect,vect,vect,float,float,bool);
          C_Disk(bool);
          C_Disk();
          void draw();
};
/*
C_LineS(vect SN,DN,CN,float W,LP,LM,KP,KM);  
  Line with coordinates of start and direction, color and width
  solution with Vertex-Lines
   attribut:     ST        stippled Line (values=1,2,3,...length of stipples)
   methodes:     draw()    object drawing
   constructors: (),
                 (bool),
                 (vect SN,DN,CN,float W,ST,bool ad)
*/
class C_LineS : public C_Vector
{ public: C_LineS(vect,vect,vect,float,int,bool);
          C_LineS(bool);
          C_LineS();
          void draw();
          int ST;
};
/*
C_Rhombus(vect SN,DN,DN2,CB,CF,float W,bool border,fill,ad);  
   Rhombus with start, two directions, Border-/Fillcolor and width of Borderline 
   draws the Rhombus while object-instantiation with rules
   attributes:   DN2   second direction vector
                 CN2   second color (CB: border color)
   methodes:     draw()           object drawing
   constructors: (),
                 (bool),
                 (vect SN,DN,DN2,CB,CF,float W,bool border,fill,ad)
*/
class C_Rhombus : public C_Vector
{ public: C_Rhombus(vect,vect,vect,vect,vect,float,bool,bool,bool);
          C_Rhombus();
          void draw(bool,bool);
          GLfloat DN2[3],CN2[4];
};
/*
C_Triangle(vect SN,DN,DN2,CB,CF,float W);  
   Triangle with start, two directions, Border-/Fillcolor and width of Borderline 
   draws the Triangle while object-instantiation with rules
   attributes:   DN2   second direction vector
                 CN2   second color (CB: border color)
   methodes:     draw()           object drawing
   constructors: (),
                 (bool),
                 (vect SN,DN,DN2,CB,CF,float W,bool ad)
*/
class C_Triangle : public C_Vector
{ public: C_Triangle(vect,vect,vect,vect,vect,float,bool,bool,bool);
          C_Triangle();
          void draw(bool,bool);
          GLfloat DN2[3],CN2[4];
};

// methodes of the classes

/* 
vect a(float x,y,z,a);  4D-vector
   attributes:   SN[4];          start-vector
   methodes:     x(),y(),z(),a() gets SN[0]...SN[4]
                 length(),       gets length of SN
   operators:    +               gets vector sum
                 -               gets vector difference
                 *               gets vector product
   constructors: (),(float x,y,z,a),(float*)
*/
vect::vect()   // Konstruktor
{ SN[0]=SN[1]=SN[2]=SN[3]=0.f;
}
vect::vect(float ex,float ey=0.f,float ez=0.f,float ea=0.f)   // Konstruktor
{ SN[0]=ex;SN[1]=ey;SN[2]=ez;SN[3]=ea;
}
vect::vect(float *v)   // Konstruktor
{ for(int i=0;i<4;i++) SN[i]=v[i];
}
float vect::length(void)
{ return sqrt(SN[0]*SN[0]+SN[1]*SN[1]+SN[2]*SN[2]);
}
float vect::operator*(vect &v)
{ return sqrt(SN[0]*v.x()+SN[1]*v.y()+SN[2]*v.z()+SN[3]*v.a());
}
vect vect::operator*(float c)
{ vect nv;
  for(int i=0;i<4;i++) nv.SN[i]=SN[i]*c;
  return nv;
}
vect vect::operator/(float c)
{ vect nv;
  for(int i=0;i<4;i++) nv.SN[i]=SN[i]/c;
  return nv;
}
vect vect::operator%(vect &v)
{ vect nv;
  nv.SN[0]= SN[1]*v.z()-SN[2]*v.y();
  nv.SN[1]=-SN[0]*v.z()+SN[2]*v.x();
  nv.SN[2]= SN[0]*v.y()-SN[1]*v.x();
  return nv;
}
vect vect::operator+(vect &v)
{ vect nv;
  for(int i=0;i<4;i++) nv.SN[i]=SN[i]+v.SN[i]; 
  return nv;
}
vect vect::operator-(vect &v)
{ vect nv;
  for(int i=0;i<4;i++) nv.SN[i]=SN[i]-v.SN[i]; 
  return nv;
}

/* 
C_Point(vect DN,CN,float W);   Punkt mit kartes. und Farbkoordinaten und Breite eines Punktes
   attributes:   CN[4];        color-vector
   methodes:     draw()        object drawing
   constructors: (),
                 (bool ad),    if(ad==true) drawing
                 (float *SN,*CN,W,bool ad)
*/
C_Point::C_Point()
{ SN[0]=1.f;SN[1]=1.f;SN[2]=1.f;SN[3]=0.f; 
  CN[0]=1.f;CN[1]=1.f;CN[2]=1.f;CN[3]=1.f; 
  W=3.f;
}
C_Point::C_Point(bool ad)
{ SN[0]=1.f;SN[1]=1.f;SN[2]=1.f;SN[3]=0.f; 
  CN[0]=1.f;CN[1]=1.f;CN[2]=1.f;CN[3]=1.f; 
  W=3.f;
  if(ad) draw();
}
C_Point::C_Point(vect Direction,vect Color,float Width=5.f,bool ad=true)
{ for(int i=0;i<4;i++)SN[i]=Direction.SN[i];
  for(int i=0;i<4;i++)CN[i]=Color.SN[i];
  W=Width;
  if(ad) draw();
}
void C_Point::draw()
{ A_Pixel(SN,CN,W);
}
/* 
C_Vect0(vect SN,CN,float W);   position vector with coordinates, color and width
                               draws the vector while object-instantiation
   methodes:     draw()        object drawing
   constructors: (),
                 (bool ad),                      ad  ==true -> rendering
                 (vect SN,CN,float W, bool ad)   CN: color-vector, W:width
                 (vect SN)                       SN: direction-vector
                 (C_Point P)                     P:  P.SN-position,P.CN-color,P.W-width
*/
void C_Vect0::draw()
{ A_VectZero(SN,CN,W);
}
C_Vect0::C_Vect0()
{ SN[0]=1.f;SN[1]=1.f;SN[2]=1.f;SN[3]=0.f; 
  CN[0]=0.5f;CN[1]=0.5f;CN[2]=0.5f;CN[3]=1.f; 
  W=5.f;
}
C_Vect0::C_Vect0(bool ad)
{ SN[0]=1.f;SN[1]=1.f;SN[2]=1.f;SN[3]=0.f; 
  CN[0]=0.5f;CN[1]=0.5f;CN[2]=0.5f;CN[3]=1.f; 
  W=5.f;
  if(ad) A_VectZero(SN,CN,W);
}
C_Vect0::C_Vect0(vect Direction,vect Color,float Width=5.f,bool ad=true)
{ for(int i=0;i<3;i++) SN[i]=Direction.SN[i]; SN[3]=0.f;
  for(int i=0;i<4;i++) CN[i]=Color.SN[i];  
  W=Width;
  if(ad) A_VectZero(SN,CN,W);
}
C_Vect0::C_Vect0(vect Direction)
{ for(int i=0;i<3;i++)SN[i]=Direction.SN[i]; SN[3]=0.f;
  CN[0]=0.5f;CN[1]=0.5f;CN[2]=0.5f;CN[3]=1.f;
  W=5.f; 
  A_VectZero(SN,CN,5.f);
}
C_Vect0::C_Vect0(C_Point P)
{ for(int i=1;i<4;i++)SN[i]=P.SN[i];
  for(int i=1;i<4;i++)CN[i]=P.CN[i];
  W=P.W;
  A_VectZero(SN,CN,W);
}

/*
C_Vector(vect SN,DN,CN,float W);  vector with coordinates of start and direction
                                  , color and width
                                  draws the vector while object-instantiation
   methodes:     draw()           object drawing
   constructors: (),
                 (bool ad),       (ad==true) -> rendering
                 (vect SN,DN,CN,float W, bool ad) SN:position, DN:direction, W:width
                 (C_Point P)      P: P.SN-position,P.CN-color,P.W-width
*/
C_Vector::C_Vector()
{ SN[0]=0.f;SN[1]=0.f;SN[2]=0.f;SN[3]=0.f;
  DN[0]=1.f;DN[1]=1.f;DN[2]=1.f;DN[3]=0.f; 
  CN[0]=0.5f;CN[1]=0.5f;CN[2]=0.5f;CN[3]=1.f; 
}
C_Vector::C_Vector(bool ad)
{ SN[0]=0.f;SN[1]=0.f;SN[2]=0.f;SN[3]=0.f;
  DN[0]=1.f;DN[1]=1.f;DN[2]=1.f;DN[3]=0.f; 
  CN[0]=0.5f;CN[1]=0.5f;CN[2]=0.5f;CN[3]=1.f; 
  if(ad) A_Vect(SN,DN,CN,5.f);
}
C_Vector::C_Vector(vect Start,vect Direction,vect Color,float Width=2.f,bool ad=true)
{ for(int i=0;i<3;i++)SN[i]=Start.SN[i]; SN[3]=0.f; 
  for(int i=0;i<3;i++)DN[i]=Direction.SN[i]; DN[3]=0.f;
  for(int i=0;i<4;i++)CN[i]=Color.SN[i];  
  W=Width; 
  if(ad) A_Vect(SN,DN,CN,W);
}
void C_Vector::draw()
{ A_Vect(SN,DN,CN,W);
}
/*
C_Disk(vect SN(MiddlePnt),DN(NormalDirection),CN(FillColor),
       float LP(outerRadius),LM(innerRadius));  
  Line with coordinates of start and direction, color and width
  solution with Vertex-Lines
  methodes:     draw()    object drawing
  constructors: (),
                (bool),
                (vect SN,DN,CN,float LP,LM)
*/
void C_Disk::draw()
{ A_Disk(SN,DN,CN,LP=10.f,LM=0.f);
}
C_Disk::C_Disk()
{ SN[0]=0.f;SN[1]=0.f;SN[2]=0.f;SN[3]=0.f;
  DN[0]=1.f;DN[1]=1.f;DN[2]=1.f;DN[3]=0.f; 
  CN[0]=0.5f;CN[1]=0.5f;CN[2]=0.5f;CN[3]=1.f; 
}
C_Disk::C_Disk(bool ad)
{ SN[0]=0.f;SN[1]=0.f;SN[2]=0.f;SN[3]=0.f;
  DN[0]=1.f;DN[1]=1.f;DN[2]=1.f;DN[3]=0.f; 
  CN[0]=0.5f;CN[1]=0.5f;CN[2]=0.5f;CN[3]=1.f; 
  if(ad) A_Disk(SN,DN,CN,5.f);
}
C_Disk::C_Disk(vect MiddlePt,vect Direction,vect Color,
               float oRadius=0.f, float iRadius=0.f, bool ad=true)
{ for(int i=0;i<3;i++)SN[i]=MiddlePt.SN[i]; SN[3]=0.f; 
  for(int i=0;i<3;i++)DN[i]=Direction.SN[i]; DN[3]=0.f;
  for(int i=0;i<4;i++)CN[i]=Color.SN[i];  
  LP=oRadius;LM=iRadius; 
  if(ad) A_Disk(SN,DN,CN,LP,LM);
}

/*
C_Line(vect SN,DN,CN,float W,LP,LM,KP,KM);  
vector with coordinates of start and direction, color and width
draws the vector while object-instantiation
   attributes:
   methodes:     draw()           object drawing
   constructors: (),
                 (bool),                           (ad==true) -> rendering
                 (vect SN,DN,CN,float W, bool ad)  SN:position, DN:direction, W:width
                 (C_Point P)                       P:  P.SN-position,P.CN-color,P.W-width
*/
void C_Line::draw()
{ A_Line(SN,DN,CN,W,LP,LM,KP,KM);
}
C_Line::C_Line()
{ SN[0]=0.f;SN[1]=0.f;SN[2]=0.f;SN[3]=0.f;
  DN[0]=1.f;DN[1]=1.f;DN[2]=1.f;DN[3]=0.f; 
  CN[0]=0.5f;CN[1]=0.5f;CN[2]=0.5f;CN[3]=1.f; 
}
C_Line::C_Line(bool ad)
{ SN[0]=0.f;SN[1]=0.f;SN[2]=0.f;SN[3]=0.f;
  DN[0]=1.f;DN[1]=1.f;DN[2]=1.f;DN[3]=0.f; 
  CN[0]=0.5f;CN[1]=0.5f;CN[2]=0.5f;CN[3]=1.f; 
  if(ad) A_Line(SN,DN,CN,5.f);
}
C_Line::C_Line(vect Start,vect Direction,vect Color,float Width=2.f,
               float LP1=0.f,float LM1=0.f,float KP1=0.f,float KM1=0.f,bool ad=true)
{ for(int i=0;i<3;i++)SN[i]=Start.SN[i]; SN[3]=0.f; 
  for(int i=0;i<3;i++)DN[i]=Direction.SN[i]; DN[3]=0.f;
  for(int i=0;i<4;i++)CN[i]=Color.SN[i];  
  W=Width;LP=LP1;LM=LM1;KP=KP1;KM=KM1; 
  if(ad) A_Line(SN,DN,CN,W,LP,LM,KP,KM);
}
/*
C_LineS(vect SN,DN,CN,float W,LP,LM,KP,KM);  
  vector with coordinates of start and direction, color and width
  solution with Vertex-Lines
   attribute:    STIP      stippled Line (values=1,2,3,...length of stipples)
   methodes:     draw()           object drawing
   constructors: (),
                 (bool),
                 (vect SN,DN,CN,float W,LP,LM,KP,KM,bool ad)
*/
void C_LineS::draw()
{ A_LineS(SN,DN,CN,W,ST);
}
C_LineS::C_LineS()
{ SN[0]=0.f;SN[1]=0.f;SN[2]=0.f;SN[3]=0.f;
  DN[0]=1.f;DN[1]=1.f;DN[2]=1.f;DN[3]=0.f; 
  CN[0]=0.5f;CN[1]=0.5f;CN[2]=0.5f;CN[3]=1.f; 
}
C_LineS::C_LineS(bool ad)
{ SN[0]=0.f;SN[1]=0.f;SN[2]=0.f;SN[3]=0.f;
  DN[0]=1.f;DN[1]=1.f;DN[2]=1.f;DN[3]=0.f; 
  CN[0]=0.5f;CN[1]=0.5f;CN[2]=0.5f;CN[3]=1.f; 
  if(ad) 
  { A_LineS(SN,DN,CN,5.f);
  }
}
C_LineS::C_LineS(vect Start,vect Direction,vect Color,float Width=1.f,int Stip=0.f,bool ad=true)
{ for(int i=0;i<3;i++)SN[i]=Start.SN[i]; SN[3]=0.f; 
  for(int i=0;i<3;i++)DN[i]=Direction.SN[i]; DN[3]=0.f;
  for(int i=0;i<4;i++)CN[i]=Color.SN[i];  
  W=Width; ST=Stip; 
  if(ad) 
  { A_LineS(SN,DN,CN,W,ST);
  }
}

/*
C_Rectangle(vect SN,DN,DN2,CB,CF,float W,bool border=true,fill=true,ad=true);  
   Rectangle with start, two directions, Border-/Fillcolor and width of Borderline 
   draws the Rectangle while object-instantiation with rules
   attributes:   DN2   second direction vector
                 CN2   second color (CB: border color)
   methodes:     draw()           object drawing
   constructors: (),
                 (bool),
                 (vect SN,DN,DN2,CB,CF,float W,bool border, bool fill, bool ad)
*/
C_Rhombus::C_Rhombus(vect S,vect D,vect D2,
             vect CB, vect CF, float Width=1.f, 
             bool fill=true,bool border=true, bool ad=true)
{ for(int i=0;i<3;i++)
  { SN[i]=S.SN[i]; DN[i]=D.SN[i]; DN2[i]=D2.SN[i]; }
  for(int i=0;i<4;i++)
  { CN[i]=CF.SN[i]; CN2[i]=CB.SN[i]; } 
  W=Width;
  if(ad) draw(fill,border);
} 
C_Rhombus::C_Rhombus()
{}
void C_Rhombus::draw(bool fill,bool border)
{ A_Rhombus(SN,DN,DN2,CN2,CN,W,fill,border);
}
/*
C_Triangle(vect SN,DN,DN2,CB,CF,float W);  
   Triangle with start, two directions, Border-/Fillcolor and width of Borderline 
   draws the Triangle while object-instantiation with rules
   methodes:     draw()           object drawing
   constructors: (),
                 (bool),
                 (vect SN,DN,DN2,CB,CF,float W,bool ad)
*/
C_Triangle::C_Triangle(vect S,vect D,vect D2,
             vect CB, vect CF, float Width=1.f,
             bool fill=true,bool border=true,bool ad=true)
{ for(int i=0;i<3;i++)
  { SN[i]=S.SN[i]; DN[i]=D.SN[i]; DN2[i]=D2.SN[i]; }
  for(int i=0;i<4;i++)
  { CN[i]=CF.SN[i]; CN2[i]=CB.SN[i]; } 
  W=Width;
  if(ad) draw(fill,border);
} 
C_Triangle::C_Triangle()
{}
void C_Triangle::draw(bool fill,bool border)
{ A_Triangle(SN,DN,DN2,CN2,CN,W,fill,border);
}




#define C_ZERO          vect( 0.f, 0.f, 0.f)
#define C_UNIT_X        vect( 1.f, 0.f, 0.f)
#define C_UNIT_Y        vect( 0.f, 1.f, 0.f)
#define C_UNIT_Z        vect( 0.f, 0.f, 1.f)
#define C_UNIT_XY       vect( 1.f, 1.f, 0.f)
#define C_UNIT_XZ       vect( 1.f, 0.f, 1.f)
#define C_UNIT_YZ       vect( 0.f, 1.f, 1.f)
#define C_UNIT_XYZ      vect( 1.f, 1.f, 1.f)
#define C_UNIT_X_M      vect(-1.f, 0.f, 0.f)
#define C_UNIT_Y_M      vect( 0.f,-1.f, 0.f)
#define C_UNIT_Z_M      vect( 0.f, 0.f,-1.f)
#define C_UNIT_XY_M     vect(-1.f,-1.f, 0.f)
#define C_UNIT_XZ_M     vect(-1.f, 0.f,-1.f)
#define C_UNIT_YZ_M     vect( 0.f,-1.f,-1.f)
#define C_UNIT_XYZ_M    vect(-1.f,-1.f,-1.f)

#define C_WHITE         vect(1.f, 1.f, 1.f, 1.f)
#define C_BLUE          vect(0.f, 0.f, 1.f, 1.f)
#define C_RED           vect(1.f, 0.f, 0.f, 1.f)
#define C_GREEN         vect(0.f, 1.f, 0.f, 1.f)
#define C_YELLOW        vect(1.f, 1.f, 0.f, 1.f)
#define C_CYAN          vect(0.f, 1.f, 1.f, 1.f)
#define C_MAGENTA       vect(1.f, 0.f, 1.f, 1.f)
#define C_BLACK         vect(0.f, 0.f, 0.f, 1.f)
#define C_GRAY          vect(.5f, .5f, .5f, 1.f)
#define C_LIGHTGRAY     vect(.6f, .6f, .6f, 1.f)
#define C_LIGHTBLUE     vect(.3f, .3f, 1.f, 1.f)
#define C_LIGHTRED      vect(1.f, .3f, .3f, 1.f)
#define C_LIGHTGREEN    vect(.3f, 1.0f,.3f, 1.f)
#define C_LIGHTYELLOW   vect(1.f, 1.f, .3f, 1.f)
#define C_LIGHTCYAN     vect(.3f, 1.f, 1.f, 1.f)
#define C_LIGHTMAGENTA  vect(1.f, .3f, 1.f, 1.f)
#define C_DARKGRAY      vect(.3f, .3f, .3f, 1.f)
#define C_DARKBLUE      vect(0.f, 0.f, .5f, 1.f)
#define C_DARKRED       vect(.5f, 0.f, 0.f, 1.f)
#define C_DARKGREEN     vect(0.f, .5f, 0.f, 1.f)
#define C_DARKYELLOW    vect(.5f, .5f, 0.f, 1.f)
#define C_DARKCYAN      vect(0.f, .5f, .5f, 1.f)
#define C_DARKMAGENTA   vect(.5f, 0.f, .5f, 1.f)

#define C_TRANSPARENT   vect(0.f, 0.f, 0.f, .0f)
#define C_T_GLASS       vect(1.f, 1.f, 1.f, .33f)
#define C_T_WHITE       vect(1.f, 1.f, 1.f, .33f)
#define C_T_BLUE        vect(0.f, 0.f, 1.f, .33f)
#define C_T_RED         vect(1.f, 0.f, 0.f, .33f)
#define C_T_GREEN       vect(0.f, 1.f, 0.f, .33f)
#define C_T_YELLOW      vect(1.f, 1.f, 0.f, .33f)
#define C_T_CYAN        vect(0.f, 1.f, 1.f, .33f)
#define C_T_MAGENTA     vect(1.f, 0.f, 1.f, .33f)
#define C_T_BLACK       vect(0.f, 0.f, 0.f, .33f)
#define C_T_GRAY        vect(.5f, .5f, .5f, .33f)
#define C_T_LIGHTGRAY     vect(.6f, .6f, .6f, .5f)
#define C_T_LIGHTBLUE     vect(.3f, .3f, 1.f, .5f)
#define C_T_LIGHTRED      vect(1.f, .3f, .3f, .5f)
#define C_T_LIGHTGREEN    vect(.3f, 1.0f,.3f, .5f)
#define C_T_LIGHTYELLOW   vect(1.f, 1.f, .3f, .5f)
#define C_T_LIGHTCYAN     vect(.3f, 1.f, 1.f, .5f)
#define C_T_LIGHTMAGENTA  vect(1.f, .3f, 1.f, .5f)
#define C_T_DARKGRAY      vect(.3f, .3f, .3f, .33f)
#define C_T_DARKBLUE      vect(0.f, 0.f, .5f, .33f)
#define C_T_DARKRED       vect(.5f, 0.f, 0.f, .33f)
#define C_T_DARKGREEN     vect(0.f, .5f, 0.f, .33f)
#define C_T_DARKYELLOW    vect(.5f, .5f, 0.f, .33f)
#define C_T_DARKCYAN      vect(0.f, .5f, .5f, .33f)
#define C_T_DARKMAGENTA   vect(.5f, 0.f, .5f, .33f)



/*
void vect::VectStr(void)
{ cout<<"(" << x << ","<< y << ","<< z << ","<< a << ")";
}
*/


