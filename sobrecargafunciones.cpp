// ejemplo de sobrecarga de funciones en cpp
#include <iostream>

using std::endl;
using std::cout;

int cuadrado(int x) {
  return x * x;
}


double cuadrado(double x) {
  return x * x;
}


int main() {
  int x = 5;
  double y = 12.54;

  cout << "double cuadrado " << cuadrado(y) << endl;
  cout << "int cuadrado " << cuadrado(x) << endl;

  return 0;
}
