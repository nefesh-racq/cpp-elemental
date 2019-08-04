// control de precisión de los valores de punto flotante
#include <iostream>
using std::cout;
using std::endl;
using std::fixed;

#include <iomanip>
using std::setprecision;

#include <cmath>
using std::sqrt;	// prototipo sqrt para raicez

int main()
{
	double raiz2 = sqrt(2.0);	// calcula la raiz cuadrada de 2
	int posiciones;				// precision, varia de 0 a 9

	cout << "Raiz cuadrada de 2 con precision de 0 - 9: " << endl
		<< "Precision establecida mediante la funcion miembro precision "
		<< " de ios_base: " << endl;

	cout << fixed;	// usa el formato de punto flotante fijo

	// muestra la raiz cuadrada usando la funcion precision de ios_base
	for (posiciones = 0; posiciones <= 9; posiciones++)
	{
		cout.precision(posiciones);
		cout << raiz2 << endl;
	}

	cout << "\nPrecision establecida por el manipulador de flujo "
		<< "setprecision: " << endl;

	// establece la precision para cada digito, y despues muestra
	// la raiz cuadrada
	for (posiciones = 0; posiciones <= 9; posiciones++)
		cout << setprecision(posiciones) << raiz2 << endl;

	return 0;
}
