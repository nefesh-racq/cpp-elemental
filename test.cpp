// Fig. 11.6: Array.h
// Definición de la clase Array con operadores sobrecargados.
#ifndef ARRAY_H
#define ARRAY_H

#include <iostream>
using std::ostream;
using std::istream;

class Array
{
	friend ostream &operator<<( ostream &, const Array & );
	friend istream &operator>>( istream &, Array & );

public:
	Array( int = 10 ); // constructor predeterminado
	Array( const Array & ); // constructor de copia
	~Array(); // destructor

	int getTamanio() const; // devuelve el tamaño
	const Array &operator=( const Array & ); // operador de asignación
	bool operator==( const Array & ) const; // operador de igualdad

	// operador de desigualdad; devuelve el opuesto del operador ==
	bool operator!=( const Array &derecho ) const
	{
		return ! ( *this == derecho ); // invoca a Array::operator==
	} // fin de la función operator!=


	// el operador de subíndice para los objetos no const devuelve un lvalue modificable
	int &operator[ ]( int );
	
// el operador de subíndice para los objetos const devuelve rvalue
	int operator[ ]( int ) const;

private:
	int tamanio; // arreglo tamaño basado en apuntador
	int *ptr; // apuntador al primer elemento del arreglo basado en apuntador
}; // fin de la clase Arreglo

#endif

// Fig 11.7: Array.cpp
// Definiciones de las funciones miembro y friend de la clase Array.
#include <iostream>
using std::cerr;
using std::cout;
using std::cin;
using std::endl;

#include <iomanip>
using std::setw;

#include <cstdlib> // prototipo de la función exit
using std::exit;

//#include "Array.h" // Definición de la clase Array

// constructor predeterminado para la clase Array (tamaño predeterminado 10)
Array::Array( int tamanioArreglo )
{
	tamanio = ( tamanioArreglo > 0 ? tamanioArreglo : 10 ); // valida tamanioArreglo
	ptr = new int[ tamanio ]; // crea espacio para el arreglo basado en apuntador

	for ( int i = 0; i < tamanio; i++ )
		ptr[ i ] = 0; // establece elemento de arreglo basado en apuntador
} // fin del constructor predeterminado de Array

// constructor de copia para la clase Array;
// debe recibir una referencia para evitar la recursividad infinita
Array::Array( const Array &arregloACopiar )
: tamanio( arregloACopiar.tamanio )
{
	ptr = new int[ tamanio ]; // crea espacio para el arreglo basado en apuntador

	for ( int i = 0; i < tamanio; i++ )
		ptr[ i ] = arregloACopiar.ptr[ i ]; // lo copia en el objeto
} // fin del constructor de copia de Array

// destructor para la clase Array
Array::~Array()
{
	delete [ ] ptr; // libera el espacio del arreglo basado en apuntador
} // fin del destructor

// devuelve el número de elementos del objeto Array
int Array::getTamanio() const
{
	return tamanio; // número de elementos en el objeto Array
} // fin de la función getTamanio

// operador de asignación sobrecargado;
// devolución de const evita: ( a1 = a2 ) = a3
const Array &Array::operator=( const Array &derecho )
{
	if ( &derecho != this ) // evita la auto-asignación
	{
		// para los objetos Array de distintos tamaños, desasigna el arreglo
		// original del lado izquierdo, después asigna el nuevo arreglo del lado izquierdo
		if ( tamanio != derecho.tamanio )
		{
			delete [ ] ptr; // libera espacio
			tamanio = derecho.tamanio; // cambia el tamaño de este objeto
			ptr = new int[ tamanio ]; // crea espacio para la copia del arreglo
		} // fin del if interior

		for ( int i = 0; i < tamanio; i++ )
			ptr[ i ] = derecho.ptr[ i ]; // copia el arreglo en el objeto
	} // fin del if exterior

	return *this; // permite x = y = z, por ejemplo
} // fin de la función operator=

// determina si dos objetos Array son iguales y
// devuelve true, en caso contrario devuelve false
bool Array::operator==( const Array &derecho ) const
{
	if ( tamanio != derecho.tamanio )
		return false; // arreglos con distinto número de elementos

	for ( int i = 0; i < tamanio; i++ )
		if ( ptr[ i ] != derecho.ptr[ i ] )
			return false; // el contenido de los objetos Array no es igual

	return true; // los objetos Array son iguales
} // fin de la función operator==

// operador de subíndice sobrecargado para objetos Array no const;
// la devolución de una referencia crea un lvalue modificable
int &Array::operator[ ]( int subindice )
{
	// comprueba error de subíndice fuera de rango
	if ( subindice < 0 || subindice >= tamanio )
	{
		cerr << "\nError: subindice " << subindice
			<< " fuera de rango" << endl;
		exit( 1 ); // termina el programa; subíndice fuera de rango
	} // fin de if

	return ptr[ subindice ]; // devuelve una referencia
} // fin de la función operator[ ]

// operador de subíndice sobrecargado para objetos Array const
// devolución de referencia const crea un rvalue
int Array::operator[ ]( int subindice ) const
{
	// comprueba error de subíndice fuera de rango
	if ( subindice < 0 || subindice >= tamanio )
	{
		cerr << "\nError: subindice " << subindice
			<< " fuera de rango" << endl;
			exit( 1 ); // termina el programa; subíndice fuera de rango
	} // fin de if

	return ptr[ subindice ]; // devuelve una copia de este elemento
} // fin de la función operator[ ]

// operador de entrada sobrecargado para la clase Array;
// recibe valores para el objeto Array completo
istream &operator>>( istream &entrada, Array &a )
{
	for ( int i = 0; i < a.tamanio; i++ )
		entrada >> a.ptr[ i ];

	return entrada; // permite cin >> x >> y;
} // fin de la función

// operador de salida sobrecargado para la clase Array
ostream &operator<<( ostream &salida, const Array &a )
{
	int i;

	// imprime arreglo private basado en ptr
	for ( i = 0; i < a.tamanio; i++ )
	{
		salida << setw( 12 ) << a.ptr[ i ];
		
		if ( ( i + 1 ) % 4 == 0 ) // 4 números por fila de salida
			salida << endl;
	} // fin de for

	if ( i % 4 != 0 ) // fin de la última línea de salida
		salida << endl;

	return salida; // permite cout << x << y;
} // fin de la función operator<<

// Fig. 11.8: f ig11_08.cpp
// Programa de prueba de la clase Array.
#include <iostream>
using std::cout;
using std::cin;
using std::endl;

//#include "Array.h"

int main()
{
	Array enteros1( 7 ); // objeto Array de 7 elementos
	Array enteros2; // objeto Array de 10 elementos de manera predeterminada

	// imprime el tamaño y contenido de enteros1
	cout << "El tamanio del objeto Array enteros1 es "
		<< enteros1.getTamanio()
		<< "\nEl objeto Array despues de la inicializacion es:\n" << enteros1;

	// imprime el tamaño y el contenido de enteros2
	cout << "\nEl tamanio del objeto Array enteros2 es "
		<< enteros2.getTamanio()
		<< "\nEl objeto Array despues de la inicializacion es:\n" << enteros2;

	// recibe e imprime enteros1 y enteros2
	cout << "\nIntroduzca 17 enteros:" << endl;
	cin >> enteros1 >> enteros2;
	cout << "\nDespues de la entrada, los objetos Array contienen:\n"
		<< "enteros1:\n" << enteros1
		<< "enteros2:\n" << enteros2;
	
	// usa el operador de desigualdad (!=) sobrecargado
	cout << "\nEvaluando: enteros1 != enteros2" << endl;
	
	if ( enteros1 != enteros2 )
		cout << "enteros1 y enteros2 no son iguales" << endl;

	// crea el objeto Array enteros3, usando enteros1 como
	// inicializador; imprime el tamaño y el contenido
	Array enteros3( enteros1 ); // invoca el constructor de copia
	cout << "\nEl tamanio del objeto Array enteros3 es "
		<< enteros3.getTamanio()
		<< "\nObjeto Array despues de la inicializacion:\n" << enteros3;
	
	// usa el operador de asignación (=) sobrecargado
	cout << "\nAsignando enteros2 a enteros1:" << endl;
	enteros1 = enteros2; // observe que el objeto Array de destino es más pequeño

	cout << "enteros1:\n" << enteros1
		<< "enteros2:\n" << enteros2;
	
	// usa el operador de igualdad (==) sobrecargado
	cout << "\nEvaluando: enteros1 == enteros2" << endl;

	if ( enteros1 == enteros2 )
		cout << "enteros1 y enteros2 son iguales" << endl;

	// usa el operador de subíndice sobrecargado para crear rvalue
	cout << "\nenteros1[5] es " << enteros1[ 5 ];
	// usa el operador de subíndice sobrecargado para crear lvalue
	cout << "\n\nAsignando 1000 a enteros1[5]" << endl;
	enteros1[ 5 ] = 1000;
	cout << "enteros1:\n" << enteros1;
	// trata de usar un subíndice fuera de rango
	cout << "\nTrata de asignar 1000 a enteros1[15]" << endl;
	enteros1[ 15 ] = 1000; // ERROR: fuera de rango
	
	return 0;
} // fin de main

