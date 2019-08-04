/*
 implementacion del nodo solo maneja un dato
 el cual puede ser una cualidad o nombre de un animal

*/
#include "Nodo.h"

Nodo::Nodo()
{
	setInfo("");

	derPtr = 0;
	izdPtr = 0;
}


Nodo::Nodo(string informacion)
{
	setInfo(informacion);


	derPtr = 0;
	izdPtr = 0;
}

// constructor de copia
Nodo::Nodo(Nodo &nodo)
{

}
	
Nodo::~Nodo()
{
	derPtr = 0;
	izdPtr = 0;
}

void Nodo::setInfo(string informacion)
{
	info = informacion;
}

string Nodo::getInfo() const
{
	return info;
}
