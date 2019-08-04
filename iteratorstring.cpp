// use de un iterador para imprimir un objeto string
#include <iostream>
using std::endl;
using std::cout;

#include <string>
using std::string;

int main()
{
	string cadena("Prueba de los iteradores");
	// este iterator es constante no puede modificar el dato al que apunta
	string::const_iterator iterador1 = cadena.begin();

	cout << "cadena: " << cadena
		<< "\n(usando el iterador) cadena es: ";

	// itera a traves el objeto string
	while (iterador1 != cadena.end())
	{
		cout << *iterador1;	// desreferencia el iterador para acceder a su contenido
		iterador1++;		// itera usando aritmetica de operadores
	}

	cout << endl;

	return 0;
}
