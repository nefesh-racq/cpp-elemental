// funcion width crea espacios
#include <iostream>
using std::cin;
using std::cout;
using std::endl;

int main()
{
	int valorAnchura = 4;
	char enunciado[10];

	cout << "Escriba un enunciado: " << endl;
	cin.width(5);	// introduce solo 5 caracteres del enunciado

	while (cin >> enunciado)
	{
		cout.width(valorAnchura++);
		cout << enunciado << endl;
		cin.width(5);	// introduce 5 caracteres mas de enunciado
	}

	return 0;


}
