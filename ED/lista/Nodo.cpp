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