// operaciones de entrada desde un objeto istringstream
#include <iostream>
using std::cout;
using std::endl;

#include <string>
using std::string;

#include <sstream>
using std::istringstream;

int main()
{
	string entrada("entrada prueba 123 4.7 A");
	istringstream cadenaEntrada(entrada);
	string cadena1;
	string cadena2;
	int entero;
	double doble;
	char caracter;

	cadenaEntrada >> cadena1
		>> cadena2
		>> entero
		>> doble
		>> caracter;

	cout << "se extrajeron los siguientes elementos\n"
		<< "del objeto istringstream: "
		<< "\nstring: " << cadena1
		<< "\nstring: " << cadena2
		<< "\n   int: " << entero
		<< "\ndouble: " << doble
		<< "\n  char: " << caracter
		<< endl;

	// intento de leer de un flujo vacio
	long valor;
	cadenaEntrada >> valor;

	// prueba los resultados del flujo
	if (cadenaEntrada.good())
		cout << "\n\ndl valor long es: " << valor << endl;
	else
		cout << "\n\ncadenaEntrada esta vacia" << endl;

	return 0;
}
