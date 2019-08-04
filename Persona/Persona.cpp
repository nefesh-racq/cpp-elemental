// implementacion de la clase Persona
#include <cstring>
using std::strcpy;

#include <iostream>
using std::cout;

#include "Persona.h"

Persona::Persona()
{
	nombre = "sin nombre";
	edad = 0;
}

Persona::Persona(string nom, int e)
{
	nombre = nom;
	edad = e;
}

void Persona::setNombre(char nom[])
{
	nombre = nom;
	//strcpy(nombre, nom);
}

void Persona::setEdad(int e)
{
	edad = e;
}

void Persona::presentarse()
{
	cout << "Mi nombre es. " << nombre
		<< " y tengo " << edad << " años\n";
}

