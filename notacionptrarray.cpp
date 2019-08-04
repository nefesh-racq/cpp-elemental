// copia de una cadena usando notacion de arreglos y notacion de apuntadores
#include <iostream>
using std::endl;
using std::cout;

void copia1(char *, const char *);
void copia2(char *, const char *);

int main()
{
	char cadena1[10];
	const char *cadena2 = "hola";
	char cadena3[10];
	char cadena4[] = "Hasta luego";

	copia1(cadena1, cadena2);	// copia cadena2 a cadena1
	cout << "cadena1 = " << cadena1 << endl;

	copia2(cadena3, cadena4);	// copia cadena 4 a cadena3
	cout << "cadena3 = " << cadena3 << endl;

	return 0;	
}

void copia1(char *s1, const char *s2)
{
	// la copia ocurre en el encabezado del for
	for (int i = 0; (s1[i] = s2[i]) != '\0'; i++)
		;
}

void copia2(char *s1, const char *s2)
{
	// la copia ocurre en el encabezado del for
	for ( ; (*s1 = *s2) != '\0'; s1++, s2++)
		;
}

