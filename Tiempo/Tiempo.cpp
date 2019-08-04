// definiciones de las funciones miembro para la clase Tiempo
#include <iostream>
using std::cout;

#include <iomanip>
using std::setfill;
using std::setw;

#include "Tiempo.h"	 // incluye la definicion de la clase

// inicializa los datos, asegura que los objetos inicien con datos
Tiempo::Tiempo()
{
	hora = minuto = segundo = 0;
}

// establece la hora del tiempo, con la hora universal
void Tiempo::establecerTiempo(int h, int m, int s)
{
	// validamos la hora, minutos y segundos
	hora = (h >= 0 && h < 24) ? h : 0;
	minuto = (m >= 0 && m < 60) ? m : 0;
	segundo = (s >= 0 && s < 60) ? s : 0;
}

// imprime el tiempo en formato universal (HH:MM:SS)
void Tiempo::imprimirUniversal()
{
	cout << setfill('0') << setw(2) << hora << ":"
		<< setw(2) << minuto << ":" << setw(2) << segundo;
}

// imprime la hora en formato estandar (HH:MM:SS AM or PM)
void Tiempo::imprimirEstandar()
{
	cout << ((hora == 0 || hora == 12) ? 12 : hora % 12) << ":"
		<< setfill('0') << setw(2) << minuto << ":"
		<< setw(2) << segundo << (hora < 12 ? " AM" : " PM");
}

