#include <iostream>
using std::cout;

#include "EmpleadoAsalariado.h"

EmpleadoAsalariado::EmpleadoAsalariado(const string &nombre,
	const string &apellido, const string &nss, double salario)
	: Empleado(nombre, apellido, nss)
{
	setSalarioSemanal(salario);
}

void EmpleadoAsalariado::setSalarioSemanal(double salario)
{
	salarioSemanal = (salario < 0.0) ? 0.0 : salario;
}

double EmpleadoAsalariado::getSalarioSemanal() const
{
	return salarioSemanal;
}

// calcula los ingresos:
// sobrescribe a la funcion virtual pura ingresos
double EmpleadoAsalariado::ingresos() const
{
	return getSalarioSemanal();
}

void EmpleadoAsalariado::imprimir() const
{
	cout << "empleado asalariado: ";
	
	Empleado::imprimir();
	cout << "\nsalario semanal: " << getSalarioSemanal();
}

