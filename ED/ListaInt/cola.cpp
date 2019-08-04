#include "Lista.h"

class Cola : private Lista
{
public:
	Cola();
	~Cola();

	void insertar(int &);
	void sacar(int &);

	void imprimirCola() const;
};

Cola::Cola()
{}

Cola::~Cola()
{}

void Cola::insertar(int &dato)
{
	this->insertarAlFinal(dato);
}


void Cola::sacar(int &dato)
{
	this->eliminarDelInicio(dato);
}

void Cola::imprimirCola() const
{
	this->imprimir();
}

/*********************************/
#include <iostream>
using std::endl;
using std::cout;

int main()
{
	Cola cola;
	int entero = 2;

	for (int i = 1; i < 12; i++)
	{
		entero = entero * i + 2;
		cola.insertar(entero);
	}

	cola.imprimirCola();

	cola.sacar(entero);
	cout << entero << endl;

	cola.sacar(entero);
	cout << entero << endl;
	
	cola.sacar(entero);
	cout << entero << endl;
	
	cola.sacar(entero);
	cout << entero << endl;

	cola.imprimirCola();
	
	return 0;
}
