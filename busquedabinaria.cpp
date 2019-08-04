// ejemplo de busqueda binaria
#include <iostream>
using std::cout;
using std::endl;
using std::cin;

int busquedaBinaria(int *, int, int);
void imprimir(int*, int);

int main()
{
	// array de 10 elementos
	int array[] = {-5, -2, 1, 5, 7, 12, 15, 20, 78, 100};
	int clave;
	int indice = -1;

	cout << "Array:\n";
	imprimir(array, 10);

	cout << "Ingrese un nro a buscar.\n";
	cin >> clave;

	indice = busquedaBinaria(array, 10, clave);

	if (indice != -1)
		cout << "Elemento encontrado en la posicion. " << indice;
	else
		cout << "No se encontro el elemento. ";

	cout << endl;

	return 0;
}

int busquedaBinaria(int* a, int tam, int clave)
{
	int icentral;
	int alto, bajo;

	bajo = 0;
	alto = tam - 1;

	while (bajo <= alto)
	{
		icentral = (bajo + alto) / 2;

		if (a[icentral] == clave)
			return icentral;
		else if (clave > a[icentral])
			bajo = icentral + 1;
		else
			alto = icentral - 1;
	}

	return -1;
}

void imprimir(int* a, int tam)
{
	int i;

	for (i = 0; i < tam; i++)
		cout << a[i] << " ";

	cout << endl;
}
