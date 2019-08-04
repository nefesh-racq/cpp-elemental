#include <iostream>
using std::cout;
using std::endl;

void imprimirCaracteres(const char *);

int main()
{
	const char frase[] = "imprimir caracteres de una cadena";

	cout << "la cadena es :\n";
	imprimirCaracteres(frase);
	cout << endl;

	return 0;
}

// sPtr se puede modificar, pero no puede modificar al caracter que apunta
// es decir sPtr es un apuntador de solo lectura
void imprimirCaracteres(const char *sPtr)
{
	for (; *sPtr != '\0'; sPtr++)
		cout << *sPtr;

}

