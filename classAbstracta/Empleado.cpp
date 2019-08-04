#include <iostream>
using std::cout;

#include "Empleado.h"

Empleado::Empleado(const string &nombre, const string &apellido,
	const string &nss)
	: primerNombre(nombre), apellidoPaterno(apellido), nroSeguroSocial(nss)
{
	;
}

void Empleado::setPrimerNombre(const string &nombre)
{
	primerNombre = nombre;
}

string Empleado::getPrimerNombre() const
{
	return primerNombre;
}

void Empleado::setApellidoPaterno(const string &apellido)
{
	apellidoPaterno = apellido;
}

string Empleado::getApellidoPaterno() const
{
	return apellidoPaterno;
}

void Empleado::setNroSeguroSocial(const string &nss)
{
	nroSeguroSocial = nss;
}

string Empleado::getNroSeguroSocial() const
{
	return nroSeguroSocial;
}

// funcion virtual pura
void Empleado::imprimir() const
{
	cout << getPrimerNombre() << " " << getApellidoPaterno()
		<< "\nnumero de seguro social: " << getNroSeguroSocial();
}

