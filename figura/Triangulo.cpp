#include <iostream>
using std::cout;
using std::endl;

#include "Triangulo.h"

Triangulo::Triangulo()
	: Figura("triangulo")
{
	base = 5;
	altura = 5;
}

Triangulo::Triangulo(int _base, int _altura)
	: Figura("triangulo")
{
	base = _base;
	altura = _altura;
}

Triangulo::~Triangulo()
{}

// virtual
// no dibuja triangulo en todo los casos
// solo cuando base es eldoble de altura
void Triangulo::dibujar() const
{
	int left = base / 2;
	int right = base / 2;

	for (int i = 0; i < altura; i++)
	{
		for (int j = 0; j < base; j++)
		{
			if (j >= left && j <= right)
				cout << '*';
			else
				cout << ' ';
		}

		cout << endl;
		left--;
		right++;
	}
}
