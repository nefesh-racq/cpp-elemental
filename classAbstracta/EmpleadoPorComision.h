#ifndef COMISION_H
#define COMISION_H

#include "Empleado.h"

class EmpleadoPorComision : public Empleado
{
public:
	EmpleadoPorComision(const string &, const string &, const string &,
		double = 0.0, double = 0.0);

	void setTarifaComision(double);
	double getTarifaComision() const;

	void setVentasBrutas(double);
	double getVentasBrutas() const;

	// virtuales
	virtual double ingresos() const;
	virtual void imprimir() const;

private:
	double ventasBrutas;
	double tarifaComision;
};

#endif//COMISION_H
