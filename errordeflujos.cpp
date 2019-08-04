// prueba de los estados de error
#include <iostream>
using std::cin;
using std::cout;
using std::endl;

int main()
{
	int valorEntero;

	// muestra los resultados de las funciones cin
	cout << "Antes de una operacion de entrada incorrecta:"
		<< "\ncin.rdstate(): " << cin.rdstate()
		<< "\n    cin.eof(): " << cin.eof()
		<< "\n   cin.fail(): " << cin.fail()
		<< "\n    cin.bad(): " << cin.bad()
		<< "\n   cin.good(): " << cin.good()
		<< "\n\nEspera un entero, pero se introduce caracter: ";

	cin >> valorEntero;	// escribe el valor tipo caracter
	cout << endl;

	// muestra los resultados de las funciones de cin despues de una
	// entrada incorrecta
	cout << "Despues de una operacion de entrada incorrecta:"
		<< "\ncin.rdstate(): " << cin.rdstate()
		<< "\n    cin.eof(): " << cin.eof()
		<< "\n   cin.fail(): " << cin.fail()
		<< "\n    cin.bad(): " << cin.bad()
		<< "\n   cin.good(): " << cin.good() << endl << endl;

	cin.clear();	// borra el flujo

	// muestra los resultados de las funciones de cin
	cout << "Despues de cin.clear()" << "\ncni.fail(): " << cin.fail()
		<< "\ncin.good(): " << cin.good() << endl;

	return 0;
}
