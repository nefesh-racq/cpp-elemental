#include <iostream>
using std::cout;
using std::cin;
using std::endl;
using std::cerr;
using std::ios;

#include <fstream>
using std::ofstream;
using std::ifstream;

#include <cstdlib>
using std::exit;

#include <string>
using std::string;

int main()
{
	int nro;
	char nombre[50];
	string archivo = "test1.dat";

	ofstream escribir(archivo, ios::out);

	if (!escribir)
	{
		cerr << "Error al crear " << endl;
		exit(1);
	}

	cout << "Ingrese el nro, nombre.\n?: ";
	while (cin >> nro >> nombre)
	{
		escribir << nro << ' ' << nombre << endl;
		cout << "?: ";
	}

	ifstream leer(archivo, ios::in);

	if (!leer)
	{
		cerr << "Error al leer" << endl;
		exit(1);
	}

	//leer.seekg(1, ios::beg);
	cout << "\nnro " << "nombre" << endl;

	while (leer >> nro >> nombre)
		cout << nro << ' ' << nombre << endl;

	return 0;
}
