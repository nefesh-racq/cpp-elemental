// ejemplo de arrays de punteros, se usan por lo general
// para leer argumentos en la linea de comandos.
// almacenar cadenas
#include <iostream>
using std::endl;
using std::cout;

int main()
{
	const char *nombres[] = {"jose", "alberto", "antonio jose", "nanci"};
	//const char nombress[] = "aaabbbccc";
	//const char tam[4][10] = {"jose", "alberto", "antonio", "nanci"};

	//nombres[0] = "pepe luis";	// es valido porque el array es de punteros no de cadena de caracteres
	//cout << *(nombres + 1) << endl
	//	<< nombres[2] << endl;

	for (int i = 0; i < 4; i++)
		cout << nombres[i] << endl;

	return 0;
}

