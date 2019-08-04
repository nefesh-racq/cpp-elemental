#include <iostream>
using std::cout;
using std::endl;

#include <iomanip>
using std::setw;

void mostrarBits(unsigned);

int main()
{
	unsigned num1;
	unsigned num2;
	unsigned mascara;
	unsigned establecerBits;

	// & a nivel de bits "and"
	num1 = 2179876355;
	mascara = 1;
	cout << "numero y mascara \n";
	mostrarBits(num1);
	mostrarBits(mascara);
	cout << "usando AND \"&\" a nivel de bits es :\n";
	mostrarBits(num1 & mascara);

	// | a nivel de bit "or inclusivo"
	num1 = 15;
	establecerBits = 241;
	cout << "\nnumero establecerBits\n";
	mostrarBits(num1);
	mostrarBits(establecerBits);
	cout << "usando OR inclusivo \"|\" es :\n";
	mostrarBits(num1 | establecerBits);

	// demuestra or exclusivo
	num1 = 139;
	num2 = 199;
	cout << "\nvalores\n";
	mostrarBits(num1);
	mostrarBits(num2);
	cout << "usando OR exclusivo \"^\" es:\n";
	mostrarBits(num1 ^ num2);

	// complemento a nivel de bits
	num1 = 21845;
	cout << "\nvalores:\n";
	mostrarBits(num1);
	cout << "es " << endl;
	mostrarBits(~num1);
	
	return 0;
}

void mostrarBits(unsigned valor)
{
	const int DESPL = 8 * sizeof(unsigned) - 1;
	const unsigned MASCARA = 1 << DESPL;

	cout << setw(10) << valor << " = ";

	for (unsigned i = 1; i <= DESPL + 1; i++)
	{
		cout << (valor & MASCARA ? '1' : '0');
		valor <<= 1;	// desplaza el valor a la izquierda

		if (i % 8 == 0)
			cout << ' ';
	}

	cout << endl;
}
