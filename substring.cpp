// demostracion de la clase substr de string
#include <iostream>
using std::endl;
using std::cout;

#include <string>
using std::string;

int main()
{
	string cadena1("El aeroplano aterrizo a tiempo.");

	// obtiene la subcadena "plano" que empieza en
	// el subindice 7 y consiste de 5 caracteres
	cout << "cadena1: " << cadena1 << "\n\n";
	cout << "cadena1.substr(7, 5): "
		<< cadena1.substr(7, 5) << endl;

	return 0;
}
