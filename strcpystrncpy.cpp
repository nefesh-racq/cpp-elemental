// uso de strcpy y strncpy
#include <iostream>
using std::cout;
using std::endl;

#include <cstring>	// prototipo para strcpy y strncpy
using std::strcpy;
using std::strncpy;

int main()
{
	char x[] = "feliz cumpleaños a ti";
	char y[25];
	char z[18];

	strcpy(y, x);	// copia el contenido de x en y

	cout << "La cadena en el arreglo x es: " << x
		<< "\nLa cadena en el arreglo y es: " << y << endl;

	// copia los primeros 17 caracteres de x a z
	strncpy(z, x, 17);
	z[17] = '\0';

	cout << "La cadena en el arreglo z es: " << z << endl;

	return 0;
}

