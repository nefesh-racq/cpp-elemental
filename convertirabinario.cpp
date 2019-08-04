// imprime un entero sin signo en bits
#include <iostream>
using std::cout;
using std::cin;
using std::endl;

#include <iomanip>
using std::setw;

void mostrarBits(unsigned);

int main()
{
	unsigned valor;

	cout << "Escriba un entero positivo: ";
	cin >> valor;
	mostrarBits(valor);

	return 0;
}

void mostrarBits(unsigned valor)
{
	const int DESPL = 8 * sizeof(unsigned) - 1;
	const unsigned MASCARA = 1 << DESPL;

	cout << setw(10) << valor << " = ";

	// muestra los bits
	for (unsigned i = 1; i <= DESPL + 1; i++)
	{
		cout << (valor & MASCARA ? '1' : '0');
		valor <<= 1;	// desplaza el valos a la izquierda por 1

		if (i % 8 == 0)	// imprime espacio despues de 8 bits
			cout << ' ';
	}

	cout << endl;
}
