// uso de gcount, read y write
#include <iostream>
using std::cin;
using std::cout;
using std::endl;

int main()
{
	const int TAMANIO = 80;
	char bufer[TAMANIO];

	cout << "cin.read: "<< endl;
	cin.read(bufer, 20);
	//cout << bufer << endl;

	// usa las funciones write y gcount para mostrar los caracteres del bufer
	cout << "\nel enunciado que escribio fue " << endl;
	cout.write(bufer, cin.gcount());
	cout << endl;

	return 0;
}
