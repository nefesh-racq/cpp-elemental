// ejemploarchivos.cpp lectura y escritura de archivos
#include <iostream>
using std::cout;
using std::cin;
using std::endl;
using std::ios;
using std::cerr;
using std::fixed;
using std::left;
using std::right;

#include <iomanip>
using std::setw;
using std::setprecision;

#include <fstream>
using std::ofstream;
using std::ifstream;


#include <cstdlib>
using std::exit;

int main()
{
	ofstream archivo("test0.dat", ios::out);

	if (!archivo)
	{
		cerr << "no se puede crear o leer el archivo.\n";
		exit(1);
	}

	int nro;
	char producto[30];
	double precio;

	cout << "Ingrese nro, producto, precio: (ctrl+d para terminar)\n";

	while (cin >> nro >> producto >> precio)
	{
		archivo << nro << " " << producto << " " << precio << endl;
		cout << "?: ";
	}

	/*****************************/
	ifstream lectura("test0.dat", ios::in);

	if (!lectura)
	{
		cerr << "No puede leerse el archivo.\n";
		exit(1);
	}

	cout << fixed << endl;
	cout << left << setw(7) << "Nro" << setw(13) << "producto"
		<< "precio" << endl;

	while (lectura >> nro >> producto >> precio)
		cout << setw(6) << nro << " " 
			<< setw(13) << producto << " " 
			<< setprecision(2) << precio << endl;

	return 0;
}
