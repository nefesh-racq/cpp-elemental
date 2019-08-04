#include "Lista.h"

class Pila : private Lista
{
public:
	Pila();
	~Pila();

	void insertar(int &);
	void sacar(int &);

	void imprimirPila() const;
};

/////////////////////////
Pila::Pila()
{}

Pila::~Pila() {}

void Pila::insertar(int &dato)
{
	this->insertarAlInicio(dato);
}

void Pila::sacar(int &dato)
{
	this->eliminarDelInicio(dato);
}

void Pila::imprimirPila() const
{
	this->imprimir();
}

/**************************************/
#include <iostream>
using std::cout;
using std::endl;

int main()
{
	Pila pila;
	int entero;

	for (int i = 1; i < 15; i++)
	{
		entero = entero * i;
		pila.insertar(entero);
	}

	pila.imprimirPila();

	pila.sacar(entero);
	cout << entero << endl;

	pila.sacar(entero);
	cout << entero << endl;

	pila.sacar(entero);
	cout << entero << endl;

	pila.sacar(entero);
	cout << entero << endl;

	pila.imprimirPila();

	return 0;
}