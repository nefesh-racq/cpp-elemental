#ifndef FIGURA_H
#define FIGURA_H

#include <iostream>
using std::cout;

#include <string>
using std::string;

class Figura
{
public:
	Figura(const string &nombre) : nombreFigura(nombre) {};
	Figura() : nombreFigura("none") {};
	virtual ~Figura() {};

	virtual void dibujar() const = 0;
	virtual void queSoy() const
	{
		cout << "soy un " << nombreFigura;
	}

private:
	string nombreFigura;
};

#endif//FIGURA_H
