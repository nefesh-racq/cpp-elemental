#include <iostream>
using std::endl;
using std::cout;

#include <ctime>
using std::time;

#include <cstdlib>
using std::srand;
using std::rand;

void ordenamientoInsercion(int [], int);
void ordenInsercion(int [], int);

int main() {
	const int TAM = 20;
	int datos[TAM] = {};
	srand(time(NULL));

	cout << "el arreglo sin ordenar es." << endl;

	for (int i = 0; i < TAM; i++) {
		datos[i] = 1 + rand() % 100;
		cout << datos[i] << " ";
	}
	
	cout << endl;
	ordenamientoInsercion(datos, TAM);
	//ordenInsercion(datos, TAM);
	cout << "el arreglo ordenado es. " << endl;
	
	for (int j = 0; j < TAM; j++)
		cout << datos[j] << " ";

	cout << endl;

	return 0;
}

void ordenamientoInsercion(int a[], int tam) {
	int temp = 0;

	for (int i = 0; i < tam; i++) 	{
		for (int j = i + 1; j < tam; j++) {
			if (a[i] > a[j]) {
				temp = a[i];
				a[i] = a[j];
				a[j] = temp;
			}				
		}
	}
}


void ordenInsercion(int a[], int tam) {
	int insertar = 0;

	for (int sgte = 1; sgte < tam; sgte++) {
		insertar = a[sgte];	// almacena el valor con el elemento actual

		int moverElemento = sgte;	// inicializa la ubicación

		// busca la ubicación en la que va a colocr el elemento actual
		while ((moverElemento > 0) && (a[moverElemento - 1] > insertar)) {
			a[moverElemento] = a[moverElemento - 1];
			moverElemento--;
		}

		a[moverElemento] = insertar;
	}
}

