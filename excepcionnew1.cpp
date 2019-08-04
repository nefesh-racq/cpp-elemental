// estos ejemplos no dan error por que hay mucha memoria
#include <iostream>
using std::cerr;
using std::cout;
using std::endl;

#include <new>	// operador new estandar
using std::bad_alloc;

int main()
{
	double *ptr[50];

	// orienta cada ptr[i] a un bloque extenso de memoria
	try
	{
		// asigna memoria a ptr; new lanza bad_alloc al fallar
		for (int i = 0; i < 50; i++)
		{
			ptr[i] = new double[50000000];	// puede lanzar una excepion
			cout << "ptr[" << i << "] apunta a 50,000,000 nuevos valores double\n";
		}
	}
	catch (bad_alloc &e)
	{
		cerr << "Ocurrio una excepcion: "
			<< e.what() << endl;
	}

	return 0;
}
