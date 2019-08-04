#include <iostream>
using std::cout;

#include "EmpleadoBaseMasComision.h"

EmpleadoBaseMasComision::EmpleadoBaseMasComision(const string &nombre,
	const string &apellido, const string &nss, double ventas,
	double tarifa, double salario)
	: EmpleadoPorComision(nombre, apellido, nss, ventas, tarifa)
{
	setSalarioBase(salario);
}

void EmpleadoBaseMasComision::setSalarioBase(double salario)
{
	salarioBase = ((salario < 0.0) ? 0.0 : salario);
}

double EmpleadoBaseMasComision::getSalarioBase() const
{
	return salarioBase;
}

double EmpleadoBaseMasComision::ingresos() const
{
	return getSalarioBase() + EmpleadoPorComision::ingresos();
}

void EmpleadoBaseMasComision::imprimir() const
{
	cout << "con salario base ";
	EmpleadoPorComision::imprimir();
	cout << "; salario base: " << getSalarioBase();
}

