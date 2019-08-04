#include <iostream>
using std::endl;
using std::cout;

#include <iomanip>
using std::setw;
using std::fixed;
using std::setprecision;

double promedio(const int[], const int);

int main()
{
	const int ESTUDIANTES = 10;
	const int EXAMENES = 3;
	int datos[ESTUDIANTES][EXAMENES] = 
		{
			{50, 63, 78},
			{51, 60, 70},
			{85, 54, 77},
			{80, 50, 64},
			{87, 90, 35},
			{89, 97, 58},
			{25, 54, 65},
			{74, 66, 38},
			{55, 66, 88},
			{79, 86, 72}
		};

	cout << "\nLas notas de los estudiantes son:" << endl;
	cout << "               ";

	for (int nota = 0; nota < EXAMENES; nota++)
		cout << "examen " << nota + 1 << "  ";

	cout << setw(10) << "promedio" << endl;

	for (int estudiante = 0; estudiante < ESTUDIANTES; estudiante++)
	{
		cout << "estudiante " << setw(2) << estudiante + 1;

		for (int examen = 0; examen < EXAMENES; examen++)
			cout << setw(10) << datos[estudiante][examen];

		cout << setw(12) << fixed << setprecision(2) << promedio(datos[estudiante], EXAMENES) << endl;
	}

	return 0;
}

double promedio(const int d[], const int tam)
{
	int total = 0;

	for (int nota = 0; nota < tam; nota++)
		total += d[nota];

	return static_cast<double>(total) / tam;
}

