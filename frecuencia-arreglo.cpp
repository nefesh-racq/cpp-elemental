#include <iostream>
using std::cout;
using std::endl;

#include <iomanip>
using std::setw;

#include <cstdlib>
using std::rand;
using std::srand;

#include <ctime>
using std::time;

int main() {
  const int tamArreglo = 7;
  int frecuencia[tamArreglo] = {};

  srand(time(0));

  // generamos los tiros y contamos las coincidencias
  for (int tiro = 0; tiro <= 6000000; tiro++) {
    frecuencia[1 + rand() % 6]++;
  }

  // imprimimos las coincidencias
  cout << "cara" << setw(15) << "coincidencias" << endl;
  
  for (int cara = 1; cara < tamArreglo; cara++)
    cout << setw(4) << cara << setw(15) << frecuencia[cara] << endl;

  return 0;
}
