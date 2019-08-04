// demostracion de la funcion new previa al estandar que devuelve 0
// cuando falla la asignacion de memoria
// la excepcion devuelve 0, en gcc
// estos ejemplos no dan error por que hay mucha memoria
#include <iostream>
using std::cerr;
using std::cout;

int main()
{
	double *ptr[50];

	// arienta cada ptr[] a un bloque extenso de memoria
	for (int i = 0; i < 50; i++)
	{
		ptr[i] = new double[50000000];	// asigna un bloque extenso

		if (ptr[i] == 0)	// ¿fallo new al asignar la memoria?
		{
			cerr << "La asignacion de memoria fallo para ptr["
				<< i << "]\n";
			break;
		}
		else	// asignacion de memoria exitosa
			cout << "ptr[" << i << "] apunta a 50.000.000 valores double\n";
	}

	return 0;
}
