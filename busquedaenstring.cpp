// demostracion de las funciones miembro de busqueda
// en objetos string
#include <iostream>
using std::cout;
using std::endl;

#include <string>
using std::string;

int main()
{
	string cadena("mediodia es 12 pm; medianoche no es.");
	int ubicacion;

	// encuentra "es" en las ubicaciones 8 y 33
	cout << "Cadena original:\n" << cadena
		<< "\n\n(find) \"es\" se encontro en: " << cadena.find("es")
		<< "\n(rfind) \"es\" se encontro en: " << cadena.rfind("es");

	// encuentra 'e' en la ubicacion 1
	ubicacion = cadena.find_first_of("liesop");
	cout << "\n\n(find_first_of) encontro '" << cadena[ubicacion]
		<< "' del grupo \"liesop\" en: " << ubicacion;

	// encuentra 's' en la ubicacion 34
	ubicacion = cadena.find_last_of("misop");
	cout << "\n\n(find_last_of) encontro '" << cadena[ubicacion]
		<< "' del grupo \"misop\" en: " << ubicacion;

	// encuentra l en la ubicacion 12
	ubicacion = cadena.find_first_not_of("medop ias");
	cout << "\n\n(find_first_not_of) '" << cadena[ubicacion]
		<< "' no esta contenido en \"medop ias\" y se encontro en: "
		<< ubicacion;
/*
	//
	//
	ubicacion = cadena.find_first_of("medop ias");
	cout << "\n\n(find_first_of) '" << cadena[ubicacion]
		<< "' no esta contenido en \"medop ias\" y se encontro en: "
		<< ubicacion;
*/
	// encuentra ';' en la ubicacion 17
	ubicacion = cadena.find_first_not_of("12medop ias");
	cout << "\n\n(find_first_not_of) '" << cadena[ubicacion]
		<< "' no esta contenido en \"12medop ias\" y se "
		<< "encontro en: " << ubicacion << endl;

	// busca los caracteres que no estén en cadena
	ubicacion = cadena.find_first_not_of("mediodia es 12pm; medianoche no es.");
	cout << "\nfind_first_not_of(\"mediodia es 12pm; media noche no es.\")"
		<< " devuelve:: " << ubicacion << endl;

	return 0;
}
