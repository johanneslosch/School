// Thomas Cassebaum, 26.4.2012, all rights reserved
// Header der Algeo-Klassen

void display(void);	                                                   
#include <GL/glut.h>
#include <algeoproc.h>
/* vect a(float x,y,z,a);  4D-Vektor
   
   Attribute:    SN[4];          Attribute der Vektorkomponenten
   Methoden:     x(),y(),z(),a() liefert SN[0]...SN[4]
                 vectstr(n)      liefert String mit den Vektorkomponenten z.B.: "(.01|-11.2|3.7|0.5)"
                 length(),       liefert die Vektorlänge
   Operatoren:   +, -, *, %, /, !=, ==, <<        
   Konstruktoren:(),(float x,y,z,a),(float*)
*/
class vect                        // Vektorklasse
{ public: float SN[4];			  // 4 float Attribute
    vect();                       // Konstruktor parameterlos
    vect(float,float,float,float);// Konstruktor Parameter: 4 float-Werte, Standardswerte : x:ohne y:0 z:0 a:1 
    vect(float*);                 // Konstruktor Parameter: Array von bis zu 4 float-Werten
    char* vectstr(int n);         // liefert Text zum Vektor   n: Dimension (Standard:3) z.B. "(1.7|-4|9e-3)" 
    float* GLvect();              // liefert ein float-Array mit den xyza-Werten
    float length(void);			  // liefert die Länge des Vektors
    vect operator+(vect);      	  // Addition + Operatorübeladung 
    vect operator+(void);		  // Vorzeichen + Operatorübeladung
    vect operator-(vect);     	  // Subtraktion - Operatorübeladung
    vect operator-(void);		  // Vorzeichen - Operatorübeladung
    float operator*(vect);   	  // Skalarprodukt * Operatorübeladung
    vect operator%(vect);    	  // Vektorprodukt % Operatorübeladung
    vect operator*(float );    	  // Skalarmultiplikation * Operatorübeladung
    vect operator/(float );    	  // Skalardivision / Operatorübeladung
    bool operator!=(const vect &);// liefert true bei ungleich, sonst false
    bool operator==(const vect &);// liefert true bei gleich, sonst false
    operator=(const vect &);      // füllt den Objektvektor SN mit den Werten des Parameters
    operator=(const float*);      // füllt den Objektvektor SN mit den ersten 4 Arrayelementen des Parameterarrays
    friend ostream& operator<<(ostream &os, const vect &v); // Leftshift << Operatorüberladung des Vektorstrings für cout
    float x(){return SN[0];}	  // liefert den x-Parameter
    float y(){return SN[1];}	  // liefert den y-Parameter
    float z(){return SN[2];}	  // liefert den z-Parameter
    float a(){return SN[3];}	  // liefert den alpha-Parameter (Transparenz, 0...1, 0:unsichtbar 1:undurchsichtig
};
/* 
Punkt(vect SN,CN,float W,bool ad); Punktkreuz mit SN:Ortsvektor, CN:Color und W:Linienstärke des Kreuzes
                                   Zeichnet ein Punktkreuz bei der Objektbildung automatisch, wenn Parameter ad==true (Standard).
  Attribute:     CN[4];            Colorvektor
  Methoden:      zeichne()         Objekt zeichnen
  Konstruktoren: (),
                 (bool),
                 (float *SN,*CN,W, bool ad),(float*)
*/
class Punkt : public vect
{ public: Punkt(vect,vect,float,bool);
          Punkt(bool);
          Punkt();
          void zeichne();
          float CN[4],W;
};
/* 
Ortsvektor(vect SN,CN,float W,bool ad);   Ortsvektor SN:Ortsvektor, CN:Color und W:Linienstärke des 3D-Vektors
                                  Zeichnet den 3D-Vektor bei der Objektbildung automatisch, wenn Parameter ad==true (Standard).
  Methoden:      zeichne()        Objekt zeichnen
  Konstruktoren: (),
                 (bool),
                 (vect SN,CN,float W, bool ad)
                 (Punkt P)
*/
class Ortsvektor : public Punkt
{ public: Ortsvektor(vect,vect,float,bool);
          Ortsvektor(vect,vect);
          Ortsvektor(Punkt);
          Ortsvektor(vect);
          Ortsvektor(bool);
          Ortsvektor();
          void zeichne();
};
/* 
Kugel(vect SN,CN,float R,bool ad); SN:Mittelpunkt, CN:Color und W:Radius der Kugel
                                   Zeichnet die Kugel bei der Objektbildung automatisch, wenn Parameter ad==true (Standard).
  Methoden:      zeichne()         Objekt zeichnen
  Konstruktoren: (),
                 (bool),
                 (vect),
                 (vect SN,CN,float W, bool ad),
                 (Punkt P)
*/
class Kugel : public Punkt
{ public: Kugel(vect,vect,float,bool);
          Kugel(vect,vect);
          Kugel(Punkt);
          Kugel(vect);
          Kugel(bool);
          Kugel();
          void zeichne();
};

class TextAus : public Punkt
{ public: TextAus(vect,char*,vect,bool);
          void zeichne();
          char Txt[256];    // 4 vector-elements
};

/*
Vektor(vect SN,DN,CN,float W,bool ad); Vektor SN:Ortsvektor Startpunkt, DN: Richtungsvektor, CN:Color, 
                                              W:Linienstärke des 3D-Vektors 
                                       Zeichnet einen 3D-Vektor bei der Objektbildung automatisch, wenn Parameter ad==true (Standard).
   methodes:     zeichne()             Objekt zeichnen
   constructors: (),
                 (bool),
                 (vect SN,DN,CN,float W, bool ad)
                 (Punkt P)
*/
class Vektor : public Ortsvektor
{ public: Vektor(vect,vect,vect,float,bool);
          Vektor(bool);
          Vektor();
          void zeichne();
          GLfloat DN[4];    // 4 vector-elements
};
/*
Strecke(vect SN,DN,CN,float W,LP,LM,KP,KM,bool ad);  
  3D-Strecke, Strahl oder Gerade mit SN:Ortsvektor Startpunkt, DN:Richtungsvektor, CN:Color, W: Dicke der Linie,
                                     LP:Verlängerung der Linie in plus-Richtung, LM:dito in minus.Richtung
                                     KP:Lücke vor, KM:Lücke nach dem Richtungsvektor  
                                     Zeichnet einen 3D-Zylinder bei der Objektbildung automatisch, wenn Parameter ad==true (Standard).
   methodes:     zeichne()           Objekt zeichnen
   constructors: (),
                 (bool),
                 (vect SN,DN,CN,float W,LP,LM,KP,KM,bool ad)
*/
class Strecke : public Vektor
{ public: Strecke(vect,vect,vect,float,bool);
          Strecke(bool);
          Strecke();
          void zeichne();
          GLfloat LP,LM,KP,KM;
};
/*
Gerade(vect SN,DN,CN,float W,bool ad);  
  3D-Strecke, Strahl oder Gerade mit SN:Ortsvektor Startpunkt, DN:Richtungsvektor, CN:Color, W: Dicke der Linie,
                                     LP:Verlängerung der Linie in plus-Richtung, LM:dito in minus.Richtung
                                     KP:Lücke vor, KM:Lücke nach dem Richtungsvektor  
                                     Zeichnet einen 3D-Zylinder bei der Objektbildung automatisch, wenn Parameter ad==true (Standard).
   methodes:     zeichne()           Objekt zeichnen
   constructors: (),
                 (bool),
                 (vect SN,DN,CN,float W,bool ad)
*/
class Gerade : public Vektor
{ public: Gerade(vect,vect,vect,float,bool);
          Gerade(bool);
          Gerade();
          void Spurpunkt(vect,float);
          void zeichne();
          GLfloat LP,LM,KP,KM;
};

/*
Kreis(vect SN(MittelPunkt),DN(Normale),CN(FüllColor),float LP(AußenRadius),LM(Innenradius),bool ad);  
  Zeichnet Kreisfläche ohne Innenkreis bei der Objektbildung automatisch, wenn Parameter ad==true (Standard). 
  Methoden:      zeichne()    Objekt zeichnen
  Konstructoren: (),
                 (bool),
                 (vect SN,DN,CN,float LP,LM,bool ad)
*/
class Kreis : public Strecke
{ public: Kreis(vect,vect,vect,float,float,bool);
          Kreis(bool);
          Kreis();
          void zeichne();
};
/*
StreckeV(vect SN,DN,CN,float W,int ST,bool ad);  Vertex-Strecke mit SN:Ortsvektor Startpunkt, DN:Richtungsvektor bestimmt auch Länge, 
                                                 CN:Color, W: Dicke der Linie,ST:Code der Strichelung
                                                 Zeichnet bei der Objektbildung automatisch, wenn Parameter ad==true (Standard).
  Attribut:      ST           Strichelung (Werte=1,2,3,...Länge der Strichelung)
  Methoden:      zeichne()    Objekt zeichnen
  Konstructoren: (),
                 (bool),
                 (vect SN,DN,CN,float W,int ST,bool ad)
*/
class StreckeV : public Vektor
{ public: StreckeV(vect,vect,vect,float,int,bool);
          StreckeV(bool);
          StreckeV();
          void zeichne();
          int ST;
};
/*
Parallelogramm(vect SN,DN,DN2,CB,CF,float W,bool border,fill,ad);  
   Parallelogrammfläche mit SN:Ortsvektor zur Stützposition, DN,DN2:zwei Richtungsvektoren, CB: Randlinien-/ CF:Füllcolor
                            W:Dicke der 3D-Randlinie, border:mit/ohne Rand und fill:mit/ohne Füllfarbe 
                            Zeichnet das Parallelogramm bei der Objektbildung automatisch, wenn Parameter ad==true (Standard).
   Attributes:    DN2       zweiter Richtungsvektor
                  CN2       zweiter Farbvektor (für die Flächenfüllfarbe)
   Methoden:      zeichne() Objekt zeichnen
   Konstruktoren: (),
                  (bool),
                  (vect SN,DN,DN2,CB,CF,float W,bool border,fill,ad)   
*/
class Parallelogramm : public Vektor
{ public: Parallelogramm(vect,vect,vect,vect,vect,float,bool,bool,bool);
          Parallelogramm();
          void zeichne(bool,bool);
          GLfloat DN2[3],CN2[4];
};
/*
Ebene(vect SN,DN,DN2,CF,bool ad);  
   Ebene mit SN:Ortsvektor zur Stützposition, DN,DN2:zwei Richtungsvektoren, CF:Füllcolor
                            Zeichnet die Ebene bei der Objektbildung automatisch, wenn Parameter ad==true (Standard).
   Attributes:    DN2       zweiter Richtungsvektor
   Methoden:      zeichne() Objekt zeichnen
   Konstruktoren: (),
                  (bool),
                  (vect SN,DN,DN2,CF,bool ad)   
*/
class Ebene : public Parallelogramm
{ public: Ebene(vect,vect,vect,vect,bool);
          Ebene();
          void Spurgerade(vect,float);
          void zeichne();
};


/*
Dreieck(vect SN,DN,DN2,CB,CF,float W,bool border,fill,ad);  
   Dreiecksfläche mit SN:Ortsvektor zur Stützposition, DN,DN2:zwei Richtungsvektoren, CB: Randlinien-/ CF:Füllcolor
                      W:Dicke der 3D-Randlinie, border:mit/ohne Rand und fill:mit/ohne Füllfarbe 
                      Zeichnet das Dreieck bei der Objektbildung automatisch, wenn Parameter ad==true (Standard).
   Attributes:    DN2       zweiter Richtungsvektor
                  CN2       zweiter Farbvektor (für die Flächenfüllfarbe)
   Methoden:      zeichne() Objekt zeichnen
   Konstruktoren: (),
                  (bool),
                  (vect SN,DN,DN2,CB,CF,float W,bool border,fill,ad)   
*/

class Dreieck : public Parallelogramm
{ public: Dreieck(vect,vect,vect,vect,vect,float,bool,bool,bool);
          Dreieck();
          void zeichne(bool,bool);
};
class Rechteck : Parallelogramm
{ public: Rechteck(vect,vect,vect,vect,vect,float,bool,bool,bool);
          Rechteck();
          void zeichne(bool,bool);
};

class Quader : Parallelogramm
{ public: Quader(vect,vect,vect,vect,vect,vect,float,bool,bool,bool);
          Quader();
          void zeichne(bool,bool);
          GLfloat DN3[3];
};

class Wuerfel : public Parallelogramm
{ public: Wuerfel(vect,vect,vect,vect,float,float,bool);
          Wuerfel();
          void zeichne();
          GLfloat Brd;
};


// Methoden der Klassen

vect::vect()   // Konstruktor
{ SN[0]=SN[1]=SN[2]=0.f; 
  SN[3]=1.f;              // Alpha-Komponente wird im Standard auf "nicht transparent" gesetzt
}
vect::vect(float ex,float ey=0.f,float ez=0.f,float ea=1.f)   // Konstruktor
{ SN[0]=ex;SN[1]=ey;SN[2]=ez;SN[3]=ea;
}
vect::vect(float *v)
{ for(int i=0;i<4;i++) SN[i]=v[i];
}
float vect::length(void)
{ return sqrt(SN[0]*SN[0]+SN[1]*SN[1]+SN[2]*SN[2]);
}
vect::operator=(const vect &v) // liefert dem Zielvektor den identischen zum Parametervektor
{ for(int i=0;i<4;i++) SN[i]=v.SN[i];     
}
vect::operator=(const float* v)
{ for(int i=0;i<4;i++) SN[i]=v[i];     
}
float* vect::GLvect()
{ static float v[4]={SN[0],SN[1],SN[2],SN[3]};
  return v;
}
float vect::operator*(vect v)
{ return sqrt(SN[0]*v.x()+SN[1]*v.y()+SN[2]*v.z()+SN[3]*v.a());
}
vect vect::operator*(float c)
{ static vect nv;
  for(int i=0;i<4;i++) nv.SN[i]=SN[i]*c;
  return nv;
}
vect vect::operator/(float c)
{ vect nv;
  for(int i=0;i<4;i++) nv.SN[i]=SN[i]/c;
  return nv;
}
vect vect::operator%(vect v)
{ vect nv;
  nv.SN[0]= SN[1]*v.z()-SN[2]*v.y();
  nv.SN[1]=-SN[0]*v.z()+SN[2]*v.x();
  nv.SN[2]= SN[0]*v.y()-SN[1]*v.x();
  return nv;
}
vect vect::operator+(vect v)
{ vect nv;
  for(int i=0;i<4;i++) nv.SN[i]=SN[i]+v.SN[i]; 
  return nv;
}
vect vect::operator+(void)			
{ return *this;
}
vect vect::operator-(vect v)
{ vect nv;
  for(int i=0;i<4;i++) nv.SN[i]=SN[i]-v.SN[i]; 
  return nv;
}
vect vect::operator-(void)
{ vect nv;
  for(int i=0;i<4;i++) nv.SN[i]=-SN[i]; 
  return nv;
}
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
char* vect::vectstr(int n=3)
{ char s[50]; 
  char z[10],*st=s;
  if(n>=1) 
  { strcpy(s,"("); 
    for(int i=0;i<n;i++)
    { unsigned stellen,w=1;
      if(SN[i])
      { if(SN[i]<0)w=-SN[i];
        else w=SN[i];
      }
      gcvt(SN[i],fabs(log10(w))+5, z); 
      strcat(s,z); 
      if(i<(n-1)) strcat(s,"|");
      else    strcat(s,")");
    }
  }
  else strcpy(s,"??");
  return st;
}

/* 
Punkt(vect DN,CN,float W);   Punkt mit kartes. und Farbkoordinaten und Breite eines Punktes
   attributes:   CN[4];        color-vector
   methodes:     zeichne()        object drawing
   constructors: (),
                 (bool ad),    if(ad==true) drawing
                 (float *SN,*CN,W,bool ad)
*/
Punkt::Punkt()
{ SN[0]=1.f;SN[1]=1.f;SN[2]=1.f;SN[3]=0.f; 
  CN[0]=1.f;CN[1]=1.f;CN[2]=1.f;CN[3]=1.f; 
  W=3.f;
}
Punkt::Punkt(bool ad)
{ SN[0]=1.f;SN[1]=1.f;SN[2]=1.f;SN[3]=0.f; 
  CN[0]=1.f;CN[1]=1.f;CN[2]=1.f;CN[3]=1.f; 
  W=3.f;
  if(ad) zeichne();
}
Punkt::Punkt(vect Direction,vect Color,float Width=1.f,bool ad=true)
{ for(int i=0;i<4;i++)SN[i]=Direction.SN[i];
  for(int i=0;i<4;i++)CN[i]=Color.SN[i];
  W=Width;
  if(ad) zeichne();
}
void Punkt::zeichne()
{ float Pt[2][3];  
  Pt[0][0]=SN[0]-.1f; Pt[0][1]=SN[1]-.1f; Pt[0][2]=SN[2];
  Pt[1][0]=SN[0]+.1f; Pt[1][1]=SN[1]+.1f; Pt[1][2]=SN[2];
  A_LineS(Pt[0],Pt[1],CN,W);
  Pt[0][0]=SN[0]+.1f; Pt[0][1]=SN[1]-.1f;
  Pt[1][0]=SN[0]-.1f; Pt[1][1]=SN[1]+.1f;
  A_LineS(Pt[0],Pt[1],CN,W);  
}
/* 
Kugel(vect SN,CN,float W);   Kugel mit SN: Mittelpunkt-Vektor, CN: Farbvektor und W: Radius der Kugel
   Attribute:    CN[4];      Farbvektor
   Methoden:     zeichne()   Objekt zeichnen
   constructors: (),
                 (bool ad),    if(ad==true) drawing
                 (float *SN,*CN,W,bool ad)
*/
Kugel::Kugel()
{ SN[0]=1.f;SN[1]=1.f;SN[2]=1.f;SN[3]=1.f; 
  CN[0]=1.f;CN[1]=1.f;CN[2]=1.f;CN[3]=1.f; 
  W=3.f;
}
Kugel::Kugel(bool ad)
{ SN[0]=1.f;SN[1]=1.f;SN[2]=1.f;SN[3]=1.f; 
  CN[0]=1.f;CN[1]=1.f;CN[2]=1.f;CN[3]=1.f; 
  W=3.f;
  if(ad) zeichne();
}
Kugel::Kugel(vect Direction,vect Color,float Width=1.f,bool ad=true)
{ for(int i=0;i<4;i++)SN[i]=Direction.SN[i];
  for(int i=0;i<4;i++)CN[i]=Color.SN[i];
  W=Width;
  if(ad) zeichne();
}
void Kugel::zeichne()
{ A_Sphere(SN,CN,W);
}

/* 
Ortsvektor(vect SN,CN,float W);  Positionsvektor mit Koordinaten SN, Color CN und Dicke W
   Methoden:      zeichne()      Objekt zeichnen
   Konstruktoren: (),
                  (bool ad),                      ad  ==true -> zeichnen
                  (vect SN,CN,float W, bool ad)   CN: Colorvektor, W:Dicke der Linie
                  (vect SN)                       SN: Ortsposition
                  (Punkt P)                       P:  P.SN-position,P.CN-color,P.W-width
*/
void Ortsvektor::zeichne()
{ A_VectZero(SN,CN,W);
}
Ortsvektor::Ortsvektor()
{ SN[0]=1.f;SN[1]=1.f;SN[2]=1.f;SN[3]=0.f; 
  CN[0]=0.5f;CN[1]=0.5f;CN[2]=0.5f;CN[3]=1.f; 
  W=5.f;
}
Ortsvektor::Ortsvektor(bool ad)
{ SN[0]=1.f;SN[1]=1.f;SN[2]=1.f;SN[3]=0.f; 
  CN[0]=0.5f;CN[1]=0.5f;CN[2]=0.5f;CN[3]=1.f; 
  W=5.f;
  if(ad) A_VectZero(SN,CN,W);
}
Ortsvektor::Ortsvektor(vect Direction,vect Color,float Width=5.f,bool ad=true)
{ for(int i=0;i<3;i++) SN[i]=Direction.SN[i]; SN[3]=0.f;
  for(int i=0;i<4;i++) CN[i]=Color.SN[i];  
  W=Width;
  if(ad) A_VectZero(SN,CN,W);
}
Ortsvektor::Ortsvektor(vect Direction)
{ for(int i=0;i<4;i++)SN[i]=Direction.SN[i];
  CN[0]=0.5f;CN[1]=0.5f;CN[2]=0.5f;CN[3]=1.f;
  W=5.f; 
  A_VectZero(SN,CN,5.f);
}
Ortsvektor::Ortsvektor(Punkt P)
{ for(int i=1;i<3;i++)SN[i]=P.SN[i]; SN[3]=0.f;
  for(int i=1;i<4;i++)CN[i]=P.CN[i];
  W=P.W;
  A_VectZero(SN,CN,W);
}
/* 
TextAus(vect SN,char* Txt,vect CN,bool ad);   Beginnposition des Textes: SN, Color CN und Text Txt
   Attribut:	 char* Txt		  Zu zeichnender Text
   Methoden:     zeichne()        Objekt zeichnen
   Konstruktor:  (vect SN, char* Txt,vext CN,bool ad)  ad: wenn true: zeichnen, sonst nicht
*/
void TextAus::zeichne()
{ A_TextOut(SN,Txt,CN);
  glFlush();
}
TextAus::TextAus(vect Direction,char* Tx,vect Color,bool ad=true)
{ for(int i=0;i<3;i++)SN[i]=Direction.SN[i]; SN[3]=0.f;
  strcpy(Txt,Tx); 
  for(int i=0;i<4;i++) CN[i]=Color.SN[i]; SN[3]=1.f;
  if(ad) A_TextOut(SN,Txt,CN);
}
/*
Vektor(vect SN,DN,CN,float W);  vector with coordinates of start and direction
                                  , color and width
                                  draws the vector while object-instantiation
   methodes:     zeichne()           object drawing
   constructors: (),
                 (bool ad),       (ad==true) -> rendering
                 (vect SN,DN,CN,float W, bool ad) SN:position, DN:direction, W:width
                 (Punkt P)      P: P.SN-position,P.CN-color,P.W-width
*/
Vektor::Vektor()
{ SN[0]=0.f;SN[1]=0.f;SN[2]=0.f;SN[3]=0.f;
  DN[0]=1.f;DN[1]=1.f;DN[2]=1.f;DN[3]=0.f; 
  CN[0]=0.5f;CN[1]=0.5f;CN[2]=0.5f;CN[3]=1.f; 
}
Vektor::Vektor(bool ad)
{ SN[0]=0.f;SN[1]=0.f;SN[2]=0.f;SN[3]=0.f;
  DN[0]=1.f;DN[1]=1.f;DN[2]=1.f;DN[3]=0.f; 
  CN[0]=0.5f;CN[1]=0.5f;CN[2]=0.5f;CN[3]=1.f; 
  if(ad) A_Vect(SN,DN,CN,5.f);
}
Vektor::Vektor(vect Start,vect Direction,vect Color,float Width=2.f,bool ad=true)
{ for(int i=0;i<3;i++)SN[i]=Start.SN[i]; SN[3]=0.f; 
  for(int i=0;i<3;i++)DN[i]=Direction.SN[i]; DN[3]=0.f;
  for(int i=0;i<4;i++)CN[i]=Color.SN[i];  
  W=Width; 
  if(ad) A_Vect(SN,DN,CN,W);
}
void Vektor::zeichne()
{ A_Vect(SN,DN,CN,W);
}
/* Kreis(vect SN(MiddlePnt),DN(NormalDirection),CN(FillColor),
         float LP(outerRadius),LM(innerRadius));  
   Line with coordinates of start and direction, color and width
   solution with Vertex-Lines
   methodes:     zeichne()    object drawing
   constructors: (),
                 (bool),
                 (vect SN,DN,CN,float LP,LM)
*/
void Kreis::zeichne()
{ A_Disk(SN,DN,CN,LP=10.f,LM=0.f);
}
Kreis::Kreis()
{ SN[0]=0.f;SN[1]=0.f;SN[2]=0.f;SN[3]=0.f;
  DN[0]=1.f;DN[1]=1.f;DN[2]=1.f;DN[3]=0.f; 
  CN[0]=0.5f;CN[1]=0.5f;CN[2]=0.5f;CN[3]=1.f; 
}
Kreis::Kreis(bool ad)
{ SN[0]=0.f;SN[1]=0.f;SN[2]=0.f;SN[3]=0.f;
  DN[0]=1.f;DN[1]=1.f;DN[2]=1.f;DN[3]=0.f; 
  CN[0]=0.5f;CN[1]=0.5f;CN[2]=0.5f;CN[3]=1.f; 
  if(ad) A_Disk(SN,DN,CN,5.f);
}
Kreis::Kreis(vect MiddlePt,vect Direction,vect Color,
               float oRadius=1.f, float iRadius=0.9f, bool ad=true)
{ for(int i=0;i<3;i++)SN[i]=MiddlePt.SN[i]; SN[3]=0.f; 
  for(int i=0;i<3;i++)DN[i]=Direction.SN[i]; DN[3]=0.f;
  for(int i=0;i<4;i++)CN[i]=Color.SN[i];  
  LP=oRadius;LM=iRadius; 
  if(ad) A_Disk(SN,DN,CN,LP,LM);
}

/* Strecke(vect SN,DN,CN,float W);  
   vector with coordinates of start and direction, color and width
   draws the vector while object-instantiation
   attributes:
   methodes:     draw()           object drawing
   constructors: (),
                 (bool),                           (ad==true) -> rendering
                 (vect SN,DN,CN,float W, bool ad)  SN: startpos, DN: d, W:width
                 (Punkt P)                        P: P.SN position, P.CN: color, P.W: width
*/
void Strecke::zeichne()
{ //float P2[3];
  //for(int i=0;i<3;i++) P2[i]=DN[i]-SN[i]; 
  A_Line(SN,DN,CN,W);
}
Strecke::Strecke()
{ SN[0]=0.f;SN[1]=0.f;SN[2]=0.f;SN[3]=0.f;
  DN[0]=1.f;DN[1]=1.f;DN[2]=1.f;DN[3]=0.f; 
  CN[0]=0.5f;CN[1]=0.5f;CN[2]=0.5f;CN[3]=1.f; 
}
Strecke::Strecke(bool ad)
{ SN[0]=0.f;SN[1]=0.f;SN[2]=0.f;SN[3]=0.f;
  DN[0]=1.f;DN[1]=1.f;DN[2]=1.f;DN[3]=0.f; 
  CN[0]=0.5f;CN[1]=0.5f;CN[2]=0.5f;CN[3]=1.f; 
  W=5.f;
  if(ad) zeichne();
}
Strecke::Strecke(vect Start,vect Direction,vect Color,float Width=2.f,bool ad=true)
{ for(int i=0;i<3;i++)SN[i]=Start.SN[i]; SN[3]=0.f; 
  for(int i=0;i<3;i++)DN[i]=Direction.SN[i]; DN[3]=0.f;
  for(int i=0;i<4;i++)CN[i]=Color.SN[i];  
  W=Width;   
  if(ad) zeichne();
}
/* Gerade(vect SN,DN,CN,float W);  
   vector with coordinates of start and direction, color and width
   draws the vector while object-instantiation
   attributes:
   methodes:     draw()           object drawing
   constructors: (),
                 (bool),                           (ad==true) -> rendering
                 (vect SN,DN,CN,float W, bool ad)  SN: startpos, DN: d, W:width
                 (Punkt P)                        P: P.SN position, P.CN: color, P.W: width
*/
void Gerade::zeichne()
{ //void A_Line(GLfloat* Start,GLfloat* Desti,GLfloat* Color,         
  //          GLfloat Width, GLfloat lplus=0.f, GLfloat lminus=0.f,
  //          GLfloat kplus=0.f, GLfloat kminus=0.f)
  A_Line(SN,DN,CN,W,1000.,1000.);
}
Gerade::Gerade()
{ SN[0]=0.f;SN[1]=0.f;SN[2]=0.f;SN[3]=0.f;
  DN[0]=1.f;DN[1]=1.f;DN[2]=1.f;DN[3]=0.f; 
  CN[0]=0.5f;CN[1]=0.5f;CN[2]=0.5f;CN[3]=1.f; 
}
Gerade::Gerade(bool ad)
{ SN[0]=0.f;SN[1]=0.f;SN[2]=0.f;SN[3]=0.f;
  DN[0]=1.f;DN[1]=1.f;DN[2]=1.f;DN[3]=0.f; 
  CN[0]=0.5f;CN[1]=0.5f;CN[2]=0.5f;CN[3]=1.f; 
  W=5.f;
  if(ad) zeichne();
}
Gerade::Gerade(vect Start,vect Direction,vect Color,float Width=2.f,bool ad=true)
{ for(int i=0;i<3;i++)SN[i]=Start.SN[i]; SN[3]=0.f; 
  for(int i=0;i<3;i++)DN[i]=Direction.SN[i]; DN[3]=0.f;
  for(int i=0;i<4;i++)CN[i]=Color.SN[i];  
  W=Width;   
  if(ad) zeichne();
}
void Gerade::Spurpunkt(vect col,float rad)
{ vect xy(1,1,0),xz(1,0,1),yz(0,1,1); float r; int i;
  bool gut[3]={true,true,true};
  if(DN[2]) r=-SN[2]/DN[2]; else gut[0]=false; 
  for(i=0;i<=1;i++) xy.SN[i]=SN[i]+r*DN[i];
  if(DN[1]) r=-SN[1]/DN[1]; else gut[1]=false;
  xz.SN[0]=SN[0]+r*DN[0]; xz.SN[2]=SN[2]+r*DN[2];
  if(DN[0]) r=-SN[0]/DN[0]; else gut[2]=false;
  for(i=1;i<=2;i++) yz.SN[i]=SN[i]+r*DN[i];
  if(gut[0]) Kugel(xy,col,rad);
  if(gut[1]) Kugel(xz,col,rad);
  if(gut[2]) Kugel(yz,col,rad);  
}
/* StreckeV(vect SN,DN,CN,float W,ST,AD);  
   vector with coordinates of start and direction, color and width- solution with Vertex-Lines
   !! length of direction-vector is the length of Line !!

   attribute:    ST      stippled Line (values=1,2,3,...length of stipples)
   methodes:     zeichne()  object drawing
   constructors: - ()       , default, no render
                 - (bool ad), ad: if(ad==true) this.render();
                 - (vect SN,DN,CN,float W,LP,LM,KP,KM,bool ad)
                              SN: startpos(3d), DN: direction(3d), CN: colorvector(4d),        
                               W: width,        ST: stipple-line,  if(ad==true) this.render();
*/
void StreckeV::zeichne()
{ A_LineS(SN,DN,CN,W,ST);
}
StreckeV::StreckeV()
{ SN[0]=0.f;SN[1]=0.f;SN[2]=0.f;SN[3]=0.f;
  DN[0]=1.f;DN[1]=1.f;DN[2]=1.f;DN[3]=0.f; 
  CN[0]=0.5f;CN[1]=0.5f;CN[2]=0.5f;CN[3]=1.f; 
}
StreckeV::StreckeV(bool ad)
{ SN[0]=0.f;SN[1]=0.f;SN[2]=0.f;SN[3]=0.f;
  DN[0]=1.f;DN[1]=1.f;DN[2]=1.f;DN[3]=0.f; 
  CN[0]=0.5f;CN[1]=0.5f;CN[2]=0.5f;CN[3]=1.f; 
  if(ad) 
  { A_LineS(SN,DN,CN,5.f);
  }
}
StreckeV::StreckeV(vect Start,vect Direction,vect Color,float Width=1.f,int Stip=0.f,bool ad=true)
{ for(int i=0;i<3;i++)SN[i]=Start.SN[i]; SN[3]=0.f; 
  for(int i=0;i<3;i++)DN[i]=Direction.SN[i]; DN[3]=0.f;
  for(int i=0;i<4;i++)CN[i]=Color.SN[i];  
  W=Width; ST=Stip; 
  if(ad) 
  { A_LineS(SN,DN,CN,W,ST);
  }
}

/*
Parallelogramm(vect SN,DN,DN2,CB,CF,float W,bool border=true,fill=true,ad=true);  
   Rectangle with start, two directions, Border-/Fillcolor and width of Borderline 
   draws the Rectangle while object-instantiation with rules
   attributes:   DN2   second direction vector
                 CN2   second color (CB: border color)
   methodes:     zeichne()           object drawing
   constructors: (),
                 (bool),
                 (vect SN,DN,DN2,CB,CF,float W,bool border, bool fill, bool ad)
*/
Parallelogramm::Parallelogramm(vect S,vect D,vect D2,
             vect CB, vect CF, float Width=1.f, 
             bool fill=true,bool border=true, bool ad=true)
{ for(int i=0;i<3;i++)
  { SN[i]=S.SN[i]; DN[i]=D.SN[i]; DN2[i]=D2.SN[i]; }
  for(int i=0;i<4;i++)
  { CN[i]=CF.SN[i]; CN2[i]=CB.SN[i]; } 
  W=Width;
  if(ad) zeichne(fill,border);
} 
Parallelogramm::Parallelogramm()
{}
void Parallelogramm::zeichne(bool fill,bool border)
{ A_Rhombus(SN,DN,DN2,CN2,CN,W,fill,border);
}

/*
Quader(vect SN,DN,DN2,DN3,CB,CF,float W,bool border=true,fill=true,ad=true);  
   Rectangle with start, two directions, Border-/Fillcolor and width of Borderline 
   draws the Rectangle while object-instantiation with rules
   attributes:   DN2   second direction vector
                 DN3   third  direction vector
                 CN2   second color (CB: border color)
   methodes:     zeichne()           object drawing
   constructors: (),
                 (bool),
                 (vect SN,DN,DN2,DN3,CB,CF,float W,bool border, bool fill, bool ad)
*/
Quader::Quader(vect S,vect D,vect D2,vect D3,
             vect CB, vect CF, float Width=1.f, 
             bool fill=true,bool border=true, bool ad=true)
{ for(int i=0;i<3;i++)
  { SN[i]=S.SN[i]; DN[i]=D.SN[i]; DN2[i]=D2.SN[i]; DN3[i]=D3.SN[i]; }
  for(int i=0;i<4;i++)
  { CN[i]=CF.SN[i]; CN2[i]=CB.SN[i]; } 
  W=Width;
  if(ad) zeichne(fill,border);
} 
Quader::Quader()
{}
void Quader::zeichne(bool fill,bool border)
{ A_Quader(SN,DN,DN2,DN3,CN2,CN,W,fill,border);
}


Ebene::Ebene(vect S,vect D,vect D2,vect CF, bool ad=true)
{ for(int i=0;i<3;i++)
  { SN[i]=S.SN[i]; DN[i]=D.SN[i]; DN2[i]=D2.SN[i]; }
  for(int i=0;i<4;i++) CN[i]=CF.SN[i];  
  if(ad) zeichne();
} 
Ebene::Ebene()
{}
void Ebene::Spurgerade(vect col,float rad)
{ vect xy_s,xy_r,xz_s,xz_r,yz_s,yz_r; int i; float s,r;
  bool gut[]={true,true,true};
  // 0=SN[2]+r*DN[2]+s*DN2[2]
  // -SN[2]-r*DN[2]=s*DN2[2]
  if(DN2[2]) { s=-SN[2]/DN2[2]; r= -DN[2]/DN2[2]; } else gut[2]=false;
  for(i=0;i<3;i++)
  { xy_s.SN[i]=DN2[i]*s+SN[i]; 
    xy_r.SN[i]=DN[i]+DN2[i]*r;
  }
  if(gut[2]) Gerade(xy_s,xy_r,col,rad);

  if(DN2[1]) { s=-SN[1]/DN2[1]; r= -DN[1]/DN2[1]; } else gut[1]=false;
  for(i=0;i<3;i++)
  { xz_s.SN[i]=DN2[i]*s+SN[i]; 
    xz_r.SN[i]=DN[i]+DN2[i]*r;
  }
  if(gut[1]) Gerade(xz_s,xz_r,col,rad);

  if(DN2[0]) { s=-SN[0]/DN2[0]; r= -DN[0]/DN2[0]; } else gut[0]=false;
  for(i=0;i<3;i++)
  { yz_s.SN[i]=DN2[i]*s+SN[i]; 
    yz_r.SN[i]=DN[i]+DN2[i]*r;
  }
  if(gut[0]) Gerade(yz_s,yz_r,col,rad);
}
void Ebene::zeichne()
{ A_PlaneRound(SN,DN,DN2,CN);
}

/*
Dreieck(vect SN,DN,DN2,CB,CF,float W);  
   Triangle with start, two directions, Border-/Fillcolor and width of Borderline 
   draws the Triangle while object-instantiation with rules
   methodes:     zeichne()           object drawing
   constructors: (),
                 (bool),
                 (vect SN,DN,DN2,CB,CF,float W,bool ad)
*/
Dreieck::Dreieck(vect S,vect D,vect D2,
             vect CB, vect CF, float Width=1.f,
             bool fill=true,bool border=true,bool ad=true)
{ for(int i=0;i<3;i++)
  { SN[i]=S.SN[i]; DN[i]=D.SN[i]; DN2[i]=D2.SN[i]; }
  for(int i=0;i<4;i++)
  { CN[i]=CF.SN[i]; CN2[i]=CB.SN[i]; } 
  W=Width;
  if(ad) zeichne(fill,border);
} 
Dreieck::Dreieck()
{}
void Dreieck::zeichne(bool fill,bool border)
{ A_Triangle(SN,DN,DN2,CN2,CN,W,fill,border);
}

/*
Rechteck(vect SN,DN,DN2,CB,CF,float W);  
   Triangle with start, two directions, Border-/Fillcolor and width of Borderline 
   draws the Triangle while object-instantiation with rules
   methodes:     zeichne()           object drawing
   constructors: (),
                 (bool),
                 (vect SN,DN,DN2,CB,CF,float W,bool ad)
*/
Rechteck::Rechteck(vect S,vect D,vect D2,
             vect CB, vect CF, float Width=1.f,
             bool fill=true,bool border=true,bool ad=true)
{ for(int i=0;i<3;i++)
  { SN[i]=S.SN[i]; DN[i]=D.SN[i]; DN2[i]=D2.SN[i]; }
  for(int i=0;i<4;i++)
  { CN[i]=CF.SN[i]; CN2[i]=CB.SN[i]; } 
  W=Width;
  if(ad) zeichne(fill,border);
} 
Rechteck::Rechteck()
{}
void Rechteck::zeichne(bool fill,bool border)
{ A_Rhombus(SN,DN,DN2,CN2,CN,W,fill,border);
}



/*
Wuerfel(vect MP,D,CB,CF,float Border, Thickness, bool ad);  
   Würfel mit MP:Mittelpunkt, D: Richtung, VB:Border-/ CF:Fillcolor 
   Border:width Border, Thickness: Seitenlänge, ad: zeichnet, wenn true
   zeichnet den Würfel während der Objektbildung
   Methoden:     zeichne()           Objekt zeichnen
   Konstruktoren:(),
                 (vect SN,DN,CB,CF,float Border,Thickness,bool ad)
void A_Cube(float* MiddlePt, float* Direction, float* FillColor,float* BorderColor, float Border, float Thickness)
A_Cube(SN, DN, CN, CN2, Border, Thickness);
*/

Wuerfel::Wuerfel(vect MP,vect D,vect CF,vect CB, float Border=2.f,float Width=1.f,bool ad=true)
{ for(int i=0;i<3;i++)
  { SN[i]=MP.SN[i]; DN[i]=D.SN[i]; }
  for(int i=0;i<4;i++)
  { CN[i]=CF.SN[i]; CN2[i]=CB.SN[i]; } 
  W=Width; Brd=Border;
  if(ad) zeichne();
} 
Wuerfel::Wuerfel(){}
void Wuerfel::zeichne()
{ A_Cube(SN, DN, CN, CN2, Brd, W);
}




#define ZERO           0.f, 0.f, 0.f
#define UNIT_X         1.f, 0.f, 0.f
#define UNIT_Y         0.f, 1.f, 0.f
#define UNIT_Z         0.f, 0.f, 1.f
#define UNIT_XY        1.f, 1.f, 0.f
#define UNIT_XZ        1.f, 0.f, 1.f
#define UNIT_YZ        0.f, 1.f, 1.f
#define UNIT_XYZ       1.f, 1.f, 1.f
#define UNIT_X_M      -1.f, 0.f, 0.f
#define UNIT_Y_M       0.f,-1.f, 0.f
#define UNIT_Z_M       0.f, 0.f,-1.f
#define UNIT_XY_M     -1.f,-1.f, 0.f
#define UNIT_XZ_M     -1.f, 0.f,-1.f
#define UNIT_YZ_M      0.f,-1.f,-1.f
#define UNIT_XYZ_M    -1.f,-1.f,-1.f

#define WEISS           1.f, 1.f, 1.f, 1.f
#define BLAU            0.f, 0.f, 1.f, 1.f
#define ROT             1.f, 0.f, 0.f, 1.f
#define GRUEN           0.f, 1.f, 0.f, 1.f
#define GELB            1.f, 1.f, 0.f, 1.f
#define CYAN            0.f, 1.f, 1.f, 1.f
#define MAGENTA         1.f, 0.f, 1.f, 1.f
#define SCHWARZ         0.f, 0.f, 0.f, 1.f
#define GRAU            .5f, .5f, .5f, 1.f
#define HELLGRAU        .6f, .6f, .6f, 1.f
#define HELLBLAU        .3f, .3f, 1.f, 1.f
#define HELLROT         1.f, .3f, .3f, 1.f
#define ROSA            1.f, .3f, .3f, 1.f
#define HELLGRUEN       .3f, 1.0f,.3f, 1.f
#define HELLGELB        1.f, 1.f, .3f, 1.f
#define HELLCYAN        .3f, 1.f, 1.f, 1.f
#define HELLMAGENTA     1.f, .3f, 1.f, 1.f
#define DUNKELGRAU      .3f, .3f, .3f, 1.f
#define DUNKELBLAU      0.f, 0.f, .5f, 1.f
#define DUNKELROT       .5f, 0.f, 0.f, 1.f
#define DUNKELGRUEN     0.f, .5f, 0.f, 1.f
#define DUNKELGELB      .5f, .5f, 0.f, 1.f
#define DUNKELCYAN      0.f, .5f, .5f, 1.f
#define DUNKELMAGENTA   .5f, 0.f, .5f, 1.f

#define TRANSP     		0.f, 0.f, 0.f, .0f
#define URSPRUNG   		0.f, 0.f, 0.f, .0f

#define T_GLASS         1.f, 1.f, 1.f, .33f
#define T_WEISS         1.f, 1.f, 1.f, .33f
#define T_BLAU          0.f, 0.f, 1.f, .33f
#define T_ROT           1.f, 0.f, 0.f, .33f
#define T_GRUEN         0.f, 1.f, 0.f, .33f
#define T_GELB          1.f, 1.f, 0.f, .33f
#define T_CYAN          0.f, 1.f, 1.f, .33f
#define T_MAGENTA       1.f, 0.f, 1.f, .33f
#define T_SCHWARZ       0.f, 0.f, 0.f, .33f
#define T_GRAU          .5f, .5f, .5f, .33f
#define T_HELLGRAU      .6f, .6f, .6f, .5f
#define T_HELLBLAU      .3f, .3f, 1.f, .5f
#define T_HELLROT       1.f, .3f, .3f, .5f
#define T_ROSA          1.f, .3f, .3f, .5f
#define T_HELLGRUEN     .3f, 1.0f,.3f, .5f
#define T_HELLGELB      1.f, 1.f, .3f, .5f
#define T_HELLCYAN      .3f, 1.f, 1.f, .5f
#define T_HELLMAGENTA   1.f, .3f, 1.f, .5f
#define T_DUNKELGRAU    .3f, .3f, .3f, .33f
#define T_DUNKELBLAU    0.f, 0.f, .5f, .33f
#define T_DUNKELROT     .5f, 0.f, 0.f, .33f
#define T_DUNKELGRUEN   0.f, .5f, 0.f, .33f
#define T_DUNKELGELB    .5f, .5f, 0.f, .33f
#define T_DUNKELCYAN    0.f, .5f, .5f, .33f
#define T_DUNKELMAGENTA .5f, 0.f, .5f, .33f



