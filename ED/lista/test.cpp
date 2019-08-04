// clase Nodo, como plantilla para fomentar la reutilizacion
// de codigo,

#ifndef NODO_H
#define NODO_H

// declaramos la clase anticipadamente para opder definirla
// como friend de la clase nodo, asi poder acceder a sus datos
// private desde Lista
template <typename TIPOLISTA>
class Lista;

template <typename TIPONODO>
class Nodo
{
	// declaramos la clase Lista como funcion amiga
	friend class Lista<TIPONODO>;

public:
	Nodo();
	Nodo(TIPONODO &);
	~Nodo();

	//TIPONODO getInfo() const;

private:
	TIPONODO info;				// se puede acceder desde class Lista
	Nodo<TIPONODO> *sgtePtr;	// se puede acceder desde class Lista
};

#endif//NODO_H


// clase Lista es una clase amiga de Nodo
// 
#ifndef LISTA_H
#define LISTA_H

#include "Nodo.h"

template <typename TIPOLISTA>
class Lista
{
public:
	Lista();
	~Lista();

	void insertarInicio(TIPOLISTA &);
	void insertarFinal(TIPOLISTA &);

	void eliminarInicio(TIPOLISTA &);
	void eliminarFinal(TIPOLISTA &);

	void imprimir() const;

private:
	Nodo<TIPOLISTA> *inicioPtr;
	Nodo<TIPOLISTA> *finalPtr;
};

#endif//LISTA_H


/*********** definicionese *******************/
//
#include "Nodo.h"

template <typename TIPONODO>
Nodo<TIPONODO>::Nodo()
{
	sgtePtr = 0;
	info = 0;
}

template <typename TIPONODO>
Nodo<TIPONODO>::~Nodo()
{}

template <typename TIPONODO>
Nodo<TIPONODO>::Nodo(TIPONODO &dato)
{
	info = dato;
}

#include <iostream>
using std::endl;
using std::cout;

#include "Lista.h"

template <typename TIPOLISTA>
Lista<TIPOLISTA>::Lista()
{
	inicioPtr = finalPtr = 0;
}

template <typename TIPOLISTA>
Lista<TIPOLISTA>::~Lista()
{

}

template <typename TIPOLISTA>
void Lista<TIPOLISTA>::insertarInicio(TIPOLISTA &dato)
{
	Nodo<TIPOLISTA> *nuevoPtr = new Nodo<TIPOLISTA>(dato);

	if (inicioPtr == 0)
		inicioPtr = finalPtr = nuevoPtr;
	else
	{
		nuevoPtr->sgtePtr = inicioPtr;
		inicioPtr = nuevoPtr;
	}
}

template <typename TIPOLISTA>
void Lista<TIPOLISTA>::insertarFinal(TIPOLISTA &dato)
{
	Nodo<TIPOLISTA> *nuevoPtr = new Nodo<TIPOLISTA>(dato);

	if (inicioPtr == 0)
		inicioPtr = finalPtr = nuevoPtr;
	else
	{
		finalPtr->sgtePtr = nuevoPtr;
		finalPtr = nuevoPtr;
	}
}

template <typename TIPOLISTA>
void Lista<TIPOLISTA>::eliminarInicio(TIPOLISTA &dato)
{
	Nodo<TIPOLISTA> *tempPtr = inicioPtr;

	if (inicioPtr == finalPtr)
		inicioPtr = finalPtr = 0;
	else
	{
		inicioPtr = inicioPtr->sgtePtr;
	}

	tempPtr->sgtePtr = 0;
	dato = tempPtr->info;
	delete tempPtr;
}

template <typename TIPOLISTA>
void Lista<TIPOLISTA>::eliminarFinal(TIPOLISTA &dato)
{
	Nodo<TIPOLISTA> *tempPtr = finalPtr;

	if (inicioPtr == finalPtr)
		inicioPtr = finalPtr = 0;
	else
	{
		Nodo<TIPOLISTA> *itPtr = inicioPtr;

		while (itPtr->sgtePtr != finalPtr)
			itPtr = itPtr->sgtePtr;

		finalPtr = itPtr;
	}

	tempPtr->sgtePtr = 0;
	dato = tempPtr->info;
	delete tempPtr;
}

template <typename TIPOLISTA>
void Lista<TIPOLISTA>::imprimir() const
{
	Nodo<TIPOLISTA> *itPtr = inicioPtr;

	while (itPtr != 0)
	{
		cout << itPtr->info << " ";
		itPtr = itPtr->sgtePtr;
	}	

	cout << endl;
}

/******** main ************/
#include "Lista.h"

int main()
{
	Lista<int> li;
	int entero;

	for (int i = 1; i < 10; i++)
	{
		entero = 2 * i -1;
		li.insertarFinal(entero);
	}

	li.imprimir();


	return 0;
}