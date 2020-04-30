// Thomas Cassebaum, 31.1.2009, all rights reserved
#include <iostream>
using namespace std;
#define tl 218  // top left
#define tc 194	// top centre
#define tr 191  // top right
#define ml 195  // middle left
#define mc 197  // middle centre
#define mr 180  // middle right
#define bl 192  // bottom left
#define bc 193  // bottom centre
#define br 217  // bottom right
#define lh 196  // line horizontal
#define lv 179  // line vertical
#define sp 32       
int main()
{ char top[]={tl,lh,lh,lh,tc,lh,lh,lh,tc,lh,lh,lh,tc,lh,lh,lh,tc,lh,lh,lh,tc,lh,lh,lh,tc,lh,lh,lh,tc,lh,lh,lh,tr,13,10,0};
  char mid[]={ml,lh,lh,lh,mc,lh,lh,lh,mc,lh,lh,lh,mc,lh,lh,lh,mc,lh,lh,lh,mc,lh,lh,lh,mc,lh,lh,lh,mc,lh,lh,lh,mr,13,10,0};
  char clr[]={lv,sp,sp,sp,lv,sp,sp,sp,lv,sp,sp,sp,lv,sp,sp,sp,lv,sp,sp,sp,lv,sp,sp,sp,lv,sp,sp,sp,lv,sp,sp,sp,lv,13,10,0};
  char bot[]={bl,lh,lh,lh,bc,lh,lh,lh,bc,lh,lh,lh,bc,lh,lh,lh,bc,lh,lh,lh,bc,lh,lh,lh,bc,lh,lh,lh,bc,lh,lh,lh,br,13,10,0};
  
  cout << top <<  clr << mid  << clr << bot; 
  
  getchar();
  return 0;
}


