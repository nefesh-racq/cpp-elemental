#include "Nodo.h"

Nodo::Nodo()
	: info(9), sgtePtr(0)
{}

Nodo::Nodo(int &dato)
	: info(dato), sgtePtr(0)
{}

Nodo::~Nodo()
{}
