// demostracion asignacion y concatenacion de objetos string
#include <iostream>
using std::cout;
using std::endl;

#include <string>
using std::string;

int main()
{
	string cadena1("cat");
	string cadena2;	// se inicializa con cadena vacia
	string cadena3;	// se inicia con cadena vacia

	cadena2 = cadena1;	//
	cadena3.assign(cadena1);	// asigna cadena 1 a cadena 3
	cout << "cadena1: " << cadena1 << endl
		<< "cadena2: " << cadena2 << endl
		<< "cadena3: " << cadena3 << endl;

	// modifica cadena2 y cadena1
	cadena2[0] = cadena3[2] = 'r';

	cout << "Despues de modificar cadena2 y cadena3\n"
		<< "cadena1: " << cadena1
		<< "\ncadena2: " << cadena2
		<< "\ncadena3: " << cadena3 << endl << endl;

	// demostracion de la funcion miembro at
	for (int i = 0; i < cadena3.length(); i++)
		cout << cadena3.at(i);

	// declaracion cadena4 y cadena5
	string cadena4(cadena1 + "apulta");	// concatenacion
	string cadena5;

	// += sobrecargado
	cadena3 += "peta";	// crea carpeta haciendo una concatenacion
	cadena1.append("acumba");	// crea catacumba

	// adjunta las ubicacioens de los subindices 4 hasta el final
	// de cadena1 para crear la cadena "cumba" (al principio, cadena5 esta vacio)
	cadena5.append(cadena1, 4, cadena1.length() - 1);

	cout << "\n\nDespues de concatenar:\ncadena1: " << cadena1
		<< "\ncadena2: " << cadena2 << "\ncadena3: " << cadena3
		<< "\ncadena4: " << cadena4 << "\ncadena5: " << cadena5
		<< endl;

	return 0;
}
