// definicion de clase arbol
#ifndef ARBOL_H
#define ARBOL_H

#include <iostream>
using std::endl;
using std::cout;

#include "NodoArbol.h"

template <typename TIPONODO>
class Arbol
{
public:
	Arbol();

	void insertarNodo(const TIPONODO &);
	void recorridoPreOrden() const;
	void recorridoInOrden() const;
	void recorridoPostOrden() const;

private:
	NodoArbol<TIPONODO> *raizPtr;

	// funciones utilitarias
	void ayudanteInsertarNodo(NodoArbol<TIPONODO> **, const TIPONODO &);
	void ayudantePreOrden(NodoArbol<TIPONODO> *) const;
	void ayudanteInOrden(NodoArbol<TIPONODO> *) const;
	void ayudantePostOrden(NodoArbol<TIPONODO> *) const;
};

// constructor
template <typename TIPONODO>
Arbol<TIPONODO>::Arbol()
{
	raizPtr = 0;
}

// inserta el nodo en el arbol
template <typename TIPONODO>
void Arbol<TIPONODO>::insertarNodo(const TIPONODO &valor)
{
	ayudanteInsertarNodo(&raizPtr, valor);
}

// funcion utilitaria, recibe un apuntador a un apuntador
// para que la funcion pueda modificar el valor del apuntador
template <typename TIPONODO>
void Arbol<TIPONODO>::ayudanteInsertarNodo(
	NodoArbol<TIPONODO> **ptr, const TIPONODO &valor)
{
	// subarbol esta vacio
	if (*ptr == 0)
		*ptr = new NodoArbol<TIPONODO>(valor);
	else
	{
		// los datos a insertar son menores que los datos en el
		// nodo actual
		if (valor < (*ptr)->datos)
			ayudanteInsertarNodo(&((*ptr)->izquierdoPtr), valor);
		else
		{
			// los datos a insertar son mayores que los datos en el nodo actual
			if (valor > (*ptr)->datos)
				ayudanteInsertarNodo(&((*ptr)->derechoPtr), valor);
			else
				cout << valor << " dup" << endl;
		}
	}
}

// inicia el recorrido preorden del arbol
template <typename TIPONODO>
void Arbol<TIPONODO>::recorridoPreOrden() const
{
	ayudantePreOrden(raizPtr);
}

// funcion utilitaria par realizar el recorrido preorden del arbol
template <typename TIPONODO>
void Arbol<TIPONODO>::ayudantePreOrden(NodoArbol<TIPONODO> *ptr) const
{
	if (ptr != 0)
	{
		cout << ptr->datos << ' ';
		ayudantePreOrden(ptr->izquierdoPtr);// recorre subarbol izquierdo
		ayudantePreOrden(ptr->derechoPtr);	// recorre subarbol derecho
	}
}

// recorrido inorden
template <typename TIPONODO>
void Arbol<TIPONODO>::recorridoInOrden() const
{
	ayudanteInOrden(raizPtr);
}

// funcion utilitaria para el recorrido inorden
template <typename TIPONODO>
void Arbol<TIPONODO>::ayudanteInOrden(NodoArbol<TIPONODO> *ptr) const
{
	if (ptr != 0)
	{
		ayudanteInOrden(ptr->izquierdoPtr);
		cout << ptr->datos << ' ';
		ayudanteInOrden(ptr->derechoPtr);
	}
}

// recorrido postorden
template <typename TIPONODO>
void Arbol<TIPONODO>::recorridoPostOrden() const
{
	ayudantePostOrden(raizPtr);
}

// funcion utilitaria para el recorrido postorden
template <typename TIPONODO>
void Arbol<TIPONODO>::ayudantePostOrden(NodoArbol<TIPONODO> *ptr) const
{
	if (ptr != 0)
	{
		ayudantePostOrden(ptr->izquierdoPtr);
		ayudantePostOrden(ptr->derechoPtr);
		cout << ptr->datos << ' ';
	}	
}

#endif//ARBOL_H