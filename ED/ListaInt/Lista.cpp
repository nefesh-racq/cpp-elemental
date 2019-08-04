#include <iostream>
using std::cout;
using std::endl;

#include "Lista.h"

Lista::Lista()
	: inicioPtr(0), finalPtr(0)
{}

Lista::~Lista()
{}

void Lista::insertarAlInicio(int &dato)
{
	Nodo *nuevoPtr = new Nodo(dato);

	if (inicioPtr == 0)
		inicioPtr = finalPtr = nuevoPtr;
	else
	{
		nuevoPtr->sgtePtr = inicioPtr;
		inicioPtr = nuevoPtr;
	}
}

void Lista::insertarAlFinal(int &dato)
{
	Nodo *nuevoPtr = new Nodo(dato);

	if (inicioPtr == 0)
		inicioPtr = finalPtr = nuevoPtr;
	else
	{
		finalPtr->sgtePtr = nuevoPtr;
		finalPtr = nuevoPtr;
	}
}

void Lista::eliminarDelInicio(int &dato)
{
	Nodo *tempPtr = inicioPtr;

	if (inicioPtr == finalPtr)
		inicioPtr = finalPtr = 0;
	else
	{
		inicioPtr = inicioPtr->sgtePtr;
		tempPtr->sgtePtr = 0;
	}

	dato = tempPtr->info;
	delete tempPtr;
}

void Lista::eliminarDelFinal(int &dato)
{
	Nodo *tempPtr = finalPtr;

	if (inicioPtr == finalPtr)
		inicioPtr = finalPtr = 0;
	else
	{
		Nodo *itPtr = inicioPtr;

		while (itPtr->sgtePtr != finalPtr)
			itPtr = itPtr->sgtePtr;

		finalPtr = itPtr;
		finalPtr->sgtePtr = 0;
	}

	dato = tempPtr->info;
	delete tempPtr;
}

void Lista::imprimir() const
{
	Nodo *itPtr = inicioPtr;

	while (itPtr != 0)
	{
		cout << itPtr->info << " ";
		itPtr = itPtr->sgtePtr;
	}

	cout << endl;
}