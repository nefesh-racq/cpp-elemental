// apuntador no constante a datos no constantes
#include <iostream>
using std::endl;
using std::cout;

#include <cctype>	// prototipos para islower y toupper
using std::islower;
using std::toupper;

void convertirAMayusculas0(char *);
void convertirAMayusculas1(char *);

int main()
{
	char frase[] = "caracteres y $32.98";

	cout << "la frase antes de la conversion es : "
		<< frase << endl;
	convertirAMayusculas0(frase);
	cout << "la frase despues de la conversion es : "
		<< frase << endl;

	return 0;
}

void convertirAMayusculas0(char *c)
{
	for (int i = 0; c[i] != '\0'; i++)
	{
		if (islower(c[i]))
		{
			c[i] = toupper(c[i]);
		}
	}
}

void convertirAMayusculas1(char *c)
{
	while (*c != '\0')
	{
		if (islower(*c))
			*c = toupper(*c);

		c++;
	}
}

