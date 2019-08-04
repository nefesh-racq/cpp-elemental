/*
 uso de plantillas para imprimir un array
*/
#include <iostream>
using std::cout;
using std::endl;

// definicion de la plantilla funcion imprimir
template <typename T>
void imprimirArreglo(const T* const arreglo, int cuenta)
{
	for (int i = 0; i < cuenta; i++)
		cout << arreglo[i] << " ";

	cout << endl;
}

int main()
{
	const int aCta = 5;
	const int bCta = 7;
	const int cCta = 6;

	int a[aCta] = {1, 2, 3, 4, 5 };
	double b[bCta] = {1.1, 2.2, 3.3, 4.4, 5.5, 6.6, 7.7};
	char c[cCta] = "HOLA";

	cout << "El arreglo a contiene: " << endl;

	// llama a la especilizacion de plantilla para enteros
	imprimirArreglo(a, aCta);

	cout << "El arreglo b contiene: " << endl;
	// llama a la funcion para tipos double
	imprimirArreglo(b, bCta);

	cout << "El arreglo c contiene: " << endl;
	// llama a la funcion para datos de tipo char
	imprimirArreglo(c, cCta);

	return 0;
}
