// comparacion entre la entrada de una cadena
// mediante cin y cin.get
#include <iostream>
using std::cin;
using std::cout;
using std::endl;

#include <string>
using std::string;

int main()
{
	// crea dos arreglos char, de 80 posiciones
	const int TAMANIO = 80;
	char bufer1[TAMANIO];
	char bufer2[TAMANIO];

	// usa cin para introducir caracteres en bufer1
	cout << "Usando cin: " << endl;
	cin >> bufer1;
	// mostramos el resultado
	cout << "bufer1: " << bufer1 << endl;

	cout << "\nUsando cin.get(): " << endl;
	cin.get(bufer2, TAMANIO);
	cout << "bufer2: " << bufer2 << endl;

	return 0;
}