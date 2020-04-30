#include <iostream.h>
func()
{ int i=1;
  static int j=1;
  cout << i++ << " " << j++ << endl;
}
int main()
{ func(); func(); func();
  getchar();
  return 0;
}
