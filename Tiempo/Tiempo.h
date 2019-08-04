// declaracion de la clase Tiempo, las funiones estan definidas en tiempo.cpp

// evita multiples inclusiones del archivo de encabezado
#ifndef TIEMPO_H
#define TIEMPO_H

// define la clase tiempo
class Tiempo
{
public:
	Tiempo();	// constructor
	void establecerTiempo(int, int, int);	// hora, minuto, segundo
	void imprimirUniversal();	// imprime la hora en formato universal
	void imprimirEstandar();	// imprime la hora en formato estandar

private:
	int hora;		// 0 - 23
	int minuto;		// 0 - 59
	int segundo;	// 0 - 59
};

#endif

