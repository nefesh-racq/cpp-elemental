#ifndef ASALARIADO_H
#define ASALARIADO_H

#include "Empleado.h"

class EmpleadoAsalariado : public Empleado
{
public:
	EmpleadoAsalariado(const string &, const string &, const string &,
		double = 0.0);

	void setSalarioSemanal(double);
	double getSalarioSemanal() const;

	// buena practica de programacion poner virtual si sobreescribes una
	// funcion virtual
	virtual double ingresos() const;
	virtual void imprimir() const;

private:
	double salarioSemanal;
};
#endif//ASALARIADO_H
