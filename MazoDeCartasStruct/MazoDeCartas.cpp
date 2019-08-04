//
#include <iostream>
using std::cout;
using std::left;
using std::right;

#include <iomanip>
using std::setw;

#include <cstdlib>
using std::rand;
using std::srand;

#include <ctime>
using std::time;

#include "MazoDeCartas.h"

MazoDeCartas::MazoDeCartas()
{
	// palo para las cartas
	static const char *palo[4] =
		{"Corazones", "Diamante", "Treboles", "Espadas"};

	// caras para las cartas
	static const char *cara[13] =
		{"As", "Dos", "Tres", "Cuatro", "Cinco", "Seis", "Siete",
		"Ocho", "Nueve", "Diez", "Sota", "Reina", "Rey"};

	// establece valores para las 52 cartas
	for (int i = 0; i < 52; i++)
	{
		mazo[i].cara = cara[i % 13];
		mazo[i].palo = palo[i / 13];
	}

	srand(time(0));	// semilla para generar numeros aleatorios
}

void MazoDeCartas::barajar()
{
	// barajamos las cartas aleatoriamente
	for (int i = 0; i < 52; i++)
	{
		int j = rand() % 52;
		Carta temp = mazo[i];
		mazo[i] = mazo[j];
		mazo[j] =  temp;
	}
}

// repartimos las cartas en el mazo
void MazoDeCartas::repartir() const
{
	// muestra la cara y el palo
	for (int i = 0; i < 52; i++)
		cout << right << setw(6) << mazo[i].cara << " de "
			<< left << setw(8) << mazo[i].palo
			<< ((i + 1) % 2 ? '\t' : '\n');
}