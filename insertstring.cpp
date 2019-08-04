// demostracion de las funciones miembro insert de la clase string
#include <iostream>
using std::cout;
using std::endl;

#include <string>
using std::string;

int main()
{
	string cadena1("principio fin");
	string cadena2("enmedio");
	string cadena3("12345678");
	string cadena4("xx");

	cout << "Cadenas iniciales:\n"
		<< "\ncadena1: " << cadena1
		<< "\ncadena2: " << cadena2
		<< "\ncadena3: " << cadena3
		<< "\ncadena4: " << cadena4 << "\n\n";

	// inserta "enmedio" en la ubicacion 10 en cadena1
	cadena1.insert(10, cadena2);

	// inserta "xx" en la ubicacion 3 en cadena3
	//cadena3.insert(3, cadena4, 0, string::npos);
	cadena3.insert(3, cadena4, 0, cadena4.length());

	cout << "Cadenas iniciales:\n"
		<< "\ncadena1: " << cadena1
		<< "\ncadena2: " << cadena2
		<< "\ncadena3: " << cadena3
		<< "\ncadena4: " << cadena4 << "\n\n";

	return 0;
}
