/*
 arbol binario basico, almacenara en la izquierda el animal
 y en la derecha la cualidad del corresponde
*/
#ifndef ARBOLBINARIO_H
#define ARBOLBINARIO_H

#include "Nodo.h"

class ArbolBinario
{
public:
	ArbolBinario();
	~ArbolBinario();

	void insert(Nodo &);
	void insert(string, string);
	void deleted(Nodo &);
	void siguiente(Nodo &);
	Nodo &begin() const;
	void print(const Nodo &) const;

//private:
	Nodo *arbolPtr;
};

#endif//ARBOLBINARIO_H