// demostracion de la justificacion a la izquierda y derecha
#include <iostream>
using std::cout;
using std::endl;
using std::left;
using std::right;

#include <iomanip>
using std::setw;

int main()
{
	int x = 12345;

	// muestra el valor de x justificado a la derecha (predeterminado)
	cout << "La opcion predeterminada es justificada a al derecha:"
		<< endl << setw(10) << x;

	// usa el manipulador left para mostrar el valor a la izquierda
	cout << "\n\nUso de std::left para justificar x a la izquierda"
		<< endl << left << setw(10) << x;

	// usa el manipulador right para mostrar el valor  de x
	// justificado a la derecha
	cout << "\n\nUso de std::right para justificar x a la derecha:"
		<< endl << right << setw(10) << x << endl;

	return 0;
}
