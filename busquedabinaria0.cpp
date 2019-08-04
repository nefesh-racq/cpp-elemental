// ejemplo busquda binaria
#include <vector>
using std::vector;

class BusquedaBinaria
{
public:
	BusquedaBinaria(int);
	int busquedaBinaria(int) const;
	void mostrarElementos() const;

private:
	int tamanio;		// tamaño vector
	vector<int> datos;	// vector de enteros

	void mostrarSubElementos(int, int) const;
};

/**************/
#include <iostream>
using std::cout;
using std::endl;

#include <cstdlib>
using std::rand;
using std::srand;

#include <ctime>
using std::time;

#include <algorithm>	// prototipo para la funcion sort
using std::sort;

// inicializamos el vector con valores aleatorios y luego los ordenamos
BusquedaBinaria::BusquedaBinaria(int tamanioVector)
{
	tamanio = (tamanioVector > 0 ? tamanioVector : 10); // tamaño por defecto 10
	srand(time(NULL));

	// llena el vector de datos aleatorios
	for (int i = 0; i < tamanio; i++)
		datos.push_back(10 + rand() % 90);	// 10 a 99

	std::sort(datos.begin(), datos.end());	// ordena el vector
}

// busqueda binaria
int BusquedaBinaria::busquedaBinaria(int clave) const
{
	int inferior = 0;
	int superior = tamanio;
	int centro = (inferior + superior + 1) / 2;
	int ubicacion = -1;

	do
	{
		// imprime el resto de los elementos del vector
		mostrarSubElementos(inferior, superior - 1);

		// imprime espacios para alineacion
		for (int i = 0; i < inferior; i++)
			cout << "   ";

		cout << " * " << endl;	// indica el elemento actual

		// si encenra el elemento en el medio
		if (clave == datos[centro])
			ubicacion = centro;		// ubicacion actual central
		else if (clave < datos[centro])
			superior = centro - 1;	// elemento esta en la parte inferior
		else
			inferior = centro + 1;	// elemento esta en la parte superior

		centro = (inferior + superior + 1) / 2;
	}
	while ((inferior <= superior) && (ubicacion == -1));

	return ubicacion;
}

// muestra los valores en el vector
void BusquedaBinaria::mostrarElementos() const
{
	mostrarSubElementos(0, tamanio - 1);
}

// muestra ciertos valores del vector
void BusquedaBinaria::mostrarSubElementos(int inferior, int superior) const
{
	for (int i = 0; i < inferior; i++)
		cout << "   ";

	for (int i = inferior; i <= superior; i++)
		cout << datos[i] << " ";

	cout << endl;
}

/**************/
#include <iostream>
using std::cin;
using std::cout;
using std::endl;

int main()
{
	int clave;		// clave para la busqueda
	int posicion;	// ubicacion del elemento(clave) a buscar

	// crea le vector y lo imprime
	BusquedaBinaria vectorb(15);

	vectorb.mostrarElementos();
	// obtiene la entrada del usuario
	cout << "\nEscriba un valor entero (-1 para terminar):\n? ";
	cin >> clave;
	cout << endl;

	// lee un entero en forma repetida -1 para terminar
	while (clave != -1)
	{
		// usa la busqueda binaraia para la busqueda
		posicion = vectorb.busquedaBinaria(clave);

		// si posicion es -1 indica que no existe el elemento
		if (posicion == -1)
			cout << "El elemento no existe.." << endl;
		else
			cout << "Elemento " << clave << " encontrado en la "
				<< "posicion " << posicion << endl;

		// obtiene la entrada del usuario
		cout << "\nEscriba un valor entero (-1 para terminar):\n? ";
		cin >> clave;
		cout << endl;
	}

	return 0;
}
