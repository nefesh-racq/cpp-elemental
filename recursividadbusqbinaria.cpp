// busqueda binaria funcion recursiva
#include <iostream>
using namespace std;

int busquedaBinaria(double [], double, int, int);

int main()
{
	// array de 7 elementos
	double array[] = {10.10, 11.11, 12.12, 13.13, 14.14, 15.15, 16.16};
	int dato = -1;

	dato = busquedaBinaria(array, 12.12, 0, 7);

	if (dato != -1)
		cout << "elemento encontrado (posicion: " << dato << ")" << endl;

	return 0;

}

int busquedaBinaria(double a[], double dato, int inicio, int fin)
{
	int central;

	if (inicio > fin)
		return -1;
	else
	{
		central = (inicio + fin) / 2;

		if (a[central] == dato)
			return central;
		else if (a[central] < dato)
			return busquedaBinaria(a, dato, central + 1, fin);
		else
			return busquedaBinaria(a, dato, inicio, central -1);
	}
}