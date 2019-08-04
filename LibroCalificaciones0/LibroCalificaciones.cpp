#include <iostream>
using std::cout;
using std::cin;
using std::endl;
using std::fixed;

#include <iomanip>
using std::setprecision;	// establece la precision de decimales
using std::setw;			// establece el ancho de separacion

// incluye la definicion de las clases
#include "LibroCalificaciones.h"

// constructor de la clase inicializa los datos
LibroCalificaciones::LibroCalificaciones(string nombre, const int aCalificaciones[][PRUEBAS])
{
	setNombreCurso(nombre);
	
	for (int estudiante = 0; estudiante < ESTUDIANTES; estudiante++)
		for (int prueba = 0; prueba < PRUEBAS; prueba++)
			calificaciones[estudiante][prueba] = aCalificaciones[estudiante][prueba];
}

// funcion que establece el nombre del curso
void LibroCalificaciones::setNombreCurso(string nombre)
{
	nombreCurso = nombre;
}

// devuelve el nombre del curso
string LibroCalificaciones::getNombreCurso()
{
	return nombreCurso;
}

void LibroCalificaciones::mostrarMensaje()
{
	cout << "Bien venido al libro de calificaciones para\n" << getNombreCurso() << endl;
}

void LibroCalificaciones::procesarCalificaciones()
{
	// imprime el arreglo de calificaciones
	imprimirCalificaciones();

	// obtenemos las calificaciones maximas y minimas
	cout << "\nla calificaciones mas baja es : " << getMinimo()
		<< "\nla calificacion mas alta es : " << getMaximo() << endl;

	// imprimos el grafico de barras
	imprimirGrafico();
}

// obtencion de la calificacion minima
int LibroCalificaciones::getMinimo()
{
	int minimo = 100;

	for (int estudiante = 0; estudiante < ESTUDIANTES; estudiante++)
	{
		for(int prueba = 0; prueba < PRUEBAS; prueba++)
		{
			if (calificaciones[estudiante][prueba] < minimo)
				minimo = calificaciones[estudiante][prueba];
		}
	}

	return minimo;
}

// calificacion maxima
int LibroCalificaciones::getMaximo()
{
	int maximo = 0;

	for (int estudiante = 0; estudiante < ESTUDIANTES; estudiante++)
	{
		for (int prueba = 0; prueba < PRUEBAS; prueba++)
		{
			if (calificaciones[estudiante][prueba] > maximo)
				maximo = calificaciones[estudiante][prueba];
		}
	}

	return maximo;
}

// obtiene el promedio de las notas
double LibroCalificaciones::getPromedio(const int notas[], const int calificaciones)
{
	int total = 0;

	for (int calificacion = 0; calificacion < calificaciones; calificacion++)
		total += notas[calificacion];

	return static_cast<double>(total) / calificaciones;
}

// imprime el grafico de barras para las notas
void LibroCalificaciones::imprimirGrafico()
{
	cout << "\ndistribucion general de calificaciones:" << endl;

	// almacena la frecuencia de calificaciones
	const int FRECUENCIA = 11;
	int frecuencia[FRECUENCIA] = {};

	for (int estudiante = 0; estudiante < ESTUDIANTES; estudiante++)
		for (int prueba = 0; prueba < PRUEBAS; prueba++)
			++frecuencia[calificaciones[estudiante][prueba] / 10];

	// para cada frecuencia imprimimos su grafico
	for (int cuenta = 0; cuenta < FRECUENCIA; cuenta++)
	{
		if (cuenta == 0)
			cout << "  0-9: ";
		else if (cuenta == 10)
			cout << "  100: ";
		else
			cout << cuenta * 10 << "-" << (cuenta * 10) + 9 << ": ";

		for (int starts = 0; starts < frecuencia[cuenta]; starts++)
			cout << "*";

		cout << endl;
	}
}

// imprime las calificaciones
void LibroCalificaciones::imprimirCalificaciones()
{
	cout << "\nlas calificaciones son:\n\n";
	cout << "               ";

	for (int prueba = 0; prueba < PRUEBAS; prueba++)
		cout << "Prueba " << prueba +1 << "  ";

	cout << "Promedio" << endl;

	for (int estudiante = 0; estudiante < ESTUDIANTES; estudiante++)
	{
		cout << "estudiante " << setw(2) << estudiante + 1;

		for (int prueba = 0; prueba < PRUEBAS; prueba++)
			cout << setw(10) << calificaciones[estudiante][prueba];

		// imprimos el promedio, pasamos la fila del estudiante
		double promedio = getPromedio(calificaciones[estudiante], PRUEBAS);
		
		cout << setw(10) << setprecision(2) << fixed << promedio << endl;
	}
}

