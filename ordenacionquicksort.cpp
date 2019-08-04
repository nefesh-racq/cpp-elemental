// ejemplo ordenamiento quicksort
#include <iostream>
using std::cout;
using std::endl;

void quicksort(int a[], int, int);
void intercambio(int&, int&);
void imprimir(const int[], int);

int main()
{
	// array de 10 elementos
	int array[] = {5, 8, 10, 1, 4, 5, 10, 8, 1, 3};

	cout << "Array sin ordenar.\n";
	imprimir(array, 10);

	cout << "Despues de ordenar.\n";
	quicksort(array, 0, 9);
	imprimir(array, 10);

	return 0;
}

void quicksort(int a[], int primero, int ultimo)
{
	int i, j, central;
	int pivote;

	central = (primero + ultimo) / 2;
	pivote = a[central];
	i = primero;
	j = ultimo;

	do
	{
		while (a[i] < pivote) i++;
		while (a[j] > pivote) j--;

		if (i <= j)
		{
			intercambio(a[i], a[j]);
			i++;
			j--;
		}
	} while (i <= j);

	if (primero < j)
		quicksort(a, primero, j);	// sublista izquierda
	
	if (i < ultimo)
		quicksort(a, i, ultimo);	// sublista derecha
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