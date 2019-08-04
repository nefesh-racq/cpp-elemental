// implementacion de la clase Coche
#include <iostream>
using std::cout;
using std::endl;

#include "Coche.h"

Coche::Coche(string ma, string mo, int an)
{
	marca = ma;
	modelo = mo;
	anio = an;
}

void Coche::verDetalle()
{
	cout << "Marca : " << marca
		<< "\nModelo : " << modelo
		<< "\naño fabricacion : " << anio << endl;
}

