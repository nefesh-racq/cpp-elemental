// probando la clase Tiempo
// g++ Tiempo.cpp main0.cpp
#include <iostream>
using std::cout;
using std::endl;

#include "Tiempo.h"		// incluye la definicion de la clase tiempo

int main()
{
	Tiempo t;	// instancia un objeto t de tipo Tiempo y llamada al constructor de Tiempo para iniciar los datos

	// imprime los valores iniciales del objeto Tiempo
	cout << "El tiempo universal inicial es ";
	t.imprimirUniversal();	//00:00:00
	cout << "\nEl tiempo universal estandar es ";
	t.imprimirEstandar();	// 12:00:00 AM

	t.establecerTiempo(13, 27, 6);	// definimos el nuevo tiempo

	// imprimimos las nuevas horas
	cout << "\n\nEl tiempo uiversal ahora es ";
	t.imprimirUniversal();
	cout << "\nEl tiempo estandar ahora es ";
	t.imprimirEstandar();

	t.establecerTiempo(99, 99, 99);		// intento de definir datos invalidos

	// imprime los valores t despues de especificar datos incorrectos
	cout << "\n\nDespues de intentar con datos invalidos "
		<< "\nTiempo universal: ";
	t.imprimirUniversal();
	cout << "\nTiempo EStandar: ";
	t.imprimirEstandar();
	cout << endl;

	return 0;
}

