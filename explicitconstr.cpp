#ifndef ARRAY_H
#define ARRAY_H

#include <iostream>
using std::ostream;
using std::istream;

class Array
{
	friend ostream &operator<<(ostream &, const Array &);
	friend istream &operator>>(istream &, Array &);

public:
	// al usar explicit se asegura que no se use el constructor como un
	// constructor de conversion de manera implicita
	// asi imprimirArray dara error al pasarle un entero y no un obj
	explicit Array(int = 10);		// constructor de conversion predeterminado
	Array(const Array &);
	~Array();

	int getTamanio() const;	// devuelve el tamaño
	const Array &operator=(const Array &);	// operador de asignacion
	bool operator==(const Array &) const;	// operador de igualdad

	// operador de desigualdad
	bool operator!=(const Array &derecho) const
	{
		return !(*this == derecho);	// invoca a Array::operator==()
	}

	// operador de subindice para los objetos no const devuelve un
	// lvalue modificable
	int &operator[](int);

	// operador de subindice para los objetos const devuelve un rvalue modificable
	int operator[](int) const;

private:
	int tamanio;	// tamaño del arreglo
	int *ptr;		// apuntador a primer elemento del arreglo
};

#endif//ARRAY_H

#include <iostream>
using std::cerr;
using std::cout;
using std::cin;
using std::endl;

#include <iomanip>
using std::setw;

#include <cstdlib>
using std::exit;


Array::Array(int tamanioArreglo)
{
	tamanio = (tamanioArreglo > 0 ? tamanioArreglo : 10);
	ptr = new int[tamanio];

	for (int i = 0; i < tamanio; i++)
		ptr[i] = 0;	// inicializamos el arreglo
}

// constructor de copia para la clase Array
Array::Array(const Array &arregloACopiar)
	: tamanio(arregloACopiar.tamanio)
{
	ptr = new int[tamanio];	// crea espacio para la copia del array

	for (int i = 0; i < tamanio; i++)
		ptr[i] = arregloACopiar.ptr[i];	// copia los elementos de larreglo
}

// destructor
Array::~Array()
{
	delete [] ptr;
	//ptr = 0;
}

int Array::getTamanio() const
{
	return tamanio;
}

// operador de asignacion sobrecargado
// devolviendo const evita (a1 = a2) = a3
const Array &Array::operator=(const Array &derecho)
{
	// comparamos direccion de memorias
	if (&derecho != this)	// evita la autoasignacion
	{
		// para los obj de Array de diferenes tamaños
		// reasignamos el tamaño para la asignacion
		if (tamanio != derecho.tamanio)
		{
			delete [] ptr;
			tamanio = derecho.tamanio;
			ptr = new int[tamanio];
		}

		for (int i = 0; i < tamanio; i++)
			ptr[i] = derecho.ptr[i];	// copiamos el array
	}

	return *this;	// permite x = y = z
}

// determina si dos obj Array son iguales
// devuelve true si es asi y false si no es asi
bool Array::operator==(const Array &derecho) const
{
	if (tamanio != derecho.tamanio)
		return false;	// falso por q serian de tamaños diferentes por lo tanto diferentes elementos

	for (int i = 0; i < tamanio; i++)
		if (ptr[i] != derecho.ptr[i])
			return false;

	return true;	// si llega aca los objetos son iguales
}

// operador de subindice sobrecargado para obj Array no const
// devuelve una referencia crea un lvalu modificable
int &Array::operator[](int subindice)
{
	// comprueba error de suindice fuera de rango
	if (subindice < 0 || subindice >= tamanio)
	{
		cerr << "\nError: subindice " << subindice
			<< " Fuera de rango" << endl;
		exit(1);
	}

	return ptr[subindice];
}

// operador de subindice sobrecargado para obj Array const
// devuelve referencia const crea un rvalue
int Array::operator[](int subindice) const
{
	// comprueba que el indice este en el rango
	if (subindice < 0 || subindice >= tamanio)
	{
		cerr << "\nError: subindice " << subindice
			<< " fuera de rango" << endl;
		exit(1);
	}

	return ptr[subindice];
}

// sobrecarga de operador de entrada
// recibe los valores para el obj Array
istream &operator>>(istream &entrada, Array &a)
{
	for (int i = 0; i < a.tamanio; i++)
		entrada >> a.ptr[i];

	return entrada;
}

// operador de salida sobrecargado para la clase Array
ostream &operator<<(ostream &salida, const Array &a)
{
	int i;

	// imprime arreglo private
	for (i = 0; i < a.tamanio; i++)
	{
		salida << setw(12) << a.ptr[i];

		if ((i + 1) % 4 == 0)	// cada 4 numeros que imprima
			salida << endl;
	}

	if (i % 4 != 0)	// fin de la ultima linea de salida
		salida << endl;

	return salida;
}

/****************************************************************/
#include <iostream>
using std::cout;
using std::endl;
using std::cin;

void imprimirArray(const Array &arregloAImprimir);

int main()
{
	Array enteros1(7);			// arreglo con 7 elementos

	imprimirArray(enteros1);	// imprime el objeto array
	imprimirArray(3);			// convierte 3 en un obj array e imprime su contenido
	
	return 0;
}

// imprme el contenido de un objeto array
void imprimirArray(const Array &arregloAImprimir)
{
	cout << "El objeto array recibido tiene " << arregloAImprimir.getTamanio()
		<< " elementos. su contenido es:\n" << arregloAImprimir << endl;
}
