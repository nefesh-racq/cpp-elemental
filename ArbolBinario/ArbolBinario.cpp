/*
 implementacion de un arbol binario basico para
 un juego de adivinanza, en las izquierdas esta el animal
 en la derecha sus  cualidades, (ladra, maulla, cararea....etc)s
*/
#include <iostream>
using std::cout;
using std::endl;

#include "ArbolBinario.h"

// inicializa el nodo raiz con el pajaro
ArbolBinario::ArbolBinario()
{
	Nodo *raiz = new Nodo("pajaro");

	arbolPtr = raiz;
	// arbolPtr = new Nodo("pajaro");
}


ArbolBinario::~ArbolBinario()
{
	//delete arbolPtr;
	arbolPtr = 0;
}

// retorna la raiz del arbol
Nodo &ArbolBinario::begin() const
{
	return arbolPtr;
}

/*
 inserta dos nodos el izquierdo y derecho al mismo tiempo
 y ponemos el pajaro al final del arbol
*//*
void ArbolBinario::insert(Nodo &izquierdo, Nodo &derecho)
{
	// no hacemos verificaciones por que sabemos que el arbol ya tiene un nodo
	// recorremos los nodos hasta el final del arbol

	Nodo *itPtr = arbolPtr;

	for (; itPtr.derPtr != NULL; itPtr++)
		itPtr = itPtr.derPtr;

	itPtr.derPtr = derecho;
	itPtr.izdPtr = izquierdo;
}
*/
void ArbolBinario::insert(string animal, string cualidad)
{
	Nodo *itPtr = arbolPtr;

	for (; itPtr->derPtr != NULL; itPtr++)
		itPtr = itPtr->derPtr;

	Nodo *derecho = new Nodo(cualidad);
	Nodo *izquierdo = new Nodo(animal);

	itPtr->derPtr = derecho;
	itPtr->izdPtr = izquierdo;
}

void ArbolBinario::deleted(Nodo &nodo)
{}


void ArbolBinario::siguiente(Nodo &nodo)
{
	nodo = nodo.derPtr;
}


void ArbolBinario::print(const Nodo &nodo) const
{
	cout << nodo.getInfo();
}
