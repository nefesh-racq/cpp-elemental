/*
 ejemplo de enumeraciones, enum
*/
#include <iostream>
using std::cout;
using std::endl;
using std::cin;

int main(int argc, char const *argv[])
{
	enum color {BLANCO, AZUL, VERDE, ROJO};
	color rotulador = ROJO;
	int x;

	cout << "\nel colo es " << rotulador << endl;
	cout << "Intoruzca un valor: ";
	cin >> x;

	rotulador = (color)x;

	switch (rotulador)
	{
		case BLANCO:
			cout << "el color es blanco.\n"; 
			break;
		case AZUL:
			cout << "el color es azul.\n"; 
			break;
		case VERDE:
			cout << "el color es verde.\n"; 
			break;
		case ROJO:
			cout << "el color es rojo.\n"; 
			break;
		default:
			cout << "introduce un valor entre 0 - 3.\n"; 
	}

	return 0;
}
