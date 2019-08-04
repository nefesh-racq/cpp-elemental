// demostracion de la funcion miembro flags
#include <iostream>
using std::cout;
using std::endl;
using std::ios_base;
using std::oct;
using std::scientific;
using std::showbase;

int main()
{
	int valorEntero = 1000;
	double valorDouble = 0.0947628;

	// muestra valores int y double (formato original)
	cout << "El valor de la variable flags es: " << cout.flags()
		<< "\nImpresion de int y double en formato original.\n"
		<< valorEntero << '\t' << valorDouble << endl << endl;

	// usa la funcion flags de cout para guardar el formato original
	ios_base::fmtflags formatoOriginal = cout.flags();
	cout << showbase << oct << scientific;	// cambia el formato

	// muestra los valores de flags, int y double (nuevo formato)
	cout << "El valor de la variable flags es: " << cout.flags()
		<< "\nImpresion de int y double en nuevo formato:\n"
		<< valorEntero << '\t' << valorDouble << endl << endl;

	cout.flags(formatoOriginal);	// restaura el formato

	// muestra el valor de flags, int y double (formato original)
	cout << "El valor restaurado de la variable flags es:\n"
		<< cout.flags()
		<< "\nImpresion de los valores en su formato origina otra vez:\n"
		<< valorEntero << '\t' << valorDouble << endl << endl;

	return 0;
}
