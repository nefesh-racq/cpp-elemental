#include <string>
using std::string;

class LibroCalificaciones
{
public:
	// constantes estaticas
	const static int ESTUDIANTES = 10;
	const static int PRUEBAS = 3;

	// constructor inicializa el nombre curso y cakufucacuibes
	LibroCalificaciones(string, const int[][PRUEBAS]);

	void setNombreCurso(string);
	string getNombreCurso();
	void mostrarMensaje();
	void procesarCalificaciones();
	int getMinimo();
	int getMaximo();
	double getPromedio(const int[], const int);
	void imprimirGrafico();
	void imprimirCalificaciones();

private:
	string nombreCurso;
	int calificaciones[ESTUDIANTES][PRUEBAS];
};
