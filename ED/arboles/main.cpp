#include <iostream>
using std::cout;
using std::cin;
using std::fixed;

#include <iomanip>
using std::setprecision;

#include "Arbol.h"

int main()
{
	Arbol<int> arbolInt;
	int valorEntero;

	cout << "Escriba 10 valores enteros:\n";

	for (int i = 0; i < 10; i++)
	{
		cin >> valorEntero;
		arbolInt.insertarNodo(valorEntero);
	}

	cout << "\nRecorrido preorden\n";
	arbolInt.recorridoPreOrden();

	cout << "\nRecorrido inorden\n";
	arbolInt.recorridoInOrden();

	cout << "\nRecorrido postorden\n";
	arbolInt.recorridoPostOrden();

	/* arbol double */
	Arbol<double> arbolDouble;
	double valorDouble;

	cout << fixed << setprecision(1);
	cout << "\nEscriba 10 valores doubles:\n";

	for (int i = 0; i < 10; i++)
	{
		cin >> valorDouble;
		arbolDouble.insertarNodo(valorDouble);
	}

	cout << "\nRecorrido preorden\n";
	arbolDouble.recorridoPreOrden();

	cout << "\nRecorrido inorden\n";
	arbolDouble.recorridoInOrden();

	cout << "\nRecorrido postorden\n";
	arbolDouble.recorridoPostOrden();

	cout << endl;

	return 0;
}