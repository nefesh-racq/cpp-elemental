// ejemplo excepcion
// demotracion de como volve a lanzar excepciones
#include <iostream>
using std::cout;
using std::endl;

#include <exception>
using std::exception;

// lanza, atrapada y vuelve a lanzar la excepcion
void lanzarExcepcion()
{
	// lanza la excepcino y la atrapa de inmediato
	try
	{
		cout << "  la funcion lanzarExcepcion lanza una excepcion\n";
		throw exception();	// genera la excepcion
	}
	catch (exception &)		// maneja la excepcion
	{
		cout << "  La excepcion se maneja en la funcion lanzarExcepcion"
			<< "\n  La funcion lanzarExcepcion vuelve a lanzar la excepcion";

		throw;	// vuelve a lanzar la excepcion para seguir porcesandola
	}

	cout << "Esto tampoco se debe imprimir\n";
}

int main()
{
	// lanza la excepcion
	try
	{
		cout << "\nmain invoca a la funcion lanzarExcepcion\n";
		lanzarExcepcion();
		cout << "Esto no se debe imprimir\n";
	}
	catch (exception &)	// maneja la excepcion
	{
		cout << "\n\nLa excepcion se manejo en main\n";
	}

	cout << "El control del programa continua despues de catch en main\n";

	return 0;
}
