#ifndef PORHORAS_H
#define PORHORAS_H

#include "Empleado.h"

class EmpleadoPorHoras : public Empleado
{
public:
	EmpleadoPorHoras(const string &, const string &, const string &,
		double = 0.0, double = 0.0);

	void setSueldo(double);
	double getSueldo() const;

	void setHoras(double);
	double getHoras() const;

	// funciones virtuales
	virtual double ingresos() const;
	virtual void imprimir() const;

private:
	double sueldo;
	double horas;
};

#endif//PORHORAS_H
