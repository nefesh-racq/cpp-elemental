// paso por valor y referencia
#include <iostream>

using std::cout;
using std::endl;

int cuadradoPorValor(int);
void cuadradoPorReferencia(int &);

int main() {
  int x = 3;
  int z = 7;

  // usando cuadradoPorValor(int)
  cout << "x = " << x << " antes de llamada cuadradoPorValor " << endl;
  cout << "el cuadrado de x es " << cuadradoPorValor(x) << endl;
  cout << "x = " << x << " despues de llamada a cuadradoPorValor " << endl;

  // probando paso por referencia
  cout << "\nz = " << z << " antes de llamada a cuadradoPorReferencia " << endl;
  cuadradoPorReferencia(z);
  cout << "cuadrado de z = " << z << endl;
  cout << "z = " << z << " despues de la llamada a cuadradoPorReferencia " << endl;

  return 0;
}

int cuadradoPorValor(int x) {
  return x * x;
}

void cuadradoPorReferencia(int &z) {
  z = z * z;
}
