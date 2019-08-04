// divide en tokens una cadena
// luego cambiamos los \0 por espacios para restaurar la cadena
#include <iostream>
using std::cout;
using std::endl;

#include <cstring>
using std::strtok;
using std::strlen;

int main()
{
	char cad[] = "esto es una cadena de prueba nada mas";
	char *tokenPtr;
	int tam = strlen(cad);

	cout << "cadena : \n " << cad << endl;
	cout << "tam : " << tam << endl;

	// iniciamos la division
	tokenPtr = strtok(cad, " ");

	// dividimos el resto de la cadena
	while (tokenPtr != NULL)
	{
		cout << tokenPtr << endl;
		tokenPtr = strtok(NULL, " ");
	}

	cout << "cadena : " << cad << endl;

	// volvemos a apuntar al inicio de la cadena
	tokenPtr = cad;

	// restauramos la cadena reemplazando '\0' (caracter nulo) por ' ' (espacio)
	for (int i = 0; i < tam; i++)
	{
		if (*(tokenPtr + i) == '\0')
			*(tokenPtr + i) = ' ';
	}

	cout << "cadena restaurada : \n" << cad << endl;

	return 0;
}

