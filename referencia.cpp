// ejemplo de alias usando referencia
#include <iostream>

using std::cout;
using std::endl;

int main() {
  int x = 3;
  int &ref = x; // referencia a x - es un alias
  //  int &ref2;    // si no se inicializa da error

  cout << "x = " << x << endl << "ref = " << ref << endl;
  ref = 7;
  cout << "x = " << x << endl << "ref = " << ref << endl;

  return 0;
}
