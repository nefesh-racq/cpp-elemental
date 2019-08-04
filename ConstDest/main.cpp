// demostracion del orden en que se ejecutan los constructores y destructores
#include <iostream>
using std::cout;
using std::endl;

#include "CrearYDestruir.h"

void crear(void);

CrearYDestruir primero(1, "(global antes de main)"); // objeto global

int main()
{
    cout << "FUNCION MAIN: EMPIEZA LA EJECUCION\n";
    CrearYDestruir segundo(2, "(local automatico en main)");
    static CrearYDestruir tercero(3, "(local static en main)");

    crear();    // llama a la funcion para crear objetos

    cout << "\nFUNCION MAIN: CONTINUA LA EJECUCION\n";
    CrearYDestruir cuarto(4, "(local automatco en main)");
    cout << "\nFUNCION MAIN: TERMINA LA EJECUCION\n";

    return 0;
}

// funcion crear objetos
void crear(void)
{
    cout << "\nFUNCION crear(): EMPIEZA LA EJECUCION\n";
    CrearYDestruir quinto(5, "(local automatico en la funcion crear())");
    static CrearYDestruir sexto(6, "(local static en la funcion crear())");
    CrearYDestruir septimo(7, "(local automatico en la funcion crear())");

    cout << "\nFUNCION crear(): TERMINA LA EJECUCION\n";
}
