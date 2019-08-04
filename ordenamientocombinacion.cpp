// ejemplo ordenamiento por combinacion
#include <vector>
using std::vector;

class OrdenamientoCombinacion
{
public:
	OrdenamientoCombinacion(int);
	void ordenar();
	void mostrarElementos() const;

private:
	int tamanio;
	vector<int> datos;

	void ordenarSubVector(int, int);
	void combinar(int, int, int, int);
	void mostrarSubVector(int, int) const;
};

#include <iostream>
using std::cout;
using std::endl;

#include <vector>
using std::vector;

#include <cstdlib>
using std::rand;
using std::srand;

#include <ctime>
using std::time;

OrdenamientoCombinacion::OrdenamientoCombinacion(int tam)
{
	tamanio = (tam > 0 ? tam : 10);
	srand(time(0));	// srand(time(NULL)) tb es valido

	// llena el vector con valores inte aleatorios entre 10 y 99
	for (int i = 0; i < tam; i++)
		datos.push_back(10 + rand() % 90);
}

// divide el vector, ordena los subvectores y los 
// combina en un vector ordenado
void OrdenamientoCombinacion::ordenar()
{
	ordenarSubVector(0, tamanio - 1);	// ordena el vector en forma recursiva
}

// funcion recursiva para ordenar los subvectores
void OrdenamientoCombinacion::ordenarSubVector(int inferior, int superior)
{
	// comprueba el caso base, tamaño de vector = 1
	// si no es caso base
	if ((superior - inferior) >= 1)
	{
		int medio1 = (inferior + superior) / 2;	// elemento medio
		int medio2 = medio1 + 1;	// elemento arriba del medio

		// imprimimos el paso de division
		cout << " division:   ";
		mostrarSubVector(inferior, superior);
		cout << endl << "             ";
		mostrarSubVector(inferior, medio1);
		cout << endl << "             ";
		mostrarSubVector(medio2, superior);
		cout << endl << endl;

		// dive el vector en dos y ordena cada mitad
		// usa llamadas recursivas
		ordenarSubVector(inferior, medio1);	// primera mitad
		ordenarSubVector(medio2, superior);	// segunda mitad

		// combina dos vectores ordenados despues del regreso de
		// la llamada de division
		combinar(inferior, medio1, medio2, superior);
	}
}

// combina dos subvectores ordenados en un subvctor ordenado
void OrdenamientoCombinacion::combinar(int izquierda, int medio1, 
										int medio2, int derecha)
{
	int indiceIzdo = izquierda;	// subvector izquierdo (indice)
	int indiceDero = medio2;	// subvector derecho (indice)
	int indiceCombinado = izquierda;	// vector temporal (indice)
	vector<int> combinado(tamanio);	// vector temporal de trabajo

	// imprime dos subvectores antes de combinar
	cout << "combinacion..";
	mostrarSubVector(izquierda, medio1);
	cout << endl << "               ";
	mostrarSubVector(medio2, derecha);
	cout << endl;

	// combinamos los vectores hasta llegar al final de uno de ellos
	while (indiceIzdo <= medio1 && indiceDero <= derecha)
	{
		// coloca el elemento menor de dos elementos en el resultado
		// y se desplaza al siguiente espacio en el vector
		if (datos[indiceIzdo] <= datos[indiceDero])
			combinado[indiceCombinado++] = datos[indiceIzdo++];
		else
			combinado[indiceCombinado++] = datos[indiceDero++];
	}
	
	// verificamos si un vector esta en el final
	if (indiceIzdo == medio2)	// final vector izquierdo
	{
		// copiamos en el vector de trabajo el resto del derecho
		// si existe
		while (indiceDero <= derecha)
			combinado[indiceCombinado++] = datos[indiceDero++];
	}
	else // al final del vector derecho
	{
		// copiamos el resto del vector izquierdo
		while (indiceIzdo <= medio1)
			combinado[indiceCombinado++] = datos[indiceIzdo++];
	}
	
	// copiamos el vector temporal al vector original
	for (int i = izquierda; i <= derecha; i++)
		datos[i] = combinado[i];

	// imprime el vector combinado
	cout << "                     ";
	mostrarSubVector(izquierda, derecha);
	cout << "\n\n";
}

// muestra los elementos en el vector
void OrdenamientoCombinacion::mostrarElementos() const
{
	mostrarSubVector(0, tamanio - 1);
}

// muestra ciertos valores en el vector
void OrdenamientoCombinacion::mostrarSubVector(int inferior, int superior) const
{
	// imprime espacios para alineacion
	for (int i = 0; i < inferior; i++)
		cout << "   ";

	// imprime elementos izquierdo en el vector
	for (int i = inferior; i <= superior; i++)
		cout << " " << datos[i];
}

/*****************************************************/
#include <iostream>
using std::cout;
using std::endl;

int main()
{
	// crear un objeto para el ordenamiento por combinacion
	OrdenamientoCombinacion vOrdenar(10);

	cout << "Vector desordenado:" << endl;
	vOrdenar.mostrarElementos();
	cout << endl << endl;

	vOrdenar.ordenar();

	cout << "vector ordenado: " << endl;
	vOrdenar.mostrarElementos();
	cout << endl;

	return 0;
}
