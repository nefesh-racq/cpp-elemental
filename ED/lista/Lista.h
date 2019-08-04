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