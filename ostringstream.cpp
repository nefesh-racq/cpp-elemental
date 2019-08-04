// uso del objeto ostringstream asignado en forma dinamica
#include <iostream>
using std::cout;
using std::endl;

#include <string>
using std::string;

#include <sstream>			// procesamiento de flujo de cadenas
using std::ostringstream;	// operador de insercion de flujo

int main()
{
	ostringstream cadenaSalida;	

	string cadena1("Envio de varios tipos de datos ");
	string cadena2("a un objeto ostringstream. ");
	string cadena3("\n          double: ");
	string cadena4("\n             int: ");
	string cadena5("\ndireccion de int: ");
	double doble1 = 123.4567;
	int entero = 22;

	// envia objetos string, double e int al objeto ostringstream cadenaSalida
	cadenaSalida << cadena1 << cadena2 << cadena3 << cadena4
		<< entero << cadena5 << &entero;

	// llama a str para obtener el contenido string del objeto
	// ostringstream
	cout << "cadenaSalida contiene:\n" << cadenaSalida.str();

	// agreaga caracteres adicionales y llama a str para enviar
	// el objeto string
	cadenaSalida << "\nse agreagaron mas caracteres";
	cout << "\n\nDespues de las inserciones de flujo adicionales.\n"
		<< "cadenaSalida contiene:\n" << cadenaSalida.str()
		<< endl;

	return 0;
}
