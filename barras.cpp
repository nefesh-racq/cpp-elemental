#include <iostream>
using std::cout;
using std::endl;

#include <iomanip>
using std::setw;

int main() {
  const int tamArreglo = 11;
  int n[tamArreglo] = {0, 8, 0, 0, 0, 0, 0, 3, 1, 4, 2};

  cout << "Distribucion de calificaciones : " << endl;

  // para cada elemeno del arreglo n, imprimir una barra de graficos
  for (int i = 0; i < tamArreglo; i++) {
    // imptime eetiquetas de las barras ("0-9:", ...., "90-99:", "100:")
    if (i == 0)
      cout << "  0-9: ";
    else if (i == 10)
      cout << "  100: ";
    else
      cout << i * 10 << "-" << (i * 10) + 9 << ": ";

    // imprime barra de asteriscos
    for (int estrellas = 0; estrellas < n[i]; estrellas++)
      cout << '*';

    cout << endl;
  }

  return 0;
}
