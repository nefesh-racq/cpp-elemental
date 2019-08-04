// uso de la funcion swap para intercambiar dos objetos string
#include <iostream>
using std::cout;
using std::endl;
using std::cin;
using std::boolalpha;
using std::noboolalpha;

#include <string>
using std::string;

void imprimirEstadisticas(const string &);

int main()
{
	string cadena;

	cout << "estadistaica antes de la entrada de datos.\n";
		//<< boolalpha;
	imprimirEstadisticas(cadena);

	// solo lee la primera palabra
	cout << "\n\nEscriba una cadena: ";
	cin >> cadena;
	cout << "La cadena introduida fue: " << cadena;

	cout << "\nEstadisticas despues de la entrada de datos.\n";
	imprimirEstadisticas(cadena),

	// lee la segunda palabra
	cin >> cadena;
	cout << "\n\nEl resto de la cadena es:\n";
	imprimirEstadisticas(cadena);

	// adjunta 46 caracteres a cadena
	cadena += "1234567890abcdefghijklmnopqrstuvwxyz1234567890";
	cout << "\n\nla cadena es ahora: " << cadena << endl;
	imprimirEstadisticas(cadena);

	// agrega 10 elementos a cadena
	cadena.resize(cadena.length() + 10);
	cout << "\n\nEstadisticas despues de cambiar el tamaño"
		<< " en base a (length() + 10).\n";
	imprimirEstadisticas(cadena);

	cout << endl;

	return 0;
}

void imprimirEstadisticas(const string &cadena)
{
	cout << noboolalpha
		<< "capacidad: " << cadena.capacity()
		<< "\ntamaño maximo: " << cadena.max_size()
		<< "\ntamaño: " << cadena.size()
		<< "\nlongitud: " << cadena.length()
		<< boolalpha
		<< "\nvacia: " << cadena.empty();
}
