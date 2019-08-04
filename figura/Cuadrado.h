#ifndef CUADRADO_H
#define CUADRADO_H

#include "Figura.h"

class Cuadrado : public Figura
{
public:
	Cuadrado();
	Cuadrado(int);
	~Cuadrado();

	// virtual pura
	virtual void dibujar() const;

private:
	int lado;
};

#endif//CUADRADO_H