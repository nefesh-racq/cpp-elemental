// definiciones de la clase CrearYDestruir
#include <iostream>
using std::cout;
using std::endl;

#include "CrearYDestruir.h"

CrearYDestruir::CrearYDestruir(int id, string cadenaMensaje)
{
    idObjeto = id;
    mensaje = cadenaMensaje;

    cout << "El constructor del objeto " << idObjeto << " se ejecuta "
        << mensaje << endl;
}

// destructor
CrearYDestruir::~CrearYDestruir()
{
    // imprime nueva linea para ciertos objetos; mejora la legibilidad
    cout << (idObjeto == 1 || idObjeto == 6 ? "\n" : "");

    cout << "El destructor del objeto " << idObjeto << " se ejecuta "
        << mensaje << endl;
}
