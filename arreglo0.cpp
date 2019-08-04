#include <iostream>
using std::cout;
using std::endl;

#include <iomanip>
using std::setw;

#define TAM 10

int main() {
  int n[TAM];

  // inicializando los elementos
  for (int i = 0; i < TAM; i++)
    n[i] = 0;

  cout << "Elemento" << setw(13) << "valor" << endl;

  // imprimiendo los valores
  for (int i = 0; i < TAM; i++)
    cout << setw(8) << i << setw(13) << n[i] << endl;


  cout << "\n\ninicializacion en la declaracion" << endl;

  const int tam = 10;
  int m[tam] = {51, 1, 78, 10, 5, 11, 36, 4, 9, 70};

  cout << "Elemento" << setw(13) << "valor" << endl;

  for (int i = 0; i < tam; i++)
    cout << setw(8) << i << setw(13) << m[i] << endl;

  return 0;
}
