#include <iostream>
using std::cout;
using std::cin;
using std::endl;

int busquedaLineal(const int[], int, int);

int main() {
	const int TAM = 100;
	int claveBusqueda;
	int a[TAM];

	for (int i = 0; i < TAM; i++) {
		a[i] = 2 * i;
		cout << a[i] << " ";
	}

	cout << "\nIntrodusca la clave de busqueda entera ";
	cin >> claveBusqueda;

	int elemento = busquedaLineal(a, claveBusqueda, TAM);

	if (elemento != -1)
		cout << "Se encontro el valor " << elemento << endl;
	else
		cout << "No se encontro el valor" << endl;

	return 0;
}

int busquedaLineal(const int a[], int cBusqueda, int tam) {
	for (int j = 0; j < tam; j++) {
		if (a[j] == cBusqueda)
			return a[j];	// retorna el valor encontrado y termina el bucle
	}

	return -1;	// retorna -1 en caso de no encontrarse
}

