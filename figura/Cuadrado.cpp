#include <iostream>
using std::cout;
using std::endl;

#include "Cuadrado.h"

Cuadrado::Cuadrado()
	: Figura("cuadrado")
{
	lado = 5;
}

Cuadrado::Cuadrado(int _lado)
	: Figura("cuadrado")
{
	lado = _lado;
}

Cuadrado::~Cuadrado()
{ ; }

// virtual
void Cuadrado::dibujar() const
{
	for (int i = 0; i < lado; i++)
	{
		for (int j = 0; j < lado; j++)
		{
			cout << '*';
		}

		cout << endl;
	}
}
