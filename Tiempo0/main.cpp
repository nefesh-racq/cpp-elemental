// manejo de la clase Tiempo
#include <iostream>
using std::cout;

#include "Tiempo.h"

int main()
{
    cout << "Usando los datos definidos por el usuario\n";
    Tiempo t(12, 50, 12);

    t.imprimirUniversal();
    t.imprimirEstandar();

    cout << "\nUsando los datos por omision\n";

    Tiempo t0;

    t0.imprimirUniversal();
    t0.imprimirEstandar();

    return 0;
}
