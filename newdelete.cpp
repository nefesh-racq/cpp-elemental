// uso dinamico de memoria usando el operador new y delete
#ifndef EMPLEADO_H
#define EMPLEADO_H

class Empleado
{
public:
	Empleado(const char* const, const char* const);
	~Empleado();

	const char *getPrimerNombre() const;
	const char *getApellidoPaterno() const;

	// funcion miembro estatic
	static int getCuenta();	// devuelve el nro de objetos instanciados

private:
	char *primerNombre;
	char *apellidoPaterno;

	// dato static
	static int cuenta;
};

#endif//EMPLEADO_H

/*********************************************************************/

#include <iostream>
using std::cout;
using std::endl;

#include <cstring>
using std::strlen;
using std::strcpy;

// definimos e inicializamos el miembro dato static de la clase Empleado
int Empleado::cuenta = 0;	// no puede incluir la palabra static

// retorna el nro de objetos de tipo empleado instanciados
int Empleado::getCuenta()
{
	return cuenta;
}

// se asigna memoria de forma dinamica para el nombre y apellido
Empleado::Empleado(const char *const nombre, const char *const apellido)
{
	primerNombre = new char[strlen(nombre) + 1];	// reservamos memoria del tamaño de nombre + 1 para '\0'
	strcpy(primerNombre, nombre);	// copia el nombre a primerNombre

	apellidoPaterno = new char[strlen(apellido) + 1];
	strcpy(apellidoPaterno, apellido);

	cuenta++;	// lleva el conteo de las instancias

	cout << "Se llamo al constructor de Empleado para " << primerNombre << " " 
		<< apellidoPaterno << "." << endl;
}

// el destructor libera la memoria asignada
Empleado::~Empleado()
{
	cout << "Se llamo a ~Empleado() para " << primerNombre << " " << apellidoPaterno 
		<< "." << endl;

	delete [] primerNombre;		// libera la memoria asignada
	delete [] apellidoPaterno;	// libera la memoria asignada

	cuenta--;	// controlamos la cantidad de objetos de Empleado
}

const char *Empleado::getPrimerNombre() const
{
	return primerNombre;
}

const char *Empleado::getApellidoPaterno() const
{
	return apellidoPaterno;
}

/*************************************************************/

int main()
{
	// se llama a los datos y funciones static usando el operador de resolucion de ambito binario
	// no es necesario declarar un objeto para acceder a los miembros static
	cout << "El numero de empleados antes de instanciar objetos es : "
		<< Empleado::getCuenta() << endl;	// llamada usado en nombre de la clase

	// usamos new para crear objetos en forma dinamca
	Empleado *e1Ptr = new Empleado("Susan", "baker");
	Empleado *e2Ptr = new Empleado("Robert", "jones");

	// tambien podemos llamamat a getCuenta() mediante el objeto instanciado
	cout << "El numero de empleados despues de instanciar objetos es : " 
		<< e1Ptr->getCuenta();

	cout << "\n\nEmpleado 1: "
		<< e1Ptr->getPrimerNombre() << " " << e1Ptr->getApellidoPaterno()
		<< "\nEmpleado 2: "
		<< e2Ptr->getPrimerNombre() << " " << e2Ptr->getApellidoPaterno() << "\n\n";

	// liberamos la memoria
	delete e1Ptr;	// libera la memoria
	e1Ptr = 0;		// desconecta al ptr de la direccion de memoria asignada
	delete e2Ptr;	// libera la memoria
	e2Ptr = 0;		// desconecta al ptr de la direccion de memoria asignada

	cout << "El numero de empleados despues de eliminar los objetos es : "
		<< Empleado::getCuenta() << endl;

	return 0;
}

