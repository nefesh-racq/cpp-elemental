#include <iostream>
#include <iomanip>
#include <cstdlib>	// contiene prototipo para la funcion rand
#include <ctime>	// manejo de fechas hora ..

using namespace std;

int main() {
   srand(time(0));	// genera una semilla para los numeros aleatorios

   for (int i = 1; i <= 20; i++) {
      cout << setw(10) << ( 1 + rand() % 6);

      if (i % 5 == 0)
         cout << endl;
   }

   return 0;
}

