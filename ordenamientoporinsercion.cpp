#include <iostream>
using std::cout;
using std::endl;

#include <ctime>
using std::time;

#include <cstdlib>
using std::rand;
using std::srand;

#include <iomanip>
using std::setw;

void ordenar(int [], int);

int main()
{
	const int TAM = 20;
	int datos[TAM] = {};
	srand(time(NULL));

	for (int i = 0; i < TAM; i++)
	{
		datos[i] = 1 + rand() % 100;
		cout << setw(3) << datos[i] << " ";
	}

	cout << "\ndatos ordenados..!" << endl;
	ordenar(datos, TAM);

	for (int j = 0; j < TAM; j++)
		cout << setw(3) << datos[j] << " ";

	cout << endl;

	return 0;
}

void ordenar(int d[], int tam)
{
	int insertar = 0;

	for (int i = 1; i < tam; i++)
	{
		insertar = d[i];
		int sgte = i;

		while ((sgte > 0) && (d[sgte - 1] > insertar))
		{
			d[sgte] = d[sgte - 1];
			sgte--;
		}

		d[sgte] = insertar;
	}
}

