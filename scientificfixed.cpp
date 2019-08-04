// como mostrar los valores de punto flotante en los formatos
// predeterminados del sistema, cientifico y fijo
#include <iostream>
using std::cout;
using std::endl;
using std::fixed;
using std::scientific;

int main()
{
	double x = 0.001234567;
	double y = 1.946e9;

	// muestra a x e y en el formato predeterminado
	cout << "Formato predeterminado:\n"
		<< x << '\t' << y << endl;

	// muestra x e y en el formato cientifico
	cout << "\nFormato cientifico:\n"
		<< scientific << x << '\t' << y << endl;

	// muestra x e y en formato fijo
	cout << "\nFormato fijo:\n"
		<< fixed << x << '\t' << y << endl;

	return 0;
}
