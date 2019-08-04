// impresion de la direccion de memoria en una variable char*
#include <iostream>
using std::cout;
using std::endl;

int main()
{
	char* palabra = "nuevamente";

	// muestra el valor char *, y despues muestra el valor
	// de char * sttic_cast a void *
	cout << "El valor de la palabra es: " << palabra << endl
		<< "El valor de static_cast<void*>(palabra) es: "
		<< static_cast<void*>(palabra) << endl;

	return 0;
}
