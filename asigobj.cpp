// asignacion de un objeto a otro objeto del mismo tipo
#ifndef FECHA_H
#define FECHA_H

// definimos la clase Fecha
class Fecha
{
public:
    Fecha(int = 1, int = 1, int = 2000);    //  constructor con datos por omision
    //void imprimir();
    void imprimir() const;

private:
    int mes;
    int dia;
    int anio;
};

#endif // FECHA_H

// definiciones de las funciones miembro
#include <iostream>
using std::endl;
using std::cout;

Fecha::Fecha(int m, int d, int a)
{
    mes = m;
    dia = d;
    anio = a;
}

// imrimirmos la fecha en formato mm/dd/aaaa
/*void Fecha::imprimir()
{
    cout << mes << '/' << dia << '/' << anio << endl;
}
*/
// imprimir metodo constante
void Fecha::imprimir() const
{
    cout << "metodo constante ";
    cout << mes << '/' << dia << '/' << anio << endl;
}

// funcion principal para probrar la copia de objetos mediante el operador =
int main()
{
    const Fecha fecha1(7, 3, 2019);
    Fecha fecha2;

    cout << "fecha1 : ";
    fecha1.imprimir();
    cout << "fecha2 : ";
    fecha2.imprimir();

    fecha2 = fecha1;

    cout << "\nDespues de la asignacion fecha2 = fecha1.\n"
        << "la copia se realzia a nivel de bits\nfecha2 : ";
    fecha2.imprimir();
    cout << endl;

    return 0;
}
