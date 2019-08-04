// definicion de las funciones miembro de la clase Vendedor
#include <iostream>
using std::cout;
using std::cin;
using std::endl;
using std::fixed;

#include <iomanip>
using std::setprecision;

#include "Vendedor.h"	// incluye la deficion de la clase

// inicializamos los datos en el constructor
Vendedor::Vendedor()
{
	for (int i = 0; i < 12; i++)
		ventas[i] = 0.0;
}

void Vendedor::obtenerVentasDelUsuario()
{
	double cifraVentas;

	for (int i = 1; i <= 12; i++)
	{
		cout << "Escriba el monto de ventas para el mes " << i << ": ";
		cin >> cifraVentas;

		establecerVentas(i, cifraVentas);
	}
}

// establece una de las 12 cifras de ventas mensuales:
// se resta 1 al mes para el subindice en el arreglo
void Vendedor::establecerVentas(int mes, double monto)
{
	// prueba que los valores de mes y monto sean validos
	if (mes >= 1 && mes <= 12 && monto > 0)
		ventas[mes -1] = monto;
	else
		cout << "Mes o cifra de ventas invalidos" << endl;
}

// imprime el total de ventas anuales usando la funcion utilitaria
void Vendedor::imprimirVentasAnuales()
{
	cout << setprecision(2) << fixed
		<< "\nLas ventas anuales totales son : $"
		<< totalVentasAnuales() << endl;
}

// funcion utilitaria privada para totalizar las ventas anuales
double Vendedor::totalVentasAnuales()
{
	double total = 0.0;		// inicializamos el total

	for (int i = 0; i < 12; i++)
		total += ventas[i];

	return total;
}

