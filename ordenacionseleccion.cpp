// ejemplo de ordenamiento por seleccion
#include <iostream>
using std::cout;
using std::endl;

void ordenarPorSeleccion(int*, int);
void intercambio(int&, int&);
void imprimir(const int[], int);

int main()
{
	// array de 10 elementos
	int array[] = {5, 1, 10, 4, 8, 3, 9, 2, 6, 7};

	cout << "Array original.\n";
	imprimir(array, 10);

	cout << "Despues de ordenar.\n";
	ordenarPorSeleccion(array, 10);
	imprimir(array, 10);

	return 0;
}

void ordenarPorSeleccion(int* a, int tam)
{
	int indiceMin;
	int i, j;

	for (i = 0; i < tam - 1; i++)
	{
		indiceMin = i;

		for (j = i + 1; j < tam; j++)
		{
			if (a[j] < a[indiceMin])
				indiceMin = j;
		}

		if (i != indiceMin)
			intercambio(a[i], a[indiceMin]);
	}
}

void intercambio(int& a, int& b)
{
	int temp = a;

	a = b;
	b = temp;
}

void imprimir(const int a[], int tam)
{
	int i;

	for (i = 0; i < tam; i++)
		cout << a[i] << " ";

	cout << endl;
}
