#include <iostream>
#include "LC.h"

using namespace std;

int main() {
   LC lc("curso de c++ en gnu");
   string nombre;
   
   cout << "\n ingrese un nombre : ";
   getline(cin, nombre);

   lc.setNombre(nombre);
   lc.getNombre();

   return 0;
}
