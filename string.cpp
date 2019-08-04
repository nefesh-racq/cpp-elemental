// programa de prueba de clase sting de la biblioteca estandar
#include <iostream>
using std::cout;
using std::endl;

#include <string>
using std::string;

int main()
{
	string s1("feliz");
	string s2(" cumpleanios");
	string s3;

	// prueba los operadores de igualdad y relacionales sobrecargados
	cout << "s1 es \"" << s1 << "\": s2 es \"" << s2
		<< "\"; s3 es \"" << s3 << '\"'
		<< "\n\nLos resultados de comparar s2 y s1:"
		<< "\ns2 == s1 produce " << ( s2 == s1 ? "true" : "false" )
		<< "\ns2 != s1 produce " << ( s2 != s1 ? "true" : "false" )
		<< "\ns2 >  s1 produce " << ( s2 > s1 ? "true" : "false" )
		<< "\ns2 <  s1 produce " << ( s2 < s1 ? "true" : "false" )
		<< "\ns2 >= s1 produce " << ( s2 >= s1 ? "true" : "false" )
		<< "\ns2 <= s1 produce " << ( s2 <= s1 ? "true" : "false" );

	// prueba la funcion miembro empty de string
	cout << "\n\nPrueba de s2.empty():" << endl;
	
	if (s3.empty())
	{
		cout << "s3 esta vacia: se asignara s1 a s3:" << endl;
		s3 = s1;	// operador = sobrecargado
		cout << "s3 es \"" << s3 << "\"";
	}

	// prueba el operador de concatenacion
	cout << "\n\ns1 += s2 produce s1 = ";
	s1 += s2;	// operador += sobrecargado
	cout << s1;

	// prueba el operador de concatenacion sobrecargado de string
	// con una cadena estilo c
	cout << "\n\ns1 += \" a ti\" produce " << endl;
	s1 += " a ti";
	cout << "s1 = " << s1 << "\n\n";

	// prueba la funcion miembro subtr de string
	cout << "La subcadena de s1 que empieza en la ubicacion 0 para\n"
		<< "17 caracteres, s1.substr(0, 17), es:\n"
		<< s1.substr(0, 17) << "\n\n";

	// prueba la opciona "hasta el final de la cadena" de subtr
	cout << "La subcadena de s1 que empieza en\n"
		<< "la ubicacion 18, s1.substr(18), es:\n"
		<< s1.substr(18) << endl;

	// prueba el constructor de copia
	string *s4Ptr = new string(s1);
	cout << "\n*s4Ptr = " << *s4Ptr << "\n\n";

	// prueba el operador de asignacion (=) con la auto-asignacion
	cout << "asignando *s4Ptr a *s4Ptr" << endl;
	*s4Ptr = *s4Ptr;
	cout << "*s4Ptr = " << *s4Ptr << endl;

	// prueba destructor
	delete s4Ptr;

	// prueba el uso del operador de subindice para crear lvalues
	s1[0] = 'F';
	s1[6] = 'C';
	cout << "\ns1 despues de s1[0] = 'F' y s1[6] = 'C' es: "
		<< s1 << "\n\n";

	// prueba el subindice fuera de rango con la funcion miembro "at" de string
	s1.at(30) = 'd';	// ERROR: subindice fuera de rango

	return 0;
}

