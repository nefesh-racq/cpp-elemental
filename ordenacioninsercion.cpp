// ejemplo de ordenacion por insercion
#include <iostream>
using std::cout;
using std::endl;

void ordenacionInsercion(int [], int);
void imprimir(const int[], int);

int main()
{
	// array de 10 elementos
	int array[] = {10, 5, 3, 7, 2, 9, 8, 6, 4, 1};

	cout << "Array original.\n";
	imprimir(array, 10);

	cout << "Despues de ordenar.\n";
	ordenacionInsercion(array, 10);
	imprimir(array, 10);

	return 0;
}

void ordenacionInsercion(int a[], int tam)
{
	int i, j, temp;

	for (i = 1; i < tam; i++)
	{
		/*
		 indice j es para explorar la sublista buscando la posicion
		 correcta del elemento destino
		*/
		j = i;
		temp = a[i];

		// se localiza el punto de insercion hacia abajo
		while (j > 0 && temp < a[j - 1])
		{
			// desplazar elementos hacia arriba para hacer espacio
			a[j] = a[j - 1];
			j--;
		}

		a[j] = temp;
	}
}

void imprimir(const int a[], int tam)
{
	int i;

	for (i = 0; i < tam; i++)
		cout << a[i] << " ";


	cout << endl;
}
