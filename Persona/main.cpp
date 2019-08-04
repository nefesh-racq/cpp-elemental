// uso de la clase Persona
#include <iostream>
using std::cout;

#include <string>
using std::string;

#include <cstring>
using std::strcpy;

#include "Persona.h"

int main()
{
	Persona p;
	Persona p1("jose luis", 10);
	Persona p2;

	p.presentarse();

	p1.presentarse();

	char nom[] = "pepito jose";

	p2.setNombre(nom);
	p2.setEdad(12);
	p2.presentarse();

	string test = "nombre de prueba";
	char cop[20] = "hola";

	//cop = test;			// error
	//strcpy(cop, test);	// error
	//test = cop;			// si es posible


	for (int i = 0; i < test.length(); i++)
		cop[i] = test[i];

	cout << cop;

	return 0;
}

