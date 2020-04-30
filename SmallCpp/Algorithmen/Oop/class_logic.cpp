#include <iostream.h>
#include <conio.h>
class logic
{ public:
    logic(bool k);   // 3 Prototypen Konstruktor
    logic(short &k);
    logic(char &k);
    logic operator+(logic &x);  // Operatorüberladung + (AND)
    logic operator*(logic &x);  // Operatorüberladung * (OR)
    logic operator-(logic &x);  // Operatorüberladung + (NAND)
    logic operator/(logic &x);  // Operatorüberladung * (NOR)
    logic operator!(void);
    char* Value(void);
  private:
    bool w;               	   // privater Logikwert
};
logic logic::operator+(logic &x)   // Operatorüberladungen für Klasse logic
{ return logic(x.w&&w); }
logic logic::operator*(logic &x)
{ return logic(x.w||w); }
logic logic::operator-(logic &x)
{ return logic(!(x.w&&w)); }
logic logic::operator/(logic &x)
{ return logic(!(x.w||w)); }
logic logic::operator!(void)
{ return logic(!w); }
logic::logic(bool k=false)// 1.Konstruktor  (bool)
{ w=k;}
logic::logic(short &k)    // 2.Konstruktor  (int)
{ w=(bool)k;}
logic::logic(char &k)     // 3.Konstruktor  (char)
{ w=(bool)k;}
char* logic::Value(void)
{ if(w) return("true"); else return("false");}
int main()
{ logic a(true),b(0),c('a'),d;
  cout << "  a = "<<a.Value()
       << "  b = "<<b.Value()
       << "  c = "<<c.Value()
       << "  d = "<<d.Value() <<endl;
  cout << " (AND ) a + b = " <<(a+b).Value();
  cout << "\n (OR  ) a * b = " <<(a*b).Value();
  cout << "\n (NAND) c - b = " <<(c-b).Value();
  cout << "\n (NOR ) a / c = " <<(a/c).Value();
  cout << "\n (NOT ) ! d   = " <<(!d).Value();
  cout << "\n       !(c+d) = " <<(!(c+d)).Value();
  cout << "\n        c - d = " <<(c-d).Value();
  cout << "\n       !(c*d) = " <<(!(c*d)).Value();
  cout << "\n        c / d = " <<(c/d).Value();
  getch();
  return 0;
}
