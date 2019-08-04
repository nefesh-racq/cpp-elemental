#ifndef BASEMAS_H
#define BASEMAS_H

#include "EmpleadoPorComision.h"

class EmpleadoBaseMasComision : public EmpleadoPorComision
{
public:
	EmpleadoBaseMasComision(const string &, const string &,
		const string &, double = 0.0, double = 0.0, double = 0.0);

	void setSalarioBase(double);
	double getSalarioBase() const;

	// virtuales
	virtual double ingresos() const;
	virtual void imprimir() const;

private:
	double salarioBase;
};

#endif//BASEMAS_H

