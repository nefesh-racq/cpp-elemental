// uso de showpoint para controlar la impresoin
// ceros a la derecha y puntos decimales para valores doble
#include <iostream>
using std::cout;
using std::endl;
using std::showpoint;

int main()
{
	// muestra los valores double con formato de flujo predeterminado
	cout << "Antes de usar showpoint" << endl
		<< "9.9900 se imprime como: " << 9.9900 << endl
		<< "9.9000 se imprime como: " << 9.9000 << endl
		<< "9.0000 se imprime como: " << 9.0000 << endl;

	// muestra el valor double despues de showpoint
	cout << showpoint
		<< "Despues de usar showpoint" << endl
		<< "9.9900 se imprime como: " << 9.9900 << endl
		<< "9.9000 se imprime como: " << 9.9000 << endl
		<< "9.0000 se imprime como: " << 9.0000 << endl;

	return 0;
}