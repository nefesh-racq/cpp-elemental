#ifndef TRIANGULO_H
#define TRIANGULO_H

#include "Figura.h"

class Triangulo : public Figura
{
public:
	Triangulo();
	Triangulo(int, int);
	~Triangulo();

	// virtual heredada
	virtual void dibujar() const;

private:
	int base;
	int altura;
};

#endif//TRIANGULO_H