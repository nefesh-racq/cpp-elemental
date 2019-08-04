// lectura mediante la cadena getline
#include <iostream>
using std::cin;
using std::cout;
using std::endl;

int main()
{
	const int TAMANIO = 80;
	char bufer[TAMANIO];

	cout << "Escriba un enunciado: " << endl;
	cin.getline(bufer, TAMANIO);

	//
	cout << "\nEl enunciado es:\n" << bufer << endl;

	return 0;
}