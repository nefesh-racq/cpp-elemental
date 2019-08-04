// demostracion de comparacion de string
#include <iostream>
using std::endl;
using std::cout;

#include <string>
using std::string;

int main()
{
	string cadena1("probando las funciones de comparacion");
	string cadena2("hola");
	string cadena3("probador");
	string cadena4(cadena2);

	cout << "cadena1: " << cadena1 << "\ncadena2: " << cadena2
		<< "\ncadena3:" << cadena3 << "\ncadena4: " << cadena4
		<< endl;

	// comparacion de cadenas
	if (cadena1 == cadena4)
		cout << "cadena1 == cadena4\n";
	else
	{
		if (cadena1 > cadena4)
			cout << "cadena1 > cadena4\n";
		else
			cout << "cadena1 < cadena4\n";
	}

	// comparacion de cadena1 y cadena2
	int resultado = cadena1.compare(cadena2);

	if (resultado == 0)
		cout << "cadena1.compare(cadena2) == 0\n";
	else
	{
		if (resultado > 0)
			cout << "cadena1.compare(cadena2) > 0\n";
		else
			cout << "cadena1.compare(cadena2) < 0\n";
	}

	// comparacion de cadena1 (elementos 1 a 4) y 
	// cadena3 (elementos 1 a 4)
	resultado = cadena1.compare(1, 4, cadena3, 1, 4);

	if (resultado == 0)
		cout << "cadena1.compare(1, 4, cadena3, 1, 4) == 0\n";
	else
	{
		if (resultado > 0)
			cout << "cadena1.compare(1, 4, cadena3, 1, 4) > 0\n";
		else
			cout << "cadena1.compare(1, 4, cadena3, 1, 4) < 0\n";
	}


	// comparacion de cadena 2 y cadena 4
	resultado = cadena4.compare(0, cadena2.length(), cadena2);

	if (resultado == 0)
		cout << "cadena4.compare(0, cadena2.length(), cadena2) == 0\n";
	else
	{
		if (resultado > 0)
			cout << "cadena4.compare(0, cadena2.length(), cadena2) > 0\n";
		else
			cout << "cadena4.compare(0, cadena2.length(), cadena2) < 9\n";
	}

	// comparacino de cadena 2 y cadena 4
	resultado = cadena2.compare(0, 3, cadena4);

	if (resultado == 0)
		cout << "cadena2.compare(0, 3, cadena4) == 0\n";
	else
	{
		if (resultado > 0)
			cout << "cadena2.compare(0, 3, cadena4) > 0\n";
		else
			cout << "cadena2.compare(0, 3, cadena4) < 0\n";
	}

	return 0;
}