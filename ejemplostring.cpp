#include <iostream>
using std::cout;
using std::endl;
using std::cin;

#include <string>
using std::string;

int main()
{
	// string a = 'x';	// invalido por que hace la llamada al contructor en una declaracion
	// a = 'z';	// correcto por que usa el operador sobrecargado y constructor de copia
	string a;
	a = '0';
	string cadena(9, '5');

	//cout << cadena << endl;
	//getline(cin, cadena);
	cout << cadena << endl;
	cout << "cadena.length(): " << cadena.length() << endl
		<< "cadena.size(): " << cadena.size() << endl;

	return 0;
}
