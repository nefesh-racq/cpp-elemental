#include <iostream>
using std::endl;
using std::cout;
using std::cin;

int main() {
	char cadena1[20];	// reserva 20 caracteres
	char cadena2[] = "literal de cadena";	//reserva 17 caracteres

	// lee la cadena del usuario y lo pone al arreglo cadena1
	cout << "Escriba la cadena \"hola todos\": ";
	cin >> cadena1;

	// imprime las cadenas
	cout << "cadena1 es: " << cadena1 << "\ncadena2 es : " << cadena2;

	cout << "\ncadena1 con espacios entre letras es:\n";

	// imprime caracteres hasta llegar al caracter nulo
	for (int i = 0; cadena1[i] != '\0'; i++)
		cout << cadena1[i] << ' ';

	cin >> cadena1;	// lee el resto de la cadena introducida que es "todos"
	cout << "\ncadena1 es: " << cadena1 << endl;

	return 0;
}
