#ifndef FECHA_H
#define FECHA_H

class Fecha
{
public:
    Fecha(int = 1, int = 1, int = 1900);
    void imprimir() const;
    ~Fecha();

private:
    int mes;    // 1-12 (enero-diciembre)
    int dia;    // 1-31 con base en el mes
    int anio;   // cualquier año

    // funcion utilitaria para comprobar si es un dia valido
    int comprobarDia(int) const;
};

#endif // FECHA_H

#include <iostream>
using std::endl;
using std::cout;

// definicion de la clase fecha
Fecha::Fecha(int mm, int dd, int aa)
{
    if (mm > 0 && mm <= 12) // validamos el mes
        mes = mm;
    else
    {
        mes = 1;    // cuando es invalido el mes se pone en 1
        cout << "Mes invalido (" << mm << ") se establecio en 1.\n";
    }

    anio = aa;  // en este caso no estamos validando año
    dia = comprobarDia(dd);     // valida el dia

    cout << "Constructor del objeto fecha para fecha ";
    imprimir();
    cout << endl;
}

//
void Fecha::imprimir() const
{
    cout << mes << '/' << dia << '/' << anio;
}

Fecha::~Fecha()
{
    cout << "Destructor del objeto Fecha para fecha ";
    imprimir();
    cout << endl;
}

//
int Fecha::comprobarDia(int diaPrueba) const
{
    static const int diasPorMes[13] = {0, 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31 };

    // determina si el diaPrueba es valido para el mes segun el array
    if (diaPrueba > 0 && diaPrueba <= diasPorMes[mes])
        return diaPrueba;

    // comprueba 29 de febrero para año bisiesto
    if (mes == 2 && diaPrueba == 29 && (anio % 400 == 0 ||
        (anio % 4 == 0 && anio % 100 != 0)))
        return diaPrueba;

    cout << "Dia invalido (" << diaPrueba << ") se establece en 1-\n";

    return 1;
}

/**************************************************************/

#ifndef EMPLEADO_H
#define EMPLEADO_H

class Empleado
{
public:
    Empleado(const char * const, const char * const,
        const Fecha &, const Fecha &);
    void imprimir() const;
    ~Empleado();    // estamos usando para mostrar el orden de destruccion

private:
    char primerNombre[25];
    char apellidoPaterno[25];
    const Fecha fechaNacimiento;    // composicion: objeto miembro
    const Fecha fechaContratacion;  // composicion: objeto miembro
};

#endif



#include <iostream>
using std::cout;
using std::endl;

#include <cstring>
using std::strlen;
using std::strncpy;

//
Empleado::Empleado(const char * const nombre, const char * const apellido,
    const Fecha &fechaDeNacimiento, const Fecha &fechaDeContratacion)
        : fechaNacimiento(fechaDeNacimiento),       // inicializador obj const
            fechaContratacion(fechaDeContratacion)  // inicializador obj const
{
    // copia nombre en primerNombre y se asegura de que quepa
    int longitud = strlen(nombre);
    longitud = (longitud < 25 ? longitud : 14);
    strncpy(primerNombre, nombre, longitud);
    primerNombre[longitud] = '\0';

    // copia apellido dentro de apellidoPaterno
    longitud = strlen(apellido);
    longitud = (longitud < 25 ? longitud : 24);
    strncpy(apellidoPaterno, apellido, longitud);
    apellidoPaterno[longitud] = '\0';

    // imprime objeto Empleado para mostrar cuando se llama al constructor
    cout << "Constructor del objeto Empledo: "
        << primerNombre << ' ' << apellidoPaterno << endl;
}

void Empleado::imprimir() const
{
    cout << apellidoPaterno << "; " << primerNombre << "Contratacion: ";
    fechaContratacion.imprimir();
    cout << "Nacimiento: ";
    fechaNacimiento.imprimir();
    cout << endl;
}

Empleado::~Empleado()
{
    cout << "Destructor del objeto Empleado: "
        << apellidoPaterno << ", " << primerNombre << endl;
}

/*****************************************************************************/
int main()
{
    Fecha nacimiento(7, 24, 1949);
    Fecha contratacion(3, 12, 1988);
    Empleado gerente("Bob", "Blue", nacimiento, contratacion);

    cout << endl;
    gerente.imprimir();

    cout << "\nPrueba del constructor de Fecha con valores invalidos-\n";
    Fecha ultimoDiaDescanso(14, 35, 1944);
    cout << endl;

    return 0;
}
