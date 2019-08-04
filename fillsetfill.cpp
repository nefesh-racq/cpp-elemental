// uso de la funcion miembro fill y el manipulador de flujo
// setfill para cambiar el caracter de relleno para campos mas
// grandes que el valor de relleno
#include <iostream>
using std::cout;
using std::dec;
using std::hex;
using std::left;
using std::right;
using std::endl;
using std::internal;
using std::showbase;

#include <iomanip>
using std::setw;
using std::setfill;

int main()
{
	int x = 10000;

	// muestra x
	cout << x << " impreso con int justificado a la derecha y a la izquierda"
		<< endl << "y como hex con justificacion interna.\n"
		<< "Uso del caracter de relleno predeterminado (espacio):"
		<< endl;

	// muestra x con la base
	cout << showbase << setw(10) << x << endl;

	// muestra x con justificacion a la izquierda
	cout << left << setw(10) << x << endl;

	// muestra x con la hex con la justificacion interna
	cout << internal << setw(10) << hex << x << "\n\n";

	cout << "Uso de varios caracteres de relleno:\n";

	// muestra x usando caracteres de relleno (justificacion a la derecha)
	cout << right;
	cout.fill('*');
	cout << setw(10) << dec << x << endl;

	// muestra x usando caracteres de relleno (justficacion a la izquierda)
	cout << left << setw(10) << setfill('%') << x << endl;

	// muestra x usando caracteres de relleno (justificacion interna)
	cout << internal << setw(10) << setfill('A') << hex
		<< x << endl;

	return 0;
}