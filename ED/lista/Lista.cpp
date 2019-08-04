#include <iostream>
using std::endl;
using std::cout;

//#include "Nodo.h"
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
	dato = tempPtr->getInfo();
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
