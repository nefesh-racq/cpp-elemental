// demostracion de una funcion publica que devuelve una referencia
// a un miembro de datos privado
#include <iostream>
using std::cout;
using std::endl;

#include "Tiempo.h"

int main()
{
    Tiempo t;

    // inicializa horaRef con la referencia devuelta por la funcion
    int &horaRef = t.establecerHoraIncorrecta(20);  // 20 es una hora valida

    cout << "Hora valida antes de la modificacion: " << horaRef;
    horaRef = 30;   // usamos la referencia para establecer una hora no valida
    cout << "\nHora invalida despues de la modificacion: " << t.obtenerHora() << endl;

    // peligroso: llamada a una funcion que devuelve una referencia se puede
    // usar como un lvalue
    t.establecerHoraIncorrecta(12) = 62;    // asignamos otro valor invalido a hora

    cout << "\n\n**************************************************\n"
        << "MALA PRACTICA DE PROGRAMACION..!!!!!\n"
        << "t.establecerHoraIncorrecta(12) = 62 como un lvalue\n"
        << "hora invalida "
        << t.obtenerHora()
        << "\n**************************************************\n";

    return 0;
}
