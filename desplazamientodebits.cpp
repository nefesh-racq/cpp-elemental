// demostracion de los operadores de desplazamiento
#include <iostream>
using std::cout;
using std::endl;


#include <iomanip>
using std::setw;

void mostrarBits(unsigned);

int main()
{
	unsigned numero1 = 960;

	// demuestra el desplazamiento a la izquierda
	cout << "EL resultado de desplazar a la izquierda \n";
	mostrarBits(numero1);
	cout << "8 posiciones de bit mediante el operando de desplazamiento"
		<<  " a la izquierda es\n";
	mostrarBits(numero1 << 8);

	// demuestra desplazamiento a la derecha
	cout << "El resultado de desplazar a la derecha\n";
	mostrarBits(numero1);
	cout << "8 posiciones de bit mediante el operandor de "
		<< "desplazamiento a la derecha es\n";
	mostrarBits(numero1 >> 8);

	// mostramos 1 con desplazamiento a la izquierda
	// imprime todos los datos pra ver sus valores
	cout << "\n\nnumero 1: desplazamiento a la izquierda\n";
	unsigned uno = 1;
	int DSPL = 8 * sizeof(unsigned) - 1;
	unsigned MASCARA = 1 << DSPL;

	cout << "sizeof(unsigned): " << sizeof(unsigned) << endl;
	cout << "DSPL: " << DSPL << endl;
	mostrarBits(DSPL);
	cout << "MASCARA:\n";
	mostrarBits(MASCARA);
	cout << "\nuno:\n";
	mostrarBits(uno);
	cout << "\nuno & MASCARA: "
		<< (uno & MASCARA) << endl;
	mostrarBits(uno & MASCARA);
	// desplazamos 4 veces a la izquierda uno
	cout << "desplazando uno <<= " << 8 * sizeof(unsigned) - 1 << endl;
	mostrarBits(uno <<= (8 * sizeof(unsigned) - 1));
	cout << "uno & MASCARA:\n";
	mostrarBits(uno & MASCARA);

	// convertir 1 a 2, 4, 8
	unsigned nro = 1;
	cout << "nro << 1: " << (nro << 1) << endl
		<< "nro << 2: " << (nro << 2) << endl
		<< "nro << 3: " << (nro << 3) << endl;

	// 1 + 2 = 3 usando operador binario
	int u = 1;
	int d = 2;
	cout << "1 + 2 = " << (u | d) << endl
		<< "10 + 5 = " << (10 | 5) << endl
		<< "11 & 10 = " << (11 & 10) << endl
		<< "11 | 10 = " << (11 | 10) << endl
		<< "11 ^ 10 = " << (11 ^ 10) << endl;

	return 0;
}

void mostrarBits(unsigned valor)
{
	const int DSPL = 8 * sizeof(unsigned) - 1;
	const unsigned MASCARA = 1 << DSPL;

	cout << setw(10) << valor << " = ";

	for (int i = 1; i <= DSPL + 1; i++)
	{
		cout << (valor & MASCARA ? '1' : '0');
		valor <<= 1;

		if (i % 8 == 0)
			cout << " ";
	}

	cout << endl;
}
