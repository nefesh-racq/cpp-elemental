#include <iostream>
using std::cout;
using std::cin;
using std::endl;
using std::fixed;

#include <iomanip>
using std::setprecision;
using std::setw;

#include "LibroCalificaciones.h"

LibroCalificaciones::LibroCalificaciones(string nom, const int arg[]) {
	establecerNombreCurso(nom);

	for (int i = 0; i < estudiantes; i++)
		calificaciones[i] = arg[i];
}

void LibroCalificaciones::establecerNombreCurso(string nom) {
	nombreCurso = nom;
}

string LibroCalificaciones::obtenerNombreCurso() {
	return nombreCurso;
}

void LibroCalificaciones::mostrarMensaje() {
	cout << "Bien venido al libro de calificaciones para el curos " << obtenerNombreCurso() << endl;
}

void LibroCalificaciones::procesarCalificaciones() {
	// imprime el areglo de calificaciones
	imprimirCalificaciones();

	cout << "\nEl promedio de la clase es " << setprecision(2) << fixed << obtenerPromedio() << endl;

	cout << "la calificacion mas baja es " << obtenerMinimo() << endl;
	cout << "la calificacion mas alta es " << obtenerMaximo() << endl;

	imprimirGraficoBarras();
}

int LibroCalificaciones::obtenerMinimo() {
	int temp = calificaciones[0];

	for (int i = 1; i < estudiantes; i++)
		if (temp > calificaciones[i])
			temp = calificaciones[i];

	return temp;
}

int LibroCalificaciones::obtenerMaximo() {
	int temp = 0;

	for (int i = 0; i < estudiantes; i++)
		if (temp < calificaciones[i])
			temp = calificaciones[i];

	return temp;
}

double LibroCalificaciones::obtenerPromedio() {
	double promedio = 0;

	for (int i = 0; i < estudiantes; i++)
		promedio += calificaciones[i];

	promedio = promedio / estudiantes;

	return promedio;
}

void LibroCalificaciones::imprimirGraficoBarras() {
	cout << "\nDistribucion de calificaciones:" << endl;

	const int tamanioFrecuencia = 11;
	int frecuencia[tamanioFrecuencia] = {};

	// para cada calificacion incrementamos la frecuencia apropiada
	for (int calificacion = 0; calificacion < estudiantes; calificacion++)
		frecuencia[calificaciones[calificacion] / 10]++;

	for (int cuenta = 0; cuenta < tamanioFrecuencia; cuenta++) {
		if (cuenta == 0)
			cout << "  0-9: ";
		else if (cuenta == 10)
			cout << "  100: ";
		else
			cout << cuenta * 10 << "-" << (cuenta * 10) + 9 << ". ";

		for (int estrellas = 0; estrellas < frecuencia[cuenta]; estrellas++)
			cout << "*";

		cout << endl;
	}
}

void LibroCalificaciones::imprimirCalificaciones() {
	for (int i = 0; i < estudiantes; i++)
		cout << "calificacion " << i << ": " << calificaciones[i] << endl;
}


