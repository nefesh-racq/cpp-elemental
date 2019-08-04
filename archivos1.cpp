// lectura de un archivo 
#include <iostream>
using std::cout;
using std::endl;
using std::cerr;
using std::fixed;
using std::ios;
using std::left;
using std::right;
using std::showpoint;

#include <fstream>
using std::ifstream;

#include <iomanip>
using std::setprecision;
using std::setw;

#include <string>
using std::string;

#include <cstdlib>
using std::exit;	// termina el programa

void imprimirLinea(int, const string, double);

int main()
{
	// el constructor de ifstream abre el archivo
	ifstream archivo("clientes.dat", ios::in);

	// sale del programa si ifstream no puede abrir el archivo
	if (!archivo)	// operador ! sobrecargado
	{
		cerr << "No se pudo abrir el archivo." << endl;
		exit(1);
	}

	int cuenta;
	char nombre[30];
	double saldo;

	cout << left << setw(10) << "cuenta" << setw(13)
		<< "Nombre" << "saldo" << endl << fixed;// << showpoint;

	// mostramos el archivo linea por linea a la vez
	while (archivo >> cuenta >> nombre >> saldo)
		imprimirLinea(cuenta, nombre, saldo);

	return 0;
}

void imprimirLinea(int cuenta, const string nombre, double saldo)
{
	cout << left << setw(10) << cuenta << setw(11) << nombre
		<< setw(7) << setprecision(2) << right << saldo << endl;
}
