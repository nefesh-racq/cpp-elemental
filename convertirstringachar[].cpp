// conversion de string a cadenas estilo C
#include <iostream>
using std::cout;
using std::endl;

#include <string>
using std::string;

int main()
{
	string cadena("CADENAS");
	const char *ptr1 = 0;
	int longitud = cadena.length();
	char *ptr2 = new char[longitud + 1];

	// copia  caracteres de cadena a la memoria asignada
	cadena.copy(ptr2, longitud, 0);	// copia cadena a ptr2 char*
	ptr2[longitud] = '\0';			// agrega el caracter nulo

	cout << "el objeto string cadena es " << cadena
		<< "\ncadena convertida a una cadena estilo C es "
		<< cadena.c_str() << "\nptr1 es ";

	// asigna el apuntador ptr1 el valor const char* devuelto por
	// la funcion data(), NOTA: esta es una asignacion potencialmente
	// peligrosa, si se modifica cadena, el apuntador ptr1 es puede
	// hacer invalido
	ptr1 = cadena.data();

	// imprime cada caracter usando un apuntador
	for (int i = 0; i < longitud; i++)
		cout << *(ptr1 + i);	// usa aritmetica de punteros

	cout << "\nptr2 es " << ptr2 << endl;
	delete [] ptr2;

	return 0;
}
