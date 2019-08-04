// ejemplo ordenamiento burbuja
#include <iostream>
using std::cout;
using std::endl;

void ordenarBurbuja(int [], int);
void intercambio(int&, int&);
void imprimir(const int*, int);

int main()
{
	// array de 10 elementos
	int array[] = {5, 8, 10, 1, 4, 5, 10, 8, 1, 3};

	cout << "Array sin ordenar.\n";
	imprimir(array, 10);

	cout << "Despues de ordenar.\n";
	ordenarBurbuja(array, 10);
	imprimir(array, 10);

	return 0;
}

void ordenarBurbuja(int a[], int tam)
{
	bool interruptor = true;
	int pasada, j;

	// bucle externo controla la cantidad de pasadas
	for (pasada = 0; pasada < tam -1 && interruptor; pasada++)
	{
		interruptor = false;

		for (j = 0; j < tam - pasada - 1; j++)
			if (a[j] > a[j + 1])
			{
				// elementos desordenados, se intercambia+
				interruptor = true;
				intercambio(a[j], a[j + 1]);
			}
	}
}

void intercambio(int& a, int& b)
{
	int temp = a;

	a = b;
	b = temp;
}

void imprimir(const int* a, int tam)
{
	int i;

	for (i = 0; i < tam; i++)
		cout << a[i] << " ";

	cout << endl;
}
