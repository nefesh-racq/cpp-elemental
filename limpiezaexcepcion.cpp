// demostracion de la limpieza de la pila, excepciones
#include <iostream>
using std::cout;
using std::endl;

#include <stdexcept>
using std::runtime_error;

// funciones3 lanza error en tiempo de ejecucion
void funcion3() throw (runtime_error)
{
	cout << "En la funcion 3" << endl;
	// no hay bloque try, se realiza la limpieza de la pila
	// devuelve el control a la funcion2
	throw runtime_error("runtime_error en la funcion3");	// no imprime
}

// funcion2 invoca a funcion3
void funcion2() throw (runtime_error)
{
	cout << "funcion3 se llama dentro de la funcion2" << endl;
	funcion3();	// se realilza la limpieza de la pila, devuelve el control
				// a funcion1
}

// funcion1 invoca a funcion2
void funcion1() throw (runtime_error)
{
	cout << "funcion2 se llama dentro de funcion1" << endl;
	funcion2();	// se realiza la limpieza de la pila
				// devuelve el control a main
}

// demuestra la limpieza de la pila
int main()
{
	// invoca funcion1
	try
	{
		cout << "funcion1 se llama dentro de main" << endl;
		funcion1();	// llama funcion1, que lanza runtime_error
	}
	catch (runtime_error &error)
	{
		cout << "Ocurrio una excepcion: " << error.what() << endl;
		cout << "La excepcion se manejo en main" << endl;
	}

	return 0;
}
