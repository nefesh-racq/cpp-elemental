// definicion de las funciones miembros para la clase MazoDeCartas
// simula como barajar y repartir un mazo de cartas
#include <iostream>
using std::cout;
using std::left;
using std::right;

#include <iomanip>
using std::setw;

#include <cstdlib>	// prototipo para srand y rand
using std::srand;
using std::rand;

#include <ctime>	// prototipo para el manejo del tiempo
using std::time;

#include "MazoDeCartas.h"

// el constructor de mazodecartas
MazoDeCartas::MazoDeCartas()
{
	// itera a través de las filas del mazo
	for (int fila = 0; fila <= 3; fila++)
	{
		// itera a través de las columnas del mazo
		for (int columna = 0; columna <= 12; columna++)
		{
			mazo[fila][columna] = 0;	// inicializa los valores del mazo en 0
		}
	}

	srand(time(NULL));	// siembra el generador de numeros aleatorios
}

// barajando las cartas en el mazo
void MazoDeCartas::barajar()
{
	int fila;
	int columna;

	// recorre cada una de las cartas del mazo
	for (int carta = 1; carta <= 52; carta++)
	{
		do	// selecciona una nueva posicion aleatoria para mezclar las cartas
		{
			fila = rand() % 4;	// selecciona una fila ente 0-3
			columna = rand() % 13;	// selecciona una col entre 0-12
		} while (mazo[fila][columna] != 0);

		// pone la carta en la fila aleatoria
		mazo[fila][columna] = carta;
	}
}

// repartimso las cartas mezcladas
void MazoDeCartas::repartir()
{
	// iniciamos el arreglo palo
	static const char *palo[4] = {"Corazones", "Diamantes", "Bastos", "Espadas"};

	// iniciamos el arreglo de las caras del mazo
	static const char *cara[13] = {"As", "Dos", "Tres", "Cuatro", "Cinco",
									"Seis", "Siete", "Ocho", "Nueve", "Diez",
									"Sota", "Reina", "Rey"};

	// recorrermos las 52 cartas del mazo
	for (int carta = 1; carta <= 52; carta++)
	{
		// recorremos las filas del mazo
		for (int fila = 0; fila <= 3; fila++)
		{
			// recorremos las columnas del mazo
			for (int columna = 0; columna <= 12; columna++)
			{
				// si la posicion contiene la carta actual la mostramos
				if (mazo[fila][columna] == carta)
				{
					cout << setw(8) << right << cara[columna]
						<< " de " << setw(8) << left << palo[fila]
						<< (carta % 2 == 0 ? '\n' : '\t');
				}
			}
		}
	}
}

