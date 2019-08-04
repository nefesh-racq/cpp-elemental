// demostracino de set_new_handler
// los resultados pueden variar dependiendo de la memoria
// disponible en el computador, y el compilador que se usa
#include <iostream>
using std::cerr;
using std::cout;

#include <new>	// operador new estandar y set_new_handler
using std::set_new_handler;

#include <cstdlib>	// prototipo funcion abort
using std::abort;

// maneja la caracteristica de asignacion de memoria
void nuevoManejadorPersonalizado()
{
	cerr << "Se llamo a nuevoManejadorPersonalizado";
	abort();
}

// usode set_new_handler para manejar la asignacion de memoria fallida
int main()
{
	double *ptr[50];

	// especifica que se debe llamar a nuevoManejadorPersoonalizado
	// al fallar la asignacion de memoria
	set_new_handler(nuevoManejadorPersonalizado);

	// orienta cada ptr a un bloque extenso de memoria; se llama a
	// nuevoManejadorPersonalizado al fallar la asignacion de memoria
	for (int i = 0; i < 50; i++)
	{
		ptr[i] = new double[50000000];	// puede lanzar una excepcin
		cout << "ptr[" << i << "] apunta a 50,000,000 nuevos valores double\n";
	}

	return 0;
}
