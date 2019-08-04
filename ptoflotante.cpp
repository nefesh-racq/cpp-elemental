#include <iostream>

using std::cout;
using std::cin;
using std::endl;
using std::fixed;	// asegura que se muestre el punto decimal

#include <iomanip>	// manipuladores de flujo parametrizados
using std::setprecision; // establece la precision numerica de salida
using std::setw;	// permite al programa establecer una anchura de campo

int main() {
   double val = 32.61484382363;
   
   cout << setw(25) << val << endl;
   cout << "setprecision(2) << " << val << " : " << setprecision(2) << val << endl;
   cout << "setprecision(2) << fixed << " << val << " : " << setprecision(2) << fixed << val << endl;

   return 0;
}

