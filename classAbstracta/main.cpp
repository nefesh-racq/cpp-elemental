#include <iostream>
using std::cout;
using std::endl;
using std::fixed;

#include <iomanip>
using std::setprecision;

#include <vector>
using std::vector;

// definicion de las clases segun su jerarquia
#include "Empleado.h"
#include "EmpleadoAsalariado.h"
#include "EmpleadoPorHoras.h"
#include "EmpleadoPorComision.h"
#include "EmpleadoBaseMasComision.h"

void virtualViaApuntador(const Empleado * const);
void virtualViaReferencia(const Empleado &);

int main()
{
	// definimos el formato de salida para los decimales
	cout << fixed << setprecision(2);

	EmpleadoAsalariado empAsalariado("john", "smith", "111-11-1111", 800);
	EmpleadoPorHoras empPorHoras("karen", "price", "222-22-2222", 16.75, 40);
	EmpleadoPorComision empPorComision("sue", "jones", "333-33-3333", 10000, .06);
	EmpleadoBaseMasComision empBaseMasComision("bob", "lewis", "444-44-4444", 5000, .04, 300);

	cout << "empleados procesados en forma individual, usando vinculacion estatica:\n\n";

	empAsalariado.imprimir();
	cout << "\nobtuvo $" << empAsalariado.ingresos() << "\n\n";

	empPorHoras.imprimir();
	cout << "\nobtuvo $" << empPorHoras.ingresos() << "\n\n";

	empPorComision.imprimir();
	cout << "\nobtuvo $" << empPorComision.ingresos() << "\n\n";

	empBaseMasComision.imprimir();
	cout << "\nobtuvo $" << empBaseMasComision.ingresos() << "\n\n";

	// crea un vector de 4 apuntadores de la clase base
	vector<Empleado*> empleados(4);

	// inicializa el vector con objetos empleado
	empleados[0] = &empAsalariado;
	empleados[1] = &empPorHoras;
	empleados[2] = &empPorComision;
	empleados[3] = &empBaseMasComision;

	cout << "Empleados procesados en forma poliformica mediante vinculacion dinamica:\n\n";

	// llama a virtualViaApuntador para imprimir la información de cada Empleado
	// y a ingresos mediante el uso de la vinculación dinámica
	cout << "Llamadas a funciones virtuales realizadas desde apuntadores de la clase base:\n\n";

	for (int i = 0; i < empleados.size(); i++)
		virtualViaApuntador(empleados[i]);

	// llama a virtualViaReferencia para imprimir la información de cada Empleado
	// y a ingresos mediante el uso de vinculación dinámica
	cout << "Llamadas a funciones virtuales realizadas desde referencias de la clase base:\n\n";

	for (int i = 0; i < empleados.size(); i++)
		virtualViaReferencia(*empleados[i]);	// observe la desreferencia

	return 0;
}

void virtualViaApuntador(const Empleado * const claseBasePtr)
{
	claseBasePtr->imprimir();
	cout << "\nobtuvo $" << claseBasePtr->ingresos() << "\n\n";
}

void virtualViaReferencia(const Empleado &claseBaseRef)
{
	claseBaseRef.imprimir();
	cout << "\nobtuvo $" << claseBaseRef.ingresos() << "\n\n";
}

