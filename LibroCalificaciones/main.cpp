#include "LibroCalificaciones.h"

int main() {
	int notas[10] = {15, 78, 51, 46, 80, 75, 57, 69, 60, 70};
	LibroCalificaciones libro("unidad e.", notas);

	libro.mostrarMensaje();
	libro.procesarCalificaciones();

	return 0;
}

