#include <iostream>

using namespace std;

int main() {
   int fila = 10;
   int columna;

   while (fila >= 1) {
      columna = 1;

      while (columna <= 10) {
         cout << (fila % 2 ? "<" : ">");
         ++columna;
      }

      --fila;
      cout << endl;
   }

   return 0;
}

