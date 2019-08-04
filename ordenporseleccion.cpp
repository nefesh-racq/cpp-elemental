// ordenamiento por seleccion con paso por referencia
#include <iostream>
using std::endl;
using std::cout;

#include <iomanip>
using std::setw;

void ordenSeleccion(int *const, const int);
void intercambiar(int * const, int * const);

int main()
{
	const int TAM = 10;
	int a[TAM] = {5, 10, 9, 4, 6, 7, 8, 3, 2, 1};

	cout << "el arreglo en el orden original es" << endl;

	for (int i = 0; i < TAM; i++)
		cout << setw(4) << a[i];

	ordenSeleccion(a, TAM);

	cout << "\nElementos ordenados" << endl;

	for (int j = 0; j < TAM; j++)
		cout << setw(4) << a[j];

	cout << endl;

	return 0;
}

void ordenSeleccion(int * const arreglo, const int tam)
{
	int menor;

	for (int i = 0; i < tam; i++)
	{
		menor = i;

		for (int subindice = i + 1; subindice < tam; subindice++)
			if (arreglo[subindice] < arreglo[menor])
				menor = subindice;

		intercambiar(&arreglo[i], &arreglo[menor]);
	}
}

void intercambiar(int *const a, int *const b)
{
	int tmp = *a;

	*a = *b;
	*b = tmp;
}

