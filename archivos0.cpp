// creacion de un archivo secuencial
#include <iostream>
using std::cerr;
using std::cin;
using std::cout;
using std::endl;
using std::ios;

#include <fstream>		// flujo de archivos
using std::ofstream;	// flujo de archivos de salida

#include <cstdlib>
using std::exit;		// 

int main()
{
	// el constructor de ofstream abre el archivo
	ofstream archivo("clientes.dat", ios::out);

	// sale del programa si no puede crear el archivo
	if (!archivo)	// óperador ! sobrecargado
	{
		cerr << "No se puede abrir el archivo " << endl;
		exit(1);
	}

	cout << "Escriba la cuenta, nombre y saldo." << endl
		<< "Escriba fin de archivo para terminar la entrada.?" << endl;

	int cuenta;
	char nombre[30];
	double saldo;

	// lee la cuenta, nombre y saldo de cin, y luego
	// lo coloca en el archivo
	while (cin >> cuenta >> nombre >> saldo)
	{
		archivo  << cuenta << ' ' << nombre << ' ' << saldo << endl;
		cout << "? ";
	}

	return 0;
}
