// intento de modificar un apuntador constante a un dato constante
#include <iostream>
using std::cout;
using std::endl;

int main()
{
	int x = 5, y;

	// ptr es un apuntador constante a un entero constante
	// ptr siempre apunta a la misma ubicacion, el entero en esa
	// ubicacion no se puede modificar
	const int *const ptr = &x;

	cout << *ptr << endl;

	*ptr = 7;	// error *ptr es const, no se puede asignar un nuevo valor
	ptr = &y;	// error: ptr es const, no se puede asignar una nueva direccion

	return 0;
}

