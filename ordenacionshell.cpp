// ejemplo de ordenacion shell
#include <iostream>
using std::cout;
using std::endl;

void ordenacionShell(int [], int);
void intercambio(int&, int&);
void imprimir(const int[], int);

int main()
{
	// array de 10 elementos
	int array[] = {10, 55, 1, 7, 2, 9, 4, 6, 3, 14};

	cout << "Array sin ordenar.\n";
	imprimir(array, 10);

	cout << "Despues de la ordenacion.\n";
	ordenacionShell(array, 10);
	imprimir(array, 10);

	return 0;
}

void ordenacionShell(int a[], int tam)
{
	int salto, i, j, k;

	salto = tam / 2;

	while (salto > 0)
	{
		for (i = salto; i < tam; i++)
		{
			j = i - salto;

			while (j >= 0)
			{
				k = j + salto;

				if (a[j] <= a[k])
					j = -1;		// par de elementos ordenados
				else
				{
					intercambio(a[j], a[j + 1]);
					j -= salto;
				}
			}
		}

		salto = salto / 2;
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