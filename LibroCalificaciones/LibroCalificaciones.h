#include <string>	// el programa usa la clase string de la biblioteca estandar
using std::string;

class LibroCalificaciones {
public:
	// constanten cantidad de estudiantes
	const static int estudiantes = 10;	// constante cantidad de estudiantes

	// el contructor inicialia el nombre
	LibroCalificaciones(string, const int[]);

	void establecerNombreCurso(string);
	string obtenerNombreCurso();
	void mostrarMensaje();
	void procesarCalificaciones();
	int obtenerMinimo();
	int obtenerMaximo();
	double obtenerPromedio();
	void imprimirGraficoBarras();
	void imprimirCalificaciones();

private:
	string nombreCurso;
	int calificaciones[estudiantes];
};

