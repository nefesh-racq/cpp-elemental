// uso de las funciones miembro get, put y eof
#include <iostream>
using std::cin;
using std::cout;
using std::endl;

int main()
{
	int caracter;	// usa int ya que char no puede representar EOF

	// pide al usuario que introduzca una linea de texto
	cout << "Antes de la entrada, cin.eof() es " << cin.eof()
		<< "Escriba el enunciado seguido del fin de archivo: " << endl;

	// usa get para leer cada caracter; usa put para mostrarlo
	while ((caracter = cin.get()) != EOF)
		cout.put(caracter);

	// muestra el caracter de fin de archivo
	cout << "\nEOF en este sistema es: " << caracter << endl;
	cout << "Despues de introducir EOF, cin.eof() es " << cin.eof() << endl;

	return 0;
}