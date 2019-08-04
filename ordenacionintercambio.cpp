// ordenamiento por intercambio
#include <iostream>
using std::cout;
using std::endl;

void intercambio(int &, int &);
void ordenarPorIntercambio(int *, int);
void imprimir(int*, int);

int main()
{
	// array de 11 elementos
	int array[] = {10, 1, 11, 5, 7, 6, 4, 9, 3, 2, 8};

	cout << "Array sin ordenar.\n";
	imprimir(array, 11);

	cout << "Despues del ordenamiento.\n";
	ordenarPorIntercambio(array, 11);
	imprimir(array, 11);

	return 0;
}

void ordenarPorIntercambio(int *a, int tam)
{
	int i, j;

	for (i = 0; i < tam; i++)
	{
		for (j = i + 1; j < tam; j++)
		{
			if (a[i] > a[j])
				intercambio(a[i], a[j]);
		}
	}
}

void intercambio(int &a, int &b)
{
	int tmp = a;

	a = b;
	b = tmp;
}

void imprimir(int *a, int tam)
{
	int i;

	for (i = 0; i < tam; i++)
		cout << a[i] << " ";

	cout << endl;
}
