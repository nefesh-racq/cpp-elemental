//
#include <iostream>

using std::cout;
using std::endl;

int global = 2;

int main() {
  int global = 87;

  cout << "global en main = " << global << "\nglobal en el archivo = " << ::global << endl;

  return 0;
}
