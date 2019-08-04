// programa de ordenamiento multiproposito que usa apuntadores
// a una funcion
#include <iostream>
using std::cout;
using std::cin;
using std::endl;

#include <iomanip>
using std::setw;

// prototipos de funciones
void ordenarSeleccion(int [],  const int, bool (*)(int, int));
void intercambiar(int * const, int * const);
bool ascendente(int, int);	// para el ordenamiento ascendente
bool descendente(int, int);	// para el ordenamiento descendente

int main()
{
	const int TAM = 10;
	int orden;		// 1 ascendente, 2 descendente
	int contador;	// subindice del arreglo
	int a[TAM] = {2, 6, 4, 8, 10, 12, 89, 68, 45, 37};

	cout << "Escribe 1 para ordenar ascendente.\n"
		<< "Escriba 2 para ordenar descendente: ";
	cin >> orden;
	cout << "\nElementos de datos en el orden original\n";
	
	// imprime el arreglo original
	for (contador = 0; contador < TAM; contador++)
		cout << setw(4) << a[contador];

	// ordena el arreglo en forma ascendente; pasa la funcion ascendente
	// como un argumento para especificar el orden ascendente
	if (orden == 1)
	{
		ordenarSeleccion(a, TAM, ascendente);
		cout << "\nElementos de datos en orden ascendente\n";
	}
	else	// ordena el arreglo en forma descendente pasa la fun descendente
	{
		ordenarSeleccion(a, TAM, descendente);
		cout << "\nElementos de datos en orden descendente\n";
	}

	// imprimimos el arreglo ya ordenano
	for (contador = 0; contador < TAM; contador++)
		cout << setw(4) << a[contador];

	cout << endl;

	return 0;
}

// ordenamiento por seleccion
void ordenarSeleccion(int trabajo[], const int tam, bool (*compara)(int, int))
{
	int menorOMayor;	// indice del elemento mas pequeño

	// recorre el tamaño - 1 elementos
	for (int i = 0; i < tam - 1; i++)
	{
		menorOMayor = i;	// primer indice para el arreglo mas pequeño

		// reccore para encontrar el indice del elemento mas pequeño
		for (int index = i + 1; index < tam; index++)
			if (!(*compara)(trabajo[menorOMayor], trabajo[index]))
				menorOMayor = index;

		intercambiar(&trabajo[menorOMayor], &trabajo[i]);
	}
}

void intercambiar(int * const a, int * const b)
{
	int tmp = *a;

	*a = *b;
	*b = tmp;
}

// comparacion para el ordenamiento ascendente
bool ascendente(int a, int b)
{
	return a < b;
}

// comparacion para el odenamieno descendente
bool descendente(int a, int b)
{
	return a > b;
}

