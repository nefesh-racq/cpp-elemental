// ejemplo funiciones inline
#include <iostream>

using std::cout;
using std::endl;
using std::cin;

inline double cubo(const double lado) {
  return lado * lado * lado;
}

int main() {
  double lado;

  cout << "escriba el tamaño del lado : ";
  cin >> lado;

  cout << "el volumen del cubo es con un lado de " << lado << " es = " << cubo(lado) << endl;

  return 0;
}
