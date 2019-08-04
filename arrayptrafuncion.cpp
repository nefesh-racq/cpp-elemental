// demostracion de un arreglo de apuntadores a funciones
#include <iostream>
using std::cout;
using std::cin;
using std::endl;

void funcion0(int);
void funcion1(int);
void funcion2(int);

int main()
{
	// inicializa un arreglo de 3 punteros a funciones.
	// cada una recibe un argumento int y devuelve void
	void (*f[3])(int) = {funcion0, funcion1, funcion2};

	int opcion;

	cout << "Escriba un numero entre 0 y 2, 3 para terminar : ";
	cin >> opcion;

	while ((opcion >= 0) && (opcion < 3))
	{
		// invoca la funcion en el arreglo segun el indice opcion
		// del arreglo f, y pasa la opcion como argumento
		(*f[opcion])(opcion);

		cout << "Escriba un numero entre 0 y 2, 3 para terminar : ";
		cin >> opcion;
	}

	cout << "Se completo la ejecucion del programa." << endl;

	return 0;
}

void funcion0(int b)
{
	cout << "Usted escribio " << b << " por eso se llamo a funcion0()\n\n";
}

void funcion1(int b)
{
	cout << "Usted escribio " << b << " por eso se llamo a funcion1()\n\n";
}

void funcion2(int b)
{
	cout << "Usted escribio " << b << " por eso se llamo a la funcion2()\n\n";
}

