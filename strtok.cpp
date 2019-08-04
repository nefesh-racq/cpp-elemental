// uso de strtok para dividir una caden aen tokens.
#include <iostream>
using std::cout;
using std::endl;

#include <cstring>	// para los prototipos strtok
using std::strtok;

#include <iomanip>
using std::setw;

int main()
{
	char enunciado[] = "este es un enunciado con 7 tokens";
	char *tokenPtr;

	cout << "La cadena a dividir en tokens es:\n" << enunciado
		<< "\n\nLos tokens son:\n\n";

	// empieza la division de unciados en tokens
	tokenPtr = strtok(enunciado, " ");

	// continua dividiendo enunciado en tokens hasta que tokenPtr se convierta en NULL
	while (tokenPtr != NULL)
	{
		cout << tokenPtr << '\n';
		tokenPtr = strtok(NULL, " ");	// obtiene el siguiente token
	}

	cout << "\nDespues de strtok, enunciado = " << enunciado <<  endl;

	for (int i = 0; i < 33; i++)
		cout << "[" << setw(2) << i << "] = " << setw(3) << (int)enunciado[i] 
			<< " : " << enunciado[i] << endl;

	return 0;
}

