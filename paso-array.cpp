#include <iostream>
using std::cout;
using std::endl;

void modificarArreglo(int [], int);	// el arreglo es pasado por referencia
void imprimirArreglo(int [], int);	// el arreglo es pasado por referencia
void modificarElemento(int);		// el elemento del arreglo es pasdo por valor

int main() {
	int array[] = {1, 2, 3, 4, 5, 6};

	cout << "el array es\n";
	imprimirArreglo(array, 6);

	cout << "\nmodificando el array\n";
	modificarArreglo(array, 6);
	imprimirArreglo(array, 6);
	cout << endl;

	cout << "\ntratando de modificar el elemento\narray[3] = " << array[3] << endl;
	modificarElemento(array[3]);
	cout << "\nel elemento ahora es array[3] = " << array[3] << endl;

	return 0;
}


void modificarArreglo(int a[], int tam) {
	for (int i = 0; i < tam; i++)
		a[i] += i * 4;
}

void imprimirArreglo(int a[], int tam) {
	for (int i = 0; i < tam; i++)
		cout << a[i] << " ";
}

void modificarElemento(int a) {
	a = 1111;
}
