// ejemplo de ordenacion y busqueda "eliminar elementos repetidos de una lista"
#include <iostream>
using std::cout;
using std::endl;

void eliminarDobles(int[], int&);
void imprimir(int[], int);

int main()
{
	// arrray de 10 elementos
	int array[] = {4, 4, 4, 7, 11, 4, 9, 9, 9, 5, 11, 7, 3, 5, 5, 5};
	int tam = 16;

	cout << "Array original.\n";
	imprimir(array, tam);

	cout << "Despues de eliminar los repetidos.\n";
	eliminarDobles(array, tam);
	imprimir(array, tam);

	return 0;
}


// posicionarse en primer elemento y recorrer la lista
// si se encuentra una coincidencia recorremos los elementos
// eliminando ese elemento repetido
void eliminarDobles(int a[], int& tam)
{
	int i, j;
	int elemento;
	int recorrido;

	// recorremos el array/lista
	for (i = 0; i < tam; i++)
	{
		// hacemos el recorrido para la comparacion de los elementos
		// repetidos en la lista
		for (j = i + 1; j < tam; j++)
		{
			// comparamos los elementos si son iguales
			// para poder hacer un recorrido de los elementos
			// y eliminar el elemento repetido
			if (a[i] == a[j])
			{
				recorrido = j;	// variable para hacer el recorrido

				// hacemos el recorrido de los elementos de la
				// lista para eliminar el elemento repetido
				while (recorrido > i && recorrido + 1 < tam)
				{
					a[recorrido] = a[recorrido + 1];
					recorrido++;
				}

				// reducimos el tamaño de la lista ya que se
				// recorrio la lista y
				// decrementamos j para poder comparar el elemento
				// que se recorrio a esa posicion
				tam--;
				j--;
			}
		}
	}
}

void imprimir(int a[], int tam)
{
	int i;

	for (i = 0; i < tam; i++)
		cout << a[i] << " ";

	cout << endl;
}
