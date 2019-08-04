// demostracion de reemplazar caracteres en una cadena
#include <iostream>
using std::cout;
using std::endl;

#include <string>
using std::string;

int main()
{
	// el compilador une todos las partes en una sola cadena
	string cadena("Los valores en cualquier subarbol izquierdo"
		"\nson menos que el valor en el"
		"\nnodo padre y los valores en"
		"\ncualquier subarbol derecho son mayores"
		"\nque el valor en el nodo padre");

	cout << "Cadena original:\n" << cadena << "\n\n";

	// elimina todos los caracteres de (incluyendo) la ubicacion
	// 72 hasta el final de cadena
	cadena.erase(72);

	//
	cout << "Cadena original, despues de erase:\n" << cadena
		<< "\n\nDespues del primer reemplazo:\n";

	int posicion = cadena.find(" ");

	// reemplaza todos los espacios por puntos
	while (posicion != string::npos)
	{
		cadena.replace(posicion, 1, ".");
		posicion = cadena.find(" ", posicion + 1);
	}

	cout << cadena;

	// reemplazamos otra vez
	posicion = cadena.find(".");

	// reemplaza todos los puntos con dos signos de pto y coma
	// NOTA: esto sobrescribe los caracteres
	while (posicion != string::npos)
	{
		cadena.replace(posicion, 2, "xxxxx;;yyy", 5, 2);
		posicion = cadena.find(".", posicion + 1);
	}	

	cout << "\n\nDespues del segundo reemplazo:\n" << cadena
		<< endl;

	return 0;
}
