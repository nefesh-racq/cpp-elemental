#include <iostream>
using std::cout;

#include "EmpleadoPorComision.h"

EmpleadoPorComision::EmpleadoPorComision(const string &nombre,
	const string &apellido, const string &nss, double ventas,
	double tarifa)
	: Empleado(nombre, apellido, nss)
{
	setVentasBrutas(ventas);
	setTarifaComision(tarifa);
}

void EmpleadoPorComision::setTarifaComision(double tarifa)
{
	tarifaComision = ((tarifa > 0.0 && tarifa < 1.0) ? tarifa : 0.0);
}

double EmpleadoPorComision::getTarifaComision() const
{
	return tarifaComision;
}

void EmpleadoPorComision::setVentasBrutas(double ventas)
{
	ventasBrutas = ((ventas < 0.0) ? 0.0 : ventas);
}

double EmpleadoPorComision::getVentasBrutas() const
{
	return ventasBrutas;
}

// virtuales
double EmpleadoPorComision::ingresos() const
{
	return getTarifaComision() * getVentasBrutas();
}

void EmpleadoPorComision::imprimir() const
{
	cout << "empleado por comision: ";
	Empleado::imprimir();
	cout << "\nventas brutas: " << getVentasBrutas()
		<< "; tarifa de comision: " << getTarifaComision();
}

