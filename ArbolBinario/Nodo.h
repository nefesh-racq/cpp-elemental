/*
* nodo base para el arbol binario
*/
#ifndef NODO_H
#define NODO_H

#include <string>
using std::string;

class Nodo
{
public:
	Nodo();
	Nodo(string);
	Nodo(Nodo &);
	~Nodo();

	void setInfo(string);
	string getInfo() const;

	Nodo *derPtr;	// apuntador al nodo derecho
	Nodo *izdPtr;	// apuntador al nodo izquierdo

private:
	string info;	// informacion, cuando este en la izq nombre, der cualidad
};

#endif//NODO_H
